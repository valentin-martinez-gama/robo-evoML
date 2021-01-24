/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_2_ds_tdxf_p.h"
#include "Robot_d2dba219_2_ds_sys_struct.h"
#include "Robot_d2dba219_2_ds_externals.h"
#include "Robot_d2dba219_2_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_2_ds_tdxf_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDXF_P;
  out.mNumCol = 24ULL;
  out.mNumRow = 24ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 10;
  out.mJc[2] = 14;
  out.mJc[3] = 20;
  out.mJc[4] = 26;
  out.mJc[5] = 26;
  out.mJc[6] = 26;
  out.mJc[7] = 26;
  out.mJc[8] = 26;
  out.mJc[9] = 33;
  out.mJc[10] = 40;
  out.mJc[11] = 47;
  out.mJc[12] = 53;
  out.mJc[13] = 58;
  out.mJc[14] = 63;
  out.mJc[15] = 64;
  out.mJc[16] = 66;
  out.mJc[17] = 68;
  out.mJc[18] = 70;
  out.mJc[19] = 72;
  out.mJc[20] = 74;
  out.mJc[21] = 76;
  out.mJc[22] = 78;
  out.mJc[23] = 80;
  out.mJc[24] = 82;
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
  out.mIr[10] = 3;
  out.mIr[11] = 8;
  out.mIr[12] = 9;
  out.mIr[13] = 10;
  out.mIr[14] = 1;
  out.mIr[15] = 2;
  out.mIr[16] = 8;
  out.mIr[17] = 9;
  out.mIr[18] = 10;
  out.mIr[19] = 11;
  out.mIr[20] = 1;
  out.mIr[21] = 2;
  out.mIr[22] = 8;
  out.mIr[23] = 9;
  out.mIr[24] = 10;
  out.mIr[25] = 11;
  out.mIr[26] = 1;
  out.mIr[27] = 2;
  out.mIr[28] = 3;
  out.mIr[29] = 12;
  out.mIr[30] = 13;
  out.mIr[31] = 14;
  out.mIr[32] = 15;
  out.mIr[33] = 1;
  out.mIr[34] = 2;
  out.mIr[35] = 3;
  out.mIr[36] = 16;
  out.mIr[37] = 17;
  out.mIr[38] = 18;
  out.mIr[39] = 19;
  out.mIr[40] = 1;
  out.mIr[41] = 2;
  out.mIr[42] = 3;
  out.mIr[43] = 20;
  out.mIr[44] = 21;
  out.mIr[45] = 22;
  out.mIr[46] = 23;
  out.mIr[47] = 1;
  out.mIr[48] = 2;
  out.mIr[49] = 3;
  out.mIr[50] = 8;
  out.mIr[51] = 11;
  out.mIr[52] = 12;
  out.mIr[53] = 8;
  out.mIr[54] = 9;
  out.mIr[55] = 11;
  out.mIr[56] = 12;
  out.mIr[57] = 16;
  out.mIr[58] = 8;
  out.mIr[59] = 10;
  out.mIr[60] = 11;
  out.mIr[61] = 12;
  out.mIr[62] = 20;
  out.mIr[63] = 11;
  out.mIr[64] = 12;
  out.mIr[65] = 14;
  out.mIr[66] = 12;
  out.mIr[67] = 15;
  out.mIr[68] = 16;
  out.mIr[69] = 18;
  out.mIr[70] = 16;
  out.mIr[71] = 19;
  out.mIr[72] = 20;
  out.mIr[73] = 22;
  out.mIr[74] = 20;
  out.mIr[75] = 23;
  out.mIr[76] = 12;
  out.mIr[77] = 13;
  out.mIr[78] = 16;
  out.mIr[79] = 17;
  out.mIr[80] = 20;
  out.mIr[81] = 21;
  (void)sys;
  (void)t2;
  return 0;
}
