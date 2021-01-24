/*
 * Robot.c
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

/* Block signals (default storage) */
B_Robot_T Robot_B;

/* Continuous states */
X_Robot_T Robot_X;

/* Mass Matrices */
MassMatrix_Robot_T Robot_MassMatrix;

/* Block states (default storage) */
DW_Robot_T Robot_DW;

/* Real-time model */
RT_MODEL_Robot_T Robot_M_;
RT_MODEL_Robot_T *const Robot_M = &Robot_M_;

/* Forward declaration for local functions */
static real_T Robot_mod(real_T x);
static real_T Robot_mod_j(real_T x);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Robot_M->Timing.TaskCounters.TID[2])++;
  if ((Robot_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.0001s, 0.0s] */
    Robot_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Projection for root system: '<Root>' */
void Robot_projection(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[8];
  int_T tmp_1[3];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;

  /* Projection for SimscapeExecutionBlock: '<S324>/STATE_1' */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_1_SimData;
  time = Robot_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &Robot_X.RobotRevolute3Rzq[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(Robot_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = Robot_B.INTERNAL_4_1_1[0];
  tmp_0[1] = Robot_B.INTERNAL_4_1_1[1];
  tmp_0[2] = Robot_B.INTERNAL_4_1_1[2];
  tmp_0[3] = Robot_B.INTERNAL_4_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = Robot_B.INTERNAL_3_1_1[0];
  tmp_0[5] = Robot_B.INTERNAL_3_1_1[1];
  tmp_0[6] = Robot_B.INTERNAL_3_1_1[2];
  tmp_0[7] = Robot_B.INTERNAL_3_1_1[3];
  tmp_1[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_1_Simulator,
    NESL_SIM_PROJECTION, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S324>/STATE_1' */
}

/* ForcingFunction for root system: '<Root>' */
void Robot_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  boolean_T tmp_0;
  real_T tmp_1[8];
  int_T tmp_2[3];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_3;
  char *msg;
  real_T time_0;
  real_T tmp_4[28];
  int_T tmp_5[8];
  real_T time_1;
  real_T tmp_6[28];
  int_T tmp_7[8];
  real_T time_tmp;
  XDot_Robot_T *_rtXdot;
  _rtXdot = ((XDot_Robot_T *) Robot_M->derivs);

  /* ForcingFunction for SimscapeExecutionBlock: '<S324>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S324>/STATE_2'
   *  SimscapeExecutionBlock: '<S324>/STATE_3'
   */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_1_SimData;
  time_tmp = Robot_M->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &Robot_X.RobotRevolute3Rzq[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  tmp = rtmIsMajorTimeStep(Robot_M);
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_2[0] = 0;
  tmp_1[0] = Robot_B.INTERNAL_4_1_1[0];
  tmp_1[1] = Robot_B.INTERNAL_4_1_1[1];
  tmp_1[2] = Robot_B.INTERNAL_4_1_1[2];
  tmp_1[3] = Robot_B.INTERNAL_4_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = Robot_B.INTERNAL_3_1_1[0];
  tmp_1[5] = Robot_B.INTERNAL_3_1_1[1];
  tmp_1[6] = Robot_B.INTERNAL_3_1_1[2];
  tmp_1[7] = Robot_B.INTERNAL_3_1_1[3];
  tmp_2[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  simulationData->mData->mDx.mN = 10;
  simulationData->mData->mDx.mX = &_rtXdot->RobotRevolute3Rzq[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp_0) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S324>/STATE_1' */

  /* ForcingFunction for SimscapeExecutionBlock: '<S324>/STATE_2' */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_2_SimData;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 24;
  simulationData->mData->mContStates.mX =
    &Robot_X.RobotBLDCpm_dq0_Xabcangular_pos[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_2_Discrete;
  simulationData->mData->mModeVector.mN = 27;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_2_Modes[0];
  tmp_0 = false;
  simulationData->mData->mFoundZcEvents = tmp_0;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_5[0] = 0;
  tmp_4[0] = Robot_B.INTERNAL_2_1_1[0];
  tmp_4[1] = Robot_B.INTERNAL_2_1_1[1];
  tmp_4[2] = Robot_B.INTERNAL_2_1_1[2];
  tmp_4[3] = Robot_B.INTERNAL_2_1_1[3];
  tmp_5[1] = 4;
  tmp_4[4] = Robot_B.INPUT_1_1_1[0];
  tmp_4[5] = Robot_B.INPUT_1_1_1[1];
  tmp_4[6] = Robot_B.INPUT_1_1_1[2];
  tmp_4[7] = Robot_B.INPUT_1_1_1[3];
  tmp_5[2] = 8;
  tmp_4[8] = Robot_B.INPUT_2_1_1[0];
  tmp_4[9] = Robot_B.INPUT_2_1_1[1];
  tmp_4[10] = Robot_B.INPUT_2_1_1[2];
  tmp_4[11] = Robot_B.INPUT_2_1_1[3];
  tmp_5[3] = 12;
  tmp_4[12] = Robot_B.INPUT_3_1_1[0];
  tmp_4[13] = Robot_B.INPUT_3_1_1[1];
  tmp_4[14] = Robot_B.INPUT_3_1_1[2];
  tmp_4[15] = Robot_B.INPUT_3_1_1[3];
  tmp_5[4] = 16;
  tmp_4[16] = Robot_B.INPUT_4_1_1[0];
  tmp_4[17] = Robot_B.INPUT_4_1_1[1];
  tmp_4[18] = Robot_B.INPUT_4_1_1[2];
  tmp_4[19] = Robot_B.INPUT_4_1_1[3];
  tmp_5[5] = 20;
  tmp_4[20] = Robot_B.INPUT_5_1_1[0];
  tmp_4[21] = Robot_B.INPUT_5_1_1[1];
  tmp_4[22] = Robot_B.INPUT_5_1_1[2];
  tmp_4[23] = Robot_B.INPUT_5_1_1[3];
  tmp_5[6] = 24;
  tmp_4[24] = Robot_B.INPUT_6_1_1[0];
  tmp_4[25] = Robot_B.INPUT_6_1_1[1];
  tmp_4[26] = Robot_B.INPUT_6_1_1[2];
  tmp_4[27] = Robot_B.INPUT_6_1_1[3];
  tmp_5[7] = 28;
  simulationData->mData->mInputValues.mN = 28;
  simulationData->mData->mInputValues.mX = &tmp_4[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_5[0];
  simulationData->mData->mDx.mN = 24;
  simulationData->mData->mDx.mX = &_rtXdot->RobotBLDCpm_dq0_Xabcangular_pos[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_2_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_2_Simulator,
    NESL_SIM_FORCINGFUNCTION, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp_0) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }

  /* ForcingFunction for SimscapeExecutionBlock: '<S324>/STATE_3' */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_3_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 24;
  simulationData->mData->mContStates.mX =
    &Robot_X.RobotBLDC1pm_dq0_Xabcangular_po[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_3_Discrete;
  simulationData->mData->mModeVector.mN = 27;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_3_Modes[0];
  tmp_0 = false;
  simulationData->mData->mFoundZcEvents = tmp_0;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_7[0] = 0;
  tmp_6[0] = Robot_B.INTERNAL_1_1_1[0];
  tmp_6[1] = Robot_B.INTERNAL_1_1_1[1];
  tmp_6[2] = Robot_B.INTERNAL_1_1_1[2];
  tmp_6[3] = Robot_B.INTERNAL_1_1_1[3];
  tmp_7[1] = 4;
  tmp_6[4] = Robot_B.INPUT_7_1_1[0];
  tmp_6[5] = Robot_B.INPUT_7_1_1[1];
  tmp_6[6] = Robot_B.INPUT_7_1_1[2];
  tmp_6[7] = Robot_B.INPUT_7_1_1[3];
  tmp_7[2] = 8;
  tmp_6[8] = Robot_B.INPUT_8_1_1[0];
  tmp_6[9] = Robot_B.INPUT_8_1_1[1];
  tmp_6[10] = Robot_B.INPUT_8_1_1[2];
  tmp_6[11] = Robot_B.INPUT_8_1_1[3];
  tmp_7[3] = 12;
  tmp_6[12] = Robot_B.INPUT_9_1_1[0];
  tmp_6[13] = Robot_B.INPUT_9_1_1[1];
  tmp_6[14] = Robot_B.INPUT_9_1_1[2];
  tmp_6[15] = Robot_B.INPUT_9_1_1[3];
  tmp_7[4] = 16;
  tmp_6[16] = Robot_B.INPUT_10_1_1[0];
  tmp_6[17] = Robot_B.INPUT_10_1_1[1];
  tmp_6[18] = Robot_B.INPUT_10_1_1[2];
  tmp_6[19] = Robot_B.INPUT_10_1_1[3];
  tmp_7[5] = 20;
  tmp_6[20] = Robot_B.INPUT_11_1_1[0];
  tmp_6[21] = Robot_B.INPUT_11_1_1[1];
  tmp_6[22] = Robot_B.INPUT_11_1_1[2];
  tmp_6[23] = Robot_B.INPUT_11_1_1[3];
  tmp_7[6] = 24;
  tmp_6[24] = Robot_B.INPUT_12_1_1[0];
  tmp_6[25] = Robot_B.INPUT_12_1_1[1];
  tmp_6[26] = Robot_B.INPUT_12_1_1[2];
  tmp_6[27] = Robot_B.INPUT_12_1_1[3];
  tmp_7[7] = 28;
  simulationData->mData->mInputValues.mN = 28;
  simulationData->mData->mInputValues.mX = &tmp_6[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_7[0];
  simulationData->mData->mDx.mN = 24;
  simulationData->mData->mDx.mX = &_rtXdot->RobotBLDC1pm_dq0_Xabcangular_po[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_3_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_3_Simulator,
    NESL_SIM_FORCINGFUNCTION, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }
}

/* MassMatrix for root system: '<Root>' */
void Robot_massmatrix(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  boolean_T tmp_0;
  real_T tmp_1[28];
  int_T tmp_2[8];
  real_T *tmp_3;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_4;
  char *msg;
  real_T time_0;
  real_T tmp_5[28];
  int_T tmp_6[8];
  real_T time_tmp;

  /* MassMatrix for SimscapeExecutionBlock: '<S324>/STATE_2' incorporates:
   *  SimscapeExecutionBlock: '<S324>/STATE_3'
   */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_2_SimData;
  time_tmp = Robot_M->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 24;
  simulationData->mData->mContStates.mX =
    &Robot_X.RobotBLDCpm_dq0_Xabcangular_pos[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_2_Discrete;
  simulationData->mData->mModeVector.mN = 27;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_2_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  tmp = rtmIsMajorTimeStep(Robot_M);
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_2[0] = 0;
  tmp_1[0] = Robot_B.INTERNAL_2_1_1[0];
  tmp_1[1] = Robot_B.INTERNAL_2_1_1[1];
  tmp_1[2] = Robot_B.INTERNAL_2_1_1[2];
  tmp_1[3] = Robot_B.INTERNAL_2_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = Robot_B.INPUT_1_1_1[0];
  tmp_1[5] = Robot_B.INPUT_1_1_1[1];
  tmp_1[6] = Robot_B.INPUT_1_1_1[2];
  tmp_1[7] = Robot_B.INPUT_1_1_1[3];
  tmp_2[2] = 8;
  tmp_1[8] = Robot_B.INPUT_2_1_1[0];
  tmp_1[9] = Robot_B.INPUT_2_1_1[1];
  tmp_1[10] = Robot_B.INPUT_2_1_1[2];
  tmp_1[11] = Robot_B.INPUT_2_1_1[3];
  tmp_2[3] = 12;
  tmp_1[12] = Robot_B.INPUT_3_1_1[0];
  tmp_1[13] = Robot_B.INPUT_3_1_1[1];
  tmp_1[14] = Robot_B.INPUT_3_1_1[2];
  tmp_1[15] = Robot_B.INPUT_3_1_1[3];
  tmp_2[4] = 16;
  tmp_1[16] = Robot_B.INPUT_4_1_1[0];
  tmp_1[17] = Robot_B.INPUT_4_1_1[1];
  tmp_1[18] = Robot_B.INPUT_4_1_1[2];
  tmp_1[19] = Robot_B.INPUT_4_1_1[3];
  tmp_2[5] = 20;
  tmp_1[20] = Robot_B.INPUT_5_1_1[0];
  tmp_1[21] = Robot_B.INPUT_5_1_1[1];
  tmp_1[22] = Robot_B.INPUT_5_1_1[2];
  tmp_1[23] = Robot_B.INPUT_5_1_1[3];
  tmp_2[6] = 24;
  tmp_1[24] = Robot_B.INPUT_6_1_1[0];
  tmp_1[25] = Robot_B.INPUT_6_1_1[1];
  tmp_1[26] = Robot_B.INPUT_6_1_1[2];
  tmp_1[27] = Robot_B.INPUT_6_1_1[3];
  tmp_2[7] = 28;
  simulationData->mData->mInputValues.mN = 28;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  tmp_3 = Robot_MassMatrix.pr;
  tmp_3 = double_pointer_shift(tmp_3, Robot_DW.STATE_2_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 8;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_2_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_2_Simulator,
    NESL_SIM_MASSMATRIX, simulationData, diagnosticManager);
  if (tmp_4 != 0) {
    tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp_0) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S324>/STATE_2' */

  /* MassMatrix for SimscapeExecutionBlock: '<S324>/STATE_3' */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_3_SimData;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 24;
  simulationData->mData->mContStates.mX =
    &Robot_X.RobotBLDC1pm_dq0_Xabcangular_po[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_3_Discrete;
  simulationData->mData->mModeVector.mN = 27;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_3_Modes[0];
  tmp_0 = false;
  simulationData->mData->mFoundZcEvents = tmp_0;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_6[0] = 0;
  tmp_5[0] = Robot_B.INTERNAL_1_1_1[0];
  tmp_5[1] = Robot_B.INTERNAL_1_1_1[1];
  tmp_5[2] = Robot_B.INTERNAL_1_1_1[2];
  tmp_5[3] = Robot_B.INTERNAL_1_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = Robot_B.INPUT_7_1_1[0];
  tmp_5[5] = Robot_B.INPUT_7_1_1[1];
  tmp_5[6] = Robot_B.INPUT_7_1_1[2];
  tmp_5[7] = Robot_B.INPUT_7_1_1[3];
  tmp_6[2] = 8;
  tmp_5[8] = Robot_B.INPUT_8_1_1[0];
  tmp_5[9] = Robot_B.INPUT_8_1_1[1];
  tmp_5[10] = Robot_B.INPUT_8_1_1[2];
  tmp_5[11] = Robot_B.INPUT_8_1_1[3];
  tmp_6[3] = 12;
  tmp_5[12] = Robot_B.INPUT_9_1_1[0];
  tmp_5[13] = Robot_B.INPUT_9_1_1[1];
  tmp_5[14] = Robot_B.INPUT_9_1_1[2];
  tmp_5[15] = Robot_B.INPUT_9_1_1[3];
  tmp_6[4] = 16;
  tmp_5[16] = Robot_B.INPUT_10_1_1[0];
  tmp_5[17] = Robot_B.INPUT_10_1_1[1];
  tmp_5[18] = Robot_B.INPUT_10_1_1[2];
  tmp_5[19] = Robot_B.INPUT_10_1_1[3];
  tmp_6[5] = 20;
  tmp_5[20] = Robot_B.INPUT_11_1_1[0];
  tmp_5[21] = Robot_B.INPUT_11_1_1[1];
  tmp_5[22] = Robot_B.INPUT_11_1_1[2];
  tmp_5[23] = Robot_B.INPUT_11_1_1[3];
  tmp_6[6] = 24;
  tmp_5[24] = Robot_B.INPUT_12_1_1[0];
  tmp_5[25] = Robot_B.INPUT_12_1_1[1];
  tmp_5[26] = Robot_B.INPUT_12_1_1[2];
  tmp_5[27] = Robot_B.INPUT_12_1_1[3];
  tmp_6[7] = 28;
  simulationData->mData->mInputValues.mN = 28;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  tmp_3 = Robot_MassMatrix.pr;
  tmp_3 = double_pointer_shift(tmp_3, Robot_DW.STATE_3_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 8;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_3_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_3_Simulator,
    NESL_SIM_MASSMATRIX, simulationData, diagnosticManager);
  if (tmp_4 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  Robot_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 58;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    Robot_step();
    rtsiSetdX(si,p);
    Robot_forcingfunction();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14x fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 58;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  if (id->isFirstStep) {
    local_evaluateMassMatrix(si,M );
    id->isFirstStep = false;
  }

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Robot_forcingfunction();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
        real_T m_row_col = M[rowidx];
        row = Mpattern_ir[rowidx];
        p[row] += m_row_col;
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      Robot_step();
      Robot_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        Robot_step();
        Robot_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  Robot_step();
  Robot_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T Robot_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += 2.0;
      }
    }
  }

  return r;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T Robot_mod_j(real_T x)
{
  real_T r;
  boolean_T rEQ0;
  real_T q;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 0.25);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q = fabs(x / 0.25);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += 0.25;
      }
    }
  }

  return r;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Robot_step(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  real_T rtb_Integrator_c;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_d;
  boolean_T rtb_LogicalOperator_c;
  boolean_T rtb_LogicalOperator_p;
  real_T rtb_FilterCoefficient;
  real_T rtb_Sum5;
  real_T rtb_Sum2[3];
  real_T rtb_IntegralGain;
  real_T rtb_Saturation;
  real_T rtb_Relay;
  real_T rtb_SumI4;
  real_T rtb_uT;
  real_T rtb_Sum5_m;
  real_T rtb_Sum2_a[3];
  real_T rtb_IntegralGain_o;
  real_T rtb_Saturation_j;
  real_T rtb_Relay_k;
  real_T rtb_SumI4_k;
  real_T rtb_uT_i;
  real_T rtb_RateTransition6;
  real_T rtb_radsrpm;
  real_T rtb_RateTransition6_p;
  real_T rtb_RateTransition3_g;
  real_T rtb_PhasecurrentsA[3];
  real_T rtb_RateTransition3_a;
  real_T rtb_PhasecurrentsA_g[3];
  real_T rtb_radsrpm_f;
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_pr;
  if (rtmIsMajorTimeStep(Robot_M)) {
    /* set solver stop time */
    if (!(Robot_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Robot_M->solverInfo, ((Robot_M->Timing.clockTickH0
        + 1) * Robot_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Robot_M->solverInfo, ((Robot_M->Timing.clockTick0 +
        1) * Robot_M->Timing.stepSize0 + Robot_M->Timing.clockTickH0 *
        Robot_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Robot_M)) {
    Robot_M->Timing.t[0] = rtsiGetT(&Robot_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    boolean_T tmp_0;
    real_T tmp_1[8];
    int_T tmp_2[3];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T time_0;
    real_T tmp_3[18];
    int_T tmp_4[4];
    real_T time_1;
    real_T tmp_5[28];
    int_T tmp_6[8];
    real_T time_2;
    real_T tmp_7[79];
    int_T tmp_8[9];
    real_T time_3;
    real_T tmp_9[28];
    int_T tmp_a[8];
    real_T time_4;
    real_T tmp_b[79];
    int_T tmp_c[9];
    real_T rtb_Sign_o;
    real_T rtb_Saturation_m;
    real_T rtb_Sum_l;
    real_T rtb_Integrator_ff;
    real_T rtb_Sum3_i;
    real_T rtb_Is;
    real_T rtb_Sum_i;
    real_T rtb_Max;
    real_T rtb_Is_i;
    real_T rtb_Sum4_k;
    real_T tmp_d;
    int32_T rtb_DataTypeConversion1;
    int32_T rtb_DataTypeConversion1_idx_0;
    int32_T rtb_DataTypeConversion2_idx_0;
    int32_T rtb_DataTypeConversion1_idx_1;
    int32_T rtb_DataTypeConversion2_idx_1;
    real_T rtb_Product_e_idx_0;
    real_T rtb_Product_e_idx_1;
    real_T rtb_Product_e_idx_2;
    real_T rtb_Product_mc_idx_0;
    real_T rtb_Product_mc_idx_1;
    real_T rtb_Product_mc_idx_2;

    /* SimscapeExecutionBlock: '<S324>/STATE_1' incorporates:
     *  Clock: '<Root>/Clock'
     *  SimscapeExecutionBlock: '<S324>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S324>/OUTPUT_2_0'
     *  SimscapeExecutionBlock: '<S324>/OUTPUT_3_0'
     *  SimscapeExecutionBlock: '<S324>/STATE_2'
     *  SimscapeExecutionBlock: '<S324>/STATE_3'
     */
    simulationData = (NeslSimulationData *)Robot_DW.STATE_1_SimData;
    rtb_Sign_o = Robot_M->Timing.t[0];
    time = rtb_Sign_o;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 10;
    simulationData->mData->mContStates.mX = &Robot_X.RobotRevolute3Rzq[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &Robot_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp = rtmIsMajorTimeStep(Robot_M);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_2[0] = 0;
    tmp_1[0] = Robot_B.INTERNAL_4_1_1[0];
    tmp_1[1] = Robot_B.INTERNAL_4_1_1[1];
    tmp_1[2] = Robot_B.INTERNAL_4_1_1[2];
    tmp_1[3] = Robot_B.INTERNAL_4_1_1[3];
    tmp_2[1] = 4;
    tmp_1[4] = Robot_B.INTERNAL_3_1_1[0];
    tmp_1[5] = Robot_B.INTERNAL_3_1_1[1];
    tmp_1[6] = Robot_B.INTERNAL_3_1_1[2];
    tmp_1[7] = Robot_B.INTERNAL_3_1_1[3];
    tmp_2[2] = 8;
    simulationData->mData->mInputValues.mN = 8;
    simulationData->mData->mInputValues.mX = &tmp_1[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_2[0];
    simulationData->mData->mOutputs.mN = 10;
    simulationData->mData->mOutputs.mX = &Robot_B.STATE_1[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    rtb_DataTypeConversion2_idx_0 = ne_simulator_method((NeslSimulator *)
      Robot_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (rtb_DataTypeConversion2_idx_0 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S324>/STATE_1' */

    /* SimscapeExecutionBlock: '<S324>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)Robot_DW.OUTPUT_1_0_SimData;
    time_0 = rtb_Sign_o;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &Robot_DW.OUTPUT_1_0_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_4[0] = 0;
    tmp_3[0] = Robot_B.INTERNAL_4_1_1[0];
    tmp_3[1] = Robot_B.INTERNAL_4_1_1[1];
    tmp_3[2] = Robot_B.INTERNAL_4_1_1[2];
    tmp_3[3] = Robot_B.INTERNAL_4_1_1[3];
    tmp_4[1] = 4;
    tmp_3[4] = Robot_B.INTERNAL_3_1_1[0];
    tmp_3[5] = Robot_B.INTERNAL_3_1_1[1];
    tmp_3[6] = Robot_B.INTERNAL_3_1_1[2];
    tmp_3[7] = Robot_B.INTERNAL_3_1_1[3];
    tmp_4[2] = 8;
    memcpy(&tmp_3[8], &Robot_B.STATE_1[0], 10U * sizeof(real_T));
    tmp_4[3] = 18;
    simulationData->mData->mInputValues.mN = 18;
    simulationData->mData->mInputValues.mX = &tmp_3[0];
    simulationData->mData->mInputOffsets.mN = 4;
    simulationData->mData->mInputOffsets.mX = &tmp_4[0];
    simulationData->mData->mOutputs.mN = 6;
    simulationData->mData->mOutputs.mX = &Robot_B.OUTPUT_1_0[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    rtb_DataTypeConversion2_idx_0 = ne_simulator_method((NeslSimulator *)
      Robot_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (rtb_DataTypeConversion2_idx_0 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    rtb_Sum4_k = rtb_Sign_o;
    Robot_B.d1 = 0.0;
    tmp_d = Robot_mod(floor(rtb_Sign_o / 0.25));
    if (tmp_d == 0.0) {
      rtb_Sum4_k = Robot_mod_j(rtb_Sign_o);
      Robot_B.d1 = (((((0.0 * rtb_Sum4_k + 393.0) + rtb_Sum4_k * rtb_Sum4_k *
                       0.0) + -97164.799999999843 * rt_powd_snf(rtb_Sum4_k, 3.0))
                     + 582988.79999999888 * rt_powd_snf(rtb_Sum4_k, 4.0)) +
                    -932782.07999999844 * rt_powd_snf(rtb_Sum4_k, 5.0)) *
        0.017453292519943295;
    }

    if (tmp_d == 1.0) {
      rtb_Sum4_k = Robot_mod_j(rtb_Sum4_k);
      Robot_B.d1 = (((((0.0 * rtb_Sum4_k + 241.18) + rtb_Sum4_k * rtb_Sum4_k *
                       0.0) + 97164.799999999843 * rt_powd_snf(rtb_Sum4_k, 3.0))
                     + -582988.79999999888 * rt_powd_snf(rtb_Sum4_k, 4.0)) +
                    932782.07999999844 * rt_powd_snf(rtb_Sum4_k, 5.0)) *
        0.017453292519943295;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* SimscapeInputBlock: '<S324>/INTERNAL_2_1_1' */
    Robot_B.INTERNAL_2_1_1[0] = Robot_B.OUTPUT_1_0[5];
    Robot_B.INTERNAL_2_1_1[1] = 0.0;
    Robot_B.INTERNAL_2_1_1[2] = 0.0;
    Robot_B.INTERNAL_2_1_1[3] = 0.0;

    /* RateTransition: '<S29>/Rate Transition4' incorporates:
     *  DataTypeConversion: '<S37>/Data Type Conversion2'
     */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_B.RateTransition4[0] = Robot_DW.RateTransition4_Buffer0[0];
        Robot_B.RateTransition4[1] = Robot_DW.RateTransition4_Buffer0[1];
        Robot_B.RateTransition4[2] = Robot_DW.RateTransition4_Buffer0[2];
      }

      /* Logic: '<S45>/Logical Operator' incorporates:
       *  Constant: '<S46>/Constant'
       *  Constant: '<S47>/Constant'
       *  RelationalOperator: '<S46>/Compare'
       *  RelationalOperator: '<S47>/Compare'
       */
      rtb_LogicalOperator = ((Robot_DW.Integrator_DSTATE <
        Robot_P.IntegratorwithWrappedStateDiscr) || (Robot_DW.Integrator_DSTATE >=
        Robot_P.Tsc));

      /* InitialCondition: '<S45>/Initial' incorporates:
       *  Constant: '<S48>/Constant'
       *  Gain: '<S48>/Gain'
       *  Gain: '<S48>/Gain1'
       *  Rounding: '<S48>/Rounding Function'
       *  Sum: '<S48>/Sum'
       *  Sum: '<S48>/Sum1'
       */
      if (Robot_DW.Initial_FirstOutputTime) {
        Robot_DW.Initial_FirstOutputTime = false;
        Robot_B.Initial = Robot_P.Initial_Value;
      } else {
        /* Gain: '<S48>/Gain' incorporates:
         *  Gain: '<S48>/Gain1'
         */
        rtb_Sum4_k = Robot_P.Tsc - Robot_P.IntegratorwithWrappedStateDiscr;
        Robot_B.Initial = Robot_DW.Integrator_DSTATE - floor(1.0 / rtb_Sum4_k *
          (Robot_DW.Integrator_DSTATE - Robot_P.IntegratorwithWrappedStateDiscr))
          * rtb_Sum4_k;
      }

      /* End of InitialCondition: '<S45>/Initial' */

      /* DiscreteIntegrator: '<S45>/Integrator' */
      if (rtb_LogicalOperator && (Robot_DW.Integrator_PrevResetState <= 0)) {
        Robot_DW.Integrator_DSTATE = Robot_B.Initial;
      }

      rtb_Integrator = Robot_DW.Integrator_DSTATE;

      /* End of DiscreteIntegrator: '<S45>/Integrator' */

      /* Logic: '<S49>/Logical Operator' incorporates:
       *  Constant: '<S50>/Constant'
       *  Constant: '<S51>/Constant'
       *  RelationalOperator: '<S50>/Compare'
       *  RelationalOperator: '<S51>/Compare'
       */
      rtb_LogicalOperator_d = ((Robot_DW.Integrator_DSTATE_o <
        Robot_P.IntegratorwithWrappedStateDis_h) ||
        (Robot_DW.Integrator_DSTATE_o >= 2.0 * Robot_P.Tsc));

      /* InitialCondition: '<S49>/Initial' incorporates:
       *  Constant: '<S52>/Constant'
       *  Gain: '<S52>/Gain'
       *  Gain: '<S52>/Gain1'
       *  Rounding: '<S52>/Rounding Function'
       *  Sum: '<S52>/Sum'
       *  Sum: '<S52>/Sum1'
       */
      if (Robot_DW.Initial_FirstOutputTime_l) {
        Robot_DW.Initial_FirstOutputTime_l = false;
        Robot_B.Initial_e = Robot_P.Initial_Value_i;
      } else {
        /* Gain: '<S52>/Gain' incorporates:
         *  Gain: '<S52>/Gain1'
         */
        rtb_Sum4_k = 2.0 * Robot_P.Tsc - Robot_P.IntegratorwithWrappedStateDis_h;
        Robot_B.Initial_e = Robot_DW.Integrator_DSTATE_o - floor(1.0 /
          rtb_Sum4_k * (Robot_DW.Integrator_DSTATE_o -
                        Robot_P.IntegratorwithWrappedStateDis_h)) * rtb_Sum4_k;
      }

      /* End of InitialCondition: '<S49>/Initial' */

      /* DiscreteIntegrator: '<S49>/Integrator' */
      if (rtb_LogicalOperator_d && (Robot_DW.Integrator_PrevResetState_k <= 0))
      {
        Robot_DW.Integrator_DSTATE_o = Robot_B.Initial_e;
      }

      /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
       *  Constant: '<S38>/Constant2'
       *  Constant: '<S38>/Constant6'
       *  Constant: '<S44>/Constant'
       *  Product: '<S44>/Product'
       *  Product: '<S44>/Product1'
       *  Sum: '<S38>/Sum3'
       *  Sum: '<S38>/Sum5'
       *  Sum: '<S44>/Sum'
       */
      switch ((int32_T)Robot_P.Carriercounter_CarrCount) {
       case 1:
        rtb_Sum4_k = Robot_P.Tsc / (Robot_P.Tsc - Robot_B.Probe[0]) *
          rtb_Integrator;
        break;

       case 2:
        rtb_Sum4_k = Robot_P.Tsc - Robot_P.Tsc / (Robot_P.Tsc - Robot_B.Probe[0])
          * rtb_Integrator;
        break;

       default:
        /* Sum: '<S38>/Sum4' incorporates:
         *  Constant: '<S38>/Constant10'
         *  DiscreteIntegrator: '<S49>/Integrator'
         */
        rtb_Sum4_k = 2.0 * Robot_P.Tsc - Robot_DW.Integrator_DSTATE_o;

        /* Switch: '<S42>/Switch' incorporates:
         *  Constant: '<S42>/Constant2'
         *  DiscreteIntegrator: '<S49>/Integrator'
         */
        if (Robot_DW.Integrator_DSTATE_o > Robot_P.Tsc) {
          tmp_d = Robot_P.Constant2_Value;
        } else {
          tmp_d = Robot_DW.Integrator_DSTATE_o;
        }

        /* End of Switch: '<S42>/Switch' */

        /* Switch: '<S43>/Switch' incorporates:
         *  Constant: '<S43>/Constant2'
         */
        if (rtb_Sum4_k > Robot_P.Tsc) {
          rtb_Sum4_k = Robot_P.Constant2_Value_k;
        }

        /* End of Switch: '<S43>/Switch' */
        rtb_Sum4_k += tmp_d;
        break;
      }

      /* End of MultiPortSwitch: '<S38>/Multiport Switch' */

      /* Gain: '<S38>/Gain1' */
      rtb_Sum4_k *= 1.0 / Robot_P.Tsc;

      /* Saturate: '<S38>/Saturation' */
      if (rtb_Sum4_k > Robot_P.Saturation_UpperSat) {
        rtb_Sum4_k = Robot_P.Saturation_UpperSat;
      } else {
        if (rtb_Sum4_k < Robot_P.Saturation_LowerSat) {
          rtb_Sum4_k = Robot_P.Saturation_LowerSat;
        }
      }

      /* End of Saturate: '<S38>/Saturation' */

      /* Bias: '<S38>/Bias' incorporates:
       *  Gain: '<S38>/Gain'
       */
      rtb_Sum4_k = Robot_P.Carriercounter_Range * rtb_Sum4_k +
        (-Robot_P.Carriercounter_Range + 1.0);

      /* DataTypeConversion: '<S37>/Data Type Conversion2' incorporates:
       *  Constant: '<S39>/Constant'
       *  Logic: '<S37>/Logical Operator'
       *  RelationalOperator: '<S37>/Relational Operator'
       *  RelationalOperator: '<S39>/Compare'
       */
      rtb_DataTypeConversion1 = ((Robot_B.RateTransition4[0] !=
        Robot_P.Constant_Value) && (Robot_B.RateTransition4[0] >= rtb_Sum4_k));

      /* DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S36>/Data Type Conversion'
       *  Logic: '<S36>/Logical Operator'
       */
      rtb_DataTypeConversion2_idx_0 = (rtb_DataTypeConversion1 == 0);
      rtb_DataTypeConversion1_idx_0 = rtb_DataTypeConversion1;

      /* DataTypeConversion: '<S37>/Data Type Conversion2' incorporates:
       *  Constant: '<S39>/Constant'
       *  Logic: '<S37>/Logical Operator'
       *  RelationalOperator: '<S37>/Relational Operator'
       *  RelationalOperator: '<S39>/Compare'
       */
      rtb_DataTypeConversion1 = ((Robot_B.RateTransition4[1] !=
        Robot_P.Constant_Value) && (Robot_B.RateTransition4[1] >= rtb_Sum4_k));

      /* DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S36>/Data Type Conversion'
       *  Logic: '<S36>/Logical Operator'
       */
      rtb_DataTypeConversion2_idx_1 = (rtb_DataTypeConversion1 == 0);
      rtb_DataTypeConversion1_idx_1 = rtb_DataTypeConversion1;

      /* DataTypeConversion: '<S37>/Data Type Conversion2' incorporates:
       *  Constant: '<S39>/Constant'
       *  Logic: '<S37>/Logical Operator'
       *  RelationalOperator: '<S37>/Relational Operator'
       *  RelationalOperator: '<S39>/Compare'
       */
      rtb_DataTypeConversion1 = ((Robot_B.RateTransition4[2] !=
        Robot_P.Constant_Value) && (Robot_B.RateTransition4[2] >= rtb_Sum4_k));

      /* RateTransition: '<S29>/Rate Transition7' */
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_B.RateTransition7 = Robot_DW.RateTransition7_Buffer0;
      }

      /* End of RateTransition: '<S29>/Rate Transition7' */

      /* Product: '<S29>/Product1' incorporates:
       *  DataTypeConversion: '<S36>/Data Type Conversion'
       *  Logic: '<S36>/Logical Operator'
       */
      Robot_B.Product1[0] = (real_T)rtb_DataTypeConversion1_idx_0 *
        Robot_B.RateTransition7;
      Robot_B.Product1[1] = (real_T)rtb_DataTypeConversion2_idx_0 *
        Robot_B.RateTransition7;
      Robot_B.Product1[2] = (real_T)rtb_DataTypeConversion1_idx_1 *
        Robot_B.RateTransition7;
      Robot_B.Product1[3] = (real_T)rtb_DataTypeConversion2_idx_1 *
        Robot_B.RateTransition7;
      Robot_B.Product1[4] = (real_T)rtb_DataTypeConversion1 *
        Robot_B.RateTransition7;
      Robot_B.Product1[5] = (real_T)(rtb_DataTypeConversion1 == 0) *
        Robot_B.RateTransition7;
    }

    /* End of RateTransition: '<S29>/Rate Transition4' */

    /* SimscapeInputBlock: '<S324>/INPUT_1_1_1' */
    Robot_B.INPUT_1_1_1[0] = Robot_B.Product1[0];
    Robot_B.INPUT_1_1_1[1] = 0.0;
    Robot_B.INPUT_1_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_1_1_1_Discrete[0] = !(Robot_B.INPUT_1_1_1[0] ==
        Robot_DW.INPUT_1_1_1_Discrete[1]);
      Robot_DW.INPUT_1_1_1_Discrete[1] = Robot_B.INPUT_1_1_1[0];
    }

    Robot_B.INPUT_1_1_1[0] = Robot_DW.INPUT_1_1_1_Discrete[1];
    Robot_B.INPUT_1_1_1[3] = Robot_DW.INPUT_1_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_1_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_2_1_1' */
    Robot_B.INPUT_2_1_1[0] = Robot_B.Product1[1];
    Robot_B.INPUT_2_1_1[1] = 0.0;
    Robot_B.INPUT_2_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_2_1_1_Discrete[0] = !(Robot_B.INPUT_2_1_1[0] ==
        Robot_DW.INPUT_2_1_1_Discrete[1]);
      Robot_DW.INPUT_2_1_1_Discrete[1] = Robot_B.INPUT_2_1_1[0];
    }

    Robot_B.INPUT_2_1_1[0] = Robot_DW.INPUT_2_1_1_Discrete[1];
    Robot_B.INPUT_2_1_1[3] = Robot_DW.INPUT_2_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_2_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_3_1_1' */
    Robot_B.INPUT_3_1_1[0] = Robot_B.Product1[2];
    Robot_B.INPUT_3_1_1[1] = 0.0;
    Robot_B.INPUT_3_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_3_1_1_Discrete[0] = !(Robot_B.INPUT_3_1_1[0] ==
        Robot_DW.INPUT_3_1_1_Discrete[1]);
      Robot_DW.INPUT_3_1_1_Discrete[1] = Robot_B.INPUT_3_1_1[0];
    }

    Robot_B.INPUT_3_1_1[0] = Robot_DW.INPUT_3_1_1_Discrete[1];
    Robot_B.INPUT_3_1_1[3] = Robot_DW.INPUT_3_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_3_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_4_1_1' */
    Robot_B.INPUT_4_1_1[0] = Robot_B.Product1[3];
    Robot_B.INPUT_4_1_1[1] = 0.0;
    Robot_B.INPUT_4_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_4_1_1_Discrete[0] = !(Robot_B.INPUT_4_1_1[0] ==
        Robot_DW.INPUT_4_1_1_Discrete[1]);
      Robot_DW.INPUT_4_1_1_Discrete[1] = Robot_B.INPUT_4_1_1[0];
    }

    Robot_B.INPUT_4_1_1[0] = Robot_DW.INPUT_4_1_1_Discrete[1];
    Robot_B.INPUT_4_1_1[3] = Robot_DW.INPUT_4_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_4_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_5_1_1' */
    Robot_B.INPUT_5_1_1[0] = Robot_B.Product1[4];
    Robot_B.INPUT_5_1_1[1] = 0.0;
    Robot_B.INPUT_5_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_5_1_1_Discrete[0] = !(Robot_B.INPUT_5_1_1[0] ==
        Robot_DW.INPUT_5_1_1_Discrete[1]);
      Robot_DW.INPUT_5_1_1_Discrete[1] = Robot_B.INPUT_5_1_1[0];
    }

    Robot_B.INPUT_5_1_1[0] = Robot_DW.INPUT_5_1_1_Discrete[1];
    Robot_B.INPUT_5_1_1[3] = Robot_DW.INPUT_5_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_5_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_6_1_1' */
    Robot_B.INPUT_6_1_1[0] = Robot_B.Product1[5];
    Robot_B.INPUT_6_1_1[1] = 0.0;
    Robot_B.INPUT_6_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_6_1_1_Discrete[0] = !(Robot_B.INPUT_6_1_1[0] ==
        Robot_DW.INPUT_6_1_1_Discrete[1]);
      Robot_DW.INPUT_6_1_1_Discrete[1] = Robot_B.INPUT_6_1_1[0];
    }

    Robot_B.INPUT_6_1_1[0] = Robot_DW.INPUT_6_1_1_Discrete[1];
    Robot_B.INPUT_6_1_1[3] = Robot_DW.INPUT_6_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_6_1_1' */

    /* SimscapeExecutionBlock: '<S324>/STATE_2' */
    simulationData = (NeslSimulationData *)Robot_DW.STATE_2_SimData;
    time_1 = rtb_Sign_o;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 24;
    simulationData->mData->mContStates.mX =
      &Robot_X.RobotBLDCpm_dq0_Xabcangular_pos[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_2_Discrete;
    simulationData->mData->mModeVector.mN = 27;
    simulationData->mData->mModeVector.mX = &Robot_DW.STATE_2_Modes[0];
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_6[0] = 0;
    tmp_5[0] = Robot_B.INTERNAL_2_1_1[0];
    tmp_5[1] = Robot_B.INTERNAL_2_1_1[1];
    tmp_5[2] = Robot_B.INTERNAL_2_1_1[2];
    tmp_5[3] = Robot_B.INTERNAL_2_1_1[3];
    tmp_6[1] = 4;
    tmp_5[4] = Robot_B.INPUT_1_1_1[0];
    tmp_5[5] = Robot_B.INPUT_1_1_1[1];
    tmp_5[6] = Robot_B.INPUT_1_1_1[2];
    tmp_5[7] = Robot_B.INPUT_1_1_1[3];
    tmp_6[2] = 8;
    tmp_5[8] = Robot_B.INPUT_2_1_1[0];
    tmp_5[9] = Robot_B.INPUT_2_1_1[1];
    tmp_5[10] = Robot_B.INPUT_2_1_1[2];
    tmp_5[11] = Robot_B.INPUT_2_1_1[3];
    tmp_6[3] = 12;
    tmp_5[12] = Robot_B.INPUT_3_1_1[0];
    tmp_5[13] = Robot_B.INPUT_3_1_1[1];
    tmp_5[14] = Robot_B.INPUT_3_1_1[2];
    tmp_5[15] = Robot_B.INPUT_3_1_1[3];
    tmp_6[4] = 16;
    tmp_5[16] = Robot_B.INPUT_4_1_1[0];
    tmp_5[17] = Robot_B.INPUT_4_1_1[1];
    tmp_5[18] = Robot_B.INPUT_4_1_1[2];
    tmp_5[19] = Robot_B.INPUT_4_1_1[3];
    tmp_6[5] = 20;
    tmp_5[20] = Robot_B.INPUT_5_1_1[0];
    tmp_5[21] = Robot_B.INPUT_5_1_1[1];
    tmp_5[22] = Robot_B.INPUT_5_1_1[2];
    tmp_5[23] = Robot_B.INPUT_5_1_1[3];
    tmp_6[6] = 24;
    tmp_5[24] = Robot_B.INPUT_6_1_1[0];
    tmp_5[25] = Robot_B.INPUT_6_1_1[1];
    tmp_5[26] = Robot_B.INPUT_6_1_1[2];
    tmp_5[27] = Robot_B.INPUT_6_1_1[3];
    tmp_6[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    simulationData->mData->mOutputs.mN = 51;
    simulationData->mData->mOutputs.mX = &Robot_B.STATE_2[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_2_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    rtb_DataTypeConversion2_idx_0 = ne_simulator_method((NeslSimulator *)
      Robot_DW.STATE_2_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (rtb_DataTypeConversion2_idx_0 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* SimscapeExecutionBlock: '<S324>/OUTPUT_2_0' */
    simulationData = (NeslSimulationData *)Robot_DW.OUTPUT_2_0_SimData;
    time_2 = rtb_Sign_o;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.OUTPUT_2_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &Robot_DW.OUTPUT_2_0_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_8[0] = 0;
    tmp_7[0] = Robot_B.INTERNAL_2_1_1[0];
    tmp_7[1] = Robot_B.INTERNAL_2_1_1[1];
    tmp_7[2] = Robot_B.INTERNAL_2_1_1[2];
    tmp_7[3] = Robot_B.INTERNAL_2_1_1[3];
    tmp_8[1] = 4;
    tmp_7[4] = Robot_B.INPUT_1_1_1[0];
    tmp_7[5] = Robot_B.INPUT_1_1_1[1];
    tmp_7[6] = Robot_B.INPUT_1_1_1[2];
    tmp_7[7] = Robot_B.INPUT_1_1_1[3];
    tmp_8[2] = 8;
    tmp_7[8] = Robot_B.INPUT_2_1_1[0];
    tmp_7[9] = Robot_B.INPUT_2_1_1[1];
    tmp_7[10] = Robot_B.INPUT_2_1_1[2];
    tmp_7[11] = Robot_B.INPUT_2_1_1[3];
    tmp_8[3] = 12;
    tmp_7[12] = Robot_B.INPUT_3_1_1[0];
    tmp_7[13] = Robot_B.INPUT_3_1_1[1];
    tmp_7[14] = Robot_B.INPUT_3_1_1[2];
    tmp_7[15] = Robot_B.INPUT_3_1_1[3];
    tmp_8[4] = 16;
    tmp_7[16] = Robot_B.INPUT_4_1_1[0];
    tmp_7[17] = Robot_B.INPUT_4_1_1[1];
    tmp_7[18] = Robot_B.INPUT_4_1_1[2];
    tmp_7[19] = Robot_B.INPUT_4_1_1[3];
    tmp_8[5] = 20;
    tmp_7[20] = Robot_B.INPUT_5_1_1[0];
    tmp_7[21] = Robot_B.INPUT_5_1_1[1];
    tmp_7[22] = Robot_B.INPUT_5_1_1[2];
    tmp_7[23] = Robot_B.INPUT_5_1_1[3];
    tmp_8[6] = 24;
    tmp_7[24] = Robot_B.INPUT_6_1_1[0];
    tmp_7[25] = Robot_B.INPUT_6_1_1[1];
    tmp_7[26] = Robot_B.INPUT_6_1_1[2];
    tmp_7[27] = Robot_B.INPUT_6_1_1[3];
    tmp_8[7] = 28;
    memcpy(&tmp_7[28], &Robot_B.STATE_2[0], 51U * sizeof(real_T));
    tmp_8[8] = 79;
    simulationData->mData->mInputValues.mN = 79;
    simulationData->mData->mInputValues.mX = &tmp_7[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_8[0];
    simulationData->mData->mOutputs.mN = 6;
    simulationData->mData->mOutputs.mX = &Robot_B.OUTPUT_2_0[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.OUTPUT_2_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    rtb_DataTypeConversion2_idx_0 = ne_simulator_method((NeslSimulator *)
      Robot_DW.OUTPUT_2_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (rtb_DataTypeConversion2_idx_0 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S1>/Rate Transition6' */
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_DW.RateTransition6_Buffer = Robot_B.d1;
      }
    }

    /* RateTransition: '<S1>/Rate Transition6' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      rtb_RateTransition6 = Robot_DW.RateTransition6_Buffer;
    }

    /* RateTransition: '<S1>/Rate Transition3' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition3_Buffer = Robot_B.OUTPUT_1_0[4];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S1>/Sum3' */
      rtb_Sum_l = rtb_RateTransition6 - Robot_DW.RateTransition3_Buffer;

      /* Gain: '<S87>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S79>/Filter'
       *  Gain: '<S78>/Derivative Gain'
       *  Sum: '<S79>/SumD'
       */
      rtb_FilterCoefficient = (Robot_P.Positioncontroller_D * rtb_Sum_l -
        Robot_DW.Filter_DSTATE) * Robot_P.Positioncontroller_N;

      /* Sum: '<S93>/Sum' incorporates:
       *  DiscreteIntegrator: '<S84>/Integrator'
       *  Gain: '<S89>/Proportional Gain'
       */
      rtb_radsrpm_f = (Robot_P.Kpp * rtb_Sum_l + Robot_DW.Integrator_DSTATE_a) +
        rtb_FilterCoefficient;
    }

    /* End of RateTransition: '<S1>/Rate Transition3' */

    /* RateTransition: '<S1>/Rate Transition1' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition1_Buffer = Robot_B.OUTPUT_1_0[5];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Gain: '<S1>/rad//s->rpm' */
      rtb_radsrpm = Robot_P.radsrpm_Gain * Robot_DW.RateTransition1_Buffer;

      /* Sum: '<S1>/Sum' */
      rtb_Saturation_m = rtb_radsrpm_f - rtb_radsrpm;

      /* Sum: '<S141>/Sum' incorporates:
       *  DiscreteIntegrator: '<S132>/Integrator'
       *  Gain: '<S137>/Proportional Gain'
       */
      rtb_Integrator_ff = Robot_P.Kpw * rtb_Saturation_m +
        Robot_DW.Integrator_DSTATE_g;

      /* Saturate: '<S139>/Saturation' */
      if (rtb_Integrator_ff > Robot_P.Speedcontroller_UpperSaturation) {
        rtb_Sum3_i = Robot_P.Speedcontroller_UpperSaturation;
      } else if (rtb_Integrator_ff < Robot_P.Speedcontroller_LowerSaturation) {
        rtb_Sum3_i = Robot_P.Speedcontroller_LowerSaturation;
      } else {
        rtb_Sum3_i = rtb_Integrator_ff;
      }

      /* End of Saturate: '<S139>/Saturation' */

      /* Abs: '<S1>/Abs' */
      rtb_Is = fabs(rtb_Sum3_i);
    }

    /* End of RateTransition: '<S1>/Rate Transition1' */

    /* Gain: '<S306>/mech->elec' */
    rtb_Sum4_k = Robot_P.p * Robot_B.OUTPUT_2_0[1];

    /* Gain: '<S306>/rad->deg' incorporates:
     *  Trigonometry: '<S306>/Trigonometric Function'
     *  Trigonometry: '<S306>/Trigonometric Function2'
     */
    rtb_Sum4_k = Robot_P.raddeg_Gain * rt_atan2d_snf(sin(rtb_Sum4_k), cos
      (rtb_Sum4_k));

    /* Logic: '<S10>/Logical Operator' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     *  RelationalOperator: '<S10>/Relational Operator1'
     *  RelationalOperator: '<S10>/Relational Operator2'
     */
    Robot_B.LogicalOperator = ((rtb_Sum4_k >= Robot_P.Constant_Value_f) &&
      (rtb_Sum4_k <= Robot_P.Constant1_Value));

    /* Logic: '<S10>/Logical Operator1' incorporates:
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S10>/Constant3'
     *  RelationalOperator: '<S10>/Relational Operator3'
     *  RelationalOperator: '<S10>/Relational Operator4'
     */
    Robot_B.LogicalOperator1 = ((rtb_Sum4_k >= Robot_P.Constant2_Value_n) ||
      (rtb_Sum4_k <= Robot_P.Constant3_Value));

    /* Logic: '<S10>/Logical Operator2' incorporates:
     *  Constant: '<S10>/Constant4'
     *  Constant: '<S10>/Constant5'
     *  RelationalOperator: '<S10>/Relational Operator5'
     *  RelationalOperator: '<S10>/Relational Operator6'
     */
    Robot_B.LogicalOperator2 = ((rtb_Sum4_k >= Robot_P.Constant4_Value) &&
      (rtb_Sum4_k <= Robot_P.Constant5_Value));

    /* RateTransition: '<S1>/Rate Transition4' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition4_Buffer[0] = Robot_B.LogicalOperator;
      Robot_DW.RateTransition4_Buffer[1] = Robot_B.LogicalOperator1;
      Robot_DW.RateTransition4_Buffer[2] = Robot_B.LogicalOperator2;
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* LookupNDDirect: '<S33>/Direct Lookup Table (n-D)2' incorporates:
       *  DataTypeConversion: '<S33>/Data Type Conversion'
       *  Gain: '<S35>/Gain'
       *
       * About '<S33>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_DataTypeConversion2_idx_0 = (uint8_T)((uint32_T)(uint8_T)((uint32_T)
        (uint8_T)((uint32_T)(uint8_T)(Robot_DW.RateTransition4_Buffer[0] ?
        (int32_T)Robot_P.Gain_Gain_b[0] : 0) + (Robot_DW.RateTransition4_Buffer
        [1] ? (int32_T)Robot_P.Gain_Gain_b[1] : 0)) +
        (Robot_DW.RateTransition4_Buffer[2] ? (int32_T)Robot_P.Gain_Gain_b[2] :
         0)) >> 5) * 3;

      /* Signum: '<S1>/Sign' */
      if (rtb_radsrpm_f < 0.0) {
        rtb_Sum4_k = -1.0;
      } else if (rtb_radsrpm_f > 0.0) {
        rtb_Sum4_k = 1.0;
      } else if (rtb_radsrpm_f == 0.0) {
        rtb_Sum4_k = 0.0;
      } else {
        rtb_Sum4_k = (rtNaN);
      }

      /* End of Signum: '<S1>/Sign' */

      /* Product: '<S33>/Product' incorporates:
       *  LookupNDDirect: '<S33>/Direct Lookup Table (n-D)2'
       *
       * About '<S33>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_Product_e_idx_0 =
        Robot_P.DirectLookupTablenD2_table[rtb_DataTypeConversion2_idx_0] *
        rtb_Sum4_k;
      rtb_Product_e_idx_1 =
        Robot_P.DirectLookupTablenD2_table[rtb_DataTypeConversion2_idx_0 + 1] *
        rtb_Sum4_k;
      rtb_Product_e_idx_2 =
        Robot_P.DirectLookupTablenD2_table[rtb_DataTypeConversion2_idx_0 + 2] *
        rtb_Sum4_k;

      /* DiscreteTransferFcn: '<S28>/Zero-cancellation' */
      rtb_radsrpm_f = rtb_Is * Robot_P.Zerocancellation_NumCoef;
      rtb_radsrpm_f /= Robot_P.Zerocancellation_DenCoef;
    }

    /* End of RateTransition: '<S1>/Rate Transition4' */

    /* RateTransition: '<S1>/Rate Transition5' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition5_Buffer[0] = Robot_B.OUTPUT_2_0[2];
      Robot_DW.RateTransition5_Buffer[1] = Robot_B.OUTPUT_2_0[3];
      Robot_DW.RateTransition5_Buffer[2] = Robot_B.OUTPUT_2_0[4];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S28>/Sum1' incorporates:
       *  MinMax: '<S1>/MinMax'
       */
      rtb_radsrpm_f -= fmax(fmax(Robot_DW.RateTransition5_Buffer[0],
        Robot_DW.RateTransition5_Buffer[1]), Robot_DW.RateTransition5_Buffer[2]);

      /* DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S1>/Constant'
       *  Gain: '<S34>/Gain1'
       *  Gain: '<S34>/Gain2'
       *  Sum: '<S34>/Sum1'
       *  UnitDelay: '<S34>/Unit Delay'
       */
      if ((Robot_P.Constant_Value_g > 0.0) &&
          (Robot_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
        Robot_DW.DiscreteTimeIntegrator_DSTATE = Robot_P.PIcontroller_x0;
      }

      Robot_B.DiscreteTimeIntegrator = (Robot_P.Kii * rtb_radsrpm_f +
        Robot_P.BLDCCurrentController_Kaw * Robot_DW.UnitDelay_DSTATE) *
        Robot_P.DiscreteTimeIntegrator_gainval +
        Robot_DW.DiscreteTimeIntegrator_DSTATE;

      /* End of DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */

      /* Sum: '<S34>/Sum' incorporates:
       *  Gain: '<S34>/Gain'
       */
      rtb_Is = Robot_P.Kpi * rtb_radsrpm_f + Robot_B.DiscreteTimeIntegrator;

      /* Saturate: '<S28>/Saturation' */
      if (rtb_Is > Robot_P.Saturation_UpperSat_h) {
        rtb_radsrpm_f = Robot_P.Saturation_UpperSat_h;
      } else if (rtb_Is < Robot_P.Saturation_LowerSat_c) {
        rtb_radsrpm_f = Robot_P.Saturation_LowerSat_c;
      } else {
        rtb_radsrpm_f = rtb_Is;
      }

      /* End of Saturate: '<S28>/Saturation' */

      /* Sum: '<S28>/Sum5' */
      rtb_Sum5 = rtb_radsrpm_f - rtb_Is;

      /* Sum: '<S29>/Sum2' incorporates:
       *  Constant: '<S29>/Constant2'
       *  Gain: '<S29>/Gain'
       *  Product: '<S28>/Product'
       */
      rtb_Sum2[0] = rtb_radsrpm_f * rtb_Product_e_idx_0 * Robot_P.Gain_Gain +
        Robot_P.Constant2_Value_nz;
      rtb_Sum2[1] = rtb_radsrpm_f * rtb_Product_e_idx_1 * Robot_P.Gain_Gain +
        Robot_P.Constant2_Value_nz;
      rtb_Sum2[2] = rtb_radsrpm_f * rtb_Product_e_idx_2 * Robot_P.Gain_Gain +
        Robot_P.Constant2_Value_nz;

      /* Gain: '<S81>/Integral Gain' */
      rtb_IntegralGain = Robot_P.Kip * rtb_Sum_l;
    }

    /* End of RateTransition: '<S1>/Rate Transition5' */

    /* RateTransition: '<S1>/Rate Transition2' incorporates:
     *  RateTransition: '<S2>/Rate Transition6'
     */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_DW.RateTransition2_Buffer = Robot_B.OUTPUT_2_0[0];
      }

      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_DW.RateTransition6_Buffer_p = Robot_B.d1;
      }
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* RelationalOperator: '<S152>/Compare' incorporates:
       *  Constant: '<S149>/Time constant'
       *  Constant: '<S152>/Constant'
       *  Sum: '<S149>/Sum1'
       */
      rtb_Compare_c = (Robot_P.Vdcfilter_T - Robot_B.Probe_e[0] <=
                       Robot_P.Constant_Value_a);

      /* Gain: '<S32>/K' */
      rtb_Is = Robot_P.Vdcfilter_K * Robot_DW.RateTransition2_Buffer;

      /* DiscreteIntegrator: '<S154>/Integrator' */
      if (Robot_DW.Integrator_IC_LOADING != 0) {
        Robot_DW.Integrator_DSTATE_l = rtb_Is;
        if (Robot_DW.Integrator_DSTATE_l >= Robot_P.Integrator_UpperSat) {
          Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_UpperSat;
        } else {
          if (Robot_DW.Integrator_DSTATE_l <= Robot_P.Integrator_LowerSat) {
            Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_LowerSat;
          }
        }
      }

      if (rtb_Compare_c || (Robot_DW.Integrator_PrevResetState_p != 0)) {
        Robot_DW.Integrator_DSTATE_l = rtb_Is;
        if (Robot_DW.Integrator_DSTATE_l >= Robot_P.Integrator_UpperSat) {
          Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_UpperSat;
        } else {
          if (Robot_DW.Integrator_DSTATE_l <= Robot_P.Integrator_LowerSat) {
            Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_LowerSat;
          }
        }
      }

      if (Robot_DW.Integrator_DSTATE_l >= Robot_P.Integrator_UpperSat) {
        Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_UpperSat;
      } else {
        if (Robot_DW.Integrator_DSTATE_l <= Robot_P.Integrator_LowerSat) {
          Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_LowerSat;
        }
      }

      /* Saturate: '<S154>/Saturation' incorporates:
       *  DiscreteIntegrator: '<S154>/Integrator'
       */
      if (Robot_DW.Integrator_DSTATE_l > Robot_P.Saturation_UpperSat_d) {
        rtb_Saturation = Robot_P.Saturation_UpperSat_d;
      } else if (Robot_DW.Integrator_DSTATE_l < Robot_P.Saturation_LowerSat_i) {
        rtb_Saturation = Robot_P.Saturation_LowerSat_i;
      } else {
        rtb_Saturation = Robot_DW.Integrator_DSTATE_l;
      }

      /* End of Saturate: '<S154>/Saturation' */

      /* Relay: '<S1>/Relay' */
      Robot_DW.Relay_Mode = ((rtb_Saturation >= Robot_P.Vdc / 2.0) ||
        ((!(rtb_Saturation <= Robot_P.Vdc / 4.0)) && Robot_DW.Relay_Mode));
      if (Robot_DW.Relay_Mode) {
        rtb_Relay = Robot_P.Relay_YOn;
      } else {
        rtb_Relay = Robot_P.Relay_YOff;
      }

      /* End of Relay: '<S1>/Relay' */

      /* Sum: '<S125>/SumI4' incorporates:
       *  Gain: '<S125>/Kb'
       *  Gain: '<S129>/Integral Gain'
       *  Sum: '<S125>/SumI2'
       */
      rtb_SumI4 = (rtb_Sum3_i - rtb_Integrator_ff) * Robot_P.Speedcontroller_Kb
        + Robot_P.Kiw * rtb_Saturation_m;

      /* MinMax: '<S149>/Max' incorporates:
       *  Constant: '<S149>/Time constant'
       */
      rtb_Sum3_i = fmax(Robot_B.Probe_e[0], Robot_P.Vdcfilter_T);

      /* Product: '<S32>/1//T' incorporates:
       *  Fcn: '<S149>/Avoid Divide by Zero'
       *  Sum: '<S32>/Sum1'
       */
      rtb_uT = 1.0 / ((real_T)(rtb_Sum3_i == 0.0) * 2.2204460492503131e-16 +
                      rtb_Sum3_i) * (rtb_Is - rtb_Saturation);
      rtb_RateTransition6_p = Robot_DW.RateTransition6_Buffer_p;
    }

    /* End of RateTransition: '<S1>/Rate Transition2' */

    /* RateTransition: '<S2>/Rate Transition3' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition3_Buffer_g = Robot_B.OUTPUT_1_0[2];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S2>/Sum3' */
      rtb_Sum3_i = rtb_RateTransition6_p - Robot_DW.RateTransition3_Buffer_g;

      /* Sum: '<S220>/Sum' incorporates:
       *  DiscreteIntegrator: '<S211>/Integrator'
       *  Gain: '<S216>/Proportional Gain'
       */
      rtb_Saturation_m = Robot_P.Kpp * rtb_Sum3_i + Robot_DW.Integrator_DSTATE_m;
    }

    /* End of RateTransition: '<S2>/Rate Transition3' */

    /* RateTransition: '<S2>/Rate Transition1' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition1_Buffer_m = Robot_B.OUTPUT_1_0[3];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Gain: '<S2>/rad//s->rpm' */
      rtb_radsrpm_f = Robot_P.radsrpm_Gain_n * Robot_DW.RateTransition1_Buffer_m;

      /* Sum: '<S2>/Sum' */
      rtb_Sum_l = rtb_Saturation_m - rtb_radsrpm_f;

      /* Sum: '<S268>/Sum' incorporates:
       *  DiscreteIntegrator: '<S259>/Integrator'
       *  Gain: '<S264>/Proportional Gain'
       */
      rtb_Sum_i = Robot_P.Kpw * rtb_Sum_l + Robot_DW.Integrator_DSTATE_f;

      /* Saturate: '<S266>/Saturation' */
      if (rtb_Sum_i > Robot_P.Speedcontroller_UpperSaturati_o) {
        rtb_Max = Robot_P.Speedcontroller_UpperSaturati_o;
      } else if (rtb_Sum_i < Robot_P.Speedcontroller_LowerSaturati_f) {
        rtb_Max = Robot_P.Speedcontroller_LowerSaturati_f;
      } else {
        rtb_Max = rtb_Sum_i;
      }

      /* End of Saturate: '<S266>/Saturation' */

      /* Abs: '<S2>/Abs' */
      rtb_Is_i = fabs(rtb_Max);
    }

    /* End of RateTransition: '<S2>/Rate Transition1' */

    /* SimscapeInputBlock: '<S324>/INTERNAL_1_1_1' */
    Robot_B.INTERNAL_1_1_1[0] = Robot_B.OUTPUT_1_0[3];
    Robot_B.INTERNAL_1_1_1[1] = 0.0;
    Robot_B.INTERNAL_1_1_1[2] = 0.0;
    Robot_B.INTERNAL_1_1_1[3] = 0.0;

    /* RateTransition: '<S156>/Rate Transition4' incorporates:
     *  DataTypeConversion: '<S164>/Data Type Conversion2'
     */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_B.RateTransition4_b[0] = Robot_DW.RateTransition4_Buffer0_h[0];
        Robot_B.RateTransition4_b[1] = Robot_DW.RateTransition4_Buffer0_h[1];
        Robot_B.RateTransition4_b[2] = Robot_DW.RateTransition4_Buffer0_h[2];
      }

      /* Logic: '<S172>/Logical Operator' incorporates:
       *  Constant: '<S173>/Constant'
       *  Constant: '<S174>/Constant'
       *  RelationalOperator: '<S173>/Compare'
       *  RelationalOperator: '<S174>/Compare'
       */
      rtb_LogicalOperator_c = ((Robot_DW.Integrator_DSTATE_fd <
        Robot_P.IntegratorwithWrappedStateDis_g) ||
        (Robot_DW.Integrator_DSTATE_fd >= Robot_P.Tsc));

      /* InitialCondition: '<S172>/Initial' incorporates:
       *  Constant: '<S175>/Constant'
       *  Gain: '<S175>/Gain'
       *  Gain: '<S175>/Gain1'
       *  Rounding: '<S175>/Rounding Function'
       *  Sum: '<S175>/Sum'
       *  Sum: '<S175>/Sum1'
       */
      if (Robot_DW.Initial_FirstOutputTime_k) {
        Robot_DW.Initial_FirstOutputTime_k = false;
        Robot_B.Initial_f = Robot_P.Initial_Value_ic;
      } else {
        /* Gain: '<S175>/Gain' incorporates:
         *  Gain: '<S175>/Gain1'
         */
        rtb_Integrator_ff = Robot_P.Tsc -
          Robot_P.IntegratorwithWrappedStateDis_g;
        Robot_B.Initial_f = Robot_DW.Integrator_DSTATE_fd - floor(1.0 /
          rtb_Integrator_ff * (Robot_DW.Integrator_DSTATE_fd -
          Robot_P.IntegratorwithWrappedStateDis_g)) * rtb_Integrator_ff;
      }

      /* End of InitialCondition: '<S172>/Initial' */

      /* DiscreteIntegrator: '<S172>/Integrator' */
      if (rtb_LogicalOperator_c && (Robot_DW.Integrator_PrevResetState_l <= 0))
      {
        Robot_DW.Integrator_DSTATE_fd = Robot_B.Initial_f;
      }

      rtb_Integrator_c = Robot_DW.Integrator_DSTATE_fd;

      /* End of DiscreteIntegrator: '<S172>/Integrator' */

      /* Logic: '<S176>/Logical Operator' incorporates:
       *  Constant: '<S177>/Constant'
       *  Constant: '<S178>/Constant'
       *  RelationalOperator: '<S177>/Compare'
       *  RelationalOperator: '<S178>/Compare'
       */
      rtb_LogicalOperator_p = ((Robot_DW.Integrator_DSTATE_fo <
        Robot_P.IntegratorwithWrappedStateDis_a) ||
        (Robot_DW.Integrator_DSTATE_fo >= 2.0 * Robot_P.Tsc));

      /* InitialCondition: '<S176>/Initial' incorporates:
       *  Constant: '<S179>/Constant'
       *  Gain: '<S179>/Gain'
       *  Gain: '<S179>/Gain1'
       *  Rounding: '<S179>/Rounding Function'
       *  Sum: '<S179>/Sum'
       *  Sum: '<S179>/Sum1'
       */
      if (Robot_DW.Initial_FirstOutputTime_b) {
        Robot_DW.Initial_FirstOutputTime_b = false;
        Robot_B.Initial_l = Robot_P.Initial_Value_b;
      } else {
        /* Gain: '<S179>/Gain' incorporates:
         *  Gain: '<S179>/Gain1'
         */
        rtb_Integrator_ff = 2.0 * Robot_P.Tsc -
          Robot_P.IntegratorwithWrappedStateDis_a;
        Robot_B.Initial_l = Robot_DW.Integrator_DSTATE_fo - floor(1.0 /
          rtb_Integrator_ff * (Robot_DW.Integrator_DSTATE_fo -
          Robot_P.IntegratorwithWrappedStateDis_a)) * rtb_Integrator_ff;
      }

      /* End of InitialCondition: '<S176>/Initial' */

      /* DiscreteIntegrator: '<S176>/Integrator' */
      if (rtb_LogicalOperator_p && (Robot_DW.Integrator_PrevResetState_c <= 0))
      {
        Robot_DW.Integrator_DSTATE_fo = Robot_B.Initial_l;
      }

      /* MultiPortSwitch: '<S165>/Multiport Switch' incorporates:
       *  Constant: '<S165>/Constant2'
       *  Constant: '<S165>/Constant6'
       *  Constant: '<S171>/Constant'
       *  Product: '<S171>/Product'
       *  Product: '<S171>/Product1'
       *  Sum: '<S165>/Sum3'
       *  Sum: '<S165>/Sum5'
       *  Sum: '<S171>/Sum'
       */
      switch ((int32_T)Robot_P.Carriercounter_CarrCount_e) {
       case 1:
        rtb_Sum4_k = Robot_P.Tsc / (Robot_P.Tsc - Robot_B.Probe_b[0]) *
          rtb_Integrator_c;
        break;

       case 2:
        rtb_Sum4_k = Robot_P.Tsc - Robot_P.Tsc / (Robot_P.Tsc - Robot_B.Probe_b
          [0]) * rtb_Integrator_c;
        break;

       default:
        /* Sum: '<S165>/Sum4' incorporates:
         *  Constant: '<S165>/Constant10'
         *  DiscreteIntegrator: '<S176>/Integrator'
         */
        rtb_Integrator_ff = 2.0 * Robot_P.Tsc - Robot_DW.Integrator_DSTATE_fo;

        /* Switch: '<S169>/Switch' incorporates:
         *  Constant: '<S169>/Constant2'
         *  DiscreteIntegrator: '<S176>/Integrator'
         */
        if (Robot_DW.Integrator_DSTATE_fo > Robot_P.Tsc) {
          tmp_d = Robot_P.Constant2_Value_l;
        } else {
          tmp_d = Robot_DW.Integrator_DSTATE_fo;
        }

        /* End of Switch: '<S169>/Switch' */

        /* Switch: '<S170>/Switch' incorporates:
         *  Constant: '<S170>/Constant2'
         */
        if (rtb_Integrator_ff > Robot_P.Tsc) {
          rtb_Integrator_ff = Robot_P.Constant2_Value_m;
        }

        /* End of Switch: '<S170>/Switch' */
        rtb_Sum4_k = tmp_d + rtb_Integrator_ff;
        break;
      }

      /* End of MultiPortSwitch: '<S165>/Multiport Switch' */

      /* Gain: '<S165>/Gain1' */
      rtb_Sum4_k *= 1.0 / Robot_P.Tsc;

      /* Saturate: '<S165>/Saturation' */
      if (rtb_Sum4_k > Robot_P.Saturation_UpperSat_l) {
        rtb_Sum4_k = Robot_P.Saturation_UpperSat_l;
      } else {
        if (rtb_Sum4_k < Robot_P.Saturation_LowerSat_d) {
          rtb_Sum4_k = Robot_P.Saturation_LowerSat_d;
        }
      }

      /* End of Saturate: '<S165>/Saturation' */

      /* Bias: '<S165>/Bias' incorporates:
       *  Gain: '<S165>/Gain'
       */
      rtb_Integrator_ff = Robot_P.Carriercounter_Range_g * rtb_Sum4_k +
        (-Robot_P.Carriercounter_Range_g + 1.0);

      /* DataTypeConversion: '<S164>/Data Type Conversion2' incorporates:
       *  Constant: '<S166>/Constant'
       *  Logic: '<S164>/Logical Operator'
       *  RelationalOperator: '<S164>/Relational Operator'
       *  RelationalOperator: '<S166>/Compare'
       */
      rtb_DataTypeConversion1 = ((Robot_B.RateTransition4_b[0] !=
        Robot_P.Constant_Value_b) && (Robot_B.RateTransition4_b[0] >=
        rtb_Integrator_ff));

      /* DataTypeConversion: '<S163>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S163>/Data Type Conversion'
       *  Logic: '<S163>/Logical Operator'
       */
      rtb_DataTypeConversion1_idx_0 = (rtb_DataTypeConversion1 == 0);
      rtb_DataTypeConversion2_idx_0 = rtb_DataTypeConversion1;

      /* DataTypeConversion: '<S164>/Data Type Conversion2' incorporates:
       *  Constant: '<S166>/Constant'
       *  Logic: '<S164>/Logical Operator'
       *  RelationalOperator: '<S164>/Relational Operator'
       *  RelationalOperator: '<S166>/Compare'
       */
      rtb_DataTypeConversion1 = ((Robot_B.RateTransition4_b[1] !=
        Robot_P.Constant_Value_b) && (Robot_B.RateTransition4_b[1] >=
        rtb_Integrator_ff));

      /* DataTypeConversion: '<S163>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S163>/Data Type Conversion'
       *  Logic: '<S163>/Logical Operator'
       */
      rtb_DataTypeConversion1_idx_1 = (rtb_DataTypeConversion1 == 0);
      rtb_DataTypeConversion2_idx_1 = rtb_DataTypeConversion1;

      /* DataTypeConversion: '<S164>/Data Type Conversion2' incorporates:
       *  Constant: '<S166>/Constant'
       *  Logic: '<S164>/Logical Operator'
       *  RelationalOperator: '<S164>/Relational Operator'
       *  RelationalOperator: '<S166>/Compare'
       */
      rtb_DataTypeConversion1 = ((Robot_B.RateTransition4_b[2] !=
        Robot_P.Constant_Value_b) && (Robot_B.RateTransition4_b[2] >=
        rtb_Integrator_ff));

      /* RateTransition: '<S156>/Rate Transition7' */
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_B.RateTransition7_l = Robot_DW.RateTransition7_Buffer0_j;
      }

      /* End of RateTransition: '<S156>/Rate Transition7' */

      /* Product: '<S156>/Product1' incorporates:
       *  DataTypeConversion: '<S163>/Data Type Conversion'
       *  Logic: '<S163>/Logical Operator'
       */
      Robot_B.Product1_n[0] = (real_T)rtb_DataTypeConversion2_idx_0 *
        Robot_B.RateTransition7_l;
      Robot_B.Product1_n[1] = (real_T)rtb_DataTypeConversion1_idx_0 *
        Robot_B.RateTransition7_l;
      Robot_B.Product1_n[2] = (real_T)rtb_DataTypeConversion2_idx_1 *
        Robot_B.RateTransition7_l;
      Robot_B.Product1_n[3] = (real_T)rtb_DataTypeConversion1_idx_1 *
        Robot_B.RateTransition7_l;
      Robot_B.Product1_n[4] = (real_T)rtb_DataTypeConversion1 *
        Robot_B.RateTransition7_l;
      Robot_B.Product1_n[5] = (real_T)(rtb_DataTypeConversion1 == 0) *
        Robot_B.RateTransition7_l;
    }

    /* End of RateTransition: '<S156>/Rate Transition4' */

    /* SimscapeInputBlock: '<S324>/INPUT_7_1_1' */
    Robot_B.INPUT_7_1_1[0] = Robot_B.Product1_n[0];
    Robot_B.INPUT_7_1_1[1] = 0.0;
    Robot_B.INPUT_7_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_7_1_1_Discrete[0] = !(Robot_B.INPUT_7_1_1[0] ==
        Robot_DW.INPUT_7_1_1_Discrete[1]);
      Robot_DW.INPUT_7_1_1_Discrete[1] = Robot_B.INPUT_7_1_1[0];
    }

    Robot_B.INPUT_7_1_1[0] = Robot_DW.INPUT_7_1_1_Discrete[1];
    Robot_B.INPUT_7_1_1[3] = Robot_DW.INPUT_7_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_7_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_8_1_1' */
    Robot_B.INPUT_8_1_1[0] = Robot_B.Product1_n[1];
    Robot_B.INPUT_8_1_1[1] = 0.0;
    Robot_B.INPUT_8_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_8_1_1_Discrete[0] = !(Robot_B.INPUT_8_1_1[0] ==
        Robot_DW.INPUT_8_1_1_Discrete[1]);
      Robot_DW.INPUT_8_1_1_Discrete[1] = Robot_B.INPUT_8_1_1[0];
    }

    Robot_B.INPUT_8_1_1[0] = Robot_DW.INPUT_8_1_1_Discrete[1];
    Robot_B.INPUT_8_1_1[3] = Robot_DW.INPUT_8_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_8_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_9_1_1' */
    Robot_B.INPUT_9_1_1[0] = Robot_B.Product1_n[2];
    Robot_B.INPUT_9_1_1[1] = 0.0;
    Robot_B.INPUT_9_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_9_1_1_Discrete[0] = !(Robot_B.INPUT_9_1_1[0] ==
        Robot_DW.INPUT_9_1_1_Discrete[1]);
      Robot_DW.INPUT_9_1_1_Discrete[1] = Robot_B.INPUT_9_1_1[0];
    }

    Robot_B.INPUT_9_1_1[0] = Robot_DW.INPUT_9_1_1_Discrete[1];
    Robot_B.INPUT_9_1_1[3] = Robot_DW.INPUT_9_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_9_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_10_1_1' */
    Robot_B.INPUT_10_1_1[0] = Robot_B.Product1_n[3];
    Robot_B.INPUT_10_1_1[1] = 0.0;
    Robot_B.INPUT_10_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_10_1_1_Discrete[0] = !(Robot_B.INPUT_10_1_1[0] ==
        Robot_DW.INPUT_10_1_1_Discrete[1]);
      Robot_DW.INPUT_10_1_1_Discrete[1] = Robot_B.INPUT_10_1_1[0];
    }

    Robot_B.INPUT_10_1_1[0] = Robot_DW.INPUT_10_1_1_Discrete[1];
    Robot_B.INPUT_10_1_1[3] = Robot_DW.INPUT_10_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_10_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_11_1_1' */
    Robot_B.INPUT_11_1_1[0] = Robot_B.Product1_n[4];
    Robot_B.INPUT_11_1_1[1] = 0.0;
    Robot_B.INPUT_11_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_11_1_1_Discrete[0] = !(Robot_B.INPUT_11_1_1[0] ==
        Robot_DW.INPUT_11_1_1_Discrete[1]);
      Robot_DW.INPUT_11_1_1_Discrete[1] = Robot_B.INPUT_11_1_1[0];
    }

    Robot_B.INPUT_11_1_1[0] = Robot_DW.INPUT_11_1_1_Discrete[1];
    Robot_B.INPUT_11_1_1[3] = Robot_DW.INPUT_11_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_11_1_1' */

    /* SimscapeInputBlock: '<S324>/INPUT_12_1_1' */
    Robot_B.INPUT_12_1_1[0] = Robot_B.Product1_n[5];
    Robot_B.INPUT_12_1_1[1] = 0.0;
    Robot_B.INPUT_12_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Robot_M)) {
      Robot_DW.INPUT_12_1_1_Discrete[0] = !(Robot_B.INPUT_12_1_1[0] ==
        Robot_DW.INPUT_12_1_1_Discrete[1]);
      Robot_DW.INPUT_12_1_1_Discrete[1] = Robot_B.INPUT_12_1_1[0];
    }

    Robot_B.INPUT_12_1_1[0] = Robot_DW.INPUT_12_1_1_Discrete[1];
    Robot_B.INPUT_12_1_1[3] = Robot_DW.INPUT_12_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S324>/INPUT_12_1_1' */

    /* SimscapeExecutionBlock: '<S324>/STATE_3' */
    simulationData = (NeslSimulationData *)Robot_DW.STATE_3_SimData;
    time_3 = rtb_Sign_o;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 24;
    simulationData->mData->mContStates.mX =
      &Robot_X.RobotBLDC1pm_dq0_Xabcangular_po[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_3_Discrete;
    simulationData->mData->mModeVector.mN = 27;
    simulationData->mData->mModeVector.mX = &Robot_DW.STATE_3_Modes[0];
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_a[0] = 0;
    tmp_9[0] = Robot_B.INTERNAL_1_1_1[0];
    tmp_9[1] = Robot_B.INTERNAL_1_1_1[1];
    tmp_9[2] = Robot_B.INTERNAL_1_1_1[2];
    tmp_9[3] = Robot_B.INTERNAL_1_1_1[3];
    tmp_a[1] = 4;
    tmp_9[4] = Robot_B.INPUT_7_1_1[0];
    tmp_9[5] = Robot_B.INPUT_7_1_1[1];
    tmp_9[6] = Robot_B.INPUT_7_1_1[2];
    tmp_9[7] = Robot_B.INPUT_7_1_1[3];
    tmp_a[2] = 8;
    tmp_9[8] = Robot_B.INPUT_8_1_1[0];
    tmp_9[9] = Robot_B.INPUT_8_1_1[1];
    tmp_9[10] = Robot_B.INPUT_8_1_1[2];
    tmp_9[11] = Robot_B.INPUT_8_1_1[3];
    tmp_a[3] = 12;
    tmp_9[12] = Robot_B.INPUT_9_1_1[0];
    tmp_9[13] = Robot_B.INPUT_9_1_1[1];
    tmp_9[14] = Robot_B.INPUT_9_1_1[2];
    tmp_9[15] = Robot_B.INPUT_9_1_1[3];
    tmp_a[4] = 16;
    tmp_9[16] = Robot_B.INPUT_10_1_1[0];
    tmp_9[17] = Robot_B.INPUT_10_1_1[1];
    tmp_9[18] = Robot_B.INPUT_10_1_1[2];
    tmp_9[19] = Robot_B.INPUT_10_1_1[3];
    tmp_a[5] = 20;
    tmp_9[20] = Robot_B.INPUT_11_1_1[0];
    tmp_9[21] = Robot_B.INPUT_11_1_1[1];
    tmp_9[22] = Robot_B.INPUT_11_1_1[2];
    tmp_9[23] = Robot_B.INPUT_11_1_1[3];
    tmp_a[6] = 24;
    tmp_9[24] = Robot_B.INPUT_12_1_1[0];
    tmp_9[25] = Robot_B.INPUT_12_1_1[1];
    tmp_9[26] = Robot_B.INPUT_12_1_1[2];
    tmp_9[27] = Robot_B.INPUT_12_1_1[3];
    tmp_a[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &tmp_9[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_a[0];
    simulationData->mData->mOutputs.mN = 51;
    simulationData->mData->mOutputs.mX = &Robot_B.STATE_3[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_3_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    rtb_DataTypeConversion2_idx_0 = ne_simulator_method((NeslSimulator *)
      Robot_DW.STATE_3_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (rtb_DataTypeConversion2_idx_0 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* SimscapeExecutionBlock: '<S324>/OUTPUT_3_0' */
    simulationData = (NeslSimulationData *)Robot_DW.OUTPUT_3_0_SimData;
    time_4 = rtb_Sign_o;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.OUTPUT_3_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &Robot_DW.OUTPUT_3_0_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_c[0] = 0;
    tmp_b[0] = Robot_B.INTERNAL_1_1_1[0];
    tmp_b[1] = Robot_B.INTERNAL_1_1_1[1];
    tmp_b[2] = Robot_B.INTERNAL_1_1_1[2];
    tmp_b[3] = Robot_B.INTERNAL_1_1_1[3];
    tmp_c[1] = 4;
    tmp_b[4] = Robot_B.INPUT_7_1_1[0];
    tmp_b[5] = Robot_B.INPUT_7_1_1[1];
    tmp_b[6] = Robot_B.INPUT_7_1_1[2];
    tmp_b[7] = Robot_B.INPUT_7_1_1[3];
    tmp_c[2] = 8;
    tmp_b[8] = Robot_B.INPUT_8_1_1[0];
    tmp_b[9] = Robot_B.INPUT_8_1_1[1];
    tmp_b[10] = Robot_B.INPUT_8_1_1[2];
    tmp_b[11] = Robot_B.INPUT_8_1_1[3];
    tmp_c[3] = 12;
    tmp_b[12] = Robot_B.INPUT_9_1_1[0];
    tmp_b[13] = Robot_B.INPUT_9_1_1[1];
    tmp_b[14] = Robot_B.INPUT_9_1_1[2];
    tmp_b[15] = Robot_B.INPUT_9_1_1[3];
    tmp_c[4] = 16;
    tmp_b[16] = Robot_B.INPUT_10_1_1[0];
    tmp_b[17] = Robot_B.INPUT_10_1_1[1];
    tmp_b[18] = Robot_B.INPUT_10_1_1[2];
    tmp_b[19] = Robot_B.INPUT_10_1_1[3];
    tmp_c[5] = 20;
    tmp_b[20] = Robot_B.INPUT_11_1_1[0];
    tmp_b[21] = Robot_B.INPUT_11_1_1[1];
    tmp_b[22] = Robot_B.INPUT_11_1_1[2];
    tmp_b[23] = Robot_B.INPUT_11_1_1[3];
    tmp_c[6] = 24;
    tmp_b[24] = Robot_B.INPUT_12_1_1[0];
    tmp_b[25] = Robot_B.INPUT_12_1_1[1];
    tmp_b[26] = Robot_B.INPUT_12_1_1[2];
    tmp_b[27] = Robot_B.INPUT_12_1_1[3];
    tmp_c[7] = 28;
    memcpy(&tmp_b[28], &Robot_B.STATE_3[0], 51U * sizeof(real_T));
    tmp_c[8] = 79;
    simulationData->mData->mInputValues.mN = 79;
    simulationData->mData->mInputValues.mX = &tmp_b[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_c[0];
    simulationData->mData->mOutputs.mN = 6;
    simulationData->mData->mOutputs.mX = &Robot_B.OUTPUT_3_0[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.OUTPUT_3_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    rtb_DataTypeConversion2_idx_0 = ne_simulator_method((NeslSimulator *)
      Robot_DW.OUTPUT_3_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (rtb_DataTypeConversion2_idx_0 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* Gain: '<S307>/mech->elec' */
    rtb_Sum4_k = Robot_P.p * Robot_B.OUTPUT_3_0[1];

    /* Gain: '<S307>/rad->deg' incorporates:
     *  Trigonometry: '<S307>/Trigonometric Function'
     *  Trigonometry: '<S307>/Trigonometric Function2'
     */
    rtb_Sum4_k = Robot_P.raddeg_Gain_f * rt_atan2d_snf(sin(rtb_Sum4_k), cos
      (rtb_Sum4_k));

    /* Logic: '<S11>/Logical Operator' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  RelationalOperator: '<S11>/Relational Operator1'
     *  RelationalOperator: '<S11>/Relational Operator2'
     */
    Robot_B.LogicalOperator_m = ((rtb_Sum4_k >= Robot_P.Constant_Value_bq) &&
      (rtb_Sum4_k <= Robot_P.Constant1_Value_l));

    /* Logic: '<S11>/Logical Operator1' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant3'
     *  RelationalOperator: '<S11>/Relational Operator3'
     *  RelationalOperator: '<S11>/Relational Operator4'
     */
    Robot_B.LogicalOperator1_g = ((rtb_Sum4_k >= Robot_P.Constant2_Value_c) ||
      (rtb_Sum4_k <= Robot_P.Constant3_Value_k));

    /* Logic: '<S11>/Logical Operator2' incorporates:
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S11>/Constant5'
     *  RelationalOperator: '<S11>/Relational Operator5'
     *  RelationalOperator: '<S11>/Relational Operator6'
     */
    Robot_B.LogicalOperator2_a = ((rtb_Sum4_k >= Robot_P.Constant4_Value_h) &&
      (rtb_Sum4_k <= Robot_P.Constant5_Value_e));

    /* RateTransition: '<S2>/Rate Transition4' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition4_Buffer_m[0] = Robot_B.LogicalOperator_m;
      Robot_DW.RateTransition4_Buffer_m[1] = Robot_B.LogicalOperator1_g;
      Robot_DW.RateTransition4_Buffer_m[2] = Robot_B.LogicalOperator2_a;
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* LookupNDDirect: '<S160>/Direct Lookup Table (n-D)2' incorporates:
       *  DataTypeConversion: '<S160>/Data Type Conversion'
       *  Gain: '<S162>/Gain'
       *
       * About '<S160>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_DataTypeConversion2_idx_0 = (int32_T)((uint32_T)(uint8_T)((uint32_T)
        (uint8_T)((uint32_T)(uint8_T)(Robot_DW.RateTransition4_Buffer_m[0] ?
        (int32_T)Robot_P.Gain_Gain_g[0] : 0) +
                  (Robot_DW.RateTransition4_Buffer_m[1] ? (int32_T)
                   Robot_P.Gain_Gain_g[1] : 0)) +
        (Robot_DW.RateTransition4_Buffer_m[2] ? (int32_T)Robot_P.Gain_Gain_g[2] :
         0)) >> 5) * 3;

      /* Signum: '<S2>/Sign' */
      if (rtb_Saturation_m < 0.0) {
        rtb_Sign_o = -1.0;
      } else if (rtb_Saturation_m > 0.0) {
        rtb_Sign_o = 1.0;
      } else if (rtb_Saturation_m == 0.0) {
        rtb_Sign_o = 0.0;
      } else {
        rtb_Sign_o = (rtNaN);
      }

      /* End of Signum: '<S2>/Sign' */

      /* Product: '<S160>/Product' incorporates:
       *  LookupNDDirect: '<S160>/Direct Lookup Table (n-D)2'
       *
       * About '<S160>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtb_Product_mc_idx_0 =
        Robot_P.DirectLookupTablenD2_table_b[rtb_DataTypeConversion2_idx_0] *
        rtb_Sign_o;
      rtb_Product_mc_idx_1 =
        Robot_P.DirectLookupTablenD2_table_b[rtb_DataTypeConversion2_idx_0 + 1] *
        rtb_Sign_o;
      rtb_Product_mc_idx_2 =
        Robot_P.DirectLookupTablenD2_table_b[rtb_DataTypeConversion2_idx_0 + 2] *
        rtb_Sign_o;

      /* DiscreteTransferFcn: '<S155>/Zero-cancellation' */
      rtb_Saturation_m = rtb_Is_i * Robot_P.Zerocancellation_NumCoef_k /
        Robot_P.Zerocancellation_DenCoef_p;
    }

    /* End of RateTransition: '<S2>/Rate Transition4' */

    /* RateTransition: '<S2>/Rate Transition5' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition5_Buffer_g[0] = Robot_B.OUTPUT_3_0[2];
      Robot_DW.RateTransition5_Buffer_g[1] = Robot_B.OUTPUT_3_0[3];
      Robot_DW.RateTransition5_Buffer_g[2] = Robot_B.OUTPUT_3_0[4];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S155>/Sum1' incorporates:
       *  MinMax: '<S2>/MinMax'
       */
      rtb_Saturation_m -= fmax(fmax(Robot_DW.RateTransition5_Buffer_g[0],
        Robot_DW.RateTransition5_Buffer_g[1]),
        Robot_DW.RateTransition5_Buffer_g[2]);

      /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S2>/Constant'
       *  Gain: '<S161>/Gain1'
       *  Gain: '<S161>/Gain2'
       *  Sum: '<S161>/Sum1'
       *  UnitDelay: '<S161>/Unit Delay'
       */
      if ((Robot_P.Constant_Value_ff > 0.0) &&
          (Robot_DW.DiscreteTimeIntegrator_PrevRe_c <= 0)) {
        Robot_DW.DiscreteTimeIntegrator_DSTATE_a = Robot_P.PIcontroller_x0_i;
      }

      Robot_B.DiscreteTimeIntegrator_f = (Robot_P.Kii * rtb_Saturation_m +
        Robot_P.BLDCCurrentController_Kaw_g * Robot_DW.UnitDelay_DSTATE_c) *
        Robot_P.DiscreteTimeIntegrator_gainva_e +
        Robot_DW.DiscreteTimeIntegrator_DSTATE_a;

      /* End of DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */

      /* Sum: '<S161>/Sum' incorporates:
       *  Gain: '<S161>/Gain'
       */
      rtb_Is_i = Robot_P.Kpi * rtb_Saturation_m +
        Robot_B.DiscreteTimeIntegrator_f;

      /* Saturate: '<S155>/Saturation' */
      if (rtb_Is_i > Robot_P.Saturation_UpperSat_n) {
        rtb_Saturation_m = Robot_P.Saturation_UpperSat_n;
      } else if (rtb_Is_i < Robot_P.Saturation_LowerSat_m) {
        rtb_Saturation_m = Robot_P.Saturation_LowerSat_m;
      } else {
        rtb_Saturation_m = rtb_Is_i;
      }

      /* End of Saturate: '<S155>/Saturation' */

      /* Sum: '<S155>/Sum5' */
      rtb_Sum5_m = rtb_Saturation_m - rtb_Is_i;

      /* Sum: '<S156>/Sum2' incorporates:
       *  Constant: '<S156>/Constant2'
       *  Gain: '<S156>/Gain'
       *  Product: '<S155>/Product'
       */
      rtb_Sum2_a[0] = rtb_Saturation_m * rtb_Product_mc_idx_0 *
        Robot_P.Gain_Gain_p + Robot_P.Constant2_Value_lv;
      rtb_Sum2_a[1] = rtb_Saturation_m * rtb_Product_mc_idx_1 *
        Robot_P.Gain_Gain_p + Robot_P.Constant2_Value_lv;
      rtb_Sum2_a[2] = rtb_Saturation_m * rtb_Product_mc_idx_2 *
        Robot_P.Gain_Gain_p + Robot_P.Constant2_Value_lv;

      /* Gain: '<S208>/Integral Gain' */
      rtb_IntegralGain_o = Robot_P.Kip * rtb_Sum3_i;
    }

    /* End of RateTransition: '<S2>/Rate Transition5' */

    /* RateTransition: '<S2>/Rate Transition2' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition2_Buffer_a = Robot_B.OUTPUT_3_0[0];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* RelationalOperator: '<S279>/Compare' incorporates:
       *  Constant: '<S276>/Time constant'
       *  Constant: '<S279>/Constant'
       *  Sum: '<S276>/Sum1'
       */
      rtb_Compare_pr = (Robot_P.Vdcfilter_T_i - Robot_B.Probe_m[0] <=
                        Robot_P.Constant_Value_h);

      /* Gain: '<S159>/K' */
      rtb_Saturation_m = Robot_P.Vdcfilter_K_a *
        Robot_DW.RateTransition2_Buffer_a;

      /* DiscreteIntegrator: '<S281>/Integrator' */
      if (Robot_DW.Integrator_IC_LOADING_g != 0) {
        Robot_DW.Integrator_DSTATE_lq = rtb_Saturation_m;
        if (Robot_DW.Integrator_DSTATE_lq >= Robot_P.Integrator_UpperSat_d) {
          Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_UpperSat_d;
        } else {
          if (Robot_DW.Integrator_DSTATE_lq <= Robot_P.Integrator_LowerSat_k) {
            Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_LowerSat_k;
          }
        }
      }

      if (rtb_Compare_pr || (Robot_DW.Integrator_PrevResetState_a != 0)) {
        Robot_DW.Integrator_DSTATE_lq = rtb_Saturation_m;
        if (Robot_DW.Integrator_DSTATE_lq >= Robot_P.Integrator_UpperSat_d) {
          Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_UpperSat_d;
        } else {
          if (Robot_DW.Integrator_DSTATE_lq <= Robot_P.Integrator_LowerSat_k) {
            Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_LowerSat_k;
          }
        }
      }

      if (Robot_DW.Integrator_DSTATE_lq >= Robot_P.Integrator_UpperSat_d) {
        Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_UpperSat_d;
      } else {
        if (Robot_DW.Integrator_DSTATE_lq <= Robot_P.Integrator_LowerSat_k) {
          Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_LowerSat_k;
        }
      }

      /* Saturate: '<S281>/Saturation' incorporates:
       *  DiscreteIntegrator: '<S281>/Integrator'
       */
      if (Robot_DW.Integrator_DSTATE_lq > Robot_P.Saturation_UpperSat_b) {
        rtb_Saturation_j = Robot_P.Saturation_UpperSat_b;
      } else if (Robot_DW.Integrator_DSTATE_lq < Robot_P.Saturation_LowerSat_o)
      {
        rtb_Saturation_j = Robot_P.Saturation_LowerSat_o;
      } else {
        rtb_Saturation_j = Robot_DW.Integrator_DSTATE_lq;
      }

      /* End of Saturate: '<S281>/Saturation' */

      /* Relay: '<S2>/Relay' */
      Robot_DW.Relay_Mode_h = ((rtb_Saturation_j >= Robot_P.Vdc / 2.0) ||
        ((!(rtb_Saturation_j <= Robot_P.Vdc / 4.0)) && Robot_DW.Relay_Mode_h));
      if (Robot_DW.Relay_Mode_h) {
        rtb_Relay_k = Robot_P.Relay_YOn_n;
      } else {
        rtb_Relay_k = Robot_P.Relay_YOff_j;
      }

      /* End of Relay: '<S2>/Relay' */

      /* Sum: '<S252>/SumI4' incorporates:
       *  Gain: '<S252>/Kb'
       *  Gain: '<S256>/Integral Gain'
       *  Sum: '<S252>/SumI2'
       */
      rtb_SumI4_k = (rtb_Max - rtb_Sum_i) * Robot_P.Speedcontroller_Kb_n +
        Robot_P.Kiw * rtb_Sum_l;

      /* MinMax: '<S276>/Max' incorporates:
       *  Constant: '<S276>/Time constant'
       */
      rtb_Max = fmax(Robot_B.Probe_m[0], Robot_P.Vdcfilter_T_i);

      /* Product: '<S159>/1//T' incorporates:
       *  Fcn: '<S276>/Avoid Divide by Zero'
       *  Sum: '<S159>/Sum1'
       */
      rtb_uT_i = 1.0 / ((real_T)(rtb_Max == 0.0) * 2.2204460492503131e-16 +
                        rtb_Max) * (rtb_Saturation_m - rtb_Saturation_j);
    }

    /* End of RateTransition: '<S2>/Rate Transition2' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      /* RateTransition: '<S23>/Rate Transition3' */
      if (rtmIsMajorTimeStep(Robot_M) &&
          Robot_M->Timing.TaskCounters.TID[2] == 0) {
        Robot_DW.RateTransition3_Buffer_e = Robot_B.OUTPUT_1_0[4];
      }
    }

    /* RateTransition: '<S23>/Rate Transition3' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      rtb_RateTransition3_g = Robot_DW.RateTransition3_Buffer_e;
    }

    /* RateTransition: '<S23>/Rate Transition2' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition2_Buffer_a1[0] = Robot_B.OUTPUT_2_0[2];
      Robot_DW.RateTransition2_Buffer_a1[1] = Robot_B.OUTPUT_2_0[3];
      Robot_DW.RateTransition2_Buffer_a1[2] = Robot_B.OUTPUT_2_0[4];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      rtb_PhasecurrentsA[0] = Robot_DW.RateTransition2_Buffer_a1[0];
      rtb_PhasecurrentsA[1] = Robot_DW.RateTransition2_Buffer_a1[1];
      rtb_PhasecurrentsA[2] = Robot_DW.RateTransition2_Buffer_a1[2];
    }

    /* End of RateTransition: '<S23>/Rate Transition2' */

    /* RateTransition: '<S24>/Rate Transition3' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition3_Buffer_m = Robot_B.OUTPUT_1_0[2];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      rtb_RateTransition3_a = Robot_DW.RateTransition3_Buffer_m;
    }

    /* End of RateTransition: '<S24>/Rate Transition3' */

    /* RateTransition: '<S24>/Rate Transition2' */
    if ((rtmIsMajorTimeStep(Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
         (Robot_M) &&
         Robot_M->Timing.TaskCounters.TID[2] == 0)) {
      Robot_DW.RateTransition2_Buffer_m[0] = Robot_B.OUTPUT_3_0[2];
      Robot_DW.RateTransition2_Buffer_m[1] = Robot_B.OUTPUT_3_0[3];
      Robot_DW.RateTransition2_Buffer_m[2] = Robot_B.OUTPUT_3_0[4];
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      rtb_PhasecurrentsA_g[0] = Robot_DW.RateTransition2_Buffer_m[0];
      rtb_PhasecurrentsA_g[1] = Robot_DW.RateTransition2_Buffer_m[1];
      rtb_PhasecurrentsA_g[2] = Robot_DW.RateTransition2_Buffer_m[2];
    }

    /* End of RateTransition: '<S24>/Rate Transition2' */

    /* SimscapeInputBlock: '<S324>/INTERNAL_4_1_1' */
    Robot_B.INTERNAL_4_1_1[0] = Robot_B.OUTPUT_3_0[5];
    Robot_B.INTERNAL_4_1_1[1] = 0.0;
    Robot_B.INTERNAL_4_1_1[2] = 0.0;
    Robot_B.INTERNAL_4_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S324>/INTERNAL_3_1_1' */
    Robot_B.INTERNAL_3_1_1[0] = Robot_B.OUTPUT_2_0[5];
    Robot_B.INTERNAL_3_1_1[1] = 0.0;
    Robot_B.INTERNAL_3_1_1[2] = 0.0;
    Robot_B.INTERNAL_3_1_1[3] = 0.0;
  }

  if (rtmIsMajorTimeStep(Robot_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Robot_M->rtwLogInfo, (Robot_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Robot_M)) {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    boolean_T tmp_0;
    real_T tmp_1[8];
    int_T tmp_2[3];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_3;
    char *msg;
    real_T time_0;
    real_T tmp_4[28];
    int_T tmp_5[8];
    real_T time_1;
    real_T tmp_6[28];
    int_T tmp_7[8];
    real_T time_tmp;

    /* Update for SimscapeExecutionBlock: '<S324>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S324>/STATE_2'
     *  SimscapeExecutionBlock: '<S324>/STATE_3'
     */
    simulationData = (NeslSimulationData *)Robot_DW.STATE_1_SimData;
    time_tmp = Robot_M->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 10;
    simulationData->mData->mContStates.mX = &Robot_X.RobotRevolute3Rzq[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &Robot_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp = rtmIsMajorTimeStep(Robot_M);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_2[0] = 0;
    tmp_1[0] = Robot_B.INTERNAL_4_1_1[0];
    tmp_1[1] = Robot_B.INTERNAL_4_1_1[1];
    tmp_1[2] = Robot_B.INTERNAL_4_1_1[2];
    tmp_1[3] = Robot_B.INTERNAL_4_1_1[3];
    tmp_2[1] = 4;
    tmp_1[4] = Robot_B.INTERNAL_3_1_1[0];
    tmp_1[5] = Robot_B.INTERNAL_3_1_1[1];
    tmp_1[6] = Robot_B.INTERNAL_3_1_1[2];
    tmp_1[7] = Robot_B.INTERNAL_3_1_1[3];
    tmp_2[2] = 8;
    simulationData->mData->mInputValues.mN = 8;
    simulationData->mData->mInputValues.mX = &tmp_1[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_2[0];
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_1_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S324>/STATE_1' */

    /* Update for RateTransition: '<S29>/Rate Transition4' incorporates:
     *  RateTransition: '<S29>/Rate Transition7'
     */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      Robot_DW.RateTransition4_Buffer0[0] = rtb_Sum2[0];
      Robot_DW.RateTransition4_Buffer0[1] = rtb_Sum2[1];
      Robot_DW.RateTransition4_Buffer0[2] = rtb_Sum2[2];
      Robot_DW.RateTransition7_Buffer0 = rtb_Relay;
    }

    /* End of Update for RateTransition: '<S29>/Rate Transition4' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
       *  Constant: '<S38>/Constant3'
       */
      Robot_DW.Integrator_DSTATE += Robot_P.Integrator_gainval *
        Robot_P.Constant3_Value_p;
      Robot_DW.Integrator_PrevResetState = (int8_T)rtb_LogicalOperator;

      /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
       *  Constant: '<S38>/Constant3'
       */
      Robot_DW.Integrator_DSTATE_o += Robot_P.Integrator_gainval_b *
        Robot_P.Constant3_Value_p;
      Robot_DW.Integrator_PrevResetState_k = (int8_T)rtb_LogicalOperator_d;
    }

    /* Update for SimscapeExecutionBlock: '<S324>/STATE_2' */
    simulationData = (NeslSimulationData *)Robot_DW.STATE_2_SimData;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 24;
    simulationData->mData->mContStates.mX =
      &Robot_X.RobotBLDCpm_dq0_Xabcangular_pos[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_2_Discrete;
    simulationData->mData->mModeVector.mN = 27;
    simulationData->mData->mModeVector.mX = &Robot_DW.STATE_2_Modes[0];
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_5[0] = 0;
    tmp_4[0] = Robot_B.INTERNAL_2_1_1[0];
    tmp_4[1] = Robot_B.INTERNAL_2_1_1[1];
    tmp_4[2] = Robot_B.INTERNAL_2_1_1[2];
    tmp_4[3] = Robot_B.INTERNAL_2_1_1[3];
    tmp_5[1] = 4;
    tmp_4[4] = Robot_B.INPUT_1_1_1[0];
    tmp_4[5] = Robot_B.INPUT_1_1_1[1];
    tmp_4[6] = Robot_B.INPUT_1_1_1[2];
    tmp_4[7] = Robot_B.INPUT_1_1_1[3];
    tmp_5[2] = 8;
    tmp_4[8] = Robot_B.INPUT_2_1_1[0];
    tmp_4[9] = Robot_B.INPUT_2_1_1[1];
    tmp_4[10] = Robot_B.INPUT_2_1_1[2];
    tmp_4[11] = Robot_B.INPUT_2_1_1[3];
    tmp_5[3] = 12;
    tmp_4[12] = Robot_B.INPUT_3_1_1[0];
    tmp_4[13] = Robot_B.INPUT_3_1_1[1];
    tmp_4[14] = Robot_B.INPUT_3_1_1[2];
    tmp_4[15] = Robot_B.INPUT_3_1_1[3];
    tmp_5[4] = 16;
    tmp_4[16] = Robot_B.INPUT_4_1_1[0];
    tmp_4[17] = Robot_B.INPUT_4_1_1[1];
    tmp_4[18] = Robot_B.INPUT_4_1_1[2];
    tmp_4[19] = Robot_B.INPUT_4_1_1[3];
    tmp_5[5] = 20;
    tmp_4[20] = Robot_B.INPUT_5_1_1[0];
    tmp_4[21] = Robot_B.INPUT_5_1_1[1];
    tmp_4[22] = Robot_B.INPUT_5_1_1[2];
    tmp_4[23] = Robot_B.INPUT_5_1_1[3];
    tmp_5[6] = 24;
    tmp_4[24] = Robot_B.INPUT_6_1_1[0];
    tmp_4[25] = Robot_B.INPUT_6_1_1[1];
    tmp_4[26] = Robot_B.INPUT_6_1_1[2];
    tmp_4[27] = Robot_B.INPUT_6_1_1[3];
    tmp_5[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &tmp_4[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_5[0];
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_2_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_2_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* Update for RateTransition: '<S156>/Rate Transition7' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for DiscreteIntegrator: '<S84>/Integrator' */
      Robot_DW.Integrator_DSTATE_a += Robot_P.Integrator_gainval_k *
        rtb_IntegralGain;

      /* Update for DiscreteIntegrator: '<S79>/Filter' */
      Robot_DW.Filter_DSTATE += Robot_P.Filter_gainval * rtb_FilterCoefficient;

      /* Update for DiscreteIntegrator: '<S132>/Integrator' */
      Robot_DW.Integrator_DSTATE_g += Robot_P.Integrator_gainval_m * rtb_SumI4;

      /* Update for UnitDelay: '<S34>/Unit Delay' */
      Robot_DW.UnitDelay_DSTATE = rtb_Sum5;

      /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S1>/Constant'
       */
      Robot_DW.DiscreteTimeIntegrator_DSTATE = Robot_B.DiscreteTimeIntegrator;
      if (Robot_P.Constant_Value_g > 0.0) {
        Robot_DW.DiscreteTimeIntegrator_PrevRese = 1;
      } else if (Robot_P.Constant_Value_g < 0.0) {
        Robot_DW.DiscreteTimeIntegrator_PrevRese = -1;
      } else if (Robot_P.Constant_Value_g == 0.0) {
        Robot_DW.DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        Robot_DW.DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S154>/Integrator' */
      Robot_DW.Integrator_IC_LOADING = 0U;
      Robot_DW.Integrator_DSTATE_l += Robot_P.Integrator_gainval_e * rtb_uT;
      if (Robot_DW.Integrator_DSTATE_l >= Robot_P.Integrator_UpperSat) {
        Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_UpperSat;
      } else {
        if (Robot_DW.Integrator_DSTATE_l <= Robot_P.Integrator_LowerSat) {
          Robot_DW.Integrator_DSTATE_l = Robot_P.Integrator_LowerSat;
        }
      }

      Robot_DW.Integrator_PrevResetState_p = (int8_T)rtb_Compare_c;

      /* End of Update for DiscreteIntegrator: '<S154>/Integrator' */

      /* Update for DiscreteIntegrator: '<S211>/Integrator' */
      Robot_DW.Integrator_DSTATE_m += Robot_P.Integrator_gainval_h *
        rtb_IntegralGain_o;

      /* Update for DiscreteIntegrator: '<S259>/Integrator' */
      Robot_DW.Integrator_DSTATE_f += Robot_P.Integrator_gainval_e3 *
        rtb_SumI4_k;

      /* Update for RateTransition: '<S156>/Rate Transition4' */
      Robot_DW.RateTransition4_Buffer0_h[0] = rtb_Sum2_a[0];
      Robot_DW.RateTransition4_Buffer0_h[1] = rtb_Sum2_a[1];
      Robot_DW.RateTransition4_Buffer0_h[2] = rtb_Sum2_a[2];
      Robot_DW.RateTransition7_Buffer0_j = rtb_Relay_k;
    }

    /* End of Update for RateTransition: '<S156>/Rate Transition7' */
    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for DiscreteIntegrator: '<S172>/Integrator' incorporates:
       *  Constant: '<S165>/Constant3'
       */
      Robot_DW.Integrator_DSTATE_fd += Robot_P.Integrator_gainval_f *
        Robot_P.Constant3_Value_c;
      Robot_DW.Integrator_PrevResetState_l = (int8_T)rtb_LogicalOperator_c;

      /* Update for DiscreteIntegrator: '<S176>/Integrator' incorporates:
       *  Constant: '<S165>/Constant3'
       */
      Robot_DW.Integrator_DSTATE_fo += Robot_P.Integrator_gainval_f3 *
        Robot_P.Constant3_Value_c;
      Robot_DW.Integrator_PrevResetState_c = (int8_T)rtb_LogicalOperator_p;
    }

    /* Update for SimscapeExecutionBlock: '<S324>/STATE_3' */
    simulationData = (NeslSimulationData *)Robot_DW.STATE_3_SimData;
    time_1 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 24;
    simulationData->mData->mContStates.mX =
      &Robot_X.RobotBLDC1pm_dq0_Xabcangular_po[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_3_Discrete;
    simulationData->mData->mModeVector.mN = 27;
    simulationData->mData->mModeVector.mX = &Robot_DW.STATE_3_Modes[0];
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_7[0] = 0;
    tmp_6[0] = Robot_B.INTERNAL_1_1_1[0];
    tmp_6[1] = Robot_B.INTERNAL_1_1_1[1];
    tmp_6[2] = Robot_B.INTERNAL_1_1_1[2];
    tmp_6[3] = Robot_B.INTERNAL_1_1_1[3];
    tmp_7[1] = 4;
    tmp_6[4] = Robot_B.INPUT_7_1_1[0];
    tmp_6[5] = Robot_B.INPUT_7_1_1[1];
    tmp_6[6] = Robot_B.INPUT_7_1_1[2];
    tmp_6[7] = Robot_B.INPUT_7_1_1[3];
    tmp_7[2] = 8;
    tmp_6[8] = Robot_B.INPUT_8_1_1[0];
    tmp_6[9] = Robot_B.INPUT_8_1_1[1];
    tmp_6[10] = Robot_B.INPUT_8_1_1[2];
    tmp_6[11] = Robot_B.INPUT_8_1_1[3];
    tmp_7[3] = 12;
    tmp_6[12] = Robot_B.INPUT_9_1_1[0];
    tmp_6[13] = Robot_B.INPUT_9_1_1[1];
    tmp_6[14] = Robot_B.INPUT_9_1_1[2];
    tmp_6[15] = Robot_B.INPUT_9_1_1[3];
    tmp_7[4] = 16;
    tmp_6[16] = Robot_B.INPUT_10_1_1[0];
    tmp_6[17] = Robot_B.INPUT_10_1_1[1];
    tmp_6[18] = Robot_B.INPUT_10_1_1[2];
    tmp_6[19] = Robot_B.INPUT_10_1_1[3];
    tmp_7[5] = 20;
    tmp_6[20] = Robot_B.INPUT_11_1_1[0];
    tmp_6[21] = Robot_B.INPUT_11_1_1[1];
    tmp_6[22] = Robot_B.INPUT_11_1_1[2];
    tmp_6[23] = Robot_B.INPUT_11_1_1[3];
    tmp_7[6] = 24;
    tmp_6[24] = Robot_B.INPUT_12_1_1[0];
    tmp_6[25] = Robot_B.INPUT_12_1_1[1];
    tmp_6[26] = Robot_B.INPUT_12_1_1[2];
    tmp_6[27] = Robot_B.INPUT_12_1_1[3];
    tmp_7[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &tmp_6[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_7[0];
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_3_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_3_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    if (rtmIsMajorTimeStep(Robot_M) &&
        Robot_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for UnitDelay: '<S161>/Unit Delay' */
      Robot_DW.UnitDelay_DSTATE_c = rtb_Sum5_m;

      /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S2>/Constant'
       */
      Robot_DW.DiscreteTimeIntegrator_DSTATE_a =
        Robot_B.DiscreteTimeIntegrator_f;
      if (Robot_P.Constant_Value_ff > 0.0) {
        Robot_DW.DiscreteTimeIntegrator_PrevRe_c = 1;
      } else if (Robot_P.Constant_Value_ff < 0.0) {
        Robot_DW.DiscreteTimeIntegrator_PrevRe_c = -1;
      } else if (Robot_P.Constant_Value_ff == 0.0) {
        Robot_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
      } else {
        Robot_DW.DiscreteTimeIntegrator_PrevRe_c = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S281>/Integrator' */
      Robot_DW.Integrator_IC_LOADING_g = 0U;
      Robot_DW.Integrator_DSTATE_lq += Robot_P.Integrator_gainval_hl * rtb_uT_i;
      if (Robot_DW.Integrator_DSTATE_lq >= Robot_P.Integrator_UpperSat_d) {
        Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_UpperSat_d;
      } else {
        if (Robot_DW.Integrator_DSTATE_lq <= Robot_P.Integrator_LowerSat_k) {
          Robot_DW.Integrator_DSTATE_lq = Robot_P.Integrator_LowerSat_k;
        }
      }

      Robot_DW.Integrator_PrevResetState_a = (int8_T)rtb_Compare_pr;

      /* End of Update for DiscreteIntegrator: '<S281>/Integrator' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Robot_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Robot_M)!=-1) &&
          !((rtmGetTFinal(Robot_M)-(((Robot_M->Timing.clockTick1+
               Robot_M->Timing.clockTickH1* 4294967296.0)) * 1.0E-5)) >
            (((Robot_M->Timing.clockTick1+Robot_M->Timing.clockTickH1*
               4294967296.0)) * 1.0E-5) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Robot_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Robot_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Robot_M->Timing.clockTick0)) {
      ++Robot_M->Timing.clockTickH0;
    }

    Robot_M->Timing.t[0] = rtsiGetSolverStopTime(&Robot_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Robot_M->Timing.clockTick1++;
      if (!Robot_M->Timing.clockTick1) {
        Robot_M->Timing.clockTickH1++;
      }
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Robot_derivatives(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  boolean_T tmp_0;
  real_T tmp_1[8];
  int_T tmp_2[3];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_3;
  char *msg;
  real_T time_0;
  real_T tmp_4[28];
  int_T tmp_5[8];
  real_T time_1;
  real_T tmp_6[28];
  int_T tmp_7[8];
  real_T time_tmp;
  XDot_Robot_T *_rtXdot;
  _rtXdot = ((XDot_Robot_T *) Robot_M->derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S324>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S324>/STATE_2'
   *  SimscapeExecutionBlock: '<S324>/STATE_3'
   */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_1_SimData;
  time_tmp = Robot_M->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &Robot_X.RobotRevolute3Rzq[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  tmp = rtmIsMajorTimeStep(Robot_M);
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_2[0] = 0;
  tmp_1[0] = Robot_B.INTERNAL_4_1_1[0];
  tmp_1[1] = Robot_B.INTERNAL_4_1_1[1];
  tmp_1[2] = Robot_B.INTERNAL_4_1_1[2];
  tmp_1[3] = Robot_B.INTERNAL_4_1_1[3];
  tmp_2[1] = 4;
  tmp_1[4] = Robot_B.INTERNAL_3_1_1[0];
  tmp_1[5] = Robot_B.INTERNAL_3_1_1[1];
  tmp_1[6] = Robot_B.INTERNAL_3_1_1[2];
  tmp_1[7] = Robot_B.INTERNAL_3_1_1[3];
  tmp_2[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &tmp_1[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_2[0];
  simulationData->mData->mDx.mN = 10;
  simulationData->mData->mDx.mX = &_rtXdot->RobotRevolute3Rzq[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp_0) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S324>/STATE_1' */

  /* Derivatives for SimscapeExecutionBlock: '<S324>/STATE_2' */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_2_SimData;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 24;
  simulationData->mData->mContStates.mX =
    &Robot_X.RobotBLDCpm_dq0_Xabcangular_pos[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_2_Discrete;
  simulationData->mData->mModeVector.mN = 27;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_2_Modes[0];
  tmp_0 = false;
  simulationData->mData->mFoundZcEvents = tmp_0;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp_0 = false;
  simulationData->mData->mIsSolverAssertCheck = tmp_0;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp_0 = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp_0;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_5[0] = 0;
  tmp_4[0] = Robot_B.INTERNAL_2_1_1[0];
  tmp_4[1] = Robot_B.INTERNAL_2_1_1[1];
  tmp_4[2] = Robot_B.INTERNAL_2_1_1[2];
  tmp_4[3] = Robot_B.INTERNAL_2_1_1[3];
  tmp_5[1] = 4;
  tmp_4[4] = Robot_B.INPUT_1_1_1[0];
  tmp_4[5] = Robot_B.INPUT_1_1_1[1];
  tmp_4[6] = Robot_B.INPUT_1_1_1[2];
  tmp_4[7] = Robot_B.INPUT_1_1_1[3];
  tmp_5[2] = 8;
  tmp_4[8] = Robot_B.INPUT_2_1_1[0];
  tmp_4[9] = Robot_B.INPUT_2_1_1[1];
  tmp_4[10] = Robot_B.INPUT_2_1_1[2];
  tmp_4[11] = Robot_B.INPUT_2_1_1[3];
  tmp_5[3] = 12;
  tmp_4[12] = Robot_B.INPUT_3_1_1[0];
  tmp_4[13] = Robot_B.INPUT_3_1_1[1];
  tmp_4[14] = Robot_B.INPUT_3_1_1[2];
  tmp_4[15] = Robot_B.INPUT_3_1_1[3];
  tmp_5[4] = 16;
  tmp_4[16] = Robot_B.INPUT_4_1_1[0];
  tmp_4[17] = Robot_B.INPUT_4_1_1[1];
  tmp_4[18] = Robot_B.INPUT_4_1_1[2];
  tmp_4[19] = Robot_B.INPUT_4_1_1[3];
  tmp_5[5] = 20;
  tmp_4[20] = Robot_B.INPUT_5_1_1[0];
  tmp_4[21] = Robot_B.INPUT_5_1_1[1];
  tmp_4[22] = Robot_B.INPUT_5_1_1[2];
  tmp_4[23] = Robot_B.INPUT_5_1_1[3];
  tmp_5[6] = 24;
  tmp_4[24] = Robot_B.INPUT_6_1_1[0];
  tmp_4[25] = Robot_B.INPUT_6_1_1[1];
  tmp_4[26] = Robot_B.INPUT_6_1_1[2];
  tmp_4[27] = Robot_B.INPUT_6_1_1[3];
  tmp_5[7] = 28;
  simulationData->mData->mInputValues.mN = 28;
  simulationData->mData->mInputValues.mX = &tmp_4[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_5[0];
  simulationData->mData->mDx.mN = 24;
  simulationData->mData->mDx.mX = &_rtXdot->RobotBLDCpm_dq0_Xabcangular_pos[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_2_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_2_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp_0) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }

  /* Derivatives for SimscapeExecutionBlock: '<S324>/STATE_3' */
  simulationData = (NeslSimulationData *)Robot_DW.STATE_3_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 24;
  simulationData->mData->mContStates.mX =
    &Robot_X.RobotBLDC1pm_dq0_Xabcangular_po[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &Robot_DW.STATE_3_Discrete;
  simulationData->mData->mModeVector.mN = 27;
  simulationData->mData->mModeVector.mX = &Robot_DW.STATE_3_Modes[0];
  tmp_0 = false;
  simulationData->mData->mFoundZcEvents = tmp_0;
  simulationData->mData->mIsMajorTimeStep = tmp;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Robot_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_7[0] = 0;
  tmp_6[0] = Robot_B.INTERNAL_1_1_1[0];
  tmp_6[1] = Robot_B.INTERNAL_1_1_1[1];
  tmp_6[2] = Robot_B.INTERNAL_1_1_1[2];
  tmp_6[3] = Robot_B.INTERNAL_1_1_1[3];
  tmp_7[1] = 4;
  tmp_6[4] = Robot_B.INPUT_7_1_1[0];
  tmp_6[5] = Robot_B.INPUT_7_1_1[1];
  tmp_6[6] = Robot_B.INPUT_7_1_1[2];
  tmp_6[7] = Robot_B.INPUT_7_1_1[3];
  tmp_7[2] = 8;
  tmp_6[8] = Robot_B.INPUT_8_1_1[0];
  tmp_6[9] = Robot_B.INPUT_8_1_1[1];
  tmp_6[10] = Robot_B.INPUT_8_1_1[2];
  tmp_6[11] = Robot_B.INPUT_8_1_1[3];
  tmp_7[3] = 12;
  tmp_6[12] = Robot_B.INPUT_9_1_1[0];
  tmp_6[13] = Robot_B.INPUT_9_1_1[1];
  tmp_6[14] = Robot_B.INPUT_9_1_1[2];
  tmp_6[15] = Robot_B.INPUT_9_1_1[3];
  tmp_7[4] = 16;
  tmp_6[16] = Robot_B.INPUT_10_1_1[0];
  tmp_6[17] = Robot_B.INPUT_10_1_1[1];
  tmp_6[18] = Robot_B.INPUT_10_1_1[2];
  tmp_6[19] = Robot_B.INPUT_10_1_1[3];
  tmp_7[5] = 20;
  tmp_6[20] = Robot_B.INPUT_11_1_1[0];
  tmp_6[21] = Robot_B.INPUT_11_1_1[1];
  tmp_6[22] = Robot_B.INPUT_11_1_1[2];
  tmp_6[23] = Robot_B.INPUT_11_1_1[3];
  tmp_7[6] = 24;
  tmp_6[24] = Robot_B.INPUT_12_1_1[0];
  tmp_6[25] = Robot_B.INPUT_12_1_1[1];
  tmp_6[26] = Robot_B.INPUT_12_1_1[2];
  tmp_6[27] = Robot_B.INPUT_12_1_1[3];
  tmp_7[7] = 28;
  simulationData->mData->mInputValues.mN = 28;
  simulationData->mData->mInputValues.mX = &tmp_6[0];
  simulationData->mData->mInputOffsets.mN = 8;
  simulationData->mData->mInputOffsets.mX = &tmp_7[0];
  simulationData->mData->mDx.mN = 24;
  simulationData->mData->mDx.mX = &_rtXdot->RobotBLDC1pm_dq0_Xabcangular_po[0];
  diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_3_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)Robot_DW.STATE_3_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Robot_M, msg);
    }
  }
}

/* Model initialize function */
void Robot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Robot_P.Integrator_UpperSat = rtInf;
  Robot_P.Integrator_LowerSat = rtMinusInf;
  Robot_P.Saturation_UpperSat_d = rtInf;
  Robot_P.Saturation_LowerSat_i = rtMinusInf;
  Robot_P.Integrator_UpperSat_d = rtInf;
  Robot_P.Integrator_LowerSat_k = rtMinusInf;
  Robot_P.Saturation_UpperSat_b = rtInf;
  Robot_P.Saturation_LowerSat_o = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)Robot_M, 0,
                sizeof(RT_MODEL_Robot_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Robot_M->solverInfo, &Robot_M->Timing.simTimeStep);
    rtsiSetTPtr(&Robot_M->solverInfo, &rtmGetTPtr(Robot_M));
    rtsiSetStepSizePtr(&Robot_M->solverInfo, &Robot_M->Timing.stepSize0);
    rtsiSetdXPtr(&Robot_M->solverInfo, &Robot_M->derivs);
    rtsiSetContStatesPtr(&Robot_M->solverInfo, (real_T **) &Robot_M->contStates);
    rtsiSetNumContStatesPtr(&Robot_M->solverInfo, &Robot_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Robot_M->solverInfo,
      &Robot_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Robot_M->solverInfo,
      &Robot_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Robot_M->solverInfo,
      &Robot_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Robot_M->solverInfo, (&rtmGetErrorStatus(Robot_M)));
    rtsiSetSolverMassMatrixIr(&Robot_M->solverInfo, Robot_MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&Robot_M->solverInfo, Robot_MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&Robot_M->solverInfo, Robot_MassMatrix.pr);
    rtsiSetRTModelPtr(&Robot_M->solverInfo, Robot_M);
  }

  rtsiSetSimTimeStep(&Robot_M->solverInfo, MAJOR_TIME_STEP);
  Robot_M->intgData.x0 = Robot_M->odeX0;
  Robot_M->intgData.f0 = Robot_M->odeF0;
  Robot_M->intgData.x1start = Robot_M->odeX1START;
  Robot_M->intgData.f1 = Robot_M->odeF1;
  Robot_M->intgData.Delta = Robot_M->odeDELTA;
  Robot_M->intgData.E = Robot_M->odeE;
  Robot_M->intgData.fac = Robot_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = Robot_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(Robot_M->odeFAC)/sizeof(real_T)); i++) {
      f[i] = 1.5e-8;
    }
  }

  Robot_M->intgData.DFDX = Robot_M->odeDFDX;
  Robot_M->intgData.W = Robot_M->odeW;
  Robot_M->intgData.pivots = Robot_M->odePIVOTS;
  Robot_M->intgData.xtmp = Robot_M->odeXTMP;
  Robot_M->intgData.ztmp = Robot_M->odeZTMP;
  Robot_M->intgData.M = Robot_M->odeMASSMATRIX_M;
  Robot_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&Robot_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&Robot_M->solverInfo, 1);
  Robot_M->contStates = ((X_Robot_T *) &Robot_X);
  Robot_M->massMatrixType = ((ssMatrixType)1);
  Robot_M->massMatrixNzMax = (26);
  Robot_M->massMatrixIr = (Robot_MassMatrix.ir);
  Robot_M->massMatrixJc = (Robot_MassMatrix.jc);
  Robot_M->massMatrixPr = (Robot_MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&Robot_M->solverInfo, (ssMatrixType)1);
  rtsiSetSolverMassMatrixNzMax(&Robot_M->solverInfo, 26);
  rtsiSetSolverData(&Robot_M->solverInfo, (void *)&Robot_M->intgData);
  rtsiSetSolverName(&Robot_M->solverInfo,"ode14x");
  rtmSetTPtr(Robot_M, &Robot_M->Timing.tArray[0]);
  rtmSetTFinal(Robot_M, 0.5);
  Robot_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Robot_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Robot_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Robot_M->rtwLogInfo, (NULL));
    rtliSetLogT(Robot_M->rtwLogInfo, "tout");
    rtliSetLogX(Robot_M->rtwLogInfo, "");
    rtliSetLogXFinal(Robot_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Robot_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Robot_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Robot_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Robot_M->rtwLogInfo, 1);
    rtliSetLogY(Robot_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Robot_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Robot_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Robot_B), 0,
                sizeof(B_Robot_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Robot_X, 0,
                  sizeof(X_Robot_T));
  }

  /* global mass matrix */
  {
    int_T *ir = Robot_MassMatrix.ir;
    int_T *jc = Robot_MassMatrix.jc;
    real_T *pr = Robot_MassMatrix.pr;
    (void) memset((void *)ir, 0,
                  26*sizeof(int_T));
    (void) memset((void *)jc, 0,
                  (58+1)*sizeof(int_T));
    (void) memset((void *)pr, 0,
                  26*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Robot_DW, 0,
                sizeof(DW_Robot_T));

  /* Root-level init GlobalMassMatrixPr offset */
  {
    Robot_DW.STATE_2_MASS_MATRIX_PR = 10;/* '<S324>/STATE_2' */
    Robot_DW.STATE_3_MASS_MATRIX_PR = 18;/* '<S324>/STATE_3' */
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Robot_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Robot_M), Robot_M->Timing.stepSize0, (&rtmGetErrorStatus(Robot_M)));

  {
    NeslSimulator *tmp;
    boolean_T tmp_0;
    NeslSimulationData *tmp_1;
    NeuDiagnosticManager *diagnosticManager;
    NeModelParameters modelParameters;
    real_T tmp_2;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_3;
    char *msg;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeModelParameters modelParameters_2;
    NeModelParameters modelParameters_3;
    NeModelParameters modelParameters_4;

    /* Start for SimscapeExecutionBlock: '<S324>/STATE_1' */
    tmp = nesl_lease_simulator("Robot/Solver Configuration_1", 0, 0);
    Robot_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Robot_DW.STATE_1_Simulator);
    if (tmp_0) {
      Robot_d2dba219_1_gateway();
      tmp = nesl_lease_simulator("Robot/Solver Configuration_1", 0, 0);
      Robot_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Robot_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Robot_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 5.21147926E+8;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Robot_DW.STATE_1_Simulator, &modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S324>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S324>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("Robot/Solver Configuration_1", 1, 0);
    Robot_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Robot_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      Robot_d2dba219_1_gateway();
      tmp = nesl_lease_simulator("Robot/Solver Configuration_1", 1, 0);
      Robot_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Robot_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Robot_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 5.21147926E+8;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Robot_DW.OUTPUT_1_0_Simulator, &modelParameters_0, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S324>/OUTPUT_1_0' */

    /* Start for RateTransition: '<S29>/Rate Transition4' */
    Robot_B.RateTransition4[0] = Robot_P.RateTransition4_InitialConditio;
    Robot_B.RateTransition4[1] = Robot_P.RateTransition4_InitialConditio;
    Robot_B.RateTransition4[2] = Robot_P.RateTransition4_InitialConditio;

    /* Start for Probe: '<S44>/Probe' */
    Robot_B.Probe[0] = 1.0E-5;
    Robot_B.Probe[1] = 0.0;

    /* Start for InitialCondition: '<S45>/Initial' */
    Robot_B.Initial = Robot_P.Initial_Value;
    Robot_DW.Initial_FirstOutputTime = true;

    /* Start for InitialCondition: '<S49>/Initial' */
    Robot_B.Initial_e = Robot_P.Initial_Value_i;
    Robot_DW.Initial_FirstOutputTime_l = true;

    /* Start for RateTransition: '<S29>/Rate Transition7' */
    Robot_B.RateTransition7 = Robot_P.RateTransition7_InitialConditio;

    /* Start for SimscapeExecutionBlock: '<S324>/STATE_2' */
    tmp = nesl_lease_simulator("Robot/Solver Configuration_2", 0, 0);
    Robot_DW.STATE_2_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Robot_DW.STATE_2_Simulator);
    if (tmp_0) {
      Robot_d2dba219_2_gateway();
      tmp = nesl_lease_simulator("Robot/Solver Configuration_2", 0, 0);
      Robot_DW.STATE_2_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Robot_DW.STATE_2_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Robot_DW.STATE_2_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverTolerance = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mIsUsingODEN = false;
    modelParameters_1.mFixedStepSize = 0.001;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_1.mRTWModifiedTimeStamp = 5.21147926E+8;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_1.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_1.mIsUsingODEN = tmp_0;
    modelParameters_1.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_2_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Robot_DW.STATE_2_Simulator, &modelParameters_1, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S324>/STATE_2' */

    /* Start for SimscapeExecutionBlock: '<S324>/OUTPUT_2_0' */
    tmp = nesl_lease_simulator("Robot/Solver Configuration_2", 1, 0);
    Robot_DW.OUTPUT_2_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Robot_DW.OUTPUT_2_0_Simulator);
    if (tmp_0) {
      Robot_d2dba219_2_gateway();
      tmp = nesl_lease_simulator("Robot/Solver Configuration_2", 1, 0);
      Robot_DW.OUTPUT_2_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Robot_DW.OUTPUT_2_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Robot_DW.OUTPUT_2_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_2.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_2.mSolverTolerance = 0.001;
    modelParameters_2.mVariableStepSolver = false;
    modelParameters_2.mIsUsingODEN = false;
    modelParameters_2.mFixedStepSize = 0.001;
    modelParameters_2.mStartTime = 0.0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mUseSimState = false;
    modelParameters_2.mLinTrimCompile = false;
    modelParameters_2.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_2.mRTWModifiedTimeStamp = 5.21147926E+8;
    tmp_2 = 0.001;
    modelParameters_2.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_2.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_2.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_2.mIsUsingODEN = tmp_0;
    modelParameters_2.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.OUTPUT_2_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Robot_DW.OUTPUT_2_0_Simulator, &modelParameters_2, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S324>/OUTPUT_2_0' */

    /* Start for Probe: '<S149>/Probe' */
    Robot_B.Probe_e[0] = 0.0001;
    Robot_B.Probe_e[1] = 0.0;

    /* Start for RateTransition: '<S156>/Rate Transition4' */
    Robot_B.RateTransition4_b[0] = Robot_P.RateTransition4_InitialCondit_m;
    Robot_B.RateTransition4_b[1] = Robot_P.RateTransition4_InitialCondit_m;
    Robot_B.RateTransition4_b[2] = Robot_P.RateTransition4_InitialCondit_m;

    /* Start for Probe: '<S171>/Probe' */
    Robot_B.Probe_b[0] = 1.0E-5;
    Robot_B.Probe_b[1] = 0.0;

    /* Start for InitialCondition: '<S172>/Initial' */
    Robot_B.Initial_f = Robot_P.Initial_Value_ic;
    Robot_DW.Initial_FirstOutputTime_k = true;

    /* Start for InitialCondition: '<S176>/Initial' */
    Robot_B.Initial_l = Robot_P.Initial_Value_b;
    Robot_DW.Initial_FirstOutputTime_b = true;

    /* Start for RateTransition: '<S156>/Rate Transition7' */
    Robot_B.RateTransition7_l = Robot_P.RateTransition7_InitialCondit_d;

    /* Start for SimscapeExecutionBlock: '<S324>/STATE_3' */
    tmp = nesl_lease_simulator("Robot/Solver Configuration_3", 0, 0);
    Robot_DW.STATE_3_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Robot_DW.STATE_3_Simulator);
    if (tmp_0) {
      Robot_d2dba219_3_gateway();
      tmp = nesl_lease_simulator("Robot/Solver Configuration_3", 0, 0);
      Robot_DW.STATE_3_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Robot_DW.STATE_3_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Robot_DW.STATE_3_DiagMgr = (void *)diagnosticManager;
    modelParameters_3.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_3.mSolverTolerance = 0.001;
    modelParameters_3.mVariableStepSolver = false;
    modelParameters_3.mIsUsingODEN = false;
    modelParameters_3.mFixedStepSize = 0.001;
    modelParameters_3.mStartTime = 0.0;
    modelParameters_3.mLoadInitialState = false;
    modelParameters_3.mUseSimState = false;
    modelParameters_3.mLinTrimCompile = false;
    modelParameters_3.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_3.mRTWModifiedTimeStamp = 5.21147926E+8;
    tmp_2 = 0.001;
    modelParameters_3.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_3.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_3.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_3.mIsUsingODEN = tmp_0;
    modelParameters_3.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.STATE_3_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Robot_DW.STATE_3_Simulator, &modelParameters_3, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S324>/STATE_3' */

    /* Start for SimscapeExecutionBlock: '<S324>/OUTPUT_3_0' */
    tmp = nesl_lease_simulator("Robot/Solver Configuration_3", 1, 0);
    Robot_DW.OUTPUT_3_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Robot_DW.OUTPUT_3_0_Simulator);
    if (tmp_0) {
      Robot_d2dba219_3_gateway();
      tmp = nesl_lease_simulator("Robot/Solver Configuration_3", 1, 0);
      Robot_DW.OUTPUT_3_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Robot_DW.OUTPUT_3_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Robot_DW.OUTPUT_3_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_4.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_4.mSolverTolerance = 0.001;
    modelParameters_4.mVariableStepSolver = false;
    modelParameters_4.mIsUsingODEN = false;
    modelParameters_4.mFixedStepSize = 0.001;
    modelParameters_4.mStartTime = 0.0;
    modelParameters_4.mLoadInitialState = false;
    modelParameters_4.mUseSimState = false;
    modelParameters_4.mLinTrimCompile = false;
    modelParameters_4.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_4.mRTWModifiedTimeStamp = 5.21147926E+8;
    tmp_2 = 0.001;
    modelParameters_4.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    modelParameters_4.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_4.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_4.mIsUsingODEN = tmp_0;
    modelParameters_4.mLoadInitialState = false;
    diagnosticManager = (NeuDiagnosticManager *)Robot_DW.OUTPUT_3_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Robot_DW.OUTPUT_3_0_Simulator, &modelParameters_4, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Robot_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Robot_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S324>/OUTPUT_3_0' */

    /* Start for Probe: '<S276>/Probe' */
    Robot_B.Probe_m[0] = 0.0001;
    Robot_B.Probe_m[1] = 0.0;
  }

  {
    boolean_T tmp;
    int_T tmp_0;
    char *tmp_1;

    /* InitializeConditions for SimscapeExecutionBlock: '<S324>/STATE_1' */
    tmp = false;
    if (tmp) {
      tmp_0 = strcmp("ode14x", rtsiGetSolverName(&Robot_M->solverInfo));
      if (tmp_0 != 0) {
        tmp_1 = solver_mismatch_message("ode14x", rtsiGetSolverName
          (&Robot_M->solverInfo));
        rtmSetErrorStatus(Robot_M, tmp_1);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S324>/STATE_1' */

    /* InitializeConditions for RateTransition: '<S29>/Rate Transition4' */
    Robot_DW.RateTransition4_Buffer0[0] =
      Robot_P.RateTransition4_InitialConditio;
    Robot_DW.RateTransition4_Buffer0[1] =
      Robot_P.RateTransition4_InitialConditio;
    Robot_DW.RateTransition4_Buffer0[2] =
      Robot_P.RateTransition4_InitialConditio;

    /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator' */
    Robot_DW.Integrator_DSTATE = Robot_B.Initial;
    Robot_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S49>/Integrator' */
    Robot_DW.Integrator_DSTATE_o = Robot_B.Initial_e;
    Robot_DW.Integrator_PrevResetState_k = 2;

    /* InitializeConditions for RateTransition: '<S29>/Rate Transition7' */
    Robot_DW.RateTransition7_Buffer0 = Robot_P.RateTransition7_InitialConditio;

    /* InitializeConditions for SimscapeExecutionBlock: '<S324>/STATE_2' */
    tmp = false;
    if (tmp) {
      tmp_0 = strcmp("ode14x", rtsiGetSolverName(&Robot_M->solverInfo));
      if (tmp_0 != 0) {
        tmp_1 = solver_mismatch_message("ode14x", rtsiGetSolverName
          (&Robot_M->solverInfo));
        rtmSetErrorStatus(Robot_M, tmp_1);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S324>/STATE_2' */

    /* InitializeConditions for DiscreteIntegrator: '<S84>/Integrator' */
    Robot_DW.Integrator_DSTATE_a = Robot_P.Positioncontroller_InitialCon_k;

    /* InitializeConditions for DiscreteIntegrator: '<S79>/Filter' */
    Robot_DW.Filter_DSTATE = Robot_P.Positioncontroller_InitialCondi;

    /* InitializeConditions for DiscreteIntegrator: '<S132>/Integrator' */
    Robot_DW.Integrator_DSTATE_g = Robot_P.Speedcontroller_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
    Robot_DW.UnitDelay_DSTATE = Robot_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
    Robot_DW.DiscreteTimeIntegrator_DSTATE = Robot_P.PIcontroller_x0;
    Robot_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
    Robot_DW.Integrator_PrevResetState_p = 0;
    Robot_DW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S211>/Integrator' */
    Robot_DW.Integrator_DSTATE_m = Robot_P.Positioncontroller_InitialCo_kb;

    /* InitializeConditions for DiscreteIntegrator: '<S259>/Integrator' */
    Robot_DW.Integrator_DSTATE_f = Robot_P.Speedcontroller_InitialCondit_e;

    /* InitializeConditions for RateTransition: '<S156>/Rate Transition4' */
    Robot_DW.RateTransition4_Buffer0_h[0] =
      Robot_P.RateTransition4_InitialCondit_m;
    Robot_DW.RateTransition4_Buffer0_h[1] =
      Robot_P.RateTransition4_InitialCondit_m;
    Robot_DW.RateTransition4_Buffer0_h[2] =
      Robot_P.RateTransition4_InitialCondit_m;

    /* InitializeConditions for DiscreteIntegrator: '<S172>/Integrator' */
    Robot_DW.Integrator_DSTATE_fd = Robot_B.Initial_f;
    Robot_DW.Integrator_PrevResetState_l = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S176>/Integrator' */
    Robot_DW.Integrator_DSTATE_fo = Robot_B.Initial_l;
    Robot_DW.Integrator_PrevResetState_c = 2;

    /* InitializeConditions for RateTransition: '<S156>/Rate Transition7' */
    Robot_DW.RateTransition7_Buffer0_j = Robot_P.RateTransition7_InitialCondit_d;

    /* InitializeConditions for SimscapeExecutionBlock: '<S324>/STATE_3' */
    tmp = false;
    if (tmp) {
      tmp_0 = strcmp("ode14x", rtsiGetSolverName(&Robot_M->solverInfo));
      if (tmp_0 != 0) {
        tmp_1 = solver_mismatch_message("ode14x", rtsiGetSolverName
          (&Robot_M->solverInfo));
        rtmSetErrorStatus(Robot_M, tmp_1);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S324>/STATE_3' */

    /* InitializeConditions for UnitDelay: '<S161>/Unit Delay' */
    Robot_DW.UnitDelay_DSTATE_c = Robot_P.UnitDelay_InitialCondition_f;

    /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
    Robot_DW.DiscreteTimeIntegrator_DSTATE_a = Robot_P.PIcontroller_x0_i;
    Robot_DW.DiscreteTimeIntegrator_PrevRe_c = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S281>/Integrator' */
    Robot_DW.Integrator_PrevResetState_a = 0;
    Robot_DW.Integrator_IC_LOADING_g = 1U;

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        13, 11, 12, 14, 15, 16, 17, 34, 37, 35, 36, 38, 39, 40, 41 };

      static int_T modelMassMatrixJc[59] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
        18, 18, 18, 18, 18, 18, 19, 20, 21, 22, 23, 24, 25, 26, 26, 26, 26, 26,
        26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26 };

      static real_T modelMassMatrixPr[26] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0 };

      (void) memcpy(Robot_MassMatrix.ir, modelMassMatrixIr,
                    26*sizeof(int_T));
      (void) memcpy(Robot_MassMatrix.jc, modelMassMatrixJc,
                    59*sizeof(int_T));
      (void) memcpy(Robot_MassMatrix.pr, modelMassMatrixPr,
                    26*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void Robot_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S324>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Robot_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)Robot_DW.STATE_1_SimData);
  nesl_erase_simulator("Robot/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S324>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Robot_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)Robot_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("Robot/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S324>/STATE_2' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Robot_DW.STATE_2_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)Robot_DW.STATE_2_SimData);
  nesl_erase_simulator("Robot/Solver Configuration_2");

  /* Terminate for SimscapeExecutionBlock: '<S324>/OUTPUT_2_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Robot_DW.OUTPUT_2_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)Robot_DW.OUTPUT_2_0_SimData);
  nesl_erase_simulator("Robot/Solver Configuration_2");

  /* Terminate for SimscapeExecutionBlock: '<S324>/STATE_3' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Robot_DW.STATE_3_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)Robot_DW.STATE_3_SimData);
  nesl_erase_simulator("Robot/Solver Configuration_3");

  /* Terminate for SimscapeExecutionBlock: '<S324>/OUTPUT_3_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Robot_DW.OUTPUT_3_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)Robot_DW.OUTPUT_3_0_SimData);
  nesl_erase_simulator("Robot/Solver Configuration_3");
}
