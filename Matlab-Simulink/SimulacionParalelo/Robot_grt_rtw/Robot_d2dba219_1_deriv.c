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
#include "Robot_d2dba219_1_geometries.h"

PmfMessageId Robot_d2dba219_1_compDerivs(const RuntimeDerivedValuesBundle *rtdv,
  const int *eqnEnableFlags, const double *state, const int *modeVector, const
  double *input, const double *inputDot, const double *inputDdot, const double
  *discreteState, double *deriv, double *errorResult, NeuDiagnosticManager
  *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[2];
  double xx[161];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 2.0;
  xx[1] = 0.06165588643208984;
  xx[2] = 0.5;
  xx[3] = xx[2] * state[2];
  xx[4] = sin(xx[3]);
  xx[5] = xx[1] * xx[4];
  xx[6] = xx[0] * xx[5] * xx[4];
  xx[7] = xx[6] - 0.1240463136703027;
  xx[8] = cos(xx[3]);
  xx[3] = xx[8] * xx[5];
  xx[5] = xx[0] * xx[3];
  xx[9] = xx[5] * state[1] * state[1];
  xx[10] = xx[7] * state[1] * state[1];
  xx[11] = xx[10] * xx[4];
  xx[12] = xx[9] * xx[4];
  xx[13] = 0.01885369454746664;
  xx[14] = (xx[9] + xx[0] * (xx[8] * xx[11] - xx[12] * xx[4])) * xx[13];
  xx[9] = 1.162441249843914e-3;
  xx[15] = xx[2] * state[0];
  xx[16] = sin(xx[15]);
  xx[17] = xx[5] * xx[16];
  xx[18] = xx[17] * xx[16];
  xx[19] = cos(xx[15]);
  xx[15] = xx[6] - xx[1];
  xx[20] = xx[16] * xx[15];
  xx[21] = xx[19] * xx[4] + xx[8] * xx[16];
  xx[22] = 0.05834411356795617;
  xx[23] = xx[21] * xx[22];
  xx[24] = xx[19] * xx[8] - xx[16] * xx[4];
  xx[25] = xx[0] * xx[23] * xx[24];
  xx[26] = xx[5] - xx[0] * (xx[18] + xx[19] * xx[20]) + xx[25];
  xx[27] = 1.016547249206476e-4;
  ii[0] = factorSymmetricPosDef(xx + 27, 1, xx + 28);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'Robot/Revolute1' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[28] = xx[26] / xx[27];
  xx[29] = xx[9] * xx[28];
  xx[30] = xx[29] * xx[4];
  xx[31] = xx[29] - xx[0] * xx[30] * xx[4];
  xx[29] = 2.998337923629462e-5;
  xx[32] = 0.05760957276177599;
  xx[33] = xx[7] * xx[16];
  xx[34] = xx[32] * xx[16];
  xx[35] = xx[0] * xx[19] * xx[34];
  xx[36] = xx[5] - (xx[19] * xx[33] + xx[18]) * xx[0] + xx[35] + xx[25];
  xx[18] = xx[29] / xx[27];
  xx[25] = xx[8] * xx[8];
  xx[37] = 1.0;
  xx[38] = (xx[25] + xx[4] * xx[4]) * xx[0] - xx[37];
  xx[39] = xx[9] / xx[27];
  xx[40] = xx[29] * xx[39];
  xx[41] = xx[8] * xx[4];
  xx[42] = xx[0] * xx[41];
  xx[43] = xx[40] * xx[42] * xx[38];
  xx[44] = xx[0] * xx[25] - xx[37];
  xx[25] = xx[40] * xx[44] * xx[38];
  xx[40] = xx[5] * xx[43] - xx[7] * xx[25];
  xx[45] = xx[13] * xx[44];
  xx[46] = xx[13] - xx[9] * xx[39];
  xx[47] = xx[42] * xx[46];
  xx[48] = xx[45] * xx[42] - xx[47] * xx[44];
  xx[49] = xx[13] * xx[42];
  xx[50] = xx[46] * xx[44];
  xx[46] = xx[49] * xx[42] + xx[50] * xx[44];
  xx[51] = xx[5] * xx[48] + xx[7] * xx[46];
  xx[52] = (xx[45] * xx[44] + xx[42] * xx[47]) * xx[5] + xx[7] * (xx[49] * xx[44]
    - xx[42] * xx[50]);
  xx[45] = xx[51] + xx[25];
  xx[25] = 0.0190940852903285;
  xx[47] = 3.079565011046661e-5;
  xx[49] = (xx[29] - xx[29] * xx[18]) * xx[38] * xx[38] - xx[40] - xx[40] + xx[7]
    * xx[51] + xx[52] * xx[5] - xx[32] * xx[45] - (xx[45] - (xx[25] + xx[46]) *
    xx[32]) * xx[32] + xx[47];
  ii[0] = factorSymmetricPosDef(xx + 49, 1, xx + 38);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'Robot/Revolute3' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[38] = (xx[7] * xx[31] - xx[5] * xx[0] * xx[8] * xx[30] - xx[29] * xx[28] -
            xx[32] * xx[31] + xx[36]) / xx[49];
  xx[30] = xx[7] * xx[38] - xx[32] * xx[38];
  xx[31] = xx[2] * state[4];
  xx[40] = cos(xx[31]);
  xx[45] = 0.9998679088263617;
  xx[46] = xx[2] * state[6];
  xx[2] = cos(xx[46]);
  xx[50] = xx[45] * xx[2];
  xx[51] = sin(xx[31]);
  xx[31] = 0.9994716702016028;
  xx[53] = sin(xx[46]);
  xx[46] = xx[31] * xx[53];
  xx[54] = 0.01625315043917926;
  xx[55] = 0.03250200708292485;
  xx[56] = xx[55] * xx[53];
  xx[53] = xx[45] * xx[46] + xx[54] * xx[56];
  xx[57] = xx[40] * xx[50] - xx[51] * xx[53];
  xx[58] = xx[54] * xx[2];
  xx[2] = xx[45] * xx[56] - xx[54] * xx[46];
  xx[45] = xx[58] * xx[51] + xx[2] * xx[40];
  xx[46] = xx[2] * xx[51] - xx[40] * xx[58];
  xx[54] = xx[40] * xx[53] + xx[50] * xx[51];
  xx[59] = xx[57];
  xx[60] = - xx[45];
  xx[61] = - xx[46];
  xx[62] = xx[54];
  xx[56] = 6.093517183011606e-3;
  xx[63] = xx[58] * xx[53];
  xx[64] = xx[2] * xx[50];
  xx[65] = (xx[63] - xx[64]) * xx[0];
  xx[66] = 0.06435386271755822;
  xx[67] = xx[2] * xx[2];
  xx[68] = xx[58] * xx[58];
  xx[69] = xx[2] * xx[53];
  xx[70] = xx[58] * xx[50];
  xx[71] = xx[69] + xx[70];
  xx[72] = xx[56] * xx[65];
  xx[73] = xx[66] * (xx[37] - (xx[67] + xx[68]) * xx[0]) + 0.01218703436602321 *
    xx[71];
  xx[74] = - (xx[66] * xx[65]);
  pm_math_Quaternion_xform_ra(xx + 59, xx + 72, xx + 75);
  xx[59] = - xx[58];
  xx[60] = - xx[53];
  xx[72] = xx[2];
  xx[73] = xx[59];
  xx[74] = xx[60];
  xx[61] = 0.01218799303507748;
  xx[62] = xx[61] * xx[58];
  xx[65] = 0.0559077577774378;
  xx[78] = xx[65] * xx[53] - xx[2] * xx[61];
  xx[79] = xx[65] * xx[58];
  xx[80] = - xx[62];
  xx[81] = xx[78];
  xx[82] = - xx[79];
  pm_math_Vector3_cross_ra(xx + 72, xx + 80, xx + 83);
  xx[80] = (xx[84] - xx[50] * xx[78]) * xx[0];
  xx[78] = xx[80] * xx[51];
  xx[81] = 0.06239042723821288 + (xx[62] * xx[50] + xx[83]) * xx[0] - xx[65];
  xx[62] = xx[51] * xx[81];
  xx[65] = 0.05760957276178814;
  xx[82] = xx[65] * xx[51];
  xx[86] = xx[0] * xx[40] * xx[82];
  xx[87] = xx[75] + xx[80] - (xx[78] * xx[51] - xx[40] * xx[62]) * xx[0] + xx[86];
  xx[88] = 3.742830800355274e-5;
  xx[89] = 0.06451791419288473;
  xx[90] = xx[89] * xx[45];
  xx[91] = xx[54] * xx[89];
  xx[92] = 0.05548208580708968;
  xx[93] = xx[2] * xx[92];
  xx[94] = xx[92] * xx[53];
  xx[95] = xx[93] * xx[58] + xx[94] * xx[50];
  xx[96] = xx[0] * xx[95];
  xx[97] = xx[92] - (xx[94] * xx[53] + xx[2] * xx[93]) * xx[0];
  xx[93] = xx[51] * xx[97];
  xx[94] = xx[96] * xx[51];
  xx[98] = xx[0] * (xx[46] * xx[90] - xx[91] * xx[57]) - (xx[96] + (xx[40] * xx
    [93] - xx[94] * xx[51]) * xx[0]);
  xx[96] = 1.019049061227501e-4;
  ii[0] = factorSymmetricPosDef(xx + 96, 1, xx + 99);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'Robot/Revolute2' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[99] = xx[98] / xx[96];
  xx[100] = xx[88] * xx[99];
  xx[101] = 5.253337498216983e-8;
  xx[102] = xx[101] * xx[99];
  xx[103] = xx[102] * xx[58];
  xx[104] = - (xx[100] * xx[58]);
  xx[105] = xx[102] * xx[53] - xx[2] * xx[100];
  xx[106] = - xx[103];
  pm_math_Vector3_cross_ra(xx + 72, xx + 104, xx + 107);
  xx[104] = - xx[81];
  xx[105] = - xx[80];
  xx[106] = - (5.0e-3 + xx[61] + xx[0] * (xx[85] + xx[79] * xx[50]));
  xx[61] = 1.162441249843065e-3;
  xx[79] = xx[61] * xx[99];
  xx[83] = xx[2] * xx[79];
  xx[84] = xx[79] * xx[53];
  xx[85] = xx[79] - (xx[84] * xx[53] + xx[2] * xx[83]) * xx[0];
  xx[110] = - (xx[0] * (xx[83] * xx[58] + xx[50] * xx[84]));
  xx[111] = xx[85];
  xx[112] = (xx[58] * xx[84] - xx[83] * xx[50]) * xx[0];
  pm_math_Vector3_cross_ra(xx + 104, xx + 110, xx + 113);
  xx[79] = xx[50] * xx[50];
  xx[83] = (xx[79] + xx[67]) * xx[0] - xx[37];
  xx[67] = xx[2] * xx[58];
  xx[84] = xx[50] * xx[53];
  xx[102] = xx[0] * (xx[67] + xx[84]);
  xx[107] = (xx[70] - xx[69]) * xx[0];
  xx[69] = (xx[84] - xx[67]) * xx[0];
  xx[67] = (xx[79] + xx[68]) * xx[0] - xx[37];
  xx[68] = xx[0] * (xx[63] + xx[64]);
  xx[70] = xx[0] * xx[71];
  xx[71] = (xx[63] - xx[64]) * xx[0];
  xx[63] = (xx[79] + xx[53] * xx[53]) * xx[0] - xx[37];
  xx[116] = xx[83];
  xx[117] = - xx[102];
  xx[118] = xx[107];
  xx[119] = xx[69];
  xx[120] = xx[67];
  xx[121] = xx[68];
  xx[122] = - xx[70];
  xx[123] = xx[71];
  xx[124] = xx[63];
  xx[64] = 1.61631172032353e-6;
  xx[79] = xx[101] / xx[96];
  xx[84] = xx[64] - xx[101] * xx[79];
  xx[108] = xx[88] * xx[79];
  xx[110] = 3.648284752569075e-5;
  xx[111] = 3.744809294694976e-5;
  xx[112] = xx[88] / xx[96];
  xx[113] = xx[111] - xx[88] * xx[112];
  xx[125] = xx[84] * xx[83] + xx[107] * xx[108];
  xx[126] = xx[69] * xx[84] + xx[108] * xx[68];
  xx[127] = xx[108] * xx[63] - xx[70] * xx[84];
  xx[128] = - (xx[110] * xx[102]);
  xx[129] = xx[110] * xx[67];
  xx[130] = xx[110] * xx[71];
  xx[131] = xx[107] * xx[113] + xx[108] * xx[83];
  xx[132] = xx[68] * xx[113] + xx[69] * xx[108];
  xx[133] = xx[113] * xx[63] - xx[108] * xx[70];
  pm_math_Matrix3x3_compose_ra(xx + 116, xx + 125, xx + 134);
  xx[84] = xx[61] / xx[96];
  xx[108] = xx[101] * xx[84];
  xx[113] = xx[108] * xx[102];
  xx[114] = xx[88] * xx[84];
  xx[125] = xx[114] * xx[102];
  xx[126] = xx[114] * xx[67];
  xx[127] = xx[108] * xx[67];
  xx[128] = xx[71] * xx[114];
  xx[114] = xx[71] * xx[108];
  xx[108] = xx[70] * xx[113] + xx[125] * xx[63];
  xx[129] = xx[70] * xx[127] + xx[126] * xx[63];
  xx[130] = xx[70] * xx[114] + xx[128] * xx[63];
  xx[131] = - (xx[113] * xx[83] - xx[107] * xx[125]);
  xx[132] = - (xx[107] * xx[126] - xx[127] * xx[83]);
  xx[133] = - (xx[107] * xx[128] - xx[114] * xx[83]);
  xx[134] = - (xx[69] * xx[113] - xx[68] * xx[125]);
  xx[135] = - (xx[68] * xx[126] - xx[69] * xx[127]);
  xx[136] = - (xx[68] * xx[128] - xx[69] * xx[114]);
  xx[137] = xx[108];
  xx[138] = - xx[129];
  xx[139] = - xx[130];
  pm_math_Matrix3x3_postCross_ra(xx + 131, xx + 104, xx + 143);
  xx[113] = 0.0209516501215339;
  xx[114] = xx[113] - xx[61] * xx[84];
  xx[131] = xx[113] * xx[83];
  xx[132] = xx[113] * xx[69];
  xx[133] = - (xx[113] * xx[70]);
  xx[134] = - (xx[102] * xx[114]);
  xx[135] = xx[114] * xx[67];
  xx[136] = xx[71] * xx[114];
  xx[137] = xx[113] * xx[107];
  xx[138] = xx[113] * xx[68];
  xx[139] = xx[113] * xx[63];
  pm_math_Matrix3x3_compose_ra(xx + 116, xx + 131, xx + 152);
  pm_math_Matrix3x3_postCross_ra(xx + 152, xx + 104, xx + 116);
  pm_math_Matrix3x3_preCross_ra(xx + 116, xx + 104, xx + 131);
  xx[63] = xx[129] + xx[121];
  xx[67] = xx[142] - xx[151] - xx[151] - xx[139] + xx[63] * xx[65] + xx[65] *
    ((xx[25] + xx[156]) * xx[65] + xx[63]) + xx[47];
  ii[0] = factorSymmetricPosDef(xx + 67, 1, xx + 25);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'Robot/Revolute4' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[25] = (xx[87] - (xx[100] + xx[0] * (xx[109] + xx[50] * xx[103]) + xx[115] -
                      xx[65] * xx[85])) / xx[67];
  xx[47] = xx[2] * xx[25];
  xx[63] = xx[25] * xx[58];
  xx[70] = xx[65] * xx[25] + xx[25] * xx[81];
  xx[71] = xx[25] * xx[80];
  xx[85] = xx[71] * xx[53];
  xx[114] = - (xx[70] * xx[53]);
  xx[115] = - xx[85];
  xx[116] = xx[58] * xx[71] - xx[2] * xx[70];
  pm_math_Vector3_cross_ra(xx + 72, xx + 114, xx + 119);
  xx[71] = xx[19] * xx[17];
  xx[17] = xx[0] * xx[21] * xx[23];
  xx[23] = xx[15] - ((xx[20] * xx[16] - xx[71]) * xx[0] - xx[17]) - xx[22];
  xx[20] = xx[23] / xx[27];
  xx[100] = xx[9] * xx[20];
  xx[102] = xx[100] * xx[4];
  xx[103] = xx[100] - xx[0] * xx[102] * xx[4];
  xx[100] = xx[0] * xx[34] * xx[16];
  xx[34] = xx[7] + xx[0] * (xx[71] - xx[33] * xx[16]) + xx[100] + xx[17] -
    0.1159536863297322;
  xx[17] = (xx[7] * xx[103] - xx[5] * xx[0] * xx[8] * xx[102] - xx[29] * xx[20]
            - xx[32] * xx[103] + xx[34]) / xx[49];
  xx[33] = xx[7] * xx[17] - xx[32] * xx[17];
  xx[71] = xx[20] - (xx[39] * ((xx[8] * xx[17] * xx[5] * xx[4] + xx[33] * xx[4] *
    xx[4]) * xx[0] - xx[33]) + xx[17] * xx[18]);
  xx[20] = xx[0] * xx[82] * xx[51];
  xx[33] = xx[76] + xx[0] * (xx[40] * xx[78] + xx[62] * xx[51]) - xx[81] + xx[20]
    - xx[65];
  xx[62] = xx[97] - xx[0] * (xx[40] * xx[94] + xx[93] * xx[51]) - (xx[54] * xx
    [91] + xx[90] * xx[45]) * xx[0] + xx[89];
  xx[75] = xx[62] / xx[96];
  xx[76] = xx[88] * xx[75];
  xx[77] = xx[101] * xx[75];
  xx[78] = xx[77] * xx[58];
  xx[89] = - (xx[76] * xx[58]);
  xx[90] = xx[77] * xx[53] - xx[2] * xx[76];
  xx[91] = - xx[78];
  pm_math_Vector3_cross_ra(xx + 72, xx + 89, xx + 114);
  xx[77] = xx[61] * xx[75];
  xx[82] = xx[2] * xx[77];
  xx[89] = xx[77] * xx[53];
  xx[90] = xx[77] - (xx[89] * xx[53] + xx[2] * xx[82]) * xx[0];
  xx[121] = - (xx[0] * (xx[82] * xx[58] + xx[50] * xx[89]));
  xx[122] = xx[90];
  xx[123] = (xx[58] * xx[89] - xx[82] * xx[50]) * xx[0];
  pm_math_Vector3_cross_ra(xx + 104, xx + 121, xx + 125);
  xx[77] = (xx[33] - (xx[76] + xx[0] * (xx[116] + xx[50] * xx[78]) + xx[127] -
                      xx[65] * xx[90])) / xx[67];
  xx[76] = xx[2] * xx[77];
  xx[78] = xx[77] * xx[58];
  xx[82] = xx[65] * xx[77] + xx[77] * xx[81];
  xx[89] = xx[77] * xx[80];
  xx[90] = xx[89] * xx[53];
  xx[114] = - (xx[82] * xx[53]);
  xx[115] = - xx[90];
  xx[116] = xx[58] * xx[89] - xx[2] * xx[82];
  pm_math_Vector3_cross_ra(xx + 72, xx + 114, xx + 121);
  xx[89] = xx[75] - (xx[79] * xx[0] * (xx[76] * xx[53] + xx[50] * xx[78]) + xx
                     [112] * (xx[77] - (xx[2] * xx[76] + xx[58] * xx[78]) * xx[0])
                     + (xx[0] * (xx[122] - xx[50] * xx[90]) - xx[82]) * xx[84]);
  xx[75] = xx[17] * xx[36] + xx[71] * xx[26] + xx[87] * xx[77] + xx[98] * xx[89];
  xx[114] = xx[38] * xx[36] + (xx[28] - (xx[39] * ((xx[8] * xx[38] * xx[5] * xx
    [4] + xx[30] * xx[4] * xx[4]) * xx[0] - xx[30]) + xx[38] * xx[18])) * xx[26]
    + xx[87] * xx[25] + xx[98] * (xx[99] - (xx[79] * xx[0] * (xx[47] * xx[53] +
    xx[50] * xx[63]) + xx[112] * (xx[25] - (xx[2] * xx[47] + xx[58] * xx[63]) *
    xx[0]) + (xx[0] * (xx[120] - xx[50] * xx[85]) - xx[70]) * xx[84]));
  xx[115] = xx[75];
  xx[116] = xx[75];
  xx[117] = xx[34] * xx[17] + xx[71] * xx[23] + xx[33] * xx[77] + xx[62] * xx[89];
  xx[17] = xx[1] * xx[14] / xx[27];
  xx[25] = xx[14] - xx[9] * xx[17];
  xx[28] = xx[13] * ((xx[8] * xx[12] + xx[11] * xx[4]) * xx[0] - xx[10] + xx[1] *
                     (state[1] + state[1] + state[3]) * state[3]);
  xx[10] = xx[28] * xx[4];
  xx[11] = xx[8] * xx[10];
  xx[12] = xx[4] * xx[25];
  xx[13] = xx[25] + xx[0] * (xx[11] - xx[12] * xx[4]);
  xx[25] = xx[10] * xx[4];
  xx[10] = state[1] * state[1];
  xx[30] = xx[32] * xx[10];
  xx[38] = (xx[52] - xx[43]) * xx[30];
  xx[43] = xx[30] * xx[48];
  xx[47] = (input[0] - (xx[7] * xx[13] + xx[5] * (xx[28] - (xx[8] * xx[12] + xx
    [25]) * xx[0]) + xx[29] * xx[17] + xx[38] - xx[32] * (xx[13] + xx[43]))) /
    xx[49];
  xx[12] = xx[40] * xx[51];
  xx[13] = xx[0] * xx[12] * state[5] * state[5];
  xx[48] = xx[0] * xx[40] * xx[40] - xx[37];
  xx[52] = xx[48] * state[5] * state[5];
  xx[63] = xx[0] * xx[12];
  xx[12] = xx[31] * state[7];
  xx[70] = xx[55] * state[7];
  xx[71] = xx[70] * xx[68] + xx[69] * xx[12];
  xx[75] = xx[12] * xx[71];
  xx[76] = xx[107] * xx[70] + xx[12] * xx[83];
  xx[77] = xx[12] * xx[76];
  xx[78] = xx[57] * xx[57];
  xx[82] = xx[46] * xx[45];
  xx[85] = xx[54] * xx[57];
  xx[89] = xx[54] * xx[45];
  xx[90] = xx[46] * xx[57];
  xx[91] = xx[57] * xx[45];
  xx[93] = xx[54] * xx[46];
  xx[131] = (xx[78] + xx[45] * xx[45]) * xx[0] - xx[37];
  xx[132] = xx[0] * (xx[82] - xx[85]);
  xx[133] = - ((xx[89] + xx[90]) * xx[0]);
  xx[134] = (xx[82] + xx[85]) * xx[0];
  xx[135] = (xx[78] + xx[46] * xx[46]) * xx[0] - xx[37];
  xx[136] = xx[0] * (xx[91] - xx[93]);
  xx[137] = xx[0] * (xx[90] - xx[89]);
  xx[138] = - ((xx[93] + xx[91]) * xx[0]);
  xx[139] = (xx[78] + xx[54] * xx[54]) * xx[0] - xx[37];
  xx[78] = xx[2] * state[5];
  xx[82] = xx[58] * state[5];
  xx[85] = xx[0] * (xx[78] * xx[53] + xx[50] * xx[82]);
  xx[89] = (xx[82] * xx[53] - xx[78] * xx[50]) * xx[0];
  xx[90] = state[5] - (xx[2] * xx[78] + xx[58] * xx[82]) * xx[0];
  xx[119] = - xx[85];
  xx[120] = xx[89];
  xx[121] = xx[90];
  pm_math_Matrix3x3_postCross_ra(xx + 131, xx + 119, xx + 140);
  xx[78] = xx[70] * xx[71];
  xx[71] = xx[70] * xx[76];
  xx[76] = state[5] * state[5];
  xx[82] = 1.803279145877473e-3;
  xx[91] = xx[82] * xx[58];
  xx[93] = 0.05545277296788056;
  xx[94] = xx[93] * xx[53] + xx[2] * xx[82];
  xx[119] = xx[91];
  xx[120] = xx[94];
  xx[121] = - (xx[93] * xx[58]);
  pm_math_Vector3_cross_ra(xx + 72, xx + 119, xx + 125);
  xx[82] = state[7] * state[7];
  xx[99] = ((xx[125] - xx[91] * xx[50]) * xx[0] - xx[93]) * xx[82];
  xx[91] = (xx[126] - xx[50] * xx[94]) * xx[0] * xx[82];
  xx[82] = xx[91] * xx[51];
  xx[93] = xx[99] * xx[51];
  xx[94] = xx[97] * state[7] * state[5];
  xx[97] = xx[94] * xx[51];
  xx[102] = xx[0] * xx[95] * state[7] * state[5];
  xx[95] = xx[102] * xx[51];
  xx[103] = xx[0] * xx[19] * xx[19] - xx[37];
  xx[109] = xx[103] * state[1] * state[1];
  xx[119] = xx[19] * xx[16];
  xx[120] = xx[0] * xx[119] * state[1] * state[1];
  xx[121] = state[3] * state[3];
  xx[122] = xx[121] * (xx[1] - xx[6]);
  xx[6] = xx[5] * xx[121];
  xx[121] = xx[6] * xx[16];
  xx[123] = xx[122] * xx[16];
  xx[125] = xx[15] * state[3] * state[1];
  xx[15] = xx[125] * xx[16];
  xx[126] = xx[0] * xx[3] * state[3] * state[1];
  xx[3] = xx[126] * xx[16];
  xx[127] = xx[0] * xx[119];
  xx[119] = xx[0] * xx[41] * state[3] * state[3];
  xx[41] = xx[44] * state[3] * state[3];
  xx[128] = xx[7] * xx[47] - xx[32] * xx[47];
  xx[129] = xx[18] * xx[47] - xx[39] * (xx[128] - (xx[8] * xx[4] * (xx[47] * xx
    [5] + xx[30]) + xx[128] * xx[4] * xx[4]) * xx[0]) - xx[17];
  xx[131] = - xx[50];
  xx[132] = xx[2];
  xx[133] = xx[59];
  xx[134] = xx[60];
  xx[17] = xx[85] + xx[70];
  xx[59] = xx[90] + xx[12];
  xx[135] = - xx[17];
  xx[136] = xx[89];
  xx[137] = xx[59];
  xx[149] = - (xx[17] * xx[64]);
  xx[150] = xx[110] * xx[89];
  xx[151] = xx[59] * xx[111];
  pm_math_Vector3_cross_ra(xx + 135, xx + 149, xx + 152);
  xx[60] = xx[89] * xx[12];
  xx[128] = xx[152] + xx[64] * xx[60];
  xx[64] = xx[89] * xx[70];
  xx[89] = xx[154] + xx[111] * xx[64];
  xx[111] = xx[80] * state[5] * state[5];
  xx[135] = xx[111] * xx[53];
  xx[136] = xx[81] * state[5] * state[5];
  xx[137] = xx[136] * xx[53];
  xx[138] = xx[2] * xx[111] + xx[58] * xx[136];
  xx[149] = xx[135];
  xx[150] = - xx[137];
  xx[151] = xx[138];
  pm_math_Vector3_cross_ra(xx + 72, xx + 149, xx + 156);
  xx[72] = (xx[111] + (xx[157] - xx[50] * xx[137]) * xx[0]) * xx[113];
  xx[73] = xx[31] * xx[89] - xx[128] * xx[55] + xx[92] * xx[72];
  xx[74] = xx[73] / xx[96];
  xx[111] = xx[153] + xx[110] * (xx[12] * xx[85] - xx[70] * xx[90]);
  xx[149] = xx[128] + xx[101] * xx[74];
  xx[150] = xx[111];
  xx[151] = xx[89] - xx[88] * xx[74];
  pm_math_Quaternion_xform_ra(xx + 131, xx + 149, xx + 152);
  xx[110] = xx[92] * state[7];
  xx[92] = xx[113] * ((xx[50] * xx[135] + xx[156]) * xx[0] + xx[136] - (xx[90] +
    xx[59]) * xx[110]);
  xx[59] = (xx[0] * (xx[158] + xx[138] * xx[50]) - (xx[85] + xx[17]) * xx[110]) *
    xx[113];
  xx[135] = xx[92];
  xx[136] = xx[72] - xx[61] * xx[74];
  xx[137] = xx[59];
  pm_math_Quaternion_xform_ra(xx + 131, xx + 135, xx + 149);
  pm_math_Vector3_cross_ra(xx + 104, xx + 149, xx + 135);
  xx[17] = xx[65] * xx[76];
  xx[85] = (xx[118] - xx[108]) * xx[17];
  xx[90] = xx[155] * xx[17];
  xx[108] = 9.806649999999999;
  xx[110] = xx[108] * (xx[65] * xx[159] + xx[130] + xx[124]) / xx[67];
  xx[113] = (input[1] - (xx[154] + xx[137] - xx[85] - xx[65] * (xx[150] + xx[90])))
    / xx[67] + xx[110];
  xx[118] = xx[2] * xx[113];
  xx[124] = xx[58] * xx[113];
  xx[135] = xx[80] * xx[113] + xx[17];
  xx[136] = - (xx[65] * xx[113] + xx[113] * xx[81]);
  xx[137] = xx[108];
  pm_math_Quaternion_inverseXform_ra(xx + 131, xx + 135, xx + 149);
  xx[130] = xx[74] + xx[79] * xx[0] * (xx[118] * xx[53] + xx[50] * xx[124]) +
    xx[112] * (xx[113] - (xx[2] * xx[118] + xx[58] * xx[124]) * xx[0]) + xx[84] *
    xx[150];
  xx[135] = xx[47] * xx[36] - ((xx[69] * xx[13] - xx[52] * xx[83] + xx[63] * xx
    [75] - xx[77] * xx[48] + xx[0] * xx[141] * xx[12]) * xx[66] + xx[56] * (xx
    [13] * xx[68] - xx[107] * xx[52] + xx[63] * xx[78] - xx[71] * xx[48] + xx[0]
    * xx[141] * xx[70]) + xx[76] * (xx[65] - xx[20]) - (xx[80] * xx[13] - xx[52]
    * xx[81]) + xx[99] - (xx[40] * xx[82] + xx[93] * xx[51]) * xx[0] + xx[0] *
    (xx[0] * (xx[97] * xx[51] + xx[40] * xx[95]) - xx[94]) - (xx[10] * (xx[32] -
    xx[100]) - (xx[7] * xx[109] + xx[5] * xx[120]) + xx[122] - (xx[19] * xx[121]
    + xx[123] * xx[16]) * xx[0] + xx[0] * ((xx[15] * xx[16] - xx[19] * xx[3]) *
    xx[0] - xx[125]) - xx[22] * (xx[42] * xx[120] - xx[109] * xx[44] + xx[127] *
    xx[119] - xx[41] * xx[103] - xx[0] * (xx[0] * xx[24] * xx[24] - xx[37]) *
    state[1] * state[3]))) - xx[129] * xx[26] - xx[87] * xx[113] + xx[130] * xx
    [98];
  xx[136] = xx[34] * xx[47] - ((xx[0] * xx[144] * xx[12] - (xx[63] * xx[77] +
    xx[75] * xx[48] + xx[13] * xx[83] + xx[69] * xx[52])) * xx[66] - (xx[107] *
    xx[13] + xx[68] * xx[52] + xx[63] * xx[71] + xx[78] * xx[48] - xx[0] * xx
    [144] * xx[70]) * xx[56] + xx[80] * xx[52] + xx[13] * xx[81] + xx[86] * xx
    [76] + xx[91] + xx[0] * (xx[40] * xx[93] - xx[82] * xx[51]) - xx[0] * (xx
    [102] + (xx[40] * xx[97] - xx[95] * xx[51]) * xx[0]) - (xx[5] * xx[109] -
    xx[7] * xx[120] + xx[35] * xx[10] + xx[6] + xx[0] * (xx[19] * xx[123] - xx
    [121] * xx[16]) + xx[0] * (xx[126] - xx[0] * (xx[3] * xx[16] + xx[19] * xx
    [15])) + (xx[120] * xx[44] + xx[42] * xx[109] + xx[127] * xx[41] + xx[119] *
              xx[103] + 4.0 * xx[21] * xx[24] * state[1] * state[3]) * xx[22]))
    - xx[129] * xx[23] - xx[33] * xx[113] + xx[130] * xx[62];
  memcpy(xx + 68, xx + 114, 4 * sizeof(double));
  factorAndSolveSymmetric(xx + 68, 2, xx + 15, ii + 0, xx + 135, xx + 12, xx +
    118);
  xx[3] = (xx[12] * xx[26] + xx[23] * xx[13] - xx[1] * xx[14]) / xx[27];
  xx[1] = xx[14] + xx[9] * xx[3];
  xx[6] = xx[4] * xx[1];
  xx[9] = xx[1] + xx[0] * (xx[11] - xx[6] * xx[4]);
  xx[1] = (input[0] - (xx[7] * xx[9] + xx[5] * (xx[28] - (xx[8] * xx[6] + xx[25])
             * xx[0]) - xx[29] * xx[3] + xx[38] - xx[32] * (xx[9] + xx[43])) -
           (xx[12] * xx[36] + xx[34] * xx[13])) / xx[49];
  xx[6] = xx[7] * xx[1] - xx[32] * xx[1];
  xx[7] = xx[3] + xx[18] * xx[1] - xx[39] * (xx[6] - (xx[8] * xx[4] * (xx[1] *
    xx[5] + xx[30]) + xx[6] * xx[4] * xx[4]) * xx[0]);
  xx[3] = (xx[98] * xx[12] + xx[62] * xx[13] - xx[73]) / xx[96];
  xx[4] = xx[128] - xx[101] * xx[3];
  xx[5] = xx[111];
  xx[6] = xx[89] + xx[88] * xx[3];
  pm_math_Quaternion_xform_ra(xx + 131, xx + 4, xx + 8);
  xx[4] = xx[92];
  xx[5] = xx[72] + xx[61] * xx[3];
  xx[6] = xx[59];
  pm_math_Quaternion_xform_ra(xx + 131, xx + 4, xx + 14);
  pm_math_Vector3_cross_ra(xx + 104, xx + 14, xx + 4);
  xx[4] = (input[1] - (xx[10] + xx[6] - xx[85] - xx[65] * (xx[15] + xx[90])) +
           xx[87] * xx[12] + xx[33] * xx[13]) / xx[67] + xx[110];
  xx[5] = xx[2] * xx[4];
  xx[6] = xx[58] * xx[4];
  xx[8] = xx[0] * (xx[5] * xx[53] + xx[50] * xx[6]);
  xx[9] = xx[4] - (xx[2] * xx[5] + xx[58] * xx[6]) * xx[0];
  xx[10] = xx[80] * xx[4] + xx[17];
  xx[11] = - (xx[65] * xx[4] + xx[4] * xx[81]);
  xx[12] = xx[108];
  pm_math_Quaternion_inverseXform_ra(xx + 131, xx + 10, xx + 13);
  xx[2] = xx[3] - (xx[79] * xx[8] + xx[112] * xx[9] + xx[84] * xx[14]);
  xx[3] = xx[1] - xx[7];
  xx[5] = xx[21] * xx[46] + xx[24] * xx[45];
  xx[6] = xx[3] * xx[5];
  xx[10] = xx[46] * xx[24] - xx[21] * xx[45];
  xx[11] = xx[10] * xx[3];
  deriv[0] = state[1];
  deriv[1] = xx[1];
  deriv[2] = state[3];
  deriv[3] = - xx[7];
  deriv[4] = state[5];
  deriv[5] = xx[4];
  deriv[6] = state[7];
  deriv[7] = xx[2];
  deriv[8] = state[9];
  deriv[9] = xx[31] * (xx[9] + xx[31] * xx[2] + xx[64] - (xx[3] - (xx[6] * xx[5]
    + xx[10] * xx[11]) * xx[0])) - xx[55] * (xx[60] - (xx[8] + xx[55] * xx[2]) -
    xx[0] * ((xx[21] * xx[57] - xx[54] * xx[24]) * xx[6] + xx[11] * (xx[21] *
    xx[54] + xx[24] * xx[57])));
  errorResult[0] = 0.0;
  return NULL;
}

PmfMessageId Robot_d2dba219_1_numJacPerturbLoBounds(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *bounds, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[1];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 1.0e-8;
  bounds[0] = xx[0];
  bounds[1] = xx[0];
  bounds[2] = xx[0];
  bounds[3] = xx[0];
  bounds[4] = xx[0];
  bounds[5] = xx[0];
  bounds[6] = xx[0];
  bounds[7] = xx[0];
  bounds[8] = xx[0];
  bounds[9] = xx[0];
  errorResult[0] = 0.0;
  return NULL;
}

PmfMessageId Robot_d2dba219_1_numJacPerturbHiBounds(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *bounds, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[2];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 1.0;
  xx[1] = +pmf_get_inf();
  bounds[0] = xx[0];
  bounds[1] = xx[1];
  bounds[2] = xx[0];
  bounds[3] = xx[1];
  bounds[4] = xx[0];
  bounds[5] = xx[1];
  bounds[6] = xx[0];
  bounds[7] = xx[1];
  bounds[8] = xx[0];
  bounds[9] = xx[1];
  errorResult[0] = 0.0;
  return NULL;
}
