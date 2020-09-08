/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_zc.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_zc(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t21, NeDsMethodOutput *t22)
{
  PmRealVector out;
  real_T t1;
  boolean_T t2;
  boolean_T t3;
  boolean_T t5;
  boolean_T t7;
  real_T t9;
  boolean_T t10;
  real_T t11;
  boolean_T t12;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t20;
  real_T t13_idx_13;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T X_idx_10;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T U_idx_6;
  real_T X_idx_0;
  int32_T M_idx_14;
  int32_T M_idx_10;
  int32_T M_idx_7;
  int32_T M_idx_26;
  int32_T M_idx_17;
  int32_T M_idx_4;
  (void)t0;
  M_idx_4 = t21->mM.mX[4];
  M_idx_7 = t21->mM.mX[7];
  M_idx_10 = t21->mM.mX[10];
  M_idx_14 = t21->mM.mX[14];
  M_idx_17 = t21->mM.mX[17];
  M_idx_26 = t21->mM.mX[26];
  U_idx_1 = t21->mU.mX[1];
  U_idx_2 = t21->mU.mX[2];
  U_idx_3 = t21->mU.mX[3];
  U_idx_4 = t21->mU.mX[4];
  U_idx_5 = t21->mU.mX[5];
  U_idx_6 = t21->mU.mX[6];
  X_idx_0 = t21->mX.mX[0];
  X_idx_8 = t21->mX.mX[8];
  X_idx_9 = t21->mX.mX[9];
  X_idx_10 = t21->mX.mX[10];
  out = t22->mZC;
  t1 = X_idx_0 * 7.0 + -1.5707963267948966;
  t18 = t1;
  X_idx_0 = t1 + -2.0943951023931953;
  t20 = t1 + 2.0943951023931953;
  if (M_idx_14 == 0) {
    t1 = -pmf_get_inf() - (X_idx_10 + -24.0);
  } else {
    t1 = 0.0;
  }

  if (-X_idx_10 + 24.0 > 0.8) {
    t2 = (U_idx_5 > 0.5);
  } else {
    t2 = false;
  }

  if (X_idx_9 > 0.8) {
    t3 = (U_idx_4 > 0.5);
  } else {
    t3 = false;
  }

  if (M_idx_10 == 0) {
    t15 = -pmf_get_inf() - (-X_idx_9);
  } else {
    t15 = 0.0;
  }

  if (-X_idx_9 + 24.0 > 0.8) {
    t5 = (U_idx_3 > 0.5);
  } else {
    t5 = false;
  }

  if (M_idx_7 == 0) {
    t16 = -pmf_get_inf() - (X_idx_9 + -24.0);
  } else {
    t16 = 0.0;
  }

  if (X_idx_8 > 0.8) {
    t7 = (U_idx_2 > 0.5);
  } else {
    t7 = false;
  }

  if (M_idx_26 == 0) {
    t17 = -pmf_get_inf() - (X_idx_8 + -24.0);
  } else {
    t17 = 0.0;
  }

  if (M_idx_17 == 0) {
    t9 = -pmf_get_inf() - (-X_idx_10);
  } else {
    t9 = 0.0;
  }

  if (-X_idx_8 + 24.0 > 0.8) {
    t10 = (U_idx_1 > 0.5);
  } else {
    t10 = false;
  }

  if (M_idx_4 == 0) {
    t11 = -pmf_get_inf() - (-X_idx_8);
  } else {
    t11 = 0.0;
  }

  if (X_idx_10 > 0.8) {
    t12 = (U_idx_6 > 0.5);
  } else {
    t12 = false;
  }

  t13_idx_13 = -sin(X_idx_0);
  t18 = -sin(t18);
  X_idx_0 = -sin(t20);
  out.mX[0] = t1;
  out.mX[1] = (X_idx_10 + -24.0) - 0.8;
  out.mX[2] = (real_T)t2;
  out.mX[3] = (real_T)t3;
  out.mX[4] = t15;
  out.mX[5] = -X_idx_10 - 0.8;
  out.mX[6] = -X_idx_9 - 0.8;
  out.mX[7] = (real_T)t5;
  out.mX[8] = t16;
  out.mX[9] = (real_T)t7;
  out.mX[10] = (X_idx_9 + -24.0) - 0.8;
  out.mX[11] = t17;
  out.mX[12] = t9;
  out.mX[13] = t13_idx_13;
  out.mX[14] = t18;
  out.mX[15] = (real_T)t10;
  out.mX[16] = (U_idx_5 - 0.5) - ((-X_idx_10 + 24.0) - 0.8);
  out.mX[17] = (U_idx_6 - 0.5) - (X_idx_10 - 0.8);
  out.mX[18] = (U_idx_3 - 0.5) - ((-X_idx_9 + 24.0) - 0.8);
  out.mX[19] = X_idx_0;
  out.mX[20] = -X_idx_8 - 0.8;
  out.mX[21] = t11;
  out.mX[22] = (U_idx_4 - 0.5) - (X_idx_9 - 0.8);
  out.mX[23] = (U_idx_2 - 0.5) - (X_idx_8 - 0.8);
  out.mX[24] = (X_idx_8 + -24.0) - 0.8;
  out.mX[25] = (real_T)t12;
  out.mX[26] = (U_idx_1 - 0.5) - ((-X_idx_8 + 24.0) - 0.8);
  (void)t0;
  (void)t22;
  return 0;
}
