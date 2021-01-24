/*
 * Robot.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Robot".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Sep  4 19:19:42 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Robot_h_
#define RTW_HEADER_Robot_h_
#include <string.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#ifndef Robot_COMMON_INCLUDES_
# define Robot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "nesl_rtw.h"
#include "Robot_d2dba219_1_gateway.h"
#include "Robot_d2dba219_2_gateway.h"
#include "Robot_d2dba219_3_gateway.h"
#endif                                 /* Robot_COMMON_INCLUDES_ */

#include "Robot_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "math.h"
#include "rt_matrixlib.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMassMatrixIr
# define rtmGetMassMatrixIr(rtm)       ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
# define rtmSetMassMatrixIr(rtm, val)  ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
# define rtmGetMassMatrixJc(rtm)       ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
# define rtmSetMassMatrixJc(rtm, val)  ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
# define rtmGetMassMatrixNzMax(rtm)    ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
# define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
# define rtmGetMassMatrixPr(rtm)       ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
# define rtmSetMassMatrixPr(rtm, val)  ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
# define rtmGetMassMatrixType(rtm)     ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
# define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
# define rtmGetOdeDELTA(rtm)           ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
# define rtmSetOdeDELTA(rtm, val)      ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
# define rtmGetOdeDFDX(rtm)            ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
# define rtmSetOdeDFDX(rtm, val)       ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
# define rtmGetOdeE(rtm)               ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
# define rtmSetOdeE(rtm, val)          ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeF0
# define rtmGetOdeF0(rtm)              ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
# define rtmSetOdeF0(rtm, val)         ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
# define rtmGetOdeF1(rtm)              ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
# define rtmSetOdeF1(rtm, val)         ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
# define rtmGetOdeFAC(rtm)             ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
# define rtmSetOdeFAC(rtm, val)        ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
# define rtmGetOdeMASSMATRIX_M(rtm)    ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
# define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdePIVOTS
# define rtmGetOdePIVOTS(rtm)          ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
# define rtmSetOdePIVOTS(rtm, val)     ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
# define rtmGetOdeW(rtm)               ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
# define rtmSetOdeW(rtm, val)          ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
# define rtmGetOdeX0(rtm)              ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
# define rtmSetOdeX0(rtm, val)         ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
# define rtmGetOdeX1START(rtm)         ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
# define rtmSetOdeX1START(rtm, val)    ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
# define rtmGetOdeXTMP(rtm)            ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
# define rtmSetOdeXTMP(rtm, val)       ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
# define rtmGetOdeZTMP(rtm)            ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
# define rtmSetOdeZTMP(rtm, val)       ((rtm)->odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T STATE_1[10];                  /* '<S324>/STATE_1' */
  real_T OUTPUT_1_0[6];                /* '<S324>/OUTPUT_1_0' */
  real_T INTERNAL_2_1_1[4];            /* '<S324>/INTERNAL_2_1_1' */
  real_T RateTransition4[3];           /* '<S29>/Rate Transition4' */
  real_T Probe[2];                     /* '<S44>/Probe' */
  real_T Initial;                      /* '<S45>/Initial' */
  real_T Initial_e;                    /* '<S49>/Initial' */
  real_T RateTransition7;              /* '<S29>/Rate Transition7' */
  real_T Product1[6];                  /* '<S29>/Product1' */
  real_T INPUT_1_1_1[4];               /* '<S324>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S324>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S324>/INPUT_3_1_1' */
  real_T INPUT_4_1_1[4];               /* '<S324>/INPUT_4_1_1' */
  real_T INPUT_5_1_1[4];               /* '<S324>/INPUT_5_1_1' */
  real_T INPUT_6_1_1[4];               /* '<S324>/INPUT_6_1_1' */
  real_T STATE_2[51];                  /* '<S324>/STATE_2' */
  real_T OUTPUT_2_0[6];                /* '<S324>/OUTPUT_2_0' */
  real_T DiscreteTimeIntegrator;       /* '<S34>/Discrete-Time Integrator' */
  real_T Probe_e[2];                   /* '<S149>/Probe' */
  real_T INTERNAL_1_1_1[4];            /* '<S324>/INTERNAL_1_1_1' */
  real_T RateTransition4_b[3];         /* '<S156>/Rate Transition4' */
  real_T Probe_b[2];                   /* '<S171>/Probe' */
  real_T Initial_f;                    /* '<S172>/Initial' */
  real_T Initial_l;                    /* '<S176>/Initial' */
  real_T RateTransition7_l;            /* '<S156>/Rate Transition7' */
  real_T Product1_n[6];                /* '<S156>/Product1' */
  real_T INPUT_7_1_1[4];               /* '<S324>/INPUT_7_1_1' */
  real_T INPUT_8_1_1[4];               /* '<S324>/INPUT_8_1_1' */
  real_T INPUT_9_1_1[4];               /* '<S324>/INPUT_9_1_1' */
  real_T INPUT_10_1_1[4];              /* '<S324>/INPUT_10_1_1' */
  real_T INPUT_11_1_1[4];              /* '<S324>/INPUT_11_1_1' */
  real_T INPUT_12_1_1[4];              /* '<S324>/INPUT_12_1_1' */
  real_T STATE_3[51];                  /* '<S324>/STATE_3' */
  real_T OUTPUT_3_0[6];                /* '<S324>/OUTPUT_3_0' */
  real_T DiscreteTimeIntegrator_f;     /* '<S161>/Discrete-Time Integrator' */
  real_T Probe_m[2];                   /* '<S276>/Probe' */
  real_T INTERNAL_4_1_1[4];            /* '<S324>/INTERNAL_4_1_1' */
  real_T INTERNAL_3_1_1[4];            /* '<S324>/INTERNAL_3_1_1' */
  real_T d1;                           /* '<Root>/MATLAB Function' */
  boolean_T LogicalOperator;           /* '<S10>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S10>/Logical Operator1' */
  boolean_T LogicalOperator2;          /* '<S10>/Logical Operator2' */
  boolean_T LogicalOperator_m;         /* '<S11>/Logical Operator' */
  boolean_T LogicalOperator1_g;        /* '<S11>/Logical Operator1' */
  boolean_T LogicalOperator2_a;        /* '<S11>/Logical Operator2' */
} B_Robot_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INTERNAL_2_1_1_Discrete[2];   /* '<S324>/INTERNAL_2_1_1' */
  real_T Integrator_DSTATE;            /* '<S45>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S49>/Integrator' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S324>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S324>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete[2];      /* '<S324>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete[2];      /* '<S324>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_Discrete[2];      /* '<S324>/INPUT_5_1_1' */
  real_T INPUT_6_1_1_Discrete[2];      /* '<S324>/INPUT_6_1_1' */
  real_T Integrator_DSTATE_a;          /* '<S84>/Integrator' */
  real_T Filter_DSTATE;                /* '<S79>/Filter' */
  real_T Integrator_DSTATE_g;          /* '<S132>/Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S34>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S34>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_l;          /* '<S154>/Integrator' */
  real_T Integrator_DSTATE_m;          /* '<S211>/Integrator' */
  real_T Integrator_DSTATE_f;          /* '<S259>/Integrator' */
  real_T INTERNAL_1_1_1_Discrete[2];   /* '<S324>/INTERNAL_1_1_1' */
  real_T Integrator_DSTATE_fd;         /* '<S172>/Integrator' */
  real_T Integrator_DSTATE_fo;         /* '<S176>/Integrator' */
  real_T INPUT_7_1_1_Discrete[2];      /* '<S324>/INPUT_7_1_1' */
  real_T INPUT_8_1_1_Discrete[2];      /* '<S324>/INPUT_8_1_1' */
  real_T INPUT_9_1_1_Discrete[2];      /* '<S324>/INPUT_9_1_1' */
  real_T INPUT_10_1_1_Discrete[2];     /* '<S324>/INPUT_10_1_1' */
  real_T INPUT_11_1_1_Discrete[2];     /* '<S324>/INPUT_11_1_1' */
  real_T INPUT_12_1_1_Discrete[2];     /* '<S324>/INPUT_12_1_1' */
  real_T UnitDelay_DSTATE_c;           /* '<S161>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S161>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_lq;         /* '<S281>/Integrator' */
  real_T INTERNAL_4_1_1_Discrete[2];   /* '<S324>/INTERNAL_4_1_1' */
  real_T INTERNAL_3_1_1_Discrete[2];   /* '<S324>/INTERNAL_3_1_1' */
  real_T STATE_1_Discrete;             /* '<S324>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S324>/OUTPUT_1_0' */
  real_T RateTransition4_Buffer0[3];   /* '<S29>/Rate Transition4' */
  real_T RateTransition7_Buffer0;      /* '<S29>/Rate Transition7' */
  real_T STATE_2_Discrete;             /* '<S324>/STATE_2' */
  real_T OUTPUT_2_0_Discrete;          /* '<S324>/OUTPUT_2_0' */
  real_T RateTransition6_Buffer;       /* '<S1>/Rate Transition6' */
  real_T RateTransition3_Buffer;       /* '<S1>/Rate Transition3' */
  real_T RateTransition1_Buffer;       /* '<S1>/Rate Transition1' */
  real_T RateTransition5_Buffer[3];    /* '<S1>/Rate Transition5' */
  real_T RateTransition2_Buffer;       /* '<S1>/Rate Transition2' */
  real_T RateTransition6_Buffer_p;     /* '<S2>/Rate Transition6' */
  real_T RateTransition3_Buffer_g;     /* '<S2>/Rate Transition3' */
  real_T RateTransition1_Buffer_m;     /* '<S2>/Rate Transition1' */
  real_T RateTransition4_Buffer0_h[3]; /* '<S156>/Rate Transition4' */
  real_T RateTransition7_Buffer0_j;    /* '<S156>/Rate Transition7' */
  real_T STATE_3_Discrete;             /* '<S324>/STATE_3' */
  real_T OUTPUT_3_0_Discrete;          /* '<S324>/OUTPUT_3_0' */
  real_T RateTransition5_Buffer_g[3];  /* '<S2>/Rate Transition5' */
  real_T RateTransition2_Buffer_a;     /* '<S2>/Rate Transition2' */
  real_T RateTransition3_Buffer_e;     /* '<S23>/Rate Transition3' */
  real_T RateTransition2_Buffer_a1[3]; /* '<S23>/Rate Transition2' */
  real_T RateTransition3_Buffer_m;     /* '<S24>/Rate Transition3' */
  real_T RateTransition2_Buffer_m[3];  /* '<S24>/Rate Transition2' */
  void* STATE_1_Simulator;             /* '<S324>/STATE_1' */
  void* STATE_1_SimData;               /* '<S324>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S324>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S324>/STATE_1' */
  void* STATE_1_TsIndex;               /* '<S324>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S324>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S324>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S324>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S324>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsIndex;            /* '<S324>/OUTPUT_1_0' */
  void* STATE_2_Simulator;             /* '<S324>/STATE_2' */
  void* STATE_2_SimData;               /* '<S324>/STATE_2' */
  void* STATE_2_DiagMgr;               /* '<S324>/STATE_2' */
  void* STATE_2_ZcLogger;              /* '<S324>/STATE_2' */
  void* STATE_2_TsIndex;               /* '<S324>/STATE_2' */
  void* OUTPUT_2_0_Simulator;          /* '<S324>/OUTPUT_2_0' */
  void* OUTPUT_2_0_SimData;            /* '<S324>/OUTPUT_2_0' */
  void* OUTPUT_2_0_DiagMgr;            /* '<S324>/OUTPUT_2_0' */
  void* OUTPUT_2_0_ZcLogger;           /* '<S324>/OUTPUT_2_0' */
  void* OUTPUT_2_0_TsIndex;            /* '<S324>/OUTPUT_2_0' */
  void* STATE_3_Simulator;             /* '<S324>/STATE_3' */
  void* STATE_3_SimData;               /* '<S324>/STATE_3' */
  void* STATE_3_DiagMgr;               /* '<S324>/STATE_3' */
  void* STATE_3_ZcLogger;              /* '<S324>/STATE_3' */
  void* STATE_3_TsIndex;               /* '<S324>/STATE_3' */
  void* OUTPUT_3_0_Simulator;          /* '<S324>/OUTPUT_3_0' */
  void* OUTPUT_3_0_SimData;            /* '<S324>/OUTPUT_3_0' */
  void* OUTPUT_3_0_DiagMgr;            /* '<S324>/OUTPUT_3_0' */
  void* OUTPUT_3_0_ZcLogger;           /* '<S324>/OUTPUT_3_0' */
  void* OUTPUT_3_0_TsIndex;            /* '<S324>/OUTPUT_3_0' */
  int_T STATE_1_Modes;                 /* '<S324>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S324>/OUTPUT_1_0' */
  int_T STATE_2_Modes[27];             /* '<S324>/STATE_2' */
  int_T OUTPUT_2_0_Modes;              /* '<S324>/OUTPUT_2_0' */
  int_T STATE_3_Modes[27];             /* '<S324>/STATE_3' */
  int_T OUTPUT_3_0_Modes;              /* '<S324>/OUTPUT_3_0' */
  int32_T STATE_2_MASS_MATRIX_PR;      /* '<S324>/STATE_2' */
  int32_T STATE_3_MASS_MATRIX_PR;      /* '<S324>/STATE_3' */
  int8_T Integrator_PrevResetState;    /* '<S45>/Integrator' */
  int8_T Integrator_PrevResetState_k;  /* '<S49>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S34>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_p;  /* '<S154>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S172>/Integrator' */
  int8_T Integrator_PrevResetState_c;  /* '<S176>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S161>/Discrete-Time Integrator' */
  int8_T Integrator_PrevResetState_a;  /* '<S281>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S154>/Integrator' */
  uint8_T Integrator_IC_LOADING_g;     /* '<S281>/Integrator' */
  boolean_T STATE_1_FirstOutput;       /* '<S324>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S324>/OUTPUT_1_0' */
  boolean_T Initial_FirstOutputTime;   /* '<S45>/Initial' */
  boolean_T Initial_FirstOutputTime_l; /* '<S49>/Initial' */
  boolean_T STATE_2_FirstOutput;       /* '<S324>/STATE_2' */
  boolean_T OUTPUT_2_0_FirstOutput;    /* '<S324>/OUTPUT_2_0' */
  boolean_T RateTransition4_Buffer[3]; /* '<S1>/Rate Transition4' */
  boolean_T Relay_Mode;                /* '<S1>/Relay' */
  boolean_T Initial_FirstOutputTime_k; /* '<S172>/Initial' */
  boolean_T Initial_FirstOutputTime_b; /* '<S176>/Initial' */
  boolean_T STATE_3_FirstOutput;       /* '<S324>/STATE_3' */
  boolean_T OUTPUT_3_0_FirstOutput;    /* '<S324>/OUTPUT_3_0' */
  boolean_T RateTransition4_Buffer_m[3];/* '<S2>/Rate Transition4' */
  boolean_T Relay_Mode_h;              /* '<S2>/Relay' */
} DW_Robot_T;

/* Continuous states (default storage) */
typedef struct {
  real_T RobotRevolute3Rzq[10];        /* '<S324>/STATE_1' */
  real_T RobotBLDCpm_dq0_Xabcangular_pos[24];/* '<S324>/STATE_2' */
  real_T RobotBLDC1pm_dq0_Xabcangular_po[24];/* '<S324>/STATE_3' */
} X_Robot_T;

/* State derivatives (default storage) */
typedef struct {
  real_T RobotRevolute3Rzq[10];        /* '<S324>/STATE_1' */
  real_T RobotBLDCpm_dq0_Xabcangular_pos[24];/* '<S324>/STATE_2' */
  real_T RobotBLDC1pm_dq0_Xabcangular_po[24];/* '<S324>/STATE_3' */
} XDot_Robot_T;

/* State disabled  */
typedef struct {
  boolean_T RobotRevolute3Rzq[10];     /* '<S324>/STATE_1' */
  boolean_T RobotBLDCpm_dq0_Xabcangular_pos[24];/* '<S324>/STATE_2' */
  boolean_T RobotBLDC1pm_dq0_Xabcangular_po[24];/* '<S324>/STATE_3' */
} XDis_Robot_T;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[26];
  int_T jc[59];
  real_T pr[26];
} MassMatrix_Robot_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Parameters (default storage) */
struct P_Robot_T_ {
  real_T Kii;                          /* Variable: Kii
                                        * Referenced by:
                                        *   '<S34>/Gain1'
                                        *   '<S161>/Gain1'
                                        */
  real_T Kip;                          /* Variable: Kip
                                        * Referenced by:
                                        *   '<S81>/Integral Gain'
                                        *   '<S208>/Integral Gain'
                                        */
  real_T Kiw;                          /* Variable: Kiw
                                        * Referenced by:
                                        *   '<S129>/Integral Gain'
                                        *   '<S256>/Integral Gain'
                                        */
  real_T Kpi;                          /* Variable: Kpi
                                        * Referenced by:
                                        *   '<S34>/Gain'
                                        *   '<S161>/Gain'
                                        */
  real_T Kpp;                          /* Variable: Kpp
                                        * Referenced by:
                                        *   '<S89>/Proportional Gain'
                                        *   '<S216>/Proportional Gain'
                                        */
  real_T Kpw;                          /* Variable: Kpw
                                        * Referenced by:
                                        *   '<S137>/Proportional Gain'
                                        *   '<S264>/Proportional Gain'
                                        */
  real_T Tsc;                          /* Variable: Tsc
                                        * Referenced by:
                                        *   '<S38>/Constant10'
                                        *   '<S38>/Constant6'
                                        *   '<S38>/Gain1'
                                        *   '<S165>/Constant10'
                                        *   '<S165>/Constant6'
                                        *   '<S165>/Gain1'
                                        *   '<S42>/Switch'
                                        *   '<S43>/Switch'
                                        *   '<S44>/Constant'
                                        *   '<S169>/Switch'
                                        *   '<S170>/Switch'
                                        *   '<S171>/Constant'
                                        *   '<S47>/Constant'
                                        *   '<S48>/Gain'
                                        *   '<S48>/Gain1'
                                        *   '<S51>/Constant'
                                        *   '<S52>/Gain'
                                        *   '<S52>/Gain1'
                                        *   '<S174>/Constant'
                                        *   '<S175>/Gain'
                                        *   '<S175>/Gain1'
                                        *   '<S178>/Constant'
                                        *   '<S179>/Gain'
                                        *   '<S179>/Gain1'
                                        */
  real_T Vdc;                          /* Variable: Vdc
                                        * Referenced by:
                                        *   '<S1>/Relay'
                                        *   '<S2>/Relay'
                                        */
  real_T p;                            /* Variable: p
                                        * Referenced by:
                                        *   '<S306>/mech->elec'
                                        *   '<S307>/mech->elec'
                                        */
  real_T Carriercounter_CarrCount;   /* Mask Parameter: Carriercounter_CarrCount
                                      * Referenced by: '<S38>/Constant2'
                                      */
  real_T Carriercounter_CarrCount_e;
                                   /* Mask Parameter: Carriercounter_CarrCount_e
                                    * Referenced by: '<S165>/Constant2'
                                    */
  real_T Positioncontroller_D;         /* Mask Parameter: Positioncontroller_D
                                        * Referenced by: '<S78>/Derivative Gain'
                                        */
  real_T Positioncontroller_InitialCondi;
                              /* Mask Parameter: Positioncontroller_InitialCondi
                               * Referenced by: '<S79>/Filter'
                               */
  real_T Positioncontroller_InitialCon_k;
                              /* Mask Parameter: Positioncontroller_InitialCon_k
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T Speedcontroller_InitialConditio;
                              /* Mask Parameter: Speedcontroller_InitialConditio
                               * Referenced by: '<S132>/Integrator'
                               */
  real_T Positioncontroller_InitialCo_kb;
                              /* Mask Parameter: Positioncontroller_InitialCo_kb
                               * Referenced by: '<S211>/Integrator'
                               */
  real_T Speedcontroller_InitialCondit_e;
                              /* Mask Parameter: Speedcontroller_InitialCondit_e
                               * Referenced by: '<S259>/Integrator'
                               */
  real_T Vdcfilter_K;                  /* Mask Parameter: Vdcfilter_K
                                        * Referenced by: '<S32>/K'
                                        */
  real_T Vdcfilter_K_a;                /* Mask Parameter: Vdcfilter_K_a
                                        * Referenced by: '<S159>/K'
                                        */
  real_T BLDCCurrentController_Kaw; /* Mask Parameter: BLDCCurrentController_Kaw
                                     * Referenced by: '<S34>/Gain2'
                                     */
  real_T BLDCCurrentController_Kaw_g;
                                  /* Mask Parameter: BLDCCurrentController_Kaw_g
                                   * Referenced by: '<S161>/Gain2'
                                   */
  real_T Speedcontroller_Kb;           /* Mask Parameter: Speedcontroller_Kb
                                        * Referenced by: '<S125>/Kb'
                                        */
  real_T Speedcontroller_Kb_n;         /* Mask Parameter: Speedcontroller_Kb_n
                                        * Referenced by: '<S252>/Kb'
                                        */
  real_T Speedcontroller_LowerSaturation;
                              /* Mask Parameter: Speedcontroller_LowerSaturation
                               * Referenced by: '<S139>/Saturation'
                               */
  real_T Speedcontroller_LowerSaturati_f;
                              /* Mask Parameter: Speedcontroller_LowerSaturati_f
                               * Referenced by: '<S266>/Saturation'
                               */
  real_T Positioncontroller_N;         /* Mask Parameter: Positioncontroller_N
                                        * Referenced by: '<S87>/Filter Coefficient'
                                        */
  real_T Carriercounter_Range;         /* Mask Parameter: Carriercounter_Range
                                        * Referenced by:
                                        *   '<S38>/Bias'
                                        *   '<S38>/Gain'
                                        */
  real_T Carriercounter_Range_g;       /* Mask Parameter: Carriercounter_Range_g
                                        * Referenced by:
                                        *   '<S165>/Bias'
                                        *   '<S165>/Gain'
                                        */
  real_T Vdcfilter_T;                  /* Mask Parameter: Vdcfilter_T
                                        * Referenced by: '<S149>/Time constant'
                                        */
  real_T Vdcfilter_T_i;                /* Mask Parameter: Vdcfilter_T_i
                                        * Referenced by: '<S276>/Time constant'
                                        */
  real_T Speedcontroller_UpperSaturation;
                              /* Mask Parameter: Speedcontroller_UpperSaturation
                               * Referenced by: '<S139>/Saturation'
                               */
  real_T Speedcontroller_UpperSaturati_o;
                              /* Mask Parameter: Speedcontroller_UpperSaturati_o
                               * Referenced by: '<S266>/Saturation'
                               */
  real_T IntegratorwithWrappedStateDiscr;
                              /* Mask Parameter: IntegratorwithWrappedStateDiscr
                               * Referenced by:
                               *   '<S46>/Constant'
                               *   '<S48>/Constant'
                               *   '<S48>/Gain'
                               *   '<S48>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_h;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_h
                               * Referenced by:
                               *   '<S50>/Constant'
                               *   '<S52>/Constant'
                               *   '<S52>/Gain'
                               *   '<S52>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_g;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_g
                               * Referenced by:
                               *   '<S173>/Constant'
                               *   '<S175>/Constant'
                               *   '<S175>/Gain'
                               *   '<S175>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_a;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_a
                               * Referenced by:
                               *   '<S177>/Constant'
                               *   '<S179>/Constant'
                               *   '<S179>/Gain'
                               *   '<S179>/Gain1'
                               */
  real_T PIcontroller_x0;              /* Mask Parameter: PIcontroller_x0
                                        * Referenced by: '<S34>/Discrete-Time Integrator'
                                        */
  real_T PIcontroller_x0_i;            /* Mask Parameter: PIcontroller_x0_i
                                        * Referenced by: '<S161>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S152>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S166>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S279>/Constant'
                                        */
  real_T RateTransition4_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S29>/Rate Transition4'
                                          */
  real_T Initial_Value;                /* Expression: x0
                                        * Referenced by: '<S45>/Initial'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S45>/Integrator'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S42>/Constant2'
                                        */
  real_T Initial_Value_i;              /* Expression: x0
                                        * Referenced by: '<S49>/Initial'
                                        */
  real_T Integrator_gainval_b;       /* Computed Parameter: Integrator_gainval_b
                                      * Referenced by: '<S49>/Integrator'
                                      */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S43>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T RateTransition7_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S29>/Rate Transition7'
                                          */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S84>/Integrator'
                                      */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S79>/Filter'
                                        */
  real_T radsrpm_Gain;                 /* Expression: 30/pi
                                        * Referenced by: '<S1>/rad//s->rpm'
                                        */
  real_T Integrator_gainval_m;       /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S132>/Integrator'
                                      */
  real_T raddeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S306>/rad->deg'
                                        */
  real_T Constant_Value_f;             /* Expression: -60
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 120
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 60
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: -120
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -180
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T DirectLookupTablenD2_table[24];
          /* Expression: [0 0 -1 -1 1 1 0 0;0 -1 1 0 0 -1 1 0;0 1 0 1 -1 0 -1 0]
           * Referenced by: '<S33>/Direct Lookup Table (n-D)2'
           */
  real_T Zerocancellation_NumCoef;     /* Expression: numZC
                                        * Referenced by: '<S28>/Zero-cancellation'
                                        */
  real_T Zerocancellation_DenCoef;     /* Expression: denZC
                                        * Referenced by: '<S28>/Zero-cancellation'
                                        */
  real_T Zerocancellation_InitialStates;/* Expression: 0
                                         * Referenced by: '<S28>/Zero-cancellation'
                                         */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S34>/Unit Delay'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S34>/Discrete-Time Integrator'
                            */
  real_T Saturation_UpperSat_h;        /* Expression: 1
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Constant2_Value_nz;           /* Expression: 0.5
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Constant3_Value_p;            /* Expression: 1
                                        * Referenced by: '<S38>/Constant3'
                                        */
  real_T Integrator_gainval_e;       /* Computed Parameter: Integrator_gainval_e
                                      * Referenced by: '<S154>/Integrator'
                                      */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S154>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S154>/Integrator'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S154>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S154>/Saturation'
                                        */
  real_T Relay_YOn;                    /* Expression: 1
                                        * Referenced by: '<S1>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 0
                                        * Referenced by: '<S1>/Relay'
                                        */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S211>/Integrator'
                                      */
  real_T radsrpm_Gain_n;               /* Expression: 30/pi
                                        * Referenced by: '<S2>/rad//s->rpm'
                                        */
  real_T Integrator_gainval_e3;     /* Computed Parameter: Integrator_gainval_e3
                                     * Referenced by: '<S259>/Integrator'
                                     */
  real_T RateTransition4_InitialCondit_m;/* Expression: 0
                                          * Referenced by: '<S156>/Rate Transition4'
                                          */
  real_T Initial_Value_ic;             /* Expression: x0
                                        * Referenced by: '<S172>/Initial'
                                        */
  real_T Integrator_gainval_f;       /* Computed Parameter: Integrator_gainval_f
                                      * Referenced by: '<S172>/Integrator'
                                      */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S169>/Constant2'
                                        */
  real_T Initial_Value_b;              /* Expression: x0
                                        * Referenced by: '<S176>/Initial'
                                        */
  real_T Integrator_gainval_f3;     /* Computed Parameter: Integrator_gainval_f3
                                     * Referenced by: '<S176>/Integrator'
                                     */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<S170>/Constant2'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1
                                        * Referenced by: '<S165>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S165>/Saturation'
                                        */
  real_T RateTransition7_InitialCondit_d;/* Expression: 0
                                          * Referenced by: '<S156>/Rate Transition7'
                                          */
  real_T raddeg_Gain_f;                /* Expression: 180/pi
                                        * Referenced by: '<S307>/rad->deg'
                                        */
  real_T Constant_Value_bq;            /* Expression: -60
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 120
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 60
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Constant3_Value_k;            /* Expression: -120
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Constant4_Value_h;            /* Expression: -180
                                        * Referenced by: '<S11>/Constant4'
                                        */
  real_T Constant5_Value_e;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant5'
                                        */
  real_T DirectLookupTablenD2_table_b[24];
          /* Expression: [0 0 -1 -1 1 1 0 0;0 -1 1 0 0 -1 1 0;0 1 0 1 -1 0 -1 0]
           * Referenced by: '<S160>/Direct Lookup Table (n-D)2'
           */
  real_T Zerocancellation_NumCoef_k;   /* Expression: numZC
                                        * Referenced by: '<S155>/Zero-cancellation'
                                        */
  real_T Zerocancellation_DenCoef_p;   /* Expression: denZC
                                        * Referenced by: '<S155>/Zero-cancellation'
                                        */
  real_T Zerocancellation_InitialState_k;/* Expression: 0
                                          * Referenced by: '<S155>/Zero-cancellation'
                                          */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S161>/Unit Delay'
                                        */
  real_T Constant_Value_ff;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                           * Referenced by: '<S161>/Discrete-Time Integrator'
                           */
  real_T Saturation_UpperSat_n;        /* Expression: 1
                                        * Referenced by: '<S155>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 0
                                        * Referenced by: '<S155>/Saturation'
                                        */
  real_T Constant2_Value_lv;           /* Expression: 0.5
                                        * Referenced by: '<S156>/Constant2'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 0.5
                                        * Referenced by: '<S156>/Gain'
                                        */
  real_T Constant3_Value_c;            /* Expression: 1
                                        * Referenced by: '<S165>/Constant3'
                                        */
  real_T Integrator_gainval_hl;     /* Computed Parameter: Integrator_gainval_hl
                                     * Referenced by: '<S281>/Integrator'
                                     */
  real_T Integrator_UpperSat_d;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S281>/Integrator'
                                        */
  real_T Integrator_LowerSat_k;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S281>/Integrator'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S281>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S281>/Saturation'
                                        */
  real_T Relay_YOn_n;                  /* Expression: 1
                                        * Referenced by: '<S2>/Relay'
                                        */
  real_T Relay_YOff_j;                 /* Expression: 0
                                        * Referenced by: '<S2>/Relay'
                                        */
  uint8_T Gain_Gain_b[3];              /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S35>/Gain'
                                        */
  uint8_T Gain_Gain_g[3];              /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S162>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Robot_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Robot_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[58];
  real_T odeF0[58];
  real_T odeX1START[58];
  real_T odeF1[58];
  real_T odeDELTA[58];
  real_T odeE[4*58];
  real_T odeFAC[58];
  real_T odeDFDX[58*58];
  real_T odeW[58*58];
  int_T odePIVOTS[58];
  real_T odeXTMP[58];
  real_T odeZTMP[58];
  real_T odeMASSMATRIX_M[26];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Robot_T Robot_P;

/* Block signals (default storage) */
extern B_Robot_T Robot_B;

/* Continuous states (default storage) */
extern X_Robot_T Robot_X;

/* global MassMatrix */
extern MassMatrix_Robot_T Robot_MassMatrix;

/* Block states (default storage) */
extern DW_Robot_T Robot_DW;

/* Model entry point functions */
extern void Robot_initialize(void);
extern void Robot_step(void);
extern void Robot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Robot_T *const Robot_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Robot'
 * '<S1>'   : 'Robot/Control'
 * '<S2>'   : 'Robot/Control1'
 * '<S3>'   : 'Robot/Eslabon_1y2_1_RIGID'
 * '<S4>'   : 'Robot/Eslabon_1y2_2_RIGID'
 * '<S5>'   : 'Robot/Eslabon_3_1_RIGID'
 * '<S6>'   : 'Robot/Eslabon_4_1_RIGID'
 * '<S7>'   : 'Robot/Eslabon_5_1_RIGID'
 * '<S8>'   : 'Robot/Gate driver'
 * '<S9>'   : 'Robot/Gate driver1'
 * '<S10>'  : 'Robot/Hall sensor'
 * '<S11>'  : 'Robot/Hall sensor1'
 * '<S12>'  : 'Robot/MATLAB Function'
 * '<S13>'  : 'Robot/Meas V'
 * '<S14>'  : 'Robot/Meas V1'
 * '<S15>'  : 'Robot/PS-Simulink Converter1'
 * '<S16>'  : 'Robot/PS-Simulink Converter2'
 * '<S17>'  : 'Robot/PS-Simulink Converter3'
 * '<S18>'  : 'Robot/PS-Simulink Converter4'
 * '<S19>'  : 'Robot/PS-Simulink Converter5'
 * '<S20>'  : 'Robot/PS-Simulink Converter6'
 * '<S21>'  : 'Robot/PS-Simulink Converter7'
 * '<S22>'  : 'Robot/PS-Simulink Converter8'
 * '<S23>'  : 'Robot/Scopes'
 * '<S24>'  : 'Robot/Scopes1'
 * '<S25>'  : 'Robot/Sensing  iabc'
 * '<S26>'  : 'Robot/Sensing  iabc1'
 * '<S27>'  : 'Robot/Solver Configuration'
 * '<S28>'  : 'Robot/Control/BLDC Current Controller'
 * '<S29>'  : 'Robot/Control/PWM'
 * '<S30>'  : 'Robot/Control/Position controller'
 * '<S31>'  : 'Robot/Control/Speed controller'
 * '<S32>'  : 'Robot/Control/Vdc filter'
 * '<S33>'  : 'Robot/Control/BLDC Current Controller/BLDC Commutation Logic'
 * '<S34>'  : 'Robot/Control/BLDC Current Controller/PI controller'
 * '<S35>'  : 'Robot/Control/BLDC Current Controller/BLDC Commutation Logic/Bit concatenate'
 * '<S36>'  : 'Robot/Control/PWM/NOT'
 * '<S37>'  : 'Robot/Control/PWM/PWM Generator'
 * '<S38>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter'
 * '<S39>'  : 'Robot/Control/PWM/PWM Generator/Compare To Zero'
 * '<S40>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S41>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S42>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Limitation'
 * '<S43>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Limitation1'
 * '<S44>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/scale'
 * '<S45>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S46>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S47>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S48>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S49>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S50>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S51>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant1'
 * '<S52>'  : 'Robot/Control/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Reinitialization'
 * '<S53>'  : 'Robot/Control/Position controller/Anti-windup'
 * '<S54>'  : 'Robot/Control/Position controller/D Gain'
 * '<S55>'  : 'Robot/Control/Position controller/Filter'
 * '<S56>'  : 'Robot/Control/Position controller/Filter ICs'
 * '<S57>'  : 'Robot/Control/Position controller/I Gain'
 * '<S58>'  : 'Robot/Control/Position controller/Ideal P Gain'
 * '<S59>'  : 'Robot/Control/Position controller/Ideal P Gain Fdbk'
 * '<S60>'  : 'Robot/Control/Position controller/Integrator'
 * '<S61>'  : 'Robot/Control/Position controller/Integrator ICs'
 * '<S62>'  : 'Robot/Control/Position controller/N Copy'
 * '<S63>'  : 'Robot/Control/Position controller/N Gain'
 * '<S64>'  : 'Robot/Control/Position controller/P Copy'
 * '<S65>'  : 'Robot/Control/Position controller/Parallel P Gain'
 * '<S66>'  : 'Robot/Control/Position controller/Reset Signal'
 * '<S67>'  : 'Robot/Control/Position controller/Saturation'
 * '<S68>'  : 'Robot/Control/Position controller/Saturation Fdbk'
 * '<S69>'  : 'Robot/Control/Position controller/Sum'
 * '<S70>'  : 'Robot/Control/Position controller/Sum Fdbk'
 * '<S71>'  : 'Robot/Control/Position controller/Tracking Mode'
 * '<S72>'  : 'Robot/Control/Position controller/Tracking Mode Sum'
 * '<S73>'  : 'Robot/Control/Position controller/Tsamp - Integral'
 * '<S74>'  : 'Robot/Control/Position controller/Tsamp - Ngain'
 * '<S75>'  : 'Robot/Control/Position controller/postSat Signal'
 * '<S76>'  : 'Robot/Control/Position controller/preSat Signal'
 * '<S77>'  : 'Robot/Control/Position controller/Anti-windup/Passthrough'
 * '<S78>'  : 'Robot/Control/Position controller/D Gain/Internal Parameters'
 * '<S79>'  : 'Robot/Control/Position controller/Filter/Disc. Forward Euler Filter'
 * '<S80>'  : 'Robot/Control/Position controller/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'Robot/Control/Position controller/I Gain/Internal Parameters'
 * '<S82>'  : 'Robot/Control/Position controller/Ideal P Gain/Passthrough'
 * '<S83>'  : 'Robot/Control/Position controller/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'Robot/Control/Position controller/Integrator/Discrete'
 * '<S85>'  : 'Robot/Control/Position controller/Integrator ICs/Internal IC'
 * '<S86>'  : 'Robot/Control/Position controller/N Copy/Disabled'
 * '<S87>'  : 'Robot/Control/Position controller/N Gain/Internal Parameters'
 * '<S88>'  : 'Robot/Control/Position controller/P Copy/Disabled'
 * '<S89>'  : 'Robot/Control/Position controller/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'Robot/Control/Position controller/Reset Signal/Disabled'
 * '<S91>'  : 'Robot/Control/Position controller/Saturation/Passthrough'
 * '<S92>'  : 'Robot/Control/Position controller/Saturation Fdbk/Disabled'
 * '<S93>'  : 'Robot/Control/Position controller/Sum/Sum_PID'
 * '<S94>'  : 'Robot/Control/Position controller/Sum Fdbk/Disabled'
 * '<S95>'  : 'Robot/Control/Position controller/Tracking Mode/Disabled'
 * '<S96>'  : 'Robot/Control/Position controller/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'Robot/Control/Position controller/Tsamp - Integral/Passthrough'
 * '<S98>'  : 'Robot/Control/Position controller/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'Robot/Control/Position controller/postSat Signal/Forward_Path'
 * '<S100>' : 'Robot/Control/Position controller/preSat Signal/Forward_Path'
 * '<S101>' : 'Robot/Control/Speed controller/Anti-windup'
 * '<S102>' : 'Robot/Control/Speed controller/D Gain'
 * '<S103>' : 'Robot/Control/Speed controller/Filter'
 * '<S104>' : 'Robot/Control/Speed controller/Filter ICs'
 * '<S105>' : 'Robot/Control/Speed controller/I Gain'
 * '<S106>' : 'Robot/Control/Speed controller/Ideal P Gain'
 * '<S107>' : 'Robot/Control/Speed controller/Ideal P Gain Fdbk'
 * '<S108>' : 'Robot/Control/Speed controller/Integrator'
 * '<S109>' : 'Robot/Control/Speed controller/Integrator ICs'
 * '<S110>' : 'Robot/Control/Speed controller/N Copy'
 * '<S111>' : 'Robot/Control/Speed controller/N Gain'
 * '<S112>' : 'Robot/Control/Speed controller/P Copy'
 * '<S113>' : 'Robot/Control/Speed controller/Parallel P Gain'
 * '<S114>' : 'Robot/Control/Speed controller/Reset Signal'
 * '<S115>' : 'Robot/Control/Speed controller/Saturation'
 * '<S116>' : 'Robot/Control/Speed controller/Saturation Fdbk'
 * '<S117>' : 'Robot/Control/Speed controller/Sum'
 * '<S118>' : 'Robot/Control/Speed controller/Sum Fdbk'
 * '<S119>' : 'Robot/Control/Speed controller/Tracking Mode'
 * '<S120>' : 'Robot/Control/Speed controller/Tracking Mode Sum'
 * '<S121>' : 'Robot/Control/Speed controller/Tsamp - Integral'
 * '<S122>' : 'Robot/Control/Speed controller/Tsamp - Ngain'
 * '<S123>' : 'Robot/Control/Speed controller/postSat Signal'
 * '<S124>' : 'Robot/Control/Speed controller/preSat Signal'
 * '<S125>' : 'Robot/Control/Speed controller/Anti-windup/Back Calculation'
 * '<S126>' : 'Robot/Control/Speed controller/D Gain/Disabled'
 * '<S127>' : 'Robot/Control/Speed controller/Filter/Disabled'
 * '<S128>' : 'Robot/Control/Speed controller/Filter ICs/Disabled'
 * '<S129>' : 'Robot/Control/Speed controller/I Gain/Internal Parameters'
 * '<S130>' : 'Robot/Control/Speed controller/Ideal P Gain/Passthrough'
 * '<S131>' : 'Robot/Control/Speed controller/Ideal P Gain Fdbk/Disabled'
 * '<S132>' : 'Robot/Control/Speed controller/Integrator/Discrete'
 * '<S133>' : 'Robot/Control/Speed controller/Integrator ICs/Internal IC'
 * '<S134>' : 'Robot/Control/Speed controller/N Copy/Disabled wSignal Specification'
 * '<S135>' : 'Robot/Control/Speed controller/N Gain/Disabled'
 * '<S136>' : 'Robot/Control/Speed controller/P Copy/Disabled'
 * '<S137>' : 'Robot/Control/Speed controller/Parallel P Gain/Internal Parameters'
 * '<S138>' : 'Robot/Control/Speed controller/Reset Signal/Disabled'
 * '<S139>' : 'Robot/Control/Speed controller/Saturation/Enabled'
 * '<S140>' : 'Robot/Control/Speed controller/Saturation Fdbk/Disabled'
 * '<S141>' : 'Robot/Control/Speed controller/Sum/Sum_PI'
 * '<S142>' : 'Robot/Control/Speed controller/Sum Fdbk/Disabled'
 * '<S143>' : 'Robot/Control/Speed controller/Tracking Mode/Disabled'
 * '<S144>' : 'Robot/Control/Speed controller/Tracking Mode Sum/Passthrough'
 * '<S145>' : 'Robot/Control/Speed controller/Tsamp - Integral/Passthrough'
 * '<S146>' : 'Robot/Control/Speed controller/Tsamp - Ngain/Passthrough'
 * '<S147>' : 'Robot/Control/Speed controller/postSat Signal/Forward_Path'
 * '<S148>' : 'Robot/Control/Speed controller/preSat Signal/Forward_Path'
 * '<S149>' : 'Robot/Control/Vdc filter/Enable//disable time constant'
 * '<S150>' : 'Robot/Control/Vdc filter/Initialization'
 * '<S151>' : 'Robot/Control/Vdc filter/Integrator (Discrete or Continuous)'
 * '<S152>' : 'Robot/Control/Vdc filter/Enable//disable time constant/Compare To Zero'
 * '<S153>' : 'Robot/Control/Vdc filter/Initialization/Init_u'
 * '<S154>' : 'Robot/Control/Vdc filter/Integrator (Discrete or Continuous)/Discrete'
 * '<S155>' : 'Robot/Control1/BLDC Current Controller'
 * '<S156>' : 'Robot/Control1/PWM'
 * '<S157>' : 'Robot/Control1/Position controller'
 * '<S158>' : 'Robot/Control1/Speed controller'
 * '<S159>' : 'Robot/Control1/Vdc filter'
 * '<S160>' : 'Robot/Control1/BLDC Current Controller/BLDC Commutation Logic'
 * '<S161>' : 'Robot/Control1/BLDC Current Controller/PI controller'
 * '<S162>' : 'Robot/Control1/BLDC Current Controller/BLDC Commutation Logic/Bit concatenate'
 * '<S163>' : 'Robot/Control1/PWM/NOT'
 * '<S164>' : 'Robot/Control1/PWM/PWM Generator'
 * '<S165>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter'
 * '<S166>' : 'Robot/Control1/PWM/PWM Generator/Compare To Zero'
 * '<S167>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S168>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S169>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Limitation'
 * '<S170>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Limitation1'
 * '<S171>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/scale'
 * '<S172>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S173>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S174>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S175>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S176>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S177>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S178>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant1'
 * '<S179>' : 'Robot/Control1/PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Reinitialization'
 * '<S180>' : 'Robot/Control1/Position controller/Anti-windup'
 * '<S181>' : 'Robot/Control1/Position controller/D Gain'
 * '<S182>' : 'Robot/Control1/Position controller/Filter'
 * '<S183>' : 'Robot/Control1/Position controller/Filter ICs'
 * '<S184>' : 'Robot/Control1/Position controller/I Gain'
 * '<S185>' : 'Robot/Control1/Position controller/Ideal P Gain'
 * '<S186>' : 'Robot/Control1/Position controller/Ideal P Gain Fdbk'
 * '<S187>' : 'Robot/Control1/Position controller/Integrator'
 * '<S188>' : 'Robot/Control1/Position controller/Integrator ICs'
 * '<S189>' : 'Robot/Control1/Position controller/N Copy'
 * '<S190>' : 'Robot/Control1/Position controller/N Gain'
 * '<S191>' : 'Robot/Control1/Position controller/P Copy'
 * '<S192>' : 'Robot/Control1/Position controller/Parallel P Gain'
 * '<S193>' : 'Robot/Control1/Position controller/Reset Signal'
 * '<S194>' : 'Robot/Control1/Position controller/Saturation'
 * '<S195>' : 'Robot/Control1/Position controller/Saturation Fdbk'
 * '<S196>' : 'Robot/Control1/Position controller/Sum'
 * '<S197>' : 'Robot/Control1/Position controller/Sum Fdbk'
 * '<S198>' : 'Robot/Control1/Position controller/Tracking Mode'
 * '<S199>' : 'Robot/Control1/Position controller/Tracking Mode Sum'
 * '<S200>' : 'Robot/Control1/Position controller/Tsamp - Integral'
 * '<S201>' : 'Robot/Control1/Position controller/Tsamp - Ngain'
 * '<S202>' : 'Robot/Control1/Position controller/postSat Signal'
 * '<S203>' : 'Robot/Control1/Position controller/preSat Signal'
 * '<S204>' : 'Robot/Control1/Position controller/Anti-windup/Passthrough'
 * '<S205>' : 'Robot/Control1/Position controller/D Gain/Disabled'
 * '<S206>' : 'Robot/Control1/Position controller/Filter/Disabled'
 * '<S207>' : 'Robot/Control1/Position controller/Filter ICs/Disabled'
 * '<S208>' : 'Robot/Control1/Position controller/I Gain/Internal Parameters'
 * '<S209>' : 'Robot/Control1/Position controller/Ideal P Gain/Passthrough'
 * '<S210>' : 'Robot/Control1/Position controller/Ideal P Gain Fdbk/Disabled'
 * '<S211>' : 'Robot/Control1/Position controller/Integrator/Discrete'
 * '<S212>' : 'Robot/Control1/Position controller/Integrator ICs/Internal IC'
 * '<S213>' : 'Robot/Control1/Position controller/N Copy/Disabled wSignal Specification'
 * '<S214>' : 'Robot/Control1/Position controller/N Gain/Disabled'
 * '<S215>' : 'Robot/Control1/Position controller/P Copy/Disabled'
 * '<S216>' : 'Robot/Control1/Position controller/Parallel P Gain/Internal Parameters'
 * '<S217>' : 'Robot/Control1/Position controller/Reset Signal/Disabled'
 * '<S218>' : 'Robot/Control1/Position controller/Saturation/Passthrough'
 * '<S219>' : 'Robot/Control1/Position controller/Saturation Fdbk/Disabled'
 * '<S220>' : 'Robot/Control1/Position controller/Sum/Sum_PI'
 * '<S221>' : 'Robot/Control1/Position controller/Sum Fdbk/Disabled'
 * '<S222>' : 'Robot/Control1/Position controller/Tracking Mode/Disabled'
 * '<S223>' : 'Robot/Control1/Position controller/Tracking Mode Sum/Passthrough'
 * '<S224>' : 'Robot/Control1/Position controller/Tsamp - Integral/Passthrough'
 * '<S225>' : 'Robot/Control1/Position controller/Tsamp - Ngain/Passthrough'
 * '<S226>' : 'Robot/Control1/Position controller/postSat Signal/Forward_Path'
 * '<S227>' : 'Robot/Control1/Position controller/preSat Signal/Forward_Path'
 * '<S228>' : 'Robot/Control1/Speed controller/Anti-windup'
 * '<S229>' : 'Robot/Control1/Speed controller/D Gain'
 * '<S230>' : 'Robot/Control1/Speed controller/Filter'
 * '<S231>' : 'Robot/Control1/Speed controller/Filter ICs'
 * '<S232>' : 'Robot/Control1/Speed controller/I Gain'
 * '<S233>' : 'Robot/Control1/Speed controller/Ideal P Gain'
 * '<S234>' : 'Robot/Control1/Speed controller/Ideal P Gain Fdbk'
 * '<S235>' : 'Robot/Control1/Speed controller/Integrator'
 * '<S236>' : 'Robot/Control1/Speed controller/Integrator ICs'
 * '<S237>' : 'Robot/Control1/Speed controller/N Copy'
 * '<S238>' : 'Robot/Control1/Speed controller/N Gain'
 * '<S239>' : 'Robot/Control1/Speed controller/P Copy'
 * '<S240>' : 'Robot/Control1/Speed controller/Parallel P Gain'
 * '<S241>' : 'Robot/Control1/Speed controller/Reset Signal'
 * '<S242>' : 'Robot/Control1/Speed controller/Saturation'
 * '<S243>' : 'Robot/Control1/Speed controller/Saturation Fdbk'
 * '<S244>' : 'Robot/Control1/Speed controller/Sum'
 * '<S245>' : 'Robot/Control1/Speed controller/Sum Fdbk'
 * '<S246>' : 'Robot/Control1/Speed controller/Tracking Mode'
 * '<S247>' : 'Robot/Control1/Speed controller/Tracking Mode Sum'
 * '<S248>' : 'Robot/Control1/Speed controller/Tsamp - Integral'
 * '<S249>' : 'Robot/Control1/Speed controller/Tsamp - Ngain'
 * '<S250>' : 'Robot/Control1/Speed controller/postSat Signal'
 * '<S251>' : 'Robot/Control1/Speed controller/preSat Signal'
 * '<S252>' : 'Robot/Control1/Speed controller/Anti-windup/Back Calculation'
 * '<S253>' : 'Robot/Control1/Speed controller/D Gain/Disabled'
 * '<S254>' : 'Robot/Control1/Speed controller/Filter/Disabled'
 * '<S255>' : 'Robot/Control1/Speed controller/Filter ICs/Disabled'
 * '<S256>' : 'Robot/Control1/Speed controller/I Gain/Internal Parameters'
 * '<S257>' : 'Robot/Control1/Speed controller/Ideal P Gain/Passthrough'
 * '<S258>' : 'Robot/Control1/Speed controller/Ideal P Gain Fdbk/Disabled'
 * '<S259>' : 'Robot/Control1/Speed controller/Integrator/Discrete'
 * '<S260>' : 'Robot/Control1/Speed controller/Integrator ICs/Internal IC'
 * '<S261>' : 'Robot/Control1/Speed controller/N Copy/Disabled wSignal Specification'
 * '<S262>' : 'Robot/Control1/Speed controller/N Gain/Disabled'
 * '<S263>' : 'Robot/Control1/Speed controller/P Copy/Disabled'
 * '<S264>' : 'Robot/Control1/Speed controller/Parallel P Gain/Internal Parameters'
 * '<S265>' : 'Robot/Control1/Speed controller/Reset Signal/Disabled'
 * '<S266>' : 'Robot/Control1/Speed controller/Saturation/Enabled'
 * '<S267>' : 'Robot/Control1/Speed controller/Saturation Fdbk/Disabled'
 * '<S268>' : 'Robot/Control1/Speed controller/Sum/Sum_PI'
 * '<S269>' : 'Robot/Control1/Speed controller/Sum Fdbk/Disabled'
 * '<S270>' : 'Robot/Control1/Speed controller/Tracking Mode/Disabled'
 * '<S271>' : 'Robot/Control1/Speed controller/Tracking Mode Sum/Passthrough'
 * '<S272>' : 'Robot/Control1/Speed controller/Tsamp - Integral/Passthrough'
 * '<S273>' : 'Robot/Control1/Speed controller/Tsamp - Ngain/Passthrough'
 * '<S274>' : 'Robot/Control1/Speed controller/postSat Signal/Forward_Path'
 * '<S275>' : 'Robot/Control1/Speed controller/preSat Signal/Forward_Path'
 * '<S276>' : 'Robot/Control1/Vdc filter/Enable//disable time constant'
 * '<S277>' : 'Robot/Control1/Vdc filter/Initialization'
 * '<S278>' : 'Robot/Control1/Vdc filter/Integrator (Discrete or Continuous)'
 * '<S279>' : 'Robot/Control1/Vdc filter/Enable//disable time constant/Compare To Zero'
 * '<S280>' : 'Robot/Control1/Vdc filter/Initialization/Init_u'
 * '<S281>' : 'Robot/Control1/Vdc filter/Integrator (Discrete or Continuous)/Discrete'
 * '<S282>' : 'Robot/Gate driver/Simulink-PS Converter1'
 * '<S283>' : 'Robot/Gate driver/Simulink-PS Converter2'
 * '<S284>' : 'Robot/Gate driver/Simulink-PS Converter3'
 * '<S285>' : 'Robot/Gate driver/Simulink-PS Converter4'
 * '<S286>' : 'Robot/Gate driver/Simulink-PS Converter5'
 * '<S287>' : 'Robot/Gate driver/Simulink-PS Converter6'
 * '<S288>' : 'Robot/Gate driver/Simulink-PS Converter1/EVAL_KEY'
 * '<S289>' : 'Robot/Gate driver/Simulink-PS Converter2/EVAL_KEY'
 * '<S290>' : 'Robot/Gate driver/Simulink-PS Converter3/EVAL_KEY'
 * '<S291>' : 'Robot/Gate driver/Simulink-PS Converter4/EVAL_KEY'
 * '<S292>' : 'Robot/Gate driver/Simulink-PS Converter5/EVAL_KEY'
 * '<S293>' : 'Robot/Gate driver/Simulink-PS Converter6/EVAL_KEY'
 * '<S294>' : 'Robot/Gate driver1/Simulink-PS Converter1'
 * '<S295>' : 'Robot/Gate driver1/Simulink-PS Converter2'
 * '<S296>' : 'Robot/Gate driver1/Simulink-PS Converter3'
 * '<S297>' : 'Robot/Gate driver1/Simulink-PS Converter4'
 * '<S298>' : 'Robot/Gate driver1/Simulink-PS Converter5'
 * '<S299>' : 'Robot/Gate driver1/Simulink-PS Converter6'
 * '<S300>' : 'Robot/Gate driver1/Simulink-PS Converter1/EVAL_KEY'
 * '<S301>' : 'Robot/Gate driver1/Simulink-PS Converter2/EVAL_KEY'
 * '<S302>' : 'Robot/Gate driver1/Simulink-PS Converter3/EVAL_KEY'
 * '<S303>' : 'Robot/Gate driver1/Simulink-PS Converter4/EVAL_KEY'
 * '<S304>' : 'Robot/Gate driver1/Simulink-PS Converter5/EVAL_KEY'
 * '<S305>' : 'Robot/Gate driver1/Simulink-PS Converter6/EVAL_KEY'
 * '<S306>' : 'Robot/Hall sensor/Subsystem'
 * '<S307>' : 'Robot/Hall sensor1/Subsystem'
 * '<S308>' : 'Robot/Meas V/PS-Simulink Converter2'
 * '<S309>' : 'Robot/Meas V/PS-Simulink Converter2/EVAL_KEY'
 * '<S310>' : 'Robot/Meas V1/PS-Simulink Converter2'
 * '<S311>' : 'Robot/Meas V1/PS-Simulink Converter2/EVAL_KEY'
 * '<S312>' : 'Robot/PS-Simulink Converter1/EVAL_KEY'
 * '<S313>' : 'Robot/PS-Simulink Converter2/EVAL_KEY'
 * '<S314>' : 'Robot/PS-Simulink Converter3/EVAL_KEY'
 * '<S315>' : 'Robot/PS-Simulink Converter4/EVAL_KEY'
 * '<S316>' : 'Robot/PS-Simulink Converter5/EVAL_KEY'
 * '<S317>' : 'Robot/PS-Simulink Converter6/EVAL_KEY'
 * '<S318>' : 'Robot/PS-Simulink Converter7/EVAL_KEY'
 * '<S319>' : 'Robot/PS-Simulink Converter8/EVAL_KEY'
 * '<S320>' : 'Robot/Sensing  iabc/PS-Simulink Converter'
 * '<S321>' : 'Robot/Sensing  iabc/PS-Simulink Converter/EVAL_KEY'
 * '<S322>' : 'Robot/Sensing  iabc1/PS-Simulink Converter'
 * '<S323>' : 'Robot/Sensing  iabc1/PS-Simulink Converter/EVAL_KEY'
 * '<S324>' : 'Robot/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_Robot_h_ */
