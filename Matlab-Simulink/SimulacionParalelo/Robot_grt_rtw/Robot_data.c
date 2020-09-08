/*
 * Robot_data.c
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

#include "Robot.h"
#include "Robot_private.h"

/* Block parameters (default storage) */
P_Robot_T Robot_P = {
  /* Variable: Kii
   * Referenced by:
   *   '<S34>/Gain1'
   *   '<S161>/Gain1'
   */
  0.08,

  /* Variable: Kip
   * Referenced by:
   *   '<S81>/Integral Gain'
   *   '<S208>/Integral Gain'
   */
  3000.0,

  /* Variable: Kiw
   * Referenced by:
   *   '<S129>/Integral Gain'
   *   '<S256>/Integral Gain'
   */
  15.0,

  /* Variable: Kpi
   * Referenced by:
   *   '<S34>/Gain'
   *   '<S161>/Gain'
   */
  0.01,

  /* Variable: Kpp
   * Referenced by:
   *   '<S89>/Proportional Gain'
   *   '<S216>/Proportional Gain'
   */
  5500.0,

  /* Variable: Kpw
   * Referenced by:
   *   '<S137>/Proportional Gain'
   *   '<S264>/Proportional Gain'
   */
  0.1,

  /* Variable: Tsc
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
  0.0001,

  /* Variable: Vdc
   * Referenced by:
   *   '<S1>/Relay'
   *   '<S2>/Relay'
   */
  24.0,

  /* Variable: p
   * Referenced by:
   *   '<S306>/mech->elec'
   *   '<S307>/mech->elec'
   */
  7.0,

  /* Mask Parameter: Carriercounter_CarrCount
   * Referenced by: '<S38>/Constant2'
   */
  1.0,

  /* Mask Parameter: Carriercounter_CarrCount_e
   * Referenced by: '<S165>/Constant2'
   */
  1.0,

  /* Mask Parameter: Positioncontroller_D
   * Referenced by: '<S78>/Derivative Gain'
   */
  10.0,

  /* Mask Parameter: Positioncontroller_InitialCondi
   * Referenced by: '<S79>/Filter'
   */
  0.0,

  /* Mask Parameter: Positioncontroller_InitialCon_k
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: Speedcontroller_InitialConditio
   * Referenced by: '<S132>/Integrator'
   */
  0.0,

  /* Mask Parameter: Positioncontroller_InitialCo_kb
   * Referenced by: '<S211>/Integrator'
   */
  0.0,

  /* Mask Parameter: Speedcontroller_InitialCondit_e
   * Referenced by: '<S259>/Integrator'
   */
  0.0,

  /* Mask Parameter: Vdcfilter_K
   * Referenced by: '<S32>/K'
   */
  1.0,

  /* Mask Parameter: Vdcfilter_K_a
   * Referenced by: '<S159>/K'
   */
  1.0,

  /* Mask Parameter: BLDCCurrentController_Kaw
   * Referenced by: '<S34>/Gain2'
   */
  100.0,

  /* Mask Parameter: BLDCCurrentController_Kaw_g
   * Referenced by: '<S161>/Gain2'
   */
  100.0,

  /* Mask Parameter: Speedcontroller_Kb
   * Referenced by: '<S125>/Kb'
   */
  100.0,

  /* Mask Parameter: Speedcontroller_Kb_n
   * Referenced by: '<S252>/Kb'
   */
  100.0,

  /* Mask Parameter: Speedcontroller_LowerSaturation
   * Referenced by: '<S139>/Saturation'
   */
  -500.0,

  /* Mask Parameter: Speedcontroller_LowerSaturati_f
   * Referenced by: '<S266>/Saturation'
   */
  -500.0,

  /* Mask Parameter: Positioncontroller_N
   * Referenced by: '<S87>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: Carriercounter_Range
   * Referenced by:
   *   '<S38>/Bias'
   *   '<S38>/Gain'
   */
  1.0,

  /* Mask Parameter: Carriercounter_Range_g
   * Referenced by:
   *   '<S165>/Bias'
   *   '<S165>/Gain'
   */
  1.0,

  /* Mask Parameter: Vdcfilter_T
   * Referenced by: '<S149>/Time constant'
   */
  0.005,

  /* Mask Parameter: Vdcfilter_T_i
   * Referenced by: '<S276>/Time constant'
   */
  0.005,

  /* Mask Parameter: Speedcontroller_UpperSaturation
   * Referenced by: '<S139>/Saturation'
   */
  500.0,

  /* Mask Parameter: Speedcontroller_UpperSaturati_o
   * Referenced by: '<S266>/Saturation'
   */
  500.0,

  /* Mask Parameter: IntegratorwithWrappedStateDiscr
   * Referenced by:
   *   '<S46>/Constant'
   *   '<S48>/Constant'
   *   '<S48>/Gain'
   *   '<S48>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_h
   * Referenced by:
   *   '<S50>/Constant'
   *   '<S52>/Constant'
   *   '<S52>/Gain'
   *   '<S52>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_g
   * Referenced by:
   *   '<S173>/Constant'
   *   '<S175>/Constant'
   *   '<S175>/Gain'
   *   '<S175>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_a
   * Referenced by:
   *   '<S177>/Constant'
   *   '<S179>/Constant'
   *   '<S179>/Gain'
   *   '<S179>/Gain1'
   */
  0.0,

  /* Mask Parameter: PIcontroller_x0
   * Referenced by: '<S34>/Discrete-Time Integrator'
   */
  0.0,

  /* Mask Parameter: PIcontroller_x0_i
   * Referenced by: '<S161>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S152>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S166>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S279>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Rate Transition4'
   */
  0.0,

  /* Expression: x0
   * Referenced by: '<S45>/Initial'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S45>/Integrator'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S42>/Constant2'
   */
  0.0,

  /* Expression: x0
   * Referenced by: '<S49>/Initial'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_b
   * Referenced by: '<S49>/Integrator'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S43>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S38>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S38>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Rate Transition7'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S84>/Integrator'
   */
  0.0001,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S79>/Filter'
   */
  0.0001,

  /* Expression: 30/pi
   * Referenced by: '<S1>/rad//s->rpm'
   */
  9.5492965855137211,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S132>/Integrator'
   */
  0.0001,

  /* Expression: 180/pi
   * Referenced by: '<S306>/rad->deg'
   */
  57.295779513082323,

  /* Expression: -60
   * Referenced by: '<S10>/Constant'
   */
  -60.0,

  /* Expression: 120
   * Referenced by: '<S10>/Constant1'
   */
  120.0,

  /* Expression: 60
   * Referenced by: '<S10>/Constant2'
   */
  60.0,

  /* Expression: -120
   * Referenced by: '<S10>/Constant3'
   */
  -120.0,

  /* Expression: -180
   * Referenced by: '<S10>/Constant4'
   */
  -180.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant5'
   */
  0.0,

  /* Expression: [0 0 -1 -1 1 1 0 0;0 -1 1 0 0 -1 1 0;0 1 0 1 -1 0 -1 0]
   * Referenced by: '<S33>/Direct Lookup Table (n-D)2'
   */
  { 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, -1.0, 1.0, 0.0, -1.0, 0.0, 1.0, 1.0, 0.0,
    -1.0, 1.0, -1.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, 0.0 },

  /* Expression: numZC
   * Referenced by: '<S28>/Zero-cancellation'
   */
  1.0,

  /* Expression: denZC
   * Referenced by: '<S28>/Zero-cancellation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S28>/Zero-cancellation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S34>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S34>/Discrete-Time Integrator'
   */
  0.0001,

  /* Expression: 1
   * Referenced by: '<S28>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S28>/Saturation'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S29>/Constant2'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S29>/Gain'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S38>/Constant3'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_e
   * Referenced by: '<S154>/Integrator'
   */
  0.0001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S154>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S154>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S154>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S154>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Relay'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Relay'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S211>/Integrator'
   */
  0.0001,

  /* Expression: 30/pi
   * Referenced by: '<S2>/rad//s->rpm'
   */
  9.5492965855137211,

  /* Computed Parameter: Integrator_gainval_e3
   * Referenced by: '<S259>/Integrator'
   */
  0.0001,

  /* Expression: 0
   * Referenced by: '<S156>/Rate Transition4'
   */
  0.0,

  /* Expression: x0
   * Referenced by: '<S172>/Initial'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_f
   * Referenced by: '<S172>/Integrator'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S169>/Constant2'
   */
  0.0,

  /* Expression: x0
   * Referenced by: '<S176>/Initial'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_f3
   * Referenced by: '<S176>/Integrator'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S170>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S165>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S165>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S156>/Rate Transition7'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S307>/rad->deg'
   */
  57.295779513082323,

  /* Expression: -60
   * Referenced by: '<S11>/Constant'
   */
  -60.0,

  /* Expression: 120
   * Referenced by: '<S11>/Constant1'
   */
  120.0,

  /* Expression: 60
   * Referenced by: '<S11>/Constant2'
   */
  60.0,

  /* Expression: -120
   * Referenced by: '<S11>/Constant3'
   */
  -120.0,

  /* Expression: -180
   * Referenced by: '<S11>/Constant4'
   */
  -180.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant5'
   */
  0.0,

  /* Expression: [0 0 -1 -1 1 1 0 0;0 -1 1 0 0 -1 1 0;0 1 0 1 -1 0 -1 0]
   * Referenced by: '<S160>/Direct Lookup Table (n-D)2'
   */
  { 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, -1.0, 1.0, 0.0, -1.0, 0.0, 1.0, 1.0, 0.0,
    -1.0, 1.0, -1.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, 0.0 },

  /* Expression: numZC
   * Referenced by: '<S155>/Zero-cancellation'
   */
  1.0,

  /* Expression: denZC
   * Referenced by: '<S155>/Zero-cancellation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S155>/Zero-cancellation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S161>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
   * Referenced by: '<S161>/Discrete-Time Integrator'
   */
  0.0001,

  /* Expression: 1
   * Referenced by: '<S155>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S155>/Saturation'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S156>/Constant2'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S156>/Gain'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S165>/Constant3'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_hl
   * Referenced by: '<S281>/Integrator'
   */
  0.0001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S281>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S281>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S281>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S281>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Relay'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Relay'
   */
  0.0,

  /* Computed Parameter: Gain_Gain_b
   * Referenced by: '<S35>/Gain'
   */
  { 128U, 64U, 32U },

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S162>/Gain'
   */
  { 128U, 64U, 32U }
};
