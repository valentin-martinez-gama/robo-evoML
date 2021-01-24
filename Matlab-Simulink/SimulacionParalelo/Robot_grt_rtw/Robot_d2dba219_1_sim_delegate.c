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

void Robot_d2dba219_1_resetSimStateVector(const void *mech, double *state)
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

static void perturbSimJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbSimJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[1] = state[1] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_1_0(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbSimJointPrimitiveState_1_0v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[3] = state[3] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_2_0(double mag, double *state)
{
  state[4] = state[4] + mag;
}

static void perturbSimJointPrimitiveState_2_0v(double mag, double *state)
{
  state[4] = state[4] + mag;
  state[5] = state[5] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_3_0(double mag, double *state)
{
  state[6] = state[6] + mag;
}

static void perturbSimJointPrimitiveState_3_0v(double mag, double *state)
{
  state[6] = state[6] + mag;
  state[7] = state[7] - 0.875 * mag;
}

void Robot_d2dba219_1_perturbSimJointPrimitiveState(const void *mech, size_t
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
    perturbSimJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbSimJointPrimitiveState_0_0v(mag, state);
    break;

   case 12:
    perturbSimJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbSimJointPrimitiveState_1_0v(mag, state);
    break;

   case 24:
    perturbSimJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbSimJointPrimitiveState_2_0v(mag, state);
    break;

   case 36:
    perturbSimJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbSimJointPrimitiveState_3_0v(mag, state);
    break;
  }
}

void Robot_d2dba219_1_perturbFlexibleBodyState(const void *mech, size_t stageIdx,
  double mag, boolean_T doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch (stageIdx * 2 + (doPerturbVelocity ? 1 : 0))
  {
  }
}

void Robot_d2dba219_1_constructStateVector(const void *mech, const double
  *solverState, const double *u, const double *uDot, double *discreteState,
  double *fullState)
{
  (void) mech;
  (void) u;
  (void) uDot;
  (void) discreteState;
  fullState[0] = solverState[0];
  fullState[1] = solverState[1];
  fullState[2] = solverState[2];
  fullState[3] = solverState[3];
  fullState[4] = solverState[4];
  fullState[5] = solverState[5];
  fullState[6] = solverState[6];
  fullState[7] = solverState[7];
  fullState[8] = solverState[8];
  fullState[9] = solverState[9];
}

void Robot_d2dba219_1_extractSolverStateVector(const void *mech, const double
  *fullState, double *solverState)
{
  (void) mech;
  solverState[0] = fullState[0];
  solverState[1] = fullState[1];
  solverState[2] = fullState[2];
  solverState[3] = fullState[3];
  solverState[4] = fullState[4];
  solverState[5] = fullState[5];
  solverState[6] = fullState[6];
  solverState[7] = fullState[7];
  solverState[8] = fullState[8];
  solverState[9] = fullState[9];
}

int Robot_d2dba219_1_isPositionViolation(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[3];
  double xx[27];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  xx[0] = 2.0;
  xx[1] = 0.01625315043917926;
  xx[2] = 0.5;
  xx[3] = xx[2] * state[6];
  xx[4] = cos(xx[3]);
  xx[5] = xx[1] * xx[4];
  xx[6] = xx[2] * state[4];
  xx[7] = sin(xx[6]);
  xx[8] = 0.9998679088263617;
  xx[9] = sin(xx[3]);
  xx[3] = 0.03250200708292485 * xx[9];
  xx[10] = 0.9994716702016028 * xx[9];
  xx[9] = xx[8] * xx[3] - xx[1] * xx[10];
  xx[11] = cos(xx[6]);
  xx[6] = xx[5] * xx[7] + xx[9] * xx[11];
  xx[12] = xx[9] * xx[7] - xx[11] * xx[5];
  xx[13] = xx[8] * xx[10] + xx[1] * xx[3];
  xx[1] = xx[8] * xx[4];
  xx[3] = xx[11] * xx[13] + xx[1] * xx[7];
  xx[14] = - xx[6];
  xx[15] = - xx[12];
  xx[16] = xx[3];
  xx[4] = 6.093517183011606e-3;
  xx[8] = xx[12] * xx[4];
  xx[10] = 0.06435386271755822;
  xx[17] = xx[3] * xx[10] + xx[4] * xx[6];
  xx[18] = - xx[8];
  xx[19] = xx[17];
  xx[20] = xx[12] * xx[10];
  pm_math_Vector3_cross_ra(xx + 14, xx + 18, xx + 21);
  xx[3] = xx[11] * xx[1] - xx[7] * xx[13];
  xx[14] = xx[9];
  xx[15] = - xx[5];
  xx[16] = - xx[13];
  xx[4] = 0.01218799303507748;
  xx[6] = xx[4] * xx[5];
  xx[10] = 0.0559077577774378;
  xx[12] = xx[10] * xx[13] - xx[9] * xx[4];
  xx[18] = - xx[6];
  xx[19] = xx[12];
  xx[20] = - (xx[10] * xx[5]);
  pm_math_Vector3_cross_ra(xx + 14, xx + 18, xx + 24);
  xx[4] = (xx[25] - xx[1] * xx[12]) * xx[0];
  xx[5] = xx[4] * xx[7];
  xx[9] = 6.482669460775074e-3 + (xx[6] * xx[1] + xx[24]) * xx[0];
  xx[1] = xx[7] * xx[9];
  xx[6] = 0.05760957276178814 * xx[7];
  xx[10] = xx[2] * state[2];
  xx[12] = sin(xx[10]);
  xx[13] = 0.06165588643208984 * xx[12];
  xx[14] = xx[0] * xx[13] * xx[12] - 0.1240463136703027;
  xx[15] = xx[2] * state[0];
  xx[2] = cos(xx[15]);
  xx[16] = cos(xx[10]);
  xx[10] = xx[0] * xx[16] * xx[13];
  xx[13] = sin(xx[15]);
  xx[15] = xx[10] * xx[13];
  xx[18] = xx[14] * xx[13];
  xx[19] = 0.05760957276177599 * xx[13];
  xx[20] = xx[2] * xx[12] + xx[16] * xx[13];
  xx[24] = xx[20] * 0.05834411356795617;
  xx[25] = fabs(xx[0] * (xx[21] - xx[8] * xx[3]) + xx[0] * (xx[11] * xx[5] + xx
    [1] * xx[7]) - xx[9] + xx[0] * xx[6] * xx[7] - (xx[14] + xx[0] * (xx[2] *
    xx[15] - xx[18] * xx[13]) + xx[0] * xx[19] * xx[13] + xx[0] * xx[20] * xx[24])
                + 0.2796979762855022);
  xx[26] = fabs(xx[0] * (xx[22] + xx[17] * xx[3]) + (xx[5] * xx[7] - xx[11] *
    xx[1]) * xx[0] - (xx[4] + xx[0] * xx[11] * xx[6]) - ((xx[2] * xx[18] + xx[15]
    * xx[13]) * xx[0] - (xx[10] + xx[0] * xx[2] * xx[19]) - xx[0] * xx[24] *
    (xx[2] * xx[16] - xx[13] * xx[12])));
  ii[0] = 25;

  {
    int ll;
    for (ll = 26; ll < 27; ++ll)
      if (xx[ll] > xx[ii[0]])
        ii[0] = ll;
  }

  ii[0] -= 25;
  xx[0] = xx[25 + (ii[0])];
  xx[1] = xx[0] - 1.0e-9;
  if (xx[1] < 0.0)
    ii[0] = -1;
  else if (xx[1] > 0.0)
    ii[0] = +1;
  else
    ii[0] = 0;
  ii[1] = ii[0];
  if (0 > ii[1])
    ii[1] = 0;
  return ii[1];
}

int Robot_d2dba219_1_isVelocityViolation(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[3];
  double xx[26];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  xx[0] = 0.5;
  xx[1] = xx[0] * state[4];
  xx[2] = cos(xx[1]);
  xx[3] = 0.9998679088263617;
  xx[4] = xx[0] * state[6];
  xx[5] = cos(xx[4]);
  xx[6] = xx[3] * xx[5];
  xx[7] = sin(xx[1]);
  xx[1] = 0.9994716702016028;
  xx[8] = sin(xx[4]);
  xx[4] = xx[1] * xx[8];
  xx[9] = 0.01625315043917926;
  xx[10] = 0.03250200708292485;
  xx[11] = xx[10] * xx[8];
  xx[8] = xx[3] * xx[4] + xx[9] * xx[11];
  xx[12] = xx[9] * xx[5];
  xx[5] = xx[3] * xx[11] - xx[9] * xx[4];
  xx[13] = xx[2] * xx[6] - xx[7] * xx[8];
  xx[14] = - (xx[12] * xx[7] + xx[5] * xx[2]);
  xx[15] = - (xx[5] * xx[7] - xx[2] * xx[12]);
  xx[16] = xx[2] * xx[8] + xx[6] * xx[7];
  xx[3] = 6.093517183011606e-3;
  xx[4] = xx[12] * state[5];
  xx[9] = xx[5] * state[5];
  xx[11] = 2.0;
  xx[17] = (xx[4] * xx[8] - xx[9] * xx[6]) * xx[11];
  xx[18] = 0.06435386271755822;
  xx[19] = xx[3] * xx[17];
  xx[20] = (state[5] - (xx[5] * xx[9] + xx[12] * xx[4]) * xx[11] + xx[1] *
            state[7]) * xx[18] + (xx[11] * (xx[9] * xx[8] + xx[6] * xx[4]) + xx
    [10] * state[7]) * xx[3];
  xx[21] = - (xx[18] * xx[17]);
  pm_math_Quaternion_xform_ra(xx + 13, xx + 19, xx + 22);
  xx[13] = xx[5];
  xx[14] = - xx[12];
  xx[15] = - xx[8];
  xx[1] = 0.01218799303507748;
  xx[3] = xx[1] * xx[12];
  xx[4] = 0.0559077577774378;
  xx[9] = xx[4] * xx[8] - xx[5] * xx[1];
  xx[16] = - xx[3];
  xx[17] = xx[9];
  xx[18] = - (xx[4] * xx[12]);
  pm_math_Vector3_cross_ra(xx + 13, xx + 16, xx + 19);
  xx[1] = 0.05548208580708968;
  xx[4] = xx[5] * xx[1];
  xx[10] = xx[1] * xx[8];
  xx[13] = xx[11] * (xx[20] - xx[6] * xx[9]) * state[5] - xx[11] * (xx[4] * xx
    [12] + xx[10] * xx[6]) * state[7];
  xx[9] = (xx[1] - (xx[10] * xx[8] + xx[5] * xx[4]) * xx[11]) * state[7] -
    (6.482669460775074e-3 + (xx[3] * xx[6] + xx[19]) * xx[11]) * state[5];
  xx[1] = xx[9] * xx[7];
  xx[3] = xx[13] * xx[7];
  xx[4] = 0.05760957276178814;
  xx[5] = xx[4] * xx[7];
  xx[6] = xx[0] * state[2];
  xx[8] = cos(xx[6]);
  xx[10] = 0.06165588643208984;
  xx[12] = sin(xx[6]);
  xx[6] = xx[10] * xx[12];
  xx[14] = xx[8] * xx[6];
  xx[15] = xx[11] * xx[14] * state[1] + xx[11] * xx[14] * state[3];
  xx[14] = xx[0] * state[0];
  xx[0] = cos(xx[14]);
  xx[16] = xx[11] * xx[6] * xx[12];
  xx[6] = (xx[16] - xx[10]) * state[3] + (xx[16] - 0.1240463136703027) * state[1];
  xx[10] = sin(xx[14]);
  xx[14] = xx[6] * xx[10];
  xx[16] = xx[10] * xx[15];
  xx[17] = 0.05760957276177599;
  xx[18] = xx[17] * xx[10];
  xx[19] = xx[0] * xx[12] + xx[8] * xx[10];
  xx[20] = (state[1] + state[3]) * 0.05834411356795617;
  xx[21] = xx[19] * xx[20];
  xx[24] = fabs(xx[22] + xx[13] - (xx[2] * xx[1] + xx[3] * xx[7]) * xx[11] + xx
                [11] * xx[2] * xx[5] * state[5] - (xx[15] - (xx[0] * xx[14] +
    xx[16] * xx[10]) * xx[11] + xx[11] * xx[0] * xx[18] * state[1] + xx[11] *
    xx[21] * (xx[0] * xx[8] - xx[10] * xx[12])));
  xx[25] = fabs(xx[23] + (xx[11] * xx[5] * xx[7] - xx[4]) * state[5] + xx[9] +
                xx[11] * (xx[2] * xx[3] - xx[1] * xx[7]) - (xx[11] * xx[19] *
    xx[21] - xx[20] + (xx[11] * xx[18] * xx[10] - xx[17]) * state[1] + xx[6] +
    xx[11] * (xx[0] * xx[16] - xx[14] * xx[10])));
  ii[0] = 24;

  {
    int ll;
    for (ll = 25; ll < 26; ++ll)
      if (xx[ll] > xx[ii[0]])
        ii[0] = ll;
  }

  ii[0] -= 24;
  xx[0] = xx[24 + (ii[0])];
  xx[1] = xx[0] - 1.0e-9;
  if (xx[1] < 0.0)
    ii[0] = -1;
  else if (xx[1] > 0.0)
    ii[0] = +1;
  else
    ii[0] = 0;
  ii[1] = ii[0];
  if (0 > ii[1])
    ii[1] = 0;
  return ii[1];
}

PmfMessageId Robot_d2dba219_1_projectStateSim(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const int
  *modeVector, const double *input, double *state, void *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  int ii[4];
  double xx[90];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) input;
  (void) neDiagMgr;
  xx[0] = 2.0;
  xx[1] = 0.5;
  xx[2] = xx[1] * state[0];
  xx[3] = cos(xx[2]);
  xx[4] = xx[1] * state[2];
  xx[5] = sin(xx[4]);
  xx[6] = cos(xx[4]);
  xx[4] = sin(xx[2]);
  xx[2] = xx[3] * xx[5] + xx[6] * xx[4];
  xx[7] = 0.05834411356795617;
  xx[8] = xx[2] * xx[7];
  xx[9] = xx[0] * xx[8] * (xx[3] * xx[6] - xx[4] * xx[5]);
  xx[10] = 0.06165588643208984;
  xx[11] = xx[10] * xx[5];
  xx[12] = xx[0] * xx[6] * xx[11];
  xx[6] = xx[0] * xx[11] * xx[5];
  xx[5] = 0.1240463136703027;
  xx[11] = xx[6] - xx[5];
  xx[13] = xx[11] * xx[4];
  xx[14] = xx[12] * xx[4];
  xx[15] = xx[14] * xx[4];
  xx[16] = (xx[3] * xx[13] + xx[15]) * xx[0];
  xx[17] = 0.05760957276177599;
  xx[18] = xx[17] * xx[4];
  xx[19] = xx[0] * xx[3] * xx[18];
  xx[20] = xx[6] - xx[10];
  xx[6] = xx[4] * xx[20];
  xx[21] = xx[1] * state[4];
  xx[22] = cos(xx[21]);
  xx[23] = 0.9998679088263617;
  xx[24] = xx[1] * state[6];
  xx[25] = cos(xx[24]);
  xx[26] = xx[23] * xx[25];
  xx[27] = sin(xx[21]);
  xx[21] = 0.9994716702016028;
  xx[28] = sin(xx[24]);
  xx[24] = xx[21] * xx[28];
  xx[29] = 0.01625315043917926;
  xx[30] = 0.03250200708292485;
  xx[31] = xx[30] * xx[28];
  xx[28] = xx[23] * xx[24] + xx[29] * xx[31];
  xx[32] = xx[22] * xx[26] - xx[27] * xx[28];
  xx[33] = xx[29] * xx[25];
  xx[25] = xx[23] * xx[31] - xx[29] * xx[24];
  xx[24] = xx[33] * xx[27] + xx[25] * xx[22];
  xx[31] = - xx[24];
  xx[34] = xx[25] * xx[27] - xx[22] * xx[33];
  xx[35] = - xx[34];
  xx[36] = xx[22] * xx[28] + xx[26] * xx[27];
  xx[37] = xx[32];
  xx[38] = xx[31];
  xx[39] = xx[35];
  xx[40] = xx[36];
  xx[41] = 6.093517183011606e-3;
  xx[42] = (xx[33] * xx[28] - xx[25] * xx[26]) * xx[0];
  xx[43] = 0.06435386271755822;
  xx[44] = 1.0;
  xx[45] = 0.01218703436602321;
  xx[46] = xx[41] * xx[42];
  xx[47] = xx[43] * (xx[44] - (xx[25] * xx[25] + xx[33] * xx[33]) * xx[0]) + xx
    [45] * (xx[25] * xx[28] + xx[33] * xx[26]);
  xx[48] = - (xx[43] * xx[42]);
  pm_math_Quaternion_xform_ra(xx + 37, xx + 46, xx + 49);
  xx[37] = xx[25];
  xx[38] = - xx[33];
  xx[39] = - xx[28];
  xx[40] = 0.01218799303507748;
  xx[42] = xx[40] * xx[33];
  xx[46] = 0.0559077577774378;
  xx[47] = xx[46] * xx[28] - xx[25] * xx[40];
  xx[52] = - xx[42];
  xx[53] = xx[47];
  xx[54] = - (xx[46] * xx[33]);
  pm_math_Vector3_cross_ra(xx + 37, xx + 52, xx + 55);
  xx[37] = (xx[56] - xx[26] * xx[47]) * xx[0];
  xx[38] = xx[37] * xx[27];
  xx[39] = 6.482669460775074e-3;
  xx[47] = xx[39] + (xx[42] * xx[26] + xx[55]) * xx[0];
  xx[42] = xx[27] * xx[47];
  xx[48] = (xx[38] * xx[27] - xx[22] * xx[42]) * xx[0];
  xx[52] = 0.05760957276178814;
  xx[53] = xx[52] * xx[27];
  xx[54] = xx[0] * xx[22] * xx[53];
  xx[55] = 0.06451791419288473;
  xx[56] = xx[55] * xx[24];
  xx[57] = xx[36] * xx[55];
  xx[58] = 0.05548208580708968;
  xx[59] = xx[25] * xx[58];
  xx[60] = xx[58] * xx[28];
  xx[61] = xx[0] * (xx[59] * xx[33] + xx[60] * xx[26]);
  xx[26] = xx[58] - (xx[60] * xx[28] + xx[25] * xx[59]) * xx[0];
  xx[25] = xx[27] * xx[26];
  xx[28] = xx[61] * xx[27];
  xx[33] = xx[3] * xx[14];
  xx[14] = xx[11] + xx[0] * (xx[33] - xx[13] * xx[4]);
  xx[11] = xx[0] * xx[18] * xx[4];
  xx[13] = xx[0] * xx[2] * xx[8];
  xx[2] = 0.1159536863297322;
  xx[8] = xx[0] * (xx[22] * xx[38] + xx[42] * xx[27]) - xx[47];
  xx[18] = xx[0] * xx[53] * xx[27];
  xx[62] = - (xx[9] + xx[12] - xx[16] + xx[19]);
  xx[63] = - (xx[9] + xx[12] - xx[0] * (xx[15] + xx[3] * xx[6]));
  xx[64] = xx[49] + xx[37] - xx[48] + xx[54];
  xx[65] = xx[0] * (xx[34] * xx[56] - xx[57] * xx[32]) - (xx[61] + (xx[22] * xx
    [25] - xx[28] * xx[27]) * xx[0]);
  xx[66] = - (xx[14] + xx[11] + xx[13] - xx[2]);
  xx[67] = - (xx[20] - ((xx[6] * xx[4] - xx[33]) * xx[0] - xx[13]) - xx[7]);
  xx[68] = xx[50] + xx[8] + xx[18] - xx[52];
  xx[69] = xx[26] - xx[0] * (xx[22] * xx[28] + xx[25] * xx[27]) - (xx[36] * xx
    [57] + xx[56] * xx[24]) * xx[0] + xx[55];
  xx[25] = xx[31];
  xx[26] = xx[35];
  xx[27] = xx[36];
  xx[3] = xx[34] * xx[41];
  xx[4] = xx[36] * xx[43] + xx[41] * xx[24];
  xx[49] = - xx[3];
  xx[50] = xx[4];
  xx[51] = xx[34] * xx[43];
  pm_math_Vector3_cross_ra(xx + 25, xx + 49, xx + 33);
  xx[6] = 0.2796979762855022;
  xx[24] = - (xx[0] * (xx[33] - xx[3] * xx[32]) + xx[8] + xx[18] - (xx[14] + xx
    [11] + xx[13]) + xx[6]);
  xx[25] = xx[16] - (xx[12] + xx[19]) - xx[9] - (xx[0] * (xx[34] + xx[4] * xx[32])
    + xx[48] - (xx[37] + xx[54]));
  xx[3] = 1.0e-8;
  memcpy(xx + 31, xx + 62, 8 * sizeof(double));
  factorAndSolveWide(2, 4, xx + 31, xx + 8, xx + 15, ii + 0, xx + 24, xx[3], xx
                     + 11);
  xx[4] = state[0] + xx[11];
  xx[8] = xx[4] * xx[1];
  xx[9] = cos(xx[8]);
  xx[15] = state[2] + xx[12];
  xx[16] = xx[15] * xx[1];
  xx[18] = sin(xx[16]);
  xx[19] = cos(xx[16]);
  xx[16] = sin(xx[8]);
  xx[8] = xx[9] * xx[18] + xx[19] * xx[16];
  xx[20] = xx[8] * xx[7];
  xx[22] = xx[0] * xx[20] * (xx[9] * xx[19] - xx[16] * xx[18]);
  xx[24] = xx[10] * xx[18];
  xx[25] = xx[0] * xx[19] * xx[24];
  xx[19] = xx[0] * xx[24] * xx[18];
  xx[18] = xx[19] - xx[5];
  xx[24] = xx[18] * xx[16];
  xx[26] = xx[25] * xx[16];
  xx[27] = xx[26] * xx[16];
  xx[28] = (xx[9] * xx[24] + xx[27]) * xx[0];
  xx[31] = xx[17] * xx[16];
  xx[32] = xx[0] * xx[9] * xx[31];
  xx[33] = xx[19] - xx[10];
  xx[19] = xx[16] * xx[33];
  xx[34] = state[4] + xx[13];
  xx[35] = xx[34] * xx[1];
  xx[36] = cos(xx[35]);
  xx[11] = state[6] + xx[14];
  xx[12] = xx[11] * xx[1];
  xx[13] = cos(xx[12]);
  xx[14] = xx[23] * xx[13];
  xx[37] = sin(xx[35]);
  xx[35] = sin(xx[12]);
  xx[12] = xx[21] * xx[35];
  xx[38] = xx[30] * xx[35];
  xx[35] = xx[23] * xx[12] + xx[29] * xx[38];
  xx[42] = xx[36] * xx[14] - xx[37] * xx[35];
  xx[47] = xx[29] * xx[13];
  xx[13] = xx[23] * xx[38] - xx[29] * xx[12];
  xx[12] = xx[47] * xx[37] + xx[13] * xx[36];
  xx[38] = - xx[12];
  xx[48] = xx[13] * xx[37] - xx[36] * xx[47];
  xx[49] = - xx[48];
  xx[50] = xx[36] * xx[35] + xx[14] * xx[37];
  xx[59] = xx[42];
  xx[60] = xx[38];
  xx[61] = xx[49];
  xx[62] = xx[50];
  xx[51] = (xx[47] * xx[35] - xx[13] * xx[14]) * xx[0];
  xx[63] = xx[41] * xx[51];
  xx[64] = xx[43] * (xx[44] - (xx[13] * xx[13] + xx[47] * xx[47]) * xx[0]) + xx
    [45] * (xx[13] * xx[35] + xx[47] * xx[14]);
  xx[65] = - (xx[43] * xx[51]);
  pm_math_Quaternion_xform_ra(xx + 59, xx + 63, xx + 66);
  xx[59] = xx[13];
  xx[60] = - xx[47];
  xx[61] = - xx[35];
  xx[51] = xx[40] * xx[47];
  xx[53] = xx[46] * xx[35] - xx[13] * xx[40];
  xx[62] = - xx[51];
  xx[63] = xx[53];
  xx[64] = - (xx[46] * xx[47]);
  pm_math_Vector3_cross_ra(xx + 59, xx + 62, xx + 69);
  xx[54] = (xx[70] - xx[14] * xx[53]) * xx[0];
  xx[53] = xx[54] * xx[37];
  xx[56] = xx[39] + (xx[51] * xx[14] + xx[69]) * xx[0];
  xx[51] = xx[37] * xx[56];
  xx[57] = (xx[53] * xx[37] - xx[36] * xx[51]) * xx[0];
  xx[59] = xx[52] * xx[37];
  xx[60] = xx[0] * xx[36] * xx[59];
  xx[61] = xx[55] * xx[12];
  xx[62] = xx[50] * xx[55];
  xx[63] = xx[13] * xx[58];
  xx[64] = xx[58] * xx[35];
  xx[65] = xx[0] * (xx[63] * xx[47] + xx[64] * xx[14]);
  xx[14] = xx[58] - (xx[64] * xx[35] + xx[13] * xx[63]) * xx[0];
  xx[13] = xx[37] * xx[14];
  xx[35] = xx[65] * xx[37];
  xx[47] = xx[9] * xx[26];
  xx[26] = xx[18] + xx[0] * (xx[47] - xx[24] * xx[16]);
  xx[18] = xx[0] * xx[31] * xx[16];
  xx[24] = xx[0] * xx[8] * xx[20];
  xx[8] = xx[0] * (xx[36] * xx[53] + xx[51] * xx[37]) - xx[56];
  xx[20] = xx[0] * xx[59] * xx[37];
  xx[68] = - (xx[22] + xx[25] - xx[28] + xx[32]);
  xx[69] = - (xx[22] + xx[25] - xx[0] * (xx[27] + xx[9] * xx[19]));
  xx[70] = xx[66] + xx[54] - xx[57] + xx[60];
  xx[71] = xx[0] * (xx[48] * xx[61] - xx[62] * xx[42]) - (xx[65] + (xx[36] * xx
    [13] - xx[35] * xx[37]) * xx[0]);
  xx[72] = - (xx[26] + xx[18] + xx[24] - xx[2]);
  xx[73] = - (xx[33] - ((xx[19] * xx[16] - xx[47]) * xx[0] - xx[24]) - xx[7]);
  xx[74] = xx[67] + xx[8] + xx[20] - xx[52];
  xx[75] = xx[14] - xx[0] * (xx[36] * xx[35] + xx[13] * xx[37]) - (xx[50] * xx
    [62] + xx[61] * xx[12]) * xx[0] + xx[55];
  xx[35] = xx[38];
  xx[36] = xx[49];
  xx[37] = xx[50];
  xx[9] = xx[48] * xx[41];
  xx[13] = xx[50] * xx[43] + xx[41] * xx[12];
  xx[49] = - xx[9];
  xx[50] = xx[13];
  xx[51] = xx[48] * xx[43];
  pm_math_Vector3_cross_ra(xx + 35, xx + 49, xx + 61);
  xx[35] = - (xx[0] * (xx[61] - xx[9] * xx[42]) + xx[8] + xx[20] - (xx[26] + xx
    [18] + xx[24]) + xx[6]);
  xx[36] = xx[28] - (xx[25] + xx[32]) - xx[22] - (xx[0] * (xx[62] + xx[13] * xx
    [42]) + xx[57] - (xx[54] + xx[60]));
  memcpy(xx + 59, xx + 68, 8 * sizeof(double));
  factorAndSolveWide(2, 4, xx + 59, xx + 8, xx + 12, ii + 0, xx + 35, xx[3], xx
                     + 24);
  xx[8] = xx[4] + xx[24];
  xx[4] = xx[15] + xx[25];
  xx[9] = xx[34] + xx[26];
  xx[12] = xx[11] + xx[27];
  xx[59] = xx[8];
  xx[60] = state[1];
  xx[61] = xx[4];
  xx[62] = state[3];
  xx[63] = xx[9];
  xx[64] = state[5];
  xx[65] = xx[12];
  xx[66] = state[7];
  xx[67] = state[8];
  xx[68] = state[9];
  xx[11] = xx[12] * xx[1];
  xx[12] = cos(xx[11]);
  xx[13] = xx[29] * xx[12];
  xx[14] = xx[9] * xx[1];
  xx[9] = sin(xx[14]);
  xx[15] = sin(xx[11]);
  xx[11] = xx[30] * xx[15];
  xx[16] = xx[21] * xx[15];
  xx[15] = xx[23] * xx[11] - xx[29] * xx[16];
  xx[18] = cos(xx[14]);
  xx[14] = xx[13] * xx[9] + xx[15] * xx[18];
  xx[19] = xx[15] * xx[9] - xx[18] * xx[13];
  xx[20] = xx[23] * xx[16] + xx[29] * xx[11];
  xx[11] = xx[23] * xx[12];
  xx[12] = xx[18] * xx[20] + xx[11] * xx[9];
  xx[24] = - xx[14];
  xx[25] = - xx[19];
  xx[26] = xx[12];
  xx[16] = xx[19] * xx[41];
  xx[22] = xx[12] * xx[43] + xx[41] * xx[14];
  xx[31] = - xx[16];
  xx[32] = xx[22];
  xx[33] = xx[19] * xx[43];
  pm_math_Vector3_cross_ra(xx + 24, xx + 31, xx + 34);
  xx[12] = xx[18] * xx[11] - xx[9] * xx[20];
  xx[24] = xx[15];
  xx[25] = - xx[13];
  xx[26] = - xx[20];
  xx[14] = xx[40] * xx[13];
  xx[19] = xx[46] * xx[20] - xx[15] * xx[40];
  xx[31] = - xx[14];
  xx[32] = xx[19];
  xx[33] = - (xx[46] * xx[13]);
  pm_math_Vector3_cross_ra(xx + 24, xx + 31, xx + 47);
  xx[13] = (xx[48] - xx[11] * xx[19]) * xx[0];
  xx[15] = xx[13] * xx[9];
  xx[19] = xx[39] + (xx[14] * xx[11] + xx[47]) * xx[0];
  xx[11] = xx[9] * xx[19];
  xx[14] = xx[52] * xx[9];
  xx[20] = xx[4] * xx[1];
  xx[4] = sin(xx[20]);
  xx[24] = xx[10] * xx[4];
  xx[25] = xx[0] * xx[24] * xx[4] - xx[5];
  xx[26] = xx[8] * xx[1];
  xx[8] = cos(xx[26]);
  xx[27] = cos(xx[20]);
  xx[20] = xx[0] * xx[27] * xx[24];
  xx[24] = sin(xx[26]);
  xx[26] = xx[20] * xx[24];
  xx[28] = xx[25] * xx[24];
  xx[31] = xx[17] * xx[24];
  xx[32] = xx[8] * xx[4] + xx[27] * xx[24];
  xx[33] = xx[32] * xx[7];
  xx[36] = fabs(xx[0] * (xx[34] - xx[16] * xx[12]) + xx[0] * (xx[18] * xx[15] +
    xx[11] * xx[9]) - xx[19] + xx[0] * xx[14] * xx[9] - (xx[25] + xx[0] * (xx[8]
    * xx[26] - xx[28] * xx[24]) + xx[0] * xx[31] * xx[24] + xx[0] * xx[32] * xx
    [33]) + xx[6]);
  xx[37] = fabs(xx[0] * (xx[35] + xx[22] * xx[12]) + (xx[15] * xx[9] - xx[18] *
    xx[11]) * xx[0] - (xx[13] + xx[0] * xx[18] * xx[14]) - ((xx[8] * xx[28] +
    xx[26] * xx[24]) * xx[0] - (xx[20] + xx[0] * xx[8] * xx[31]) - xx[0] * xx[33]
    * (xx[8] * xx[27] - xx[24] * xx[4])));
  ii[0] = 36;

  {
    int ll;
    for (ll = 37; ll < 38; ++ll)
      if (xx[ll] > xx[ii[0]])
        ii[0] = ll;
  }

  ii[0] -= 36;
  xx[4] = xx[36 + (ii[0])];
  xx[6] = 1.0e-9;
  xx[8] = xx[4] - xx[6];
  if (xx[8] < 0.0)
    ii[1] = -1;
  else if (xx[8] > 0.0)
    ii[1] = +1;
  else
    ii[1] = 0;
  ii[2] = ii[1];
  if (0 > ii[2])
    ii[2] = 0;
  if (ii[2] != 0) {
    switch (ii[0])
    {
     case 0:
     case 1:
      {
        return sm_ssci_recordRunTimeError(
          "sm:compiler:messages:simulationErrors:ConstraintViolation",
          "'Robot/Revolute' kinematic constraints cannot be maintained. Check solver type and consistency tolerance in the Simscape Solver Configuration block. Check Simulink solver type and tolerances in Model Configuration Parameters. A kinematic singularity might be the source of this problem.",
          neDiagMgr);
      }
    }
  }

  xx[4] = xx[1] * xx[59];
  xx[8] = cos(xx[4]);
  xx[9] = xx[1] * xx[61];
  xx[11] = sin(xx[9]);
  xx[12] = cos(xx[9]);
  xx[9] = sin(xx[4]);
  xx[4] = xx[8] * xx[11] + xx[12] * xx[9];
  xx[13] = xx[4] * xx[7];
  xx[14] = xx[8] * xx[12] - xx[9] * xx[11];
  xx[15] = xx[0] * xx[13] * xx[14];
  xx[16] = xx[10] * xx[11];
  xx[18] = xx[12] * xx[16];
  xx[12] = xx[0] * xx[18];
  xx[19] = xx[0] * xx[16] * xx[11];
  xx[11] = xx[19] - xx[5];
  xx[5] = xx[11] * xx[9];
  xx[16] = xx[12] * xx[9];
  xx[20] = xx[16] * xx[9];
  xx[22] = xx[17] * xx[9];
  xx[24] = xx[8] * xx[22];
  xx[25] = xx[0] * xx[24];
  xx[26] = xx[19] - xx[10];
  xx[10] = xx[9] * xx[26];
  xx[19] = xx[1] * xx[63];
  xx[27] = cos(xx[19]);
  xx[28] = xx[1] * xx[65];
  xx[31] = cos(xx[28]);
  xx[32] = xx[23] * xx[31];
  xx[33] = sin(xx[19]);
  xx[19] = sin(xx[28]);
  xx[28] = xx[21] * xx[19];
  xx[34] = xx[30] * xx[19];
  xx[19] = xx[23] * xx[28] + xx[29] * xx[34];
  xx[35] = xx[27] * xx[32] - xx[33] * xx[19];
  xx[36] = xx[29] * xx[31];
  xx[31] = xx[23] * xx[34] - xx[29] * xx[28];
  xx[28] = xx[36] * xx[33] + xx[31] * xx[27];
  xx[34] = xx[31] * xx[33] - xx[27] * xx[36];
  xx[37] = xx[27] * xx[19] + xx[32] * xx[33];
  xx[47] = xx[35];
  xx[48] = - xx[28];
  xx[49] = - xx[34];
  xx[50] = xx[37];
  xx[38] = (xx[36] * xx[19] - xx[31] * xx[32]) * xx[0];
  xx[69] = xx[41] * xx[38];
  xx[70] = xx[43] * (xx[44] - (xx[31] * xx[31] + xx[36] * xx[36]) * xx[0]) + xx
    [45] * (xx[31] * xx[19] + xx[36] * xx[32]);
  xx[71] = - (xx[43] * xx[38]);
  pm_math_Quaternion_xform_ra(xx + 47, xx + 69, xx + 72);
  xx[69] = xx[31];
  xx[70] = - xx[36];
  xx[71] = - xx[19];
  xx[38] = xx[40] * xx[36];
  xx[42] = xx[46] * xx[19] - xx[31] * xx[40];
  xx[75] = - xx[38];
  xx[76] = xx[42];
  xx[77] = - (xx[46] * xx[36]);
  pm_math_Vector3_cross_ra(xx + 69, xx + 75, xx + 44);
  xx[40] = (xx[45] - xx[32] * xx[42]) * xx[0];
  xx[42] = xx[40] * xx[33];
  xx[45] = xx[39] + (xx[38] * xx[32] + xx[44]) * xx[0];
  xx[38] = xx[33] * xx[45];
  xx[39] = xx[52] * xx[33];
  xx[44] = xx[27] * xx[39];
  xx[46] = xx[0] * xx[44];
  xx[51] = xx[55] * xx[28];
  xx[53] = xx[37] * xx[55];
  xx[54] = xx[31] * xx[58];
  xx[56] = xx[58] * xx[19];
  xx[57] = xx[54] * xx[36] + xx[56] * xx[32];
  xx[69] = xx[0] * xx[57];
  xx[70] = xx[58] - (xx[56] * xx[19] + xx[31] * xx[54]) * xx[0];
  xx[54] = xx[33] * xx[70];
  xx[56] = xx[69] * xx[33];
  xx[58] = xx[8] * xx[16];
  xx[16] = xx[0] * xx[22] * xx[9];
  xx[22] = xx[0] * xx[4] * xx[13];
  xx[13] = xx[0] * xx[39] * xx[33];
  xx[74] = - (xx[15] + xx[12] - (xx[8] * xx[5] + xx[20]) * xx[0] + xx[25]);
  xx[75] = - (xx[15] + xx[12] - xx[0] * (xx[20] + xx[8] * xx[10]));
  xx[76] = xx[72] + xx[40] - (xx[42] * xx[33] - xx[27] * xx[38]) * xx[0] + xx[46];
  xx[77] = xx[0] * (xx[34] * xx[51] - xx[53] * xx[35]) - (xx[69] + (xx[27] * xx
    [54] - xx[56] * xx[33]) * xx[0]);
  xx[78] = - (xx[11] + xx[0] * (xx[58] - xx[5] * xx[9]) + xx[16] + xx[22] - xx[2]);
  xx[79] = - (xx[26] - ((xx[10] * xx[9] - xx[58]) * xx[0] - xx[22]) - xx[7]);
  xx[80] = xx[73] + xx[0] * (xx[27] * xx[42] + xx[38] * xx[33]) - xx[45] + xx[13]
    - xx[52];
  xx[81] = xx[70] - xx[0] * (xx[27] * xx[56] + xx[54] * xx[33]) - (xx[37] * xx
    [53] + xx[51] * xx[28]) * xx[0] + xx[55];
  xx[2] = xx[60] * xx[12] + xx[0] * xx[62] * xx[18];
  xx[5] = xx[62] * xx[26] + xx[11] * xx[60];
  xx[10] = xx[5] * xx[9];
  xx[15] = xx[9] * xx[2];
  xx[18] = (xx[60] + xx[62]) * xx[7];
  xx[20] = xx[4] * xx[18];
  xx[22] = xx[64] * xx[36];
  xx[28] = xx[31] * xx[64];
  xx[34] = (xx[22] * xx[19] - xx[28] * xx[32]) * xx[0];
  xx[37] = xx[41] * xx[34];
  xx[38] = (xx[64] - (xx[31] * xx[28] + xx[36] * xx[22]) * xx[0] + xx[21] * xx
            [66]) * xx[43] + (xx[0] * (xx[28] * xx[19] + xx[32] * xx[22]) + xx
    [30] * xx[66]) * xx[41];
  xx[39] = - (xx[43] * xx[34]);
  pm_math_Quaternion_xform_ra(xx + 47, xx + 37, xx + 53);
  xx[22] = xx[64] * xx[40] - xx[0] * xx[66] * xx[57];
  xx[28] = xx[66] * xx[70] - xx[64] * xx[45];
  xx[34] = xx[28] * xx[33];
  xx[35] = xx[22] * xx[33];
  xx[37] = xx[16] - xx[17];
  xx[16] = xx[13] - xx[52];
  xx[38] = xx[2] - (xx[8] * xx[10] + xx[15] * xx[9]) * xx[0] + xx[0] * xx[60] *
    xx[24] + xx[0] * xx[20] * xx[14] - (xx[53] + xx[22] - (xx[27] * xx[34] + xx
    [35] * xx[33]) * xx[0] + xx[0] * xx[64] * xx[44]);
  xx[39] = xx[0] * xx[4] * xx[20] - xx[18] + xx[60] * xx[37] + xx[5] + xx[0] *
    (xx[8] * xx[15] - xx[10] * xx[9]) - (xx[54] + xx[64] * xx[16] + xx[28] + xx
    [0] * (xx[27] * xx[35] - xx[34] * xx[33]));
  memcpy(xx + 82, xx + 74, 8 * sizeof(double));
  factorAndSolveWide(2, 4, xx + 82, xx + 17, xx + 34, ii + 0, xx + 38, xx[3], xx
                     + 51);
  xx[2] = xx[60] + xx[51];
  xx[3] = xx[62] + xx[52];
  xx[5] = xx[64] + xx[53];
  xx[10] = xx[66] + xx[54];
  xx[71] = xx[59];
  xx[72] = xx[2];
  xx[73] = xx[61];
  xx[74] = xx[3];
  xx[75] = xx[63];
  xx[76] = xx[5];
  xx[77] = xx[65];
  xx[78] = xx[10];
  xx[79] = xx[67];
  xx[80] = xx[68];
  xx[13] = xx[5] * xx[36];
  xx[15] = xx[5] * xx[31];
  xx[17] = (xx[13] * xx[19] - xx[15] * xx[32]) * xx[0];
  xx[51] = xx[41] * xx[17];
  xx[52] = (xx[5] - (xx[31] * xx[15] + xx[13] * xx[36]) * xx[0] + xx[10] * xx[21])
    * xx[43] + (xx[0] * (xx[15] * xx[19] + xx[13] * xx[32]) + xx[10] * xx[30]) *
    xx[41];
  xx[53] = - (xx[43] * xx[17]);
  pm_math_Quaternion_xform_ra(xx + 47, xx + 51, xx + 17);
  xx[13] = xx[5] * xx[40] - xx[10] * xx[69];
  xx[15] = xx[10] * xx[70] - xx[5] * xx[45];
  xx[10] = xx[15] * xx[33];
  xx[20] = xx[13] * xx[33];
  xx[22] = xx[2] * xx[12] + xx[3] * xx[12];
  xx[12] = xx[3] * xx[26] + xx[2] * xx[11];
  xx[11] = xx[12] * xx[9];
  xx[24] = xx[9] * xx[22];
  xx[26] = (xx[2] + xx[3]) * xx[7];
  xx[3] = xx[4] * xx[26];
  xx[31] = fabs(xx[17] + xx[13] - (xx[27] * xx[10] + xx[20] * xx[33]) * xx[0] +
                xx[5] * xx[46] - (xx[22] - (xx[8] * xx[11] + xx[24] * xx[9]) *
    xx[0] + xx[2] * xx[25] + xx[0] * xx[3] * xx[14]));
  xx[32] = fabs(xx[18] + xx[5] * xx[16] + xx[15] + xx[0] * (xx[27] * xx[20] -
    xx[10] * xx[33]) - (xx[0] * xx[4] * xx[3] - xx[26] + xx[2] * xx[37] + xx[12]
                        + xx[0] * (xx[8] * xx[24] - xx[11] * xx[9])));
  ii[0] = 31;

  {
    int ll;
    for (ll = 32; ll < 33; ++ll)
      if (xx[ll] > xx[ii[0]])
        ii[0] = ll;
  }

  ii[0] -= 31;
  xx[2] = xx[31 + (ii[0])];
  xx[3] = xx[2] - xx[6];
  if (xx[3] < 0.0)
    ii[1] = -1;
  else if (xx[3] > 0.0)
    ii[1] = +1;
  else
    ii[1] = 0;
  ii[2] = ii[1];
  if (0 > ii[2])
    ii[2] = 0;
  if (ii[2] != 0) {
    switch (ii[0])
    {
     case 0:
     case 1:
      {
        return sm_ssci_recordRunTimeError(
          "sm:compiler:messages:simulationErrors:ConstraintViolation",
          "'Robot/Revolute' kinematic constraints cannot be maintained. Check solver type and consistency tolerance in the Simscape Solver Configuration block. Check Simulink solver type and tolerances in Model Configuration Parameters. A kinematic singularity might be the source of this problem.",
          neDiagMgr);
      }
    }
  }

  xx[2] = xx[1] * xx[71];
  xx[3] = cos(xx[2]);
  xx[4] = xx[1] * xx[73];
  xx[5] = sin(xx[4]);
  xx[6] = cos(xx[4]);
  xx[4] = sin(xx[2]);
  xx[2] = xx[3] * xx[5] + xx[6] * xx[4];
  xx[7] = xx[1] * xx[77];
  xx[8] = sin(xx[7]);
  xx[9] = xx[30] * xx[8];
  xx[10] = xx[21] * xx[8];
  xx[8] = xx[23] * xx[9] - xx[29] * xx[10];
  xx[11] = xx[1] * xx[75];
  xx[1] = sin(xx[11]);
  xx[12] = cos(xx[11]);
  xx[11] = cos(xx[7]);
  xx[7] = xx[29] * xx[11];
  xx[13] = xx[8] * xx[1] - xx[12] * xx[7];
  xx[14] = xx[3] * xx[6] - xx[4] * xx[5];
  xx[3] = xx[7] * xx[1] + xx[8] * xx[12];
  xx[4] = xx[2] * xx[13] + xx[14] * xx[3];
  xx[5] = xx[23] * xx[11];
  xx[6] = xx[23] * xx[10] + xx[29] * xx[9];
  xx[9] = xx[12] * xx[5] - xx[1] * xx[6];
  xx[10] = xx[12] * xx[6] + xx[5] * xx[1];
  xx[1] = xx[2] * xx[9] - xx[10] * xx[14];
  xx[11] = xx[23] * xx[4] - xx[1] * xx[29];
  xx[12] = xx[13] * xx[14] - xx[2] * xx[3];
  xx[3] = xx[2] * xx[10] + xx[14] * xx[9];
  xx[2] = xx[12] * xx[23] + xx[29] * xx[3];
  xx[9] = xx[1] * xx[23] + xx[29] * xx[4];
  xx[10] = xx[12] * xx[29] - xx[23] * xx[3];
  xx[13] = xx[8] * xx[76];
  xx[14] = xx[76] * xx[7];
  xx[15] = xx[72] + xx[74];
  xx[16] = xx[15] * xx[4];
  xx[17] = xx[15] * xx[12];
  state[0] = xx[71];
  state[1] = xx[72];
  state[2] = xx[73];
  state[3] = xx[74];
  state[4] = xx[75];
  state[5] = xx[76];
  state[6] = xx[77];
  state[7] = xx[78];
  state[8] = xx[79] + sm_core_canonicalAngle(xx[0] * atan2(sqrt(xx[11] * xx[11]
    + xx[2] * xx[2] + xx[9] * xx[9]), fabs(xx[10])) * (((xx[21] * xx[9] - xx[11]
    * xx[30]) * xx[10]) < 0.0 ? -1.0 : +1.0) - xx[79]);
  state[9] = xx[30] * (xx[0] * (xx[13] * xx[6] + xx[5] * xx[14]) + xx[30] * xx
                       [78] + xx[0] * (xx[1] * xx[16] + xx[17] * xx[3])) + xx[21]
    * (xx[76] - (xx[8] * xx[13] + xx[7] * xx[14]) * xx[0] + xx[21] * xx[78] -
       (xx[15] - (xx[16] * xx[4] + xx[12] * xx[17]) * xx[0]));
  return NULL;
}

void Robot_d2dba219_1_computeConstraintError(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const int *modeVector,
  double *error)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[27];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  xx[0] = 2.0;
  xx[1] = 0.01625315043917926;
  xx[2] = 0.5;
  xx[3] = xx[2] * state[6];
  xx[4] = cos(xx[3]);
  xx[5] = xx[1] * xx[4];
  xx[6] = xx[2] * state[4];
  xx[7] = sin(xx[6]);
  xx[8] = 0.9998679088263617;
  xx[9] = sin(xx[3]);
  xx[3] = 0.03250200708292485 * xx[9];
  xx[10] = 0.9994716702016028 * xx[9];
  xx[9] = xx[8] * xx[3] - xx[1] * xx[10];
  xx[11] = cos(xx[6]);
  xx[6] = xx[5] * xx[7] + xx[9] * xx[11];
  xx[12] = xx[9] * xx[7] - xx[11] * xx[5];
  xx[13] = xx[8] * xx[10] + xx[1] * xx[3];
  xx[1] = xx[8] * xx[4];
  xx[3] = xx[11] * xx[13] + xx[1] * xx[7];
  xx[14] = - xx[6];
  xx[15] = - xx[12];
  xx[16] = xx[3];
  xx[4] = 6.093517183011606e-3;
  xx[8] = xx[12] * xx[4];
  xx[10] = 0.06435386271755822;
  xx[17] = xx[3] * xx[10] + xx[4] * xx[6];
  xx[18] = - xx[8];
  xx[19] = xx[17];
  xx[20] = xx[12] * xx[10];
  pm_math_Vector3_cross_ra(xx + 14, xx + 18, xx + 21);
  xx[3] = xx[11] * xx[1] - xx[7] * xx[13];
  xx[14] = xx[9];
  xx[15] = - xx[5];
  xx[16] = - xx[13];
  xx[4] = 0.01218799303507748;
  xx[6] = xx[4] * xx[5];
  xx[10] = 0.0559077577774378;
  xx[12] = xx[10] * xx[13] - xx[9] * xx[4];
  xx[18] = - xx[6];
  xx[19] = xx[12];
  xx[20] = - (xx[10] * xx[5]);
  pm_math_Vector3_cross_ra(xx + 14, xx + 18, xx + 24);
  xx[4] = (xx[25] - xx[1] * xx[12]) * xx[0];
  xx[5] = xx[4] * xx[7];
  xx[9] = 6.482669460775074e-3 + (xx[6] * xx[1] + xx[24]) * xx[0];
  xx[1] = xx[7] * xx[9];
  xx[6] = 0.05760957276178814 * xx[7];
  xx[10] = xx[2] * state[2];
  xx[12] = sin(xx[10]);
  xx[13] = 0.06165588643208984 * xx[12];
  xx[14] = xx[0] * xx[13] * xx[12] - 0.1240463136703027;
  xx[15] = xx[2] * state[0];
  xx[2] = cos(xx[15]);
  xx[16] = cos(xx[10]);
  xx[10] = xx[0] * xx[16] * xx[13];
  xx[13] = sin(xx[15]);
  xx[15] = xx[10] * xx[13];
  xx[18] = xx[14] * xx[13];
  xx[19] = 0.05760957276177599 * xx[13];
  xx[20] = xx[2] * xx[12] + xx[16] * xx[13];
  xx[24] = xx[20] * 0.05834411356795617;
  error[0] = xx[0] * (xx[21] - xx[8] * xx[3]) + xx[0] * (xx[11] * xx[5] + xx[1] *
    xx[7]) - xx[9] + xx[0] * xx[6] * xx[7] - (xx[14] + xx[0] * (xx[2] * xx[15] -
    xx[18] * xx[13]) + xx[0] * xx[19] * xx[13] + xx[0] * xx[20] * xx[24]) +
    0.2796979762855022;
  error[1] = xx[0] * (xx[22] + xx[17] * xx[3]) + (xx[5] * xx[7] - xx[11] * xx[1])
    * xx[0] - (xx[4] + xx[0] * xx[11] * xx[6]) - ((xx[2] * xx[18] + xx[15] * xx
    [13]) * xx[0] - (xx[10] + xx[0] * xx[2] * xx[19]) - xx[0] * xx[24] * (xx[2] *
    xx[16] - xx[13] * xx[12]));
}

void Robot_d2dba219_1_resetModeVector(const void *mech, int *modeVector)
{
  (void) mech;
  (void) modeVector;
}

boolean_T Robot_d2dba219_1_hasJointDisToNormModeChange(const void *mech, const
  int *prevModeVector, const int *modeVector)
{
  (void) mech;
  (void) prevModeVector;
  (void) modeVector;
  return 0;
}

PmfMessageId Robot_d2dba219_1_performJointDisToNormModeChange(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const int *prevModeVector, const int
  *modeVector, const double *input, double *state, void *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) prevModeVector;
  (void) modeVector;
  (void) input;
  (void) state;
  (void) neDiagMgr;
  return NULL;
}

PmfMessageId Robot_d2dba219_1_onModeChangedCutJoints(const void *mech, const int
  *prevModeVector, int *modeVector, double *state, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) prevModeVector;
  (void) modeVector;
  (void) state;
  (void) neDiagMgr;
  return NULL;
}
