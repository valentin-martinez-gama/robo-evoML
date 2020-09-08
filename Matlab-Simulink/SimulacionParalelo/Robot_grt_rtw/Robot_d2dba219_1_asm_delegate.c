/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_CTarget.h"

void Robot_d2dba219_1_setTargets(const RuntimeDerivedValuesBundle *rtdv, CTarget
  *targets)
{
  (void) rtdv;
  (void) targets;
}

void Robot_d2dba219_1_resetAsmStateVector(const void *mech, double *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = xx[0];
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = xx[0];
  state[7] = xx[0];
  state[8] = xx[0];
  state[9] = xx[0];
}

static PmfMessageId initializeTrackedAngleState_0(const
  RuntimeDerivedValuesBundle *rtdv, const int *modeVector, const double
  *motionData, double *state, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[16];
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  (void) neDiagMgr;
  xx[0] = 0.9998679088263617;
  xx[1] = motionData[28];
  xx[2] = motionData[29];
  xx[3] = motionData[30];
  xx[4] = motionData[31];
  xx[5] = motionData[35];
  xx[6] = motionData[36];
  xx[7] = motionData[37];
  xx[8] = motionData[38];
  pm_math_Quaternion_inverseCompose_ra(xx + 1, xx + 5, xx + 9);
  xx[1] = 0.01625315043917926;
  xx[2] = xx[0] * xx[10] - xx[1] * xx[12];
  xx[3] = xx[0] * xx[11] - xx[1] * xx[9];
  xx[4] = xx[0] * xx[12] + xx[1] * xx[10];
  xx[5] = xx[0] * xx[9] + xx[1] * xx[11];
  xx[0] = 0.9994716702016028;
  xx[1] = 0.03250200708292485;
  xx[6] = motionData[48];
  xx[7] = motionData[49];
  xx[8] = motionData[50];
  pm_math_Quaternion_inverseXform_ra(xx + 9, xx + 6, xx + 13);
  state[8] = sm_core_canonicalAngle(2.0 * atan2(sqrt(xx[2] * xx[2] + xx[3] * xx
    [3] + xx[4] * xx[4]), fabs(xx[5])) * (((xx[0] * xx[4] - xx[2] * xx[1]) * xx
    [5]) < 0.0 ? -1.0 : +1.0));
  state[9] = xx[0] * (motionData[62] - xx[15]) - xx[1] * (motionData[60] - xx[13]);
  return NULL;
}

void Robot_d2dba219_1_initializeTrackedAngleState(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *modeVector, const double
  *motionData, double *state, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  initializeTrackedAngleState_0(rtdv, modeVector, motionData, state, neDiagMgr);
}

void Robot_d2dba219_1_computeDiscreteState(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
}

void Robot_d2dba219_1_adjustPosition(const void *mech, const double *dofDeltas,
  double *state)
{
  (void) mech;
  state[0] = state[0] + dofDeltas[0];
  state[2] = state[2] + dofDeltas[1];
  state[4] = state[4] + dofDeltas[2];
  state[6] = state[6] + dofDeltas[3];
}

static void perturbAsmJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbAsmJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[1] = state[1] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_1_0(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbAsmJointPrimitiveState_1_0v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[3] = state[3] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_2_0(double mag, double *state)
{
  state[4] = state[4] + mag;
}

static void perturbAsmJointPrimitiveState_2_0v(double mag, double *state)
{
  state[4] = state[4] + mag;
  state[5] = state[5] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_3_0(double mag, double *state)
{
  state[6] = state[6] + mag;
}

static void perturbAsmJointPrimitiveState_3_0v(double mag, double *state)
{
  state[6] = state[6] + mag;
  state[7] = state[7] - 0.875 * mag;
}

void Robot_d2dba219_1_perturbAsmJointPrimitiveState(const void *mech, size_t
  stageIdx, size_t primIdx, double mag, boolean_T doPerturbVelocity, double
  *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbAsmJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbAsmJointPrimitiveState_0_0v(mag, state);
    break;

   case 12:
    perturbAsmJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbAsmJointPrimitiveState_1_0v(mag, state);
    break;

   case 24:
    perturbAsmJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbAsmJointPrimitiveState_2_0v(mag, state);
    break;

   case 36:
    perturbAsmJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbAsmJointPrimitiveState_3_0v(mag, state);
    break;
  }
}

void Robot_d2dba219_1_computePosDofBlendMatrix(const void *mech, size_t stageIdx,
  size_t primIdx, const double *state, int partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void Robot_d2dba219_1_computeVelDofBlendMatrix(const void *mech, size_t stageIdx,
  size_t primIdx, const double *state, int partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void Robot_d2dba219_1_projectPartiallyTargetedPos(const void *mech, size_t
  stageIdx, size_t primIdx, const double *origState, int partialType, double
  *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void Robot_d2dba219_1_propagateMotion(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[56];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  xx[0] = 0.5;
  xx[1] = xx[0] * state[0];
  xx[2] = cos(xx[1]);
  xx[3] = 0.0;
  xx[4] = sin(xx[1]);
  xx[1] = 0.1150028334860362;
  xx[5] = 0.05760957276177599;
  xx[6] = 2.0;
  xx[7] = xx[5] * xx[4];
  xx[8] = xx[5] - xx[6] * xx[7] * xx[4];
  xx[9] = 0.01712172113067823;
  xx[10] = xx[6] * xx[2] * xx[7];
  xx[7] = 0.202;
  xx[11] = xx[0] * state[2];
  xx[12] = cos(xx[11]);
  xx[13] = sin(xx[11]);
  xx[11] = 0.06239042723821288;
  xx[14] = 0.06165588643208984;
  xx[15] = xx[14] * xx[13];
  xx[16] = xx[11] + xx[14] - xx[6] * xx[15] * xx[13];
  xx[17] = xx[6] * xx[12] * xx[15];
  xx[15] = xx[0] * state[4];
  xx[18] = cos(xx[15]);
  xx[19] = sin(xx[15]);
  xx[15] = 0.04199716651396379;
  xx[20] = 0.05760957276178814;
  xx[21] = xx[20] * xx[19];
  xx[22] = xx[20] - xx[6] * xx[21] * xx[19];
  xx[23] = xx[6] * xx[18] * xx[21];
  xx[21] = 0.9998679088263617;
  xx[24] = xx[0] * state[6];
  xx[0] = cos(xx[24]);
  xx[25] = xx[21] * xx[0];
  xx[26] = 0.03250200708292485;
  xx[27] = sin(xx[24]);
  xx[24] = xx[26] * xx[27];
  xx[28] = 0.01625315043917926;
  xx[29] = 0.9994716702016028;
  xx[30] = xx[29] * xx[27];
  xx[27] = xx[21] * xx[24] - xx[28] * xx[30];
  xx[31] = xx[28] * xx[0];
  xx[0] = - xx[31];
  xx[32] = xx[21] * xx[30] + xx[28] * xx[24];
  xx[21] = - xx[32];
  xx[24] = 0.01218799303507748;
  xx[28] = xx[24] * xx[31];
  xx[33] = xx[27];
  xx[34] = xx[0];
  xx[35] = xx[21];
  xx[30] = 0.0559077577774378;
  xx[36] = xx[30] * xx[32] - xx[27] * xx[24];
  xx[37] = xx[30] * xx[31];
  xx[38] = - xx[28];
  xx[39] = xx[36];
  xx[40] = - xx[37];
  pm_math_Vector3_cross_ra(xx + 33, xx + 38, xx + 41);
  xx[38] = xx[11] + (xx[28] * xx[25] + xx[41]) * xx[6] - xx[30];
  xx[11] = (xx[42] - xx[25] * xx[36]) * xx[6];
  xx[28] = xx[24] + xx[6] * (xx[43] + xx[37] * xx[25]);
  xx[24] = xx[17] * xx[4];
  xx[30] = xx[4] * xx[16];
  xx[36] = xx[11] * xx[19];
  xx[37] = xx[19] * xx[38];
  xx[39] = xx[5] * state[1];
  xx[5] = xx[17] * state[1];
  xx[40] = xx[16] * state[1] + xx[39];
  xx[41] = xx[40] * xx[13];
  xx[42] = xx[5] * xx[13];
  xx[43] = xx[20] * state[5];
  xx[20] = xx[27] * state[5];
  xx[44] = xx[31] * state[5];
  xx[45] = xx[11] * state[5];
  xx[46] = xx[38] * state[5] + xx[43];
  xx[47] = xx[46] * xx[32];
  xx[48] = xx[45] * xx[32];
  xx[49] = xx[31] * xx[45] - xx[27] * xx[46];
  xx[50] = - xx[47];
  xx[51] = - xx[48];
  xx[52] = xx[49];
  pm_math_Vector3_cross_ra(xx + 33, xx + 50, xx + 53);
  motionData[0] = - xx[2];
  motionData[1] = xx[3];
  motionData[2] = xx[3];
  motionData[3] = - xx[4];
  motionData[4] = - (xx[1] + xx[8]);
  motionData[5] = - (xx[9] + xx[10]);
  motionData[6] = xx[7];
  motionData[7] = - xx[12];
  motionData[8] = xx[3];
  motionData[9] = xx[3];
  motionData[10] = - xx[13];
  motionData[11] = - xx[16];
  motionData[12] = - xx[17];
  motionData[13] = - 0.01;
  motionData[14] = - xx[18];
  motionData[15] = xx[3];
  motionData[16] = xx[3];
  motionData[17] = - xx[19];
  motionData[18] = xx[15] - xx[22];
  motionData[19] = - (xx[9] + xx[23]);
  motionData[20] = xx[7];
  motionData[21] = - xx[25];
  motionData[22] = xx[27];
  motionData[23] = xx[0];
  motionData[24] = xx[21];
  motionData[25] = - xx[38];
  motionData[26] = - xx[11];
  motionData[27] = - (5.0e-3 + xx[28]);
  motionData[28] = xx[2] * xx[12] - xx[4] * xx[13];
  motionData[29] = xx[3];
  motionData[30] = xx[3];
  motionData[31] = xx[2] * xx[13] + xx[12] * xx[4];
  motionData[32] = xx[6] * (xx[2] * xx[24] + xx[30] * xx[4]) - xx[16] - xx[8] -
    xx[1];
  motionData[33] = (xx[24] * xx[4] - xx[2] * xx[30]) * xx[6] - (xx[17] + xx[10])
    - xx[9];
  motionData[34] = 0.192;
  motionData[35] = xx[18] * xx[25] - xx[19] * xx[32];
  motionData[36] = - (xx[31] * xx[19] + xx[27] * xx[18]);
  motionData[37] = - (xx[27] * xx[19] - xx[18] * xx[31]);
  motionData[38] = xx[18] * xx[32] + xx[25] * xx[19];
  motionData[39] = xx[6] * (xx[18] * xx[36] + xx[37] * xx[19]) - xx[38] - xx[22]
    + xx[15];
  motionData[40] = (xx[36] * xx[19] - xx[18] * xx[37]) * xx[6] - (xx[11] + xx[23])
    - xx[9];
  motionData[41] = 0.197 - xx[28];
  motionData[42] = xx[3];
  motionData[43] = xx[3];
  motionData[44] = state[1];
  motionData[45] = xx[3];
  motionData[46] = - xx[39];
  motionData[47] = xx[3];
  motionData[48] = xx[3];
  motionData[49] = xx[3];
  motionData[50] = state[1] + state[3];
  motionData[51] = xx[5] - xx[6] * (xx[12] * xx[41] + xx[42] * xx[13]);
  motionData[52] = - (xx[40] + (xx[12] * xx[42] - xx[41] * xx[13]) * xx[6] + xx
                      [14] * state[3]);
  motionData[53] = xx[3];
  motionData[54] = xx[3];
  motionData[55] = xx[3];
  motionData[56] = state[5];
  motionData[57] = xx[3];
  motionData[58] = - xx[43];
  motionData[59] = xx[3];
  motionData[60] = - (xx[6] * (xx[20] * xx[32] + xx[25] * xx[44]) + xx[26] *
                      state[7]);
  motionData[61] = (xx[44] * xx[32] - xx[20] * xx[25]) * xx[6];
  motionData[62] = state[5] - (xx[27] * xx[20] + xx[31] * xx[44]) * xx[6] + xx
    [29] * state[7];
  motionData[63] = xx[45] + (xx[53] - xx[47] * xx[25]) * xx[6];
  motionData[64] = xx[6] * (xx[54] - xx[25] * xx[48]) - xx[46] +
    0.05548208580708968 * state[7];
  motionData[65] = xx[6] * (xx[55] + xx[25] * xx[49]);
}

static size_t computeAssemblyError_0(const RuntimeDerivedValuesBundle *rtdv,
  const double *state, const int *modeVector, const double *motionData, double
  *error)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[22];
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  xx[0] = motionData[28];
  xx[1] = motionData[29];
  xx[2] = motionData[30];
  xx[3] = motionData[31];
  xx[4] = 0.9998679088263617;
  xx[5] = 0.01625315043917926;
  xx[6] = xx[4] * motionData[35] + xx[5] * motionData[37];
  xx[7] = xx[4] * motionData[36] + xx[5] * motionData[38];
  xx[8] = xx[4] * motionData[37] - xx[5] * motionData[35];
  xx[9] = xx[4] * motionData[38] - xx[5] * motionData[36];
  pm_math_Quaternion_inverseCompose_ra(xx + 0, xx + 6, xx + 10);
  xx[0] = 6.093517183011606e-3;
  xx[1] = motionData[36];
  xx[2] = motionData[37];
  xx[3] = motionData[38];
  xx[4] = 0.06435386271755822;
  xx[5] = xx[4] * motionData[38] - xx[0] * motionData[36];
  xx[6] = xx[4] * motionData[37];
  xx[7] = xx[0] * motionData[37];
  xx[8] = xx[5];
  xx[9] = - xx[6];
  pm_math_Vector3_cross_ra(xx + 1, xx + 7, xx + 13);
  xx[1] = 2.0;
  xx[2] = motionData[29];
  xx[3] = motionData[30];
  xx[4] = motionData[31];
  xx[7] = 4.999999999999999e-3;
  xx[8] = 0.05834411356795617;
  xx[9] = xx[7] * motionData[29] - xx[8] * motionData[31];
  xx[10] = xx[8] * motionData[30];
  xx[16] = - (xx[7] * motionData[30]);
  xx[17] = xx[9];
  xx[18] = xx[10];
  pm_math_Vector3_cross_ra(xx + 2, xx + 16, xx + 19);
  error[0] = xx[11];
  error[1] = xx[12];
  error[2] = (xx[0] * motionData[35] * motionData[37] + xx[13]) * xx[1] +
    motionData[39] - ((xx[19] - xx[7] * motionData[28] * motionData[30]) * xx[1]
                      + motionData[32]) + 0.1226979762855144;
  error[3] = (xx[5] * motionData[35] + xx[14]) * xx[1] + motionData[40] - ((xx[9]
    * motionData[28] + xx[20]) * xx[1] + motionData[33]);
  error[4] = xx[1] * (xx[15] - xx[6] * motionData[35]) + motionData[41] - (xx[1]
    * (xx[21] + xx[10] * motionData[28]) + motionData[34]) + 0.0110935171830116;
  return 5;
}

size_t Robot_d2dba219_1_computeAssemblyError(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const double *state,
  const int *modeVector, const double *motionData, double *error)
{
  (void) mech;
  (void)rtdv;
  (void) state;
  (void) modeVector;
  (void) motionData;
  (void) error;
  switch (constraintIdx)
  {
   case 0:
    return computeAssemblyError_0(rtdv, state, modeVector, motionData, error);
  }

  return 0;
}

static size_t computeAssemblyJacobian_0(const RuntimeDerivedValuesBundle *rtdv,
  const double *state, const int *modeVector, const double *motionData, double
  *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[65];
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  xx[0] = motionData[28];
  xx[1] = motionData[29];
  xx[2] = motionData[30];
  xx[3] = motionData[31];
  xx[4] = 0.9998679088263617;
  xx[5] = 0.01625315043917926;
  xx[6] = xx[4] * motionData[35] + xx[5] * motionData[37];
  xx[7] = xx[4] * motionData[36] + xx[5] * motionData[38];
  xx[8] = xx[4] * motionData[37] - xx[5] * motionData[35];
  xx[9] = xx[4] * motionData[38] - xx[5] * motionData[36];
  pm_math_Quaternion_inverseCompose_ra(xx + 0, xx + 6, xx + 10);
  xx[14] = 2.0;
  xx[15] = motionData[8] * motionData[10] - motionData[7] * motionData[9];
  xx[16] = (motionData[7] * motionData[8] + motionData[9] * motionData[10]) *
    xx[14];
  xx[17] = 1.0;
  xx[18] = xx[17] - (motionData[8] * motionData[8] + motionData[9] * motionData
                     [9]) * xx[14];
  xx[19] = xx[14] * xx[15];
  xx[20] = xx[16];
  xx[21] = xx[18];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 19, xx + 22);
  pm_math_Quaternion_inverseXform_ra(xx + 6, xx + 22, xx + 0);
  xx[19] = - xx[0];
  xx[20] = - xx[1];
  xx[21] = - xx[2];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 19, xx + 0);
  xx[19] = (motionData[28] * motionData[30] + motionData[29] * motionData[31]) *
    xx[14];
  xx[20] = xx[14] * (motionData[30] * motionData[31] - motionData[28] *
                     motionData[29]);
  xx[21] = xx[17] - (motionData[29] * motionData[29] + motionData[30] *
                     motionData[30]) * xx[14];
  pm_math_Quaternion_inverseXform_ra(xx + 6, xx + 19, xx + 22);
  xx[6] = - xx[22];
  xx[7] = - xx[23];
  xx[8] = - xx[24];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 6, xx + 19);
  xx[6] = xx[14] * (motionData[22] * motionData[24] - motionData[21] *
                    motionData[23]);
  xx[7] = xx[17] - (motionData[22] * motionData[22] + motionData[23] *
                    motionData[23]) * xx[14];
  xx[8] = xx[5] * xx[7];
  xx[9] = xx[5] * xx[6];
  xx[23] = (motionData[21] * motionData[22] + motionData[23] * motionData[24]) *
    xx[14];
  xx[24] = xx[6] + xx[14] * (xx[4] * xx[8] - xx[5] * xx[9]);
  xx[25] = xx[23];
  xx[26] = xx[7] - (xx[4] * xx[9] + xx[5] * xx[8]) * xx[14];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 24, xx + 27);
  xx[8] = 0.0;
  xx[24] = xx[8];
  xx[25] = xx[8];
  xx[26] = xx[17];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 24, xx + 31);
  xx[0] = 0.5;
  xx[3] = xx[0] * state[0];
  xx[8] = sin(xx[3]);
  xx[9] = cos(xx[3]);
  xx[10] = xx[8] * motionData[10] - xx[9] * motionData[7];
  xx[11] = xx[8] * motionData[9] - xx[9] * motionData[8];
  xx[12] = - (xx[9] * motionData[9] + xx[8] * motionData[8]);
  xx[13] = - (xx[9] * motionData[10] + xx[8] * motionData[7]);
  xx[3] = 0.05834411356795617;
  xx[24] = - (4.999999999999999e-3 * xx[16]);
  xx[25] = 9.999999999999998e-3 * xx[15] - xx[3] * xx[18];
  xx[26] = xx[3] * xx[16];
  pm_math_Quaternion_xform_ra(xx + 10, xx + 24, xx + 15);
  xx[10] = xx[8] * motionData[12];
  xx[11] = xx[8] * motionData[11];
  xx[12] = 0.05760957276177599;
  xx[13] = xx[12] * xx[8];
  xx[18] = xx[0] * state[2];
  xx[19] = cos(xx[18]);
  xx[22] = sin(xx[18]);
  xx[18] = xx[19] * motionData[1] + xx[22] * motionData[2];
  xx[24] = xx[18] * xx[3];
  xx[25] = xx[22] * motionData[1] - xx[19] * motionData[2];
  xx[26] = xx[22] * motionData[0] + xx[19] * motionData[3];
  xx[27] = xx[26] * xx[3];
  xx[30] = xx[22] * motionData[3] - xx[19] * motionData[0];
  xx[34] = motionData[1];
  xx[35] = motionData[2];
  xx[36] = motionData[3];
  xx[31] = 0.06165588643208984;
  xx[37] = xx[31] * xx[22];
  xx[38] = xx[14] * xx[37] * xx[22] - xx[31];
  xx[22] = xx[38] * motionData[3];
  xx[31] = xx[14] * xx[19] * xx[37];
  xx[19] = xx[31] * motionData[3];
  xx[37] = xx[38] * motionData[1] - xx[31] * motionData[2];
  xx[39] = - xx[22];
  xx[40] = xx[19];
  xx[41] = xx[37];
  pm_math_Vector3_cross_ra(xx + 34, xx + 39, xx + 42);
  xx[34] = xx[0] * state[4];
  xx[35] = sin(xx[34]);
  xx[36] = cos(xx[34]);
  xx[45] = xx[35] * motionData[24] - xx[36] * motionData[21];
  xx[46] = xx[35] * motionData[23] - xx[36] * motionData[22];
  xx[47] = - (xx[36] * motionData[23] + xx[35] * motionData[22]);
  xx[48] = - (xx[36] * motionData[24] + xx[35] * motionData[21]);
  xx[34] = 6.093517183011606e-3;
  xx[39] = 0.06435386271755822;
  xx[49] = xx[34] * xx[23];
  xx[50] = xx[39] * xx[7] - xx[34] * xx[6];
  xx[51] = - (xx[39] * xx[23]);
  pm_math_Quaternion_xform_ra(xx + 45, xx + 49, xx + 39);
  xx[6] = xx[35] * motionData[26];
  xx[7] = xx[35] * motionData[25];
  xx[23] = 0.05760957276178814;
  xx[34] = xx[23] * xx[35];
  xx[45] = motionData[14];
  xx[46] = motionData[15];
  xx[47] = motionData[16];
  xx[48] = motionData[17];
  xx[49] = xx[0] * state[6];
  xx[0] = cos(xx[49]);
  xx[50] = xx[4] * xx[0];
  xx[51] = sin(xx[49]);
  xx[49] = 0.03250200708292485 * xx[51];
  xx[52] = 0.9994716702016028 * xx[51];
  xx[51] = xx[4] * xx[49] - xx[5] * xx[52];
  xx[53] = xx[5] * xx[0];
  xx[0] = xx[4] * xx[52] + xx[5] * xx[49];
  xx[54] = - xx[50];
  xx[55] = xx[51];
  xx[56] = - xx[53];
  xx[57] = - xx[0];
  pm_math_Quaternion_compose_ra(xx + 45, xx + 54, xx + 58);
  xx[4] = 0.06451791419288473;
  xx[5] = xx[4] * xx[59];
  xx[49] = xx[4] * xx[61];
  xx[52] = 0.05548208580708968;
  xx[54] = xx[51] * xx[52];
  xx[55] = xx[52] * xx[0];
  xx[62] = - (xx[14] * (xx[54] * xx[53] + xx[55] * xx[50]));
  xx[63] = xx[52] - (xx[55] * xx[0] + xx[51] * xx[54]) * xx[14];
  xx[64] = (xx[53] * xx[55] - xx[54] * xx[50]) * xx[14];
  pm_math_Quaternion_xform_ra(xx + 45, xx + 62, xx + 50);
  J[0] = xx[1];
  J[1] = xx[20];
  J[2] = xx[28];
  J[3] = xx[32];
  J[4] = xx[2];
  J[5] = xx[21];
  J[6] = xx[29];
  J[7] = xx[33];
  J[8] = - (xx[15] + xx[14] * (xx[10] * xx[8] - xx[9] * xx[11]) - motionData[12]
            + xx[14] * xx[9] * xx[13]);
  J[9] = - (xx[14] * (xx[24] * xx[25] - xx[27] * xx[30]) + xx[14] * (xx[42] -
             xx[22] * motionData[0]) + xx[31]);
  J[10] = xx[39] + xx[14] * (xx[6] * xx[35] - xx[36] * xx[7]) - motionData[26] +
    xx[14] * xx[36] * xx[34];
  J[11] = xx[14] * (xx[60] * xx[5] - xx[58] * xx[49]) + xx[50];
  J[12] = - (xx[16] + motionData[11] - ((xx[9] * xx[10] + xx[11] * xx[8]) * xx
              [14] - xx[14] * xx[13] * xx[8]) - xx[12]);
  J[13] = - (xx[38] + xx[14] * (xx[43] + xx[19] * motionData[0]) + (xx[26] * xx
              [27] + xx[18] * xx[24]) * xx[14] - xx[3]);
  J[14] = xx[40] + motionData[25] - ((xx[36] * xx[6] + xx[7] * xx[35]) * xx[14]
    - xx[14] * xx[34] * xx[35]) - xx[23];
  J[15] = xx[51] - (xx[61] * xx[49] + xx[59] * xx[5]) * xx[14] + xx[4];
  J[16] = - xx[17];
  J[17] = - ((xx[24] * xx[30] + xx[27] * xx[25]) * xx[14] + (xx[37] *
              motionData[0] + xx[44]) * xx[14]);
  J[18] = xx[41];
  J[19] = (xx[58] * xx[5] + xx[60] * xx[49]) * xx[14] + xx[52];
  return 5;
}

size_t Robot_d2dba219_1_computeAssemblyJacobian(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, boolean_T
  forVelocitySatisfaction, const double *state, const int *modeVector, const
  double *motionData, double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) modeVector;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
   case 0:
    return computeAssemblyJacobian_0(rtdv, state, modeVector, motionData, J);
  }

  return 0;
}

size_t Robot_d2dba219_1_computeFullAssemblyJacobian(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const int *modeVector,
  const double *motionData, double *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[65];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  xx[0] = motionData[28];
  xx[1] = motionData[29];
  xx[2] = motionData[30];
  xx[3] = motionData[31];
  xx[4] = 0.9998679088263617;
  xx[5] = 0.01625315043917926;
  xx[6] = xx[4] * motionData[35] + xx[5] * motionData[37];
  xx[7] = xx[4] * motionData[36] + xx[5] * motionData[38];
  xx[8] = xx[4] * motionData[37] - xx[5] * motionData[35];
  xx[9] = xx[4] * motionData[38] - xx[5] * motionData[36];
  pm_math_Quaternion_inverseCompose_ra(xx + 0, xx + 6, xx + 10);
  xx[14] = 2.0;
  xx[15] = motionData[8] * motionData[10] - motionData[7] * motionData[9];
  xx[16] = (motionData[7] * motionData[8] + motionData[9] * motionData[10]) *
    xx[14];
  xx[17] = 1.0;
  xx[18] = xx[17] - (motionData[8] * motionData[8] + motionData[9] * motionData
                     [9]) * xx[14];
  xx[19] = xx[14] * xx[15];
  xx[20] = xx[16];
  xx[21] = xx[18];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 19, xx + 22);
  pm_math_Quaternion_inverseXform_ra(xx + 6, xx + 22, xx + 0);
  xx[19] = - xx[0];
  xx[20] = - xx[1];
  xx[21] = - xx[2];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 19, xx + 0);
  xx[19] = (motionData[28] * motionData[30] + motionData[29] * motionData[31]) *
    xx[14];
  xx[20] = xx[14] * (motionData[30] * motionData[31] - motionData[28] *
                     motionData[29]);
  xx[21] = xx[17] - (motionData[29] * motionData[29] + motionData[30] *
                     motionData[30]) * xx[14];
  pm_math_Quaternion_inverseXform_ra(xx + 6, xx + 19, xx + 22);
  xx[6] = - xx[22];
  xx[7] = - xx[23];
  xx[8] = - xx[24];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 6, xx + 19);
  xx[6] = xx[14] * (motionData[22] * motionData[24] - motionData[21] *
                    motionData[23]);
  xx[7] = xx[17] - (motionData[22] * motionData[22] + motionData[23] *
                    motionData[23]) * xx[14];
  xx[8] = xx[5] * xx[7];
  xx[9] = xx[5] * xx[6];
  xx[23] = (motionData[21] * motionData[22] + motionData[23] * motionData[24]) *
    xx[14];
  xx[24] = xx[6] + xx[14] * (xx[4] * xx[8] - xx[5] * xx[9]);
  xx[25] = xx[23];
  xx[26] = xx[7] - (xx[4] * xx[9] + xx[5] * xx[8]) * xx[14];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 24, xx + 27);
  xx[8] = 0.0;
  xx[24] = xx[8];
  xx[25] = xx[8];
  xx[26] = xx[17];
  pm_math_Quaternion_compDeriv_ra(xx + 10, xx + 24, xx + 31);
  xx[0] = 0.5;
  xx[3] = xx[0] * state[0];
  xx[8] = sin(xx[3]);
  xx[9] = cos(xx[3]);
  xx[10] = xx[8] * motionData[10] - xx[9] * motionData[7];
  xx[11] = xx[8] * motionData[9] - xx[9] * motionData[8];
  xx[12] = - (xx[9] * motionData[9] + xx[8] * motionData[8]);
  xx[13] = - (xx[9] * motionData[10] + xx[8] * motionData[7]);
  xx[3] = 0.05834411356795617;
  xx[24] = - (4.999999999999999e-3 * xx[16]);
  xx[25] = 9.999999999999998e-3 * xx[15] - xx[3] * xx[18];
  xx[26] = xx[3] * xx[16];
  pm_math_Quaternion_xform_ra(xx + 10, xx + 24, xx + 15);
  xx[10] = xx[8] * motionData[12];
  xx[11] = xx[8] * motionData[11];
  xx[12] = 0.05760957276177599;
  xx[13] = xx[12] * xx[8];
  xx[18] = xx[0] * state[2];
  xx[19] = cos(xx[18]);
  xx[22] = sin(xx[18]);
  xx[18] = xx[19] * motionData[1] + xx[22] * motionData[2];
  xx[24] = xx[18] * xx[3];
  xx[25] = xx[22] * motionData[1] - xx[19] * motionData[2];
  xx[26] = xx[22] * motionData[0] + xx[19] * motionData[3];
  xx[27] = xx[26] * xx[3];
  xx[30] = xx[22] * motionData[3] - xx[19] * motionData[0];
  xx[34] = motionData[1];
  xx[35] = motionData[2];
  xx[36] = motionData[3];
  xx[31] = 0.06165588643208984;
  xx[37] = xx[31] * xx[22];
  xx[38] = xx[14] * xx[37] * xx[22] - xx[31];
  xx[22] = xx[38] * motionData[3];
  xx[31] = xx[14] * xx[19] * xx[37];
  xx[19] = xx[31] * motionData[3];
  xx[37] = xx[38] * motionData[1] - xx[31] * motionData[2];
  xx[39] = - xx[22];
  xx[40] = xx[19];
  xx[41] = xx[37];
  pm_math_Vector3_cross_ra(xx + 34, xx + 39, xx + 42);
  xx[34] = xx[0] * state[4];
  xx[35] = sin(xx[34]);
  xx[36] = cos(xx[34]);
  xx[45] = xx[35] * motionData[24] - xx[36] * motionData[21];
  xx[46] = xx[35] * motionData[23] - xx[36] * motionData[22];
  xx[47] = - (xx[36] * motionData[23] + xx[35] * motionData[22]);
  xx[48] = - (xx[36] * motionData[24] + xx[35] * motionData[21]);
  xx[34] = 6.093517183011606e-3;
  xx[39] = 0.06435386271755822;
  xx[49] = xx[34] * xx[23];
  xx[50] = xx[39] * xx[7] - xx[34] * xx[6];
  xx[51] = - (xx[39] * xx[23]);
  pm_math_Quaternion_xform_ra(xx + 45, xx + 49, xx + 39);
  xx[6] = xx[35] * motionData[26];
  xx[7] = xx[35] * motionData[25];
  xx[23] = 0.05760957276178814;
  xx[34] = xx[23] * xx[35];
  xx[45] = motionData[14];
  xx[46] = motionData[15];
  xx[47] = motionData[16];
  xx[48] = motionData[17];
  xx[49] = xx[0] * state[6];
  xx[0] = cos(xx[49]);
  xx[50] = xx[4] * xx[0];
  xx[51] = sin(xx[49]);
  xx[49] = 0.03250200708292485 * xx[51];
  xx[52] = 0.9994716702016028 * xx[51];
  xx[51] = xx[4] * xx[49] - xx[5] * xx[52];
  xx[53] = xx[5] * xx[0];
  xx[0] = xx[4] * xx[52] + xx[5] * xx[49];
  xx[54] = - xx[50];
  xx[55] = xx[51];
  xx[56] = - xx[53];
  xx[57] = - xx[0];
  pm_math_Quaternion_compose_ra(xx + 45, xx + 54, xx + 58);
  xx[4] = 0.06451791419288473;
  xx[5] = xx[4] * xx[59];
  xx[49] = xx[4] * xx[61];
  xx[52] = 0.05548208580708968;
  xx[54] = xx[51] * xx[52];
  xx[55] = xx[52] * xx[0];
  xx[62] = - (xx[14] * (xx[54] * xx[53] + xx[55] * xx[50]));
  xx[63] = xx[52] - (xx[55] * xx[0] + xx[51] * xx[54]) * xx[14];
  xx[64] = (xx[53] * xx[55] - xx[54] * xx[50]) * xx[14];
  pm_math_Quaternion_xform_ra(xx + 45, xx + 62, xx + 50);
  J[0] = xx[1];
  J[1] = xx[20];
  J[2] = xx[28];
  J[3] = xx[32];
  J[4] = xx[2];
  J[5] = xx[21];
  J[6] = xx[29];
  J[7] = xx[33];
  J[8] = - (xx[15] + xx[14] * (xx[10] * xx[8] - xx[9] * xx[11]) - motionData[12]
            + xx[14] * xx[9] * xx[13]);
  J[9] = - (xx[14] * (xx[24] * xx[25] - xx[27] * xx[30]) + xx[14] * (xx[42] -
             xx[22] * motionData[0]) + xx[31]);
  J[10] = xx[39] + xx[14] * (xx[6] * xx[35] - xx[36] * xx[7]) - motionData[26] +
    xx[14] * xx[36] * xx[34];
  J[11] = xx[14] * (xx[60] * xx[5] - xx[58] * xx[49]) + xx[50];
  J[12] = - (xx[16] + motionData[11] - ((xx[9] * xx[10] + xx[11] * xx[8]) * xx
              [14] - xx[14] * xx[13] * xx[8]) - xx[12]);
  J[13] = - (xx[38] + xx[14] * (xx[43] + xx[19] * motionData[0]) + (xx[26] * xx
              [27] + xx[18] * xx[24]) * xx[14] - xx[3]);
  J[14] = xx[40] + motionData[25] - ((xx[36] * xx[6] + xx[7] * xx[35]) * xx[14]
    - xx[14] * xx[34] * xx[35]) - xx[23];
  J[15] = xx[51] - (xx[61] * xx[49] + xx[59] * xx[5]) * xx[14] + xx[4];
  J[16] = - xx[17];
  J[17] = - ((xx[24] * xx[30] + xx[27] * xx[25]) * xx[14] + (xx[37] *
              motionData[0] + xx[44]) * xx[14]);
  J[18] = xx[41];
  J[19] = (xx[58] * xx[5] + xx[60] * xx[49]) * xx[14] + xx[52];
  return 5;
}

static int isInKinematicSingularity_0(const RuntimeDerivedValuesBundle *rtdv,
  const int *modeVector, const double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  (void) motionData;
  return 0;
}

int Robot_d2dba219_1_isInKinematicSingularity(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const int *modeVector,
  const double *motionData)
{
  (void) mech;
  (void) rtdv
    ;
  (void) modeVector;
  (void) motionData;
  switch (constraintIdx)
  {
   case 0:
    return isInKinematicSingularity_0(rtdv, modeVector, motionData);
  }

  return 0;
}

PmfMessageId Robot_d2dba219_1_convertStateVector(const void *asmMech, const
  RuntimeDerivedValuesBundle *rtdv, const void *simMech, const double *asmState,
  const int *asmModeVector, const int *simModeVector, double *simState, void
  *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) asmMech;
  (void) rtdvd;
  (void) rtdvi;
  (void) simMech;
  (void) asmModeVector;
  (void) simModeVector;
  (void) neDiagMgr;
  simState[0] = asmState[0];
  simState[1] = asmState[1];
  simState[2] = asmState[2];
  simState[3] = asmState[3];
  simState[4] = asmState[4];
  simState[5] = asmState[5];
  simState[6] = asmState[6];
  simState[7] = asmState[7];
  simState[8] = asmState[8];
  simState[9] = asmState[9];
  return NULL;
}
