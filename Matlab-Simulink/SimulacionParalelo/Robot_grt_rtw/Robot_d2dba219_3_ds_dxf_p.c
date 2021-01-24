/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_dxf_p.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_dxf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDXF_P;
  out.mNumCol = 24ULL;
  out.mNumRow = 24ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 10;
  out.mJc[2] = 13;
  out.mJc[3] = 18;
  out.mJc[4] = 23;
  out.mJc[5] = 23;
  out.mJc[6] = 23;
  out.mJc[7] = 23;
  out.mJc[8] = 23;
  out.mJc[9] = 29;
  out.mJc[10] = 35;
  out.mJc[11] = 41;
  out.mJc[12] = 45;
  out.mJc[13] = 48;
  out.mJc[14] = 51;
  out.mJc[15] = 51;
  out.mJc[16] = 53;
  out.mJc[17] = 55;
  out.mJc[18] = 57;
  out.mJc[19] = 59;
  out.mJc[20] = 61;
  out.mJc[21] = 63;
  out.mJc[22] = 65;
  out.mJc[23] = 67;
  out.mJc[24] = 69;
  out.mIr[0] = 1;
  out.mIr[1] = 2;
  out.mIr[2] = 3;
  out.mIr[3] = 4;
  out.mIr[4] = 5;
  out.mIr[5] = 6;
  out.mIr[6] = 8;
  out.mIr[7] = 9;
  out.mIr[8] = 10;
  out.mIr[9] = 11;
  out.mIr[10] = 8;
  out.mIr[11] = 9;
  out.mIr[12] = 10;
  out.mIr[13] = 2;
  out.mIr[14] = 8;
  out.mIr[15] = 9;
  out.mIr[16] = 10;
  out.mIr[17] = 11;
  out.mIr[18] = 1;
  out.mIr[19] = 8;
  out.mIr[20] = 9;
  out.mIr[21] = 10;
  out.mIr[22] = 11;
  out.mIr[23] = 1;
  out.mIr[24] = 2;
  out.mIr[25] = 12;
  out.mIr[26] = 13;
  out.mIr[27] = 14;
  out.mIr[28] = 15;
  out.mIr[29] = 1;
  out.mIr[30] = 2;
  out.mIr[31] = 16;
  out.mIr[32] = 17;
  out.mIr[33] = 18;
  out.mIr[34] = 19;
  out.mIr[35] = 1;
  out.mIr[36] = 2;
  out.mIr[37] = 20;
  out.mIr[38] = 21;
  out.mIr[39] = 22;
  out.mIr[40] = 23;
  out.mIr[41] = 1;
  out.mIr[42] = 2;
  out.mIr[43] = 11;
  out.mIr[44] = 12;
  out.mIr[45] = 11;
  out.mIr[46] = 12;
  out.mIr[47] = 16;
  out.mIr[48] = 11;
  out.mIr[49] = 12;
  out.mIr[50] = 20;
  out.mIr[51] = 12;
  out.mIr[52] = 14;
  out.mIr[53] = 12;
  out.mIr[54] = 15;
  out.mIr[55] = 16;
  out.mIr[56] = 18;
  out.mIr[57] = 16;
  out.mIr[58] = 19;
  out.mIr[59] = 20;
  out.mIr[60] = 22;
  out.mIr[61] = 20;
  out.mIr[62] = 23;
  out.mIr[63] = 12;
  out.mIr[64] = 13;
  out.mIr[65] = 16;
  out.mIr[66] = 17;
  out.mIr[67] = 20;
  out.mIr[68] = 21;
  (void)sys;
  (void)t2;
  return 0;
}
