###########################################################################
## Makefile generated for component 'HEV_SeriesParallel'. 
## 
## Makefile     : HEV_SeriesParallel.mk
## Generated on : Tue Mar 24 13:34:26 2026
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/HEV_SeriesParallel.exe
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = HEV_SeriesParallel
MAKEFILE                  = HEV_SeriesParallel.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2025b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2025b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/VCU/VMU-Vehicle-Management-Unit-/Model/model_powerSplit/mathworks-Simscape-HEV-Series-Parallel-25.2.5.0/work
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = HEV_SeriesParallel_comp.rsp
CMD_FILE                  = HEV_SeriesParallel.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
LIBSSC_SLI_MINGW64_OBJS   = 
LIBSSC_CORE_MINGW64_OBJS  = 
LIBPM_ST_MINGW64_OBJS     = 
LIBMC_MINGW64_OBJS        = 
LIBEX_MINGW64_OBJS        = 
LIBPM_MINGW64_OBJS        = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    8.x
# ToolchainInfo Version:   2025b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O0
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -Oline -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/HEV_SeriesParallel.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DMAT_FILE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=HEV_SeriesParallel -DNUMST=3 -DNCSTATES=74 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_y.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_ic.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_f.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxy_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_slv.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mcon_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_slf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxicr_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxicrm_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_exp.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mode.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_zc.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_q1_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_eq_tol.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxm_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_lv.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_acon_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_imin.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mnl_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vdf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_qx_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mdxy_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_apar_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vpf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_imax.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vsf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_nldv.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_sclv.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_tdxy_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_act.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxy.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_var_tol.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dnf_v_x.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_log.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_icrm_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_assert.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_all.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mpar_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_il.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_slf0.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vmf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxf_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_acon.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dnf_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxcer_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxdelt_p.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_qx.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_1_gateway.c $(MATLAB_ROOT)/rtw/c/src/rt_logging.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_backsubrr_dbl.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_lu_real.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_matrixlib_dbl.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_data.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rtGetInf.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rtGetNaN.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_look.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_look2d_normal.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_nonfinite.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_zcfcn.c $(START_DIR)/HEV_SeriesParallel_grt_rtw/rtmodel.c

MAIN_SRC = $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = HEV_SeriesParallel_c0f8494c_49_ds.obj HEV_SeriesParallel_c0f8494c_49_ds_y.obj HEV_SeriesParallel_c0f8494c_49_ds_ic.obj HEV_SeriesParallel_c0f8494c_49_ds_f.obj HEV_SeriesParallel_c0f8494c_49_ds_dxy_p.obj HEV_SeriesParallel_c0f8494c_49_ds_slv.obj HEV_SeriesParallel_c0f8494c_49_ds_mcon_p.obj HEV_SeriesParallel_c0f8494c_49_ds_slf.obj HEV_SeriesParallel_c0f8494c_49_ds_dxicr_p.obj HEV_SeriesParallel_c0f8494c_49_ds_dxicrm_p.obj HEV_SeriesParallel_c0f8494c_49_ds_obs_exp.obj HEV_SeriesParallel_c0f8494c_49_ds_mode.obj HEV_SeriesParallel_c0f8494c_49_ds_zc.obj HEV_SeriesParallel_c0f8494c_49_ds_q1_p.obj HEV_SeriesParallel_c0f8494c_49_ds_eq_tol.obj HEV_SeriesParallel_c0f8494c_49_ds_dxm_p.obj HEV_SeriesParallel_c0f8494c_49_ds_lv.obj HEV_SeriesParallel_c0f8494c_49_ds_acon_p.obj HEV_SeriesParallel_c0f8494c_49_ds_imin.obj HEV_SeriesParallel_c0f8494c_49_ds_mnl_p.obj HEV_SeriesParallel_c0f8494c_49_ds_vdf.obj HEV_SeriesParallel_c0f8494c_49_ds_qx_p.obj HEV_SeriesParallel_c0f8494c_49_ds_mdxy_p.obj HEV_SeriesParallel_c0f8494c_49_ds_apar_p.obj HEV_SeriesParallel_c0f8494c_49_ds_vpf.obj HEV_SeriesParallel_c0f8494c_49_ds_imax.obj HEV_SeriesParallel_c0f8494c_49_ds_vsf.obj HEV_SeriesParallel_c0f8494c_49_ds_nldv.obj HEV_SeriesParallel_c0f8494c_49_ds_sclv.obj HEV_SeriesParallel_c0f8494c_49_ds_dxf.obj HEV_SeriesParallel_c0f8494c_49_ds_tdxy_p.obj HEV_SeriesParallel_c0f8494c_49_ds_obs_act.obj HEV_SeriesParallel_c0f8494c_49_ds_dxy.obj HEV_SeriesParallel_c0f8494c_49_ds_var_tol.obj HEV_SeriesParallel_c0f8494c_49_ds_dnf_v_x.obj HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p.obj HEV_SeriesParallel_c0f8494c_49_ds_log.obj HEV_SeriesParallel_c0f8494c_49_ds_icrm_p.obj HEV_SeriesParallel_c0f8494c_49_ds_assert.obj HEV_SeriesParallel_c0f8494c_49_ds_obs_all.obj HEV_SeriesParallel_c0f8494c_49_ds_mpar_p.obj HEV_SeriesParallel_c0f8494c_49_ds_obs_il.obj HEV_SeriesParallel_c0f8494c_49_ds_slf0.obj HEV_SeriesParallel_c0f8494c_49_ds_vmf.obj HEV_SeriesParallel_c0f8494c_49_ds_dxf_p.obj HEV_SeriesParallel_c0f8494c_49_ds_acon.obj HEV_SeriesParallel_c0f8494c_49_ds_dnf_p.obj HEV_SeriesParallel_c0f8494c_49_ds_dxcer_p.obj HEV_SeriesParallel_c0f8494c_49_ds_dxdelt_p.obj HEV_SeriesParallel_c0f8494c_49_ds_qx.obj HEV_SeriesParallel_c0f8494c_49.obj HEV_SeriesParallel_c0f8494c_1_gateway.obj rt_logging.obj rt_backsubrr_dbl.obj rt_forwardsubrr_dbl.obj rt_lu_real.obj rt_matrixlib_dbl.obj HEV_SeriesParallel.obj HEV_SeriesParallel_data.obj rtGetInf.obj rtGetNaN.obj rt_look.obj rt_look2d_normal.obj rt_nonfinite.obj rt_zcfcn.obj rtmodel.obj

MAIN_OBJ = rt_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/lib/ssc_sli_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/lib/ssc_core_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/pm_st/lib/pm_st_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/mc/lib/mc_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/ex/lib/ex_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/pm/lib/pm_mingw64.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) -Wl,--start-group $(LIBS) -Wl,--end-group $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_y.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_y.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_ic.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_ic.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_f.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_f.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxy_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxy_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_slv.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_slv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_mcon_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mcon_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_slf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_slf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxicr_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxicr_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxicrm_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxicrm_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_obs_exp.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_mode.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mode.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_zc.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_zc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_q1_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_q1_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_eq_tol.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_eq_tol.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxm_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxm_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_lv.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_lv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_acon_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_acon_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_imin.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_imin.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_mnl_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mnl_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_vdf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vdf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_qx_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_qx_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_mdxy_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mdxy_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_apar_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_apar_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_vpf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vpf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_imax.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_imax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_vsf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vsf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_nldv.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_nldv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_sclv.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_sclv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_tdxy_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_tdxy_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_obs_act.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_act.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxy.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxy.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_var_tol.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_var_tol.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dnf_v_x.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dnf_v_x.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_tdxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_log.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_log.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_icrm_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_icrm_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_assert.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_assert.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_obs_all.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_all.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_mpar_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_mpar_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_obs_il.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_obs_il.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_slf0.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_slf0.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_vmf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_vmf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxf_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_acon.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_acon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dnf_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dnf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxcer_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxcer_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_dxdelt_p.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_dxdelt_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49_ds_qx.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49_ds_qx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_49.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_49.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_c0f8494c_1_gateway.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_c0f8494c_1_gateway.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_logging.obj : $(MATLAB_ROOT)/rtw/c/src/rt_logging.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_backsubrr_dbl.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_backsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_forwardsubrr_dbl.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_forwardsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_lu_real.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_lu_real.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_matrixlib_dbl.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_matrixlib_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


HEV_SeriesParallel_data.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/HEV_SeriesParallel_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_look.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_look.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_look2d_normal.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_look2d_normal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_zcfcn.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rt_zcfcn.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtmodel.obj : $(START_DIR)/HEV_SeriesParallel_grt_rtw/rtmodel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_main.obj : $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


#------------------------
# BUILDABLE LIBRARIES
#------------------------

$(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/lib/ssc_sli_mingw64.lib : $(LIBSSC_SLI_MINGW64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_SLI_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ssc_core/lib/ssc_core_mingw64.lib : $(LIBSSC_CORE_MINGW64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_CORE_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/pm_st/lib/pm_st_mingw64.lib : $(LIBPM_ST_MINGW64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBPM_ST_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/mc/lib/mc_mingw64.lib : $(LIBMC_MINGW64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBMC_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ex/lib/ex_mingw64.lib : $(LIBEX_MINGW64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBEX_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/pm/lib/pm_mingw64.lib : $(LIBPM_MINGW64_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBPM_MINGW64_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


