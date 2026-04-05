// vmu_requisito_SysHLR02.cpp  (versão corrigida)
// Conflitos resolvidos:
//   [FIX-A] SOC agora em escala 0.0–1.0 em ambos os lugares
//   [FIX-B] limiar de velocidade unificado em 30 km/h
//   [FIX-C] transições para Electric_Drive usam check_ev_drive()
//   [FIX-D] Step() recebe aPed e power para passar ao check

#include <iostream>
#include <string>

// ============================================================
//  BLOCO DO REQUISITO  (antes ficava em ev_drive_mex.cpp)
//  Mantido aqui para não ter dois arquivos com lógica duplicada.
//  [FIX-A] SOC em escala 0.0–1.0 igual ao resto da VMU
// ============================================================
#define MAX_SPEED_KMH  30.0f   // km/h
#define MIN_SOC        0.37f   // 0.0 – 1.0  (= 37%)
#define MAX_PEDAL_PCT  0.40f   // 0.0 – 1.0  (= 40%)
#define MAX_POWER_KW   12.0f   // kW

// Retorna true se EV_Drive é permitido
bool check_ev_drive(float speed, float soc, float aPed, float power)
{
    if (speed > MAX_SPEED_KMH) return false;   // velocidade alta
    if (soc   < MIN_SOC)       return false;   // bateria fraca
    if (aPed  > MAX_PEDAL_PCT) return false;   // pedal fundo
    if (power > MAX_POWER_KW)  return false;   // potência alta
    return true;
}

// ============================================================
//  MÁQUINA DE ESTADOS
// ============================================================
class VMU_Controller {
private:
    int  currentState;
    bool Gen_Enable, Mot_Enable, ICE_Enable;

public:
    VMU_Controller() {
        currentState = 0;
        Gen_Enable = Mot_Enable = ICE_Enable = false;
    }

    // [FIX-C][FIX-D] Step agora recebe aPed e power
    void Step(float acc, float dcc, float speed,
              float charge, float aPed, float power)
    {
        // --- freio regenerativo tem prioridade ---
        if (dcc < -0.01f) {
            currentState = 4;
        } else if (currentState == 4 && dcc > 0.01f) {
            currentState = (speed == 0.0f) ? 0 : 1;
        }

        // --- transições por estado ---
        if (currentState == 0) {  // STANDSTILL
            if (acc > 0.0f && check_ev_drive(speed, charge, aPed, power))
                currentState = 1;  // → Electric
            else if (acc > 0.0f && charge < MIN_SOC)
                currentState = 2;  // → ICE
        }

        else if (currentState == 1) {  // ELECTRIC_DRIVE
            if (speed == 0.0f && acc == 0.0f)
                currentState = 0;  // → StandStill
            else if (!check_ev_drive(speed, charge, aPed, power))
                currentState = 2;  // → ICE  [FIX-C: condição unificada]
            else if ((acc >= 0.4f || speed > MAX_SPEED_KMH) && charge >= MIN_SOC)
                currentState = 3;  // → Hybrid
        }

        else if (currentState == 2) {  // ICE_DRIVE
            // [FIX-C][FIX-D] agora verifica os 4 critérios, não só SOC
            if (check_ev_drive(speed, charge, aPed, power))
                currentState = 1;  // → Electric
            else if ((acc >= 0.4f || speed > MAX_SPEED_KMH) && charge >= MIN_SOC)
                currentState = 3;  // → Hybrid
        }

        else if (currentState == 3) {  // HYBRID_DRIVE
            // [FIX-B] velocidade unificada em MAX_SPEED_KMH (30), não 25
            if (check_ev_drive(speed, charge, aPed, power) && acc < 0.3f)
                currentState = 1;  // → Electric
            else if (charge < MIN_SOC)
                currentState = 2;  // → ICE
        }

        // --- saídas ---
        switch (currentState) {
            case 0: Gen_Enable=true;  Mot_Enable=true;  ICE_Enable=false; break;
            case 1: Gen_Enable=false; Mot_Enable=true;  ICE_Enable=false; break;
            case 2: Gen_Enable=false; Mot_Enable=false; ICE_Enable=true;  break;
            case 3: Gen_Enable=false; Mot_Enable=true;  ICE_Enable=true;  break;
            case 4: Gen_Enable=true;  Mot_Enable=false; ICE_Enable=false; break;
            default:Gen_Enable=false; Mot_Enable=false; ICE_Enable=false; break;
        }

        std::cout << "[VMU] " << GetStateName()
                  << " | Gen=" << Gen_Enable
                  << " Mot=" << Mot_Enable
                  << " ICE=" << ICE_Enable << "\n";
    }

    int         GetState()  const { return currentState; }
    bool        GetGen()    const { return Gen_Enable;   }
    bool        GetMot()    const { return Mot_Enable;   }
    bool        GetICE()    const { return ICE_Enable;   }
    void        Reset()           { currentState=0; Gen_Enable=Mot_Enable=ICE_Enable=false; }
    void        ForceState(int s) { currentState=s; }

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
