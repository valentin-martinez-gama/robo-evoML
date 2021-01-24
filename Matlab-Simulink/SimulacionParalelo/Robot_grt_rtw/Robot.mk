###########################################################################
## Makefile generated for Simulink model 'Robot'. 
## 
## Makefile     : Robot.mk
## Generated on : Fri Sep 04 19:20:01 2020
## MATLAB Coder version: 5.0 (R2020a)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Robot.exe
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# CMD_FILE                Command file

PRODUCT_NAME              = Robot
MAKEFILE                  = Robot.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/GERARD~1/DOCUME~1/GitHub/ROBO-C~1/MATLAB~1/SIMULA~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
CMD_FILE                  = Robot.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
LIBSM_SSCI_LCC_OBJS       = 
LIBSM_LCC_OBJS            = 
LIBPM_MATH_LCC_OBJS       = 
LIBSSC_SLI_LCC_OBJS       = 
LIBSSC_CORE_LCC_OBJS      = 
LIBNE_LCC_OBJS            = 
LIBMC_LCC_OBJS            = 
LIBEX_LCC_OBJS            = 
LIBPM_LCC_OBJS            = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   2020a
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = "$(CC_PATH)/lcc64"

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = "$(LD_PATH)/lcclnk64"

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = "$(AR_PATH)/lcclib64"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Robot.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/Robot_grt_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/toolbox/physmod/sm/ssci/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/sm/core/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/sm/math/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/simscape/engine/sli/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/simscape/engine/core/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/simscape/compiler/core/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/network_engine/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/common/math/core/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/common/lang/core/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/common/external/library/c/win64 -I$(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/c/win64

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DMAT_FILE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=Robot -DNUMST=3 -DNCSTATES=58 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_create.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_setParameters.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_asserts.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_deriv.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_checkDynamics.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_compOutputs.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_asm_delegate.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_sim_delegate.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_mode_zero_crossings.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_geometries.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_gateway.c $(START_DIR)/Robot_grt_rtw/pm_printf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_zc.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_tdxy_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dxy_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_il.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_all.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_act.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_exp.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_m_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_log.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dnf_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_tdxf_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_a_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dxf_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dxf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_mode.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_f.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_duf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dtf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_assert.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_gateway.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_zc.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_tdxy_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dxy_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_il.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_all.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_act.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_exp.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_m_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_log.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dnf_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_tdxf_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_a_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dxf_p.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dxf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_mode.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_f.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_duf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dtf.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_assert.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3.c $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_gateway.c $(MATLAB_ROOT)/rtw/c/src/rt_logging.c $(START_DIR)/Robot_grt_rtw/rt_backsubrr_dbl.c $(START_DIR)/Robot_grt_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/Robot_grt_rtw/rt_lu_real.c $(START_DIR)/Robot_grt_rtw/rt_matrixlib_dbl.c $(START_DIR)/Robot_grt_rtw/Robot.c $(START_DIR)/Robot_grt_rtw/Robot_data.c $(START_DIR)/Robot_grt_rtw/rtGetInf.c $(START_DIR)/Robot_grt_rtw/rtGetNaN.c $(START_DIR)/Robot_grt_rtw/rt_nonfinite.c

MAIN_SRC = $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Robot_d2dba219_1.obj Robot_d2dba219_1_create.obj Robot_d2dba219_1_setParameters.obj Robot_d2dba219_1_asserts.obj Robot_d2dba219_1_deriv.obj Robot_d2dba219_1_checkDynamics.obj Robot_d2dba219_1_compOutputs.obj Robot_d2dba219_1_asm_delegate.obj Robot_d2dba219_1_sim_delegate.obj Robot_d2dba219_1_mode_zero_crossings.obj Robot_d2dba219_1_geometries.obj Robot_d2dba219_1_gateway.obj pm_printf.obj Robot_d2dba219_2_ds.obj Robot_d2dba219_2_ds_zc.obj Robot_d2dba219_2_ds_tdxy_p.obj Robot_d2dba219_2_ds_dxy_p.obj Robot_d2dba219_2_ds_obs_il.obj Robot_d2dba219_2_ds_obs_all.obj Robot_d2dba219_2_ds_obs_act.obj Robot_d2dba219_2_ds_obs_exp.obj Robot_d2dba219_2_ds_m_p.obj Robot_d2dba219_2_ds_log.obj Robot_d2dba219_2_ds_dnf_p.obj Robot_d2dba219_2_ds_tdxf_p.obj Robot_d2dba219_2_ds_a_p.obj Robot_d2dba219_2_ds_dxf_p.obj Robot_d2dba219_2_ds_dxf.obj Robot_d2dba219_2_ds_mode.obj Robot_d2dba219_2_ds_f.obj Robot_d2dba219_2_ds_duf.obj Robot_d2dba219_2_ds_dtf.obj Robot_d2dba219_2_ds_assert.obj Robot_d2dba219_2.obj Robot_d2dba219_2_gateway.obj Robot_d2dba219_3_ds.obj Robot_d2dba219_3_ds_zc.obj Robot_d2dba219_3_ds_tdxy_p.obj Robot_d2dba219_3_ds_dxy_p.obj Robot_d2dba219_3_ds_obs_il.obj Robot_d2dba219_3_ds_obs_all.obj Robot_d2dba219_3_ds_obs_act.obj Robot_d2dba219_3_ds_obs_exp.obj Robot_d2dba219_3_ds_m_p.obj Robot_d2dba219_3_ds_log.obj Robot_d2dba219_3_ds_dnf_p.obj Robot_d2dba219_3_ds_tdxf_p.obj Robot_d2dba219_3_ds_a_p.obj Robot_d2dba219_3_ds_dxf_p.obj Robot_d2dba219_3_ds_dxf.obj Robot_d2dba219_3_ds_mode.obj Robot_d2dba219_3_ds_f.obj Robot_d2dba219_3_ds_duf.obj Robot_d2dba219_3_ds_dtf.obj Robot_d2dba219_3_ds_assert.obj Robot_d2dba219_3.obj Robot_d2dba219_3_gateway.obj rt_logging.obj rt_backsubrr_dbl.obj rt_forwardsubrr_dbl.obj rt_lu_real.obj rt_matrixlib_dbl.obj Robot.obj Robot_data.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj

MAIN_OBJ = rt_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/sm/ssci/lib/win64/SM34F0~1.LIB C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/sm/core/lib/win64/sm_lcc.lib C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/sm/math/lib/win64/PM964C~1.LIB C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/simscape/engine/sli/lib/win64/SS6C37~1.LIB C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/simscape/engine/core/lib/win64/SSB942~1.LIB C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/NETWOR~1/lib/win64/ne_lcc.lib C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/common/math/core/lib/win64/mc_lcc.lib C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/common/external/library/lib/win64/ex_lcc.lib C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/common/FOUNDA~1/core/lib/win64/pm_lcc.lib

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

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
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(subst /,\,$(subst /,\,$(LIBS))) $(subst /,\,$(subst /,\,$(SYSTEM_LIBS))) $(subst /,\,$(subst /,\,$(TOOLCHAIN_LIBS)))
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/sm/ssci/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/sm/core/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/sm/math/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/simscape/engine/sli/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/simscape/engine/core/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/simscape/compiler/core/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/network_engine/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/math/core/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/lang/core/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/external/library/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/toolbox/physmod/common/foundation/core/c/win64/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/Robot_grt_rtw/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_create.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_create.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_setParameters.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_setParameters.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_asserts.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_asserts.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_deriv.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_deriv.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_checkDynamics.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_checkDynamics.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_compOutputs.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_compOutputs.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_asm_delegate.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_asm_delegate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_sim_delegate.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_sim_delegate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_mode_zero_crossings.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_mode_zero_crossings.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_geometries.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_geometries.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_1_gateway.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_1_gateway.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


pm_printf.obj : $(START_DIR)/Robot_grt_rtw/pm_printf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_zc.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_zc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_tdxy_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_tdxy_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_dxy_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dxy_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_obs_il.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_il.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_obs_all.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_all.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_obs_act.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_act.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_obs_exp.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_obs_exp.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_m_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_m_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_log.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_log.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_dnf_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dnf_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_tdxf_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_tdxf_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_a_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_a_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_dxf_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dxf_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_dxf.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dxf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_mode.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_mode.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_f.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_f.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_duf.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_duf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_dtf.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_dtf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_ds_assert.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_ds_assert.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_2_gateway.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_2_gateway.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_zc.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_zc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_tdxy_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_tdxy_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_dxy_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dxy_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_obs_il.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_il.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_obs_all.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_all.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_obs_act.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_act.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_obs_exp.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_obs_exp.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_m_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_m_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_log.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_log.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_dnf_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dnf_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_tdxf_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_tdxf_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_a_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_a_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_dxf_p.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dxf_p.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_dxf.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dxf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_mode.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_mode.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_f.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_f.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_duf.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_duf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_dtf.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_dtf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_ds_assert.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_ds_assert.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_d2dba219_3_gateway.obj : $(START_DIR)/Robot_grt_rtw/Robot_d2dba219_3_gateway.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_logging.obj : $(MATLAB_ROOT)/rtw/c/src/rt_logging.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_backsubrr_dbl.obj : $(START_DIR)/Robot_grt_rtw/rt_backsubrr_dbl.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_forwardsubrr_dbl.obj : $(START_DIR)/Robot_grt_rtw/rt_forwardsubrr_dbl.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_lu_real.obj : $(START_DIR)/Robot_grt_rtw/rt_lu_real.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_matrixlib_dbl.obj : $(START_DIR)/Robot_grt_rtw/rt_matrixlib_dbl.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot.obj : $(START_DIR)/Robot_grt_rtw/Robot.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


Robot_data.obj : $(START_DIR)/Robot_grt_rtw/Robot_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/Robot_grt_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/Robot_grt_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/Robot_grt_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_main.obj : $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


#------------------------
# BUILDABLE LIBRARIES
#------------------------

C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/sm/ssci/lib/win64/sm_ssci_lcc.lib : $(LIBSM_SSCI_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBSM_SSCI_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/sm/core/lib/win64/sm_lcc.lib : $(LIBSM_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBSM_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/sm/math/lib/win64/pm_math_lcc.lib : $(LIBPM_MATH_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBPM_MATH_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/simscape/engine/sli/lib/win64/ssc_sli_lcc.lib : $(LIBSSC_SLI_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBSSC_SLI_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/simscape/engine/core/lib/win64/ssc_core_lcc.lib : $(LIBSSC_CORE_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBSSC_CORE_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/NETWOR~1/lib/win64/ne_lcc.lib : $(LIBNE_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBNE_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/common/math/core/lib/win64/mc_lcc.lib : $(LIBMC_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBMC_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/common/external/library/lib/win64/ex_lcc.lib : $(LIBEX_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBEX_LCC_OBJS)


C:/PROGRA~1/MATLAB/R2020a/toolbox/physmod/common/FOUNDA~1/core/lib/win64/pm_lcc.lib : $(LIBPM_LCC_OBJS)
	@echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS) /out:$@ $(LIBPM_LCC_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


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
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


