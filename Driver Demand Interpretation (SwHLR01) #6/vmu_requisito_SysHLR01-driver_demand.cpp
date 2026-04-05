
#pragma once
#include <iostream>
#include <string>

// Constante única de SOC — um limiar, sem zona morta
static const float SOC_OK = 0.37f; // Acima → bateria disponível; Abaixo → proteger

// ------------------------------------------------------------------
// [FIX-C] Função do requisito — evita duplicar as condições
// dentro da máquina de estados
// ------------------------------------------------------------------
bool check_ev_drive(float speed, float charge, float aPed, float power)
{
    if (speed  > 30.0f)  return false;  // velocidade muito alta
    if (charge < SOC_OK) return false;  // bateria fraca
    if (aPed   > 0.40f)  return false;  // pedal muito fundo
    if (power  > 12.0f)  return false;  // potência muito alta
    return true;
}

class VMU_Controller {
private:
    int  currentState;                       // Estado atual da máquina
    bool Gen_Enable, Mot_Enable, ICE_Enable; // Saídas de driveline

    // [REQ-TORQUE] calculados a cada ciclo de 10 ms em Step()
    float torque_drive;   // 0.0 a 100.0 % — pedido de torque positivo (tração)
    float torque_brake;   // 0.0 a 100.0 % — pedido de torque negativo (frenagem)

public:
    VMU_Controller() {
        currentState = 0;               // Começa em StandStill
        Gen_Enable = false;
        Mot_Enable = false;
        ICE_Enable = false;
        torque_drive = 0.0f;            // sem torque de tração
        torque_brake = 0.0f;            // sem torque de frenagem
    }

    // ------------------------------------------------------------------
    // STEP: chamado a cada ciclo de controle
    // [FIX-D] adicionados aPed e power para checar o requisito completo
    // ------------------------------------------------------------------
    void Step(float acc, float dcc, float speed, float charge,
              float aPed, float power)
    {

        // ==============================================================
        // PARTE 0 — CÁLCULO DE TORQUE  [REQ-TORQUE]
        // Executado a cada ciclo de 10 ms (frequência do Step)
        // Entradas em % (0.0 a 1.0) → saída em % (0.0 a 100.0)
        // ==============================================================
        torque_drive = acc        * 100.0f;  // pedal de acelerador → torque positivo
        torque_brake = (-dcc)     * 100.0f;  // pedal de freio      → torque negativo
        if (torque_drive < 0.0f) torque_drive = 0.0f; // garante valor positivo
        if (torque_brake < 0.0f) torque_brake = 0.0f; // garante valor positivo

        // ==============================================================
        // PARTE 1 — TRANSIÇÕES
        // ==============================================================

        // REGRA GLOBAL: freio tem prioridade absoluta sobre tudo
        if (dcc < -0.01f) {
            currentState = 4; // → Regenerative_Braking

        // Soltou o freio: sai do REGEN
        } else if (currentState == 4 && dcc > 0.01f) {
            if (speed == 0.0f) currentState = 0; // → StandStill
            else               currentState = 1; // → Electric (segurança padrão)
        }

        // --- Transições do Operation_Mode ---

        if (currentState == 0) { // STANDSTILL
            if      (acc > 0.0f && check_ev_drive(speed, charge, aPed, power)) currentState = 1; // → Electric [FIX-C]
            else if (acc > 0.0f && charge < SOC_OK)                             currentState = 2; // → ICE
        }

        else if (currentState == 1) { // ELECTRIC_DRIVE
            if      (speed == 0.0f && acc == 0.0f)                             currentState = 0; // → StandStill
            else if (!check_ev_drive(speed, charge, aPed, power))              currentState = 2; // → ICE [FIX-C]
            else if ((acc >= 0.4f || speed > 30.0f) && charge >= SOC_OK)       currentState = 3; // → Hybrid
        }

        else if (currentState == 2) { // ICE_DRIVE
            if      (check_ev_drive(speed, charge, aPed, power))               currentState = 1; // → Electric [FIX-C]
            else if ((acc >= 0.4f || speed > 30.0f) && charge < SOC_OK)        currentState = 3; // → Hybrid
        }

        else if (currentState == 3) { // HYBRID_DRIVE
            if      (check_ev_drive(speed, charge, aPed, power) && acc < 0.3f) currentState = 1; // → Electric [FIX-B][FIX-C]
            else if (charge < SOC_OK)                                           currentState = 2; // → ICE
        }

        // ==============================================================
        // PARTE 2 — AÇÕES DE SAÍDA (o que cada estado ativa)
        // ==============================================================

        switch (currentState) {
            case 0: Gen_Enable=true;  Mot_Enable=true;  ICE_Enable=false; break; // StandStill
            case 1: Gen_Enable=false; Mot_Enable=true;  ICE_Enable=false; break; // Electric
            case 2: Gen_Enable=false; Mot_Enable=false; ICE_Enable=true;  break; // ICE
            case 3: Gen_Enable=false; Mot_Enable=true;  ICE_Enable=true;  break; // Hybrid
            case 4: Gen_Enable=true;  Mot_Enable=false; ICE_Enable=false; break; // Regen
            default:Gen_Enable=false; Mot_Enable=false; ICE_Enable=false; break; // Fail-safe
        }

        std::cout << "[VMU] " << GetStateName()
                  << " | Gen=" << Gen_Enable
                  << " Mot=" << Mot_Enable
                  << " ICE=" << ICE_Enable
                  << " | TqDrive=" << torque_drive << "%"
                  << " TqBrake="  << torque_brake  << "%\n";
    }

    // --- Getters para o framework de testes ---
    int   GetState()      const { return currentState; }
    bool  GetGen()        const { return Gen_Enable;   }
    bool  GetMot()        const { return Mot_Enable;   }
    bool  GetICE()        const { return ICE_Enable;   }
    float GetTorqueDrive() const { return torque_drive; } // [REQ-TORQUE]
    float GetTorqueBrake() const { return torque_brake; } // [REQ-TORQUE]
    void  Reset()               { currentState=0; Gen_Enable=Mot_Enable=ICE_Enable=false;
                                  torque_drive=0.0f; torque_brake=0.0f; }
    void  ForceState(int s)     { currentState=s; }

    std::string GetStateName() const {
        switch(currentState) {
            case 0: return "StandStill";
            case 1: return "Electric_Drive";
            case 2: return "ICE_Drive";
            case 3: return "Hybrid_Drive";
            case 4: return "Regen_Braking";
            default: return "INVALID";
        }
    }
};
