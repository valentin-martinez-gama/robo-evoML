/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_f.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_f(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t84, NeDsMethodOutput *t85)
{
  PmRealVector out;
  real_T nonscalar2[8];
  real_T nonscalar3[8];
  real_T intrm_sf_mf_17;
  real_T zc_int12[3];
  real_T piece1;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t11;
  real_T t22[1];
  real_T t31;
  real_T t32;
  real_T t33;
  real_T t37;
  real_T t38;
  real_T t39;
  real_T t40;
  real_T t41;
  real_T t42;
  real_T t43;
  real_T t44;
  real_T t46;
  real_T t47;
  real_T t49;
  real_T t50;
  real_T t67;
  real_T t68;
  real_T t72;
  ETTS0 efOut;
  size_t _in1ivar;
  real_T b_efOut[1];
  ETTS0 c_efOut;
  real_T d_efOut[1];
  ETTS0 e_efOut;
  real_T f_efOut[1];
  real_T U_idx_0;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T X_idx_10;
  real_T X_idx_11;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_16;
  real_T X_idx_21;
  real_T X_idx_15;
  real_T X_idx_18;
  real_T X_idx_22;
  real_T X_idx_17;
  real_T X_idx_20;
  real_T X_idx_23;
  real_T X_idx_19;
  real_T X_idx_0;
  real_T X_idx_2;
  real_T X_idx_3;
  int32_T M_idx_25;
  int32_T M_idx_23;
  int32_T M_idx_24;
  int32_T M_idx_26;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_5;
  int32_T M_idx_6;
  int32_T M_idx_7;
  int32_T M_idx_8;
  int32_T M_idx_9;
  int32_T M_idx_10;
  int32_T M_idx_11;
  int32_T M_idx_13;
  int32_T M_idx_14;
  int32_T M_idx_15;
  int32_T M_idx_16;
  int32_T M_idx_17;
  int32_T M_idx_18;
  int32_T M_idx_19;
  real_T X_idx_1;
  (void)t0;
  M_idx_2 = t84->mM.mX[2];
  M_idx_3 = t84->mM.mX[3];
  M_idx_4 = t84->mM.mX[4];
  M_idx_5 = t84->mM.mX[5];
  M_idx_6 = t84->mM.mX[6];
  M_idx_7 = t84->mM.mX[7];
  M_idx_8 = t84->mM.mX[8];
  M_idx_9 = t84->mM.mX[9];
  M_idx_10 = t84->mM.mX[10];
  M_idx_11 = t84->mM.mX[11];
  M_idx_13 = t84->mM.mX[13];
  M_idx_14 = t84->mM.mX[14];
  M_idx_15 = t84->mM.mX[15];
  M_idx_16 = t84->mM.mX[16];
  M_idx_17 = t84->mM.mX[17];
  M_idx_18 = t84->mM.mX[18];
  M_idx_19 = t84->mM.mX[19];
  M_idx_23 = t84->mM.mX[23];
  M_idx_24 = t84->mM.mX[24];
  M_idx_25 = t84->mM.mX[25];
  M_idx_26 = t84->mM.mX[26];
  U_idx_0 = t84->mU.mX[0];
  X_idx_0 = t84->mX.mX[0];
  X_idx_1 = t84->mX.mX[1];
  X_idx_2 = t84->mX.mX[2];
  X_idx_3 = t84->mX.mX[3];
  X_idx_8 = t84->mX.mX[8];
  X_idx_9 = t84->mX.mX[9];
  X_idx_10 = t84->mX.mX[10];
  X_idx_11 = t84->mX.mX[11];
  X_idx_12 = t84->mX.mX[12];
  X_idx_13 = t84->mX.mX[13];
  X_idx_15 = t84->mX.mX[15];
  X_idx_16 = t84->mX.mX[16];
  X_idx_17 = t84->mX.mX[17];
  X_idx_18 = t84->mX.mX[18];
  X_idx_19 = t84->mX.mX[19];
  X_idx_20 = t84->mX.mX[20];
  X_idx_21 = t84->mX.mX[21];
  X_idx_22 = t84->mX.mX[22];
  X_idx_23 = t84->mX.mX[23];
  out = t85->mF;
  nonscalar2[0] = -0.78539816339744828;
  nonscalar2[1] = 0.0;
  nonscalar2[2] = 0.78539816339744828;
  nonscalar2[3] = 2.3561944901923448;
  nonscalar2[4] = 3.9269908169872414;
  nonscalar2[5] = 5.497787143782138;
  nonscalar2[6] = 6.2831853071795862;
  nonscalar2[7] = 7.0685834705770345;
  nonscalar3[0] = 0.014854461355243567;
  nonscalar3[1] = 0.0;
  nonscalar3[2] = -0.014854461355243567;
  nonscalar3[3] = -0.014854461355243567;
  nonscalar3[4] = 0.014854461355243567;
  nonscalar3[5] = 0.014854461355243567;
  nonscalar3[6] = 0.0;
  nonscalar3[7] = -0.014854461355243567;
  piece1 = -X_idx_11 + X_idx_8;
  t4 = -X_idx_11 + X_idx_9;
  t5 = -X_idx_11 + X_idx_10;
  t6 = ((((X_idx_11 * -1.0010000000000002E-9 + -X_idx_12) + -X_idx_13) +
         -X_idx_16) + X_idx_21) + X_idx_15;
  t11 = ((-X_idx_18 + X_idx_12) + X_idx_22) + X_idx_17;
  t72 = ((-X_idx_20 + X_idx_13) + X_idx_23) + X_idx_19;
  intrm_sf_mf_17 = X_idx_0 * 7.0 + -1.5707963267948966;
  t67 = intrm_sf_mf_17;
  t68 = intrm_sf_mf_17 + -2.0943951023931953;
  X_idx_0 = intrm_sf_mf_17 + 2.0943951023931953;
  t37 = cos(intrm_sf_mf_17) * 0.66666666666666663;
  t38 = cos(intrm_sf_mf_17 + -2.0943951023931953) * 0.66666666666666663;
  t39 = cos(intrm_sf_mf_17 + 2.0943951023931953) * 0.66666666666666663;
  t40 = -sin(intrm_sf_mf_17) * 0.66666666666666663;
  t41 = -sin(intrm_sf_mf_17 + -2.0943951023931953) * 0.66666666666666663;
  t42 = -sin(intrm_sf_mf_17 + 2.0943951023931953) * 0.66666666666666663;
  intrm_sf_mf_17 = X_idx_2 * 3.0200000000000002E-5;
  t31 = X_idx_3 * 3.0200000000000002E-5;
  t43 = cos(t67);
  t44 = -sin(t67);
  t46 = cos(t68);
  t47 = -sin(t68);
  t49 = cos(X_idx_0);
  t50 = -sin(X_idx_0);
  t32 = (atan2(fabs(-sin(X_idx_0)), -cos(X_idx_0)) * (real_T)(M_idx_25 != 0) +
         -atan2(fabs(-sin(X_idx_0)), -cos(X_idx_0)) * (real_T)(M_idx_25 == 0)) +
    3.1415926535897931;
  t22[0ULL] = t32;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)nonscalar2, (void *)t22, (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&b_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)nonscalar3, (void *)&_in1ivar);
  t33 = (atan2(fabs(-sin(t67)), -cos(t67)) * (real_T)(M_idx_23 != 0) + -atan2
         (fabs(-sin(t67)), -cos(t67)) * (real_T)(M_idx_23 == 0)) +
    3.1415926535897931;
  t22[0ULL] = t33;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&c_efOut.mField0, (void *)
    &c_efOut.mField1, (void *)&c_efOut.mField2, (void *)nonscalar2, (void *)t22,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&d_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t67 = (atan2(fabs(-sin(t68)), -cos(t68)) * (real_T)(M_idx_24 != 0) + -atan2
         (fabs(-sin(t68)), -cos(t68)) * (real_T)(M_idx_24 == 0)) +
    3.1415926535897931;
  t22[0ULL] = t67;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&e_efOut.mField0, (void *)
    &e_efOut.mField1, (void *)&e_efOut.mField2, (void *)nonscalar2, (void *)t22,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&f_efOut, (void *)e_efOut.mField0, (void *)
    e_efOut.mField1, (void *)e_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  zc_int12[0ULL] = d_efOut[0];
  zc_int12[1ULL] = f_efOut[0];
  zc_int12[2ULL] = b_efOut[0];
  t32 = ((piece1 - d_efOut[0] * U_idx_0 * 7.0) * t37 + (t4 - f_efOut[0] *
          U_idx_0 * 7.0) * t38) + (t5 - b_efOut[0] * U_idx_0 * 7.0) * t39;
  t33 = ((piece1 - d_efOut[0] * U_idx_0 * 7.0) * t40 + (t4 - f_efOut[0] *
          U_idx_0 * 7.0) * t41) + (t5 - b_efOut[0] * U_idx_0 * 7.0) * t42;
  if (M_idx_26 != 0) {
    t4 = t6 - ((X_idx_8 + -24.0) - 0.799999992) / 0.001;
  } else if (M_idx_2 != 0) {
    t4 = t6 - ((X_idx_8 + -24.0) + pmf_get_inf()) / 0.3;
  } else {
    t4 = t6 - (X_idx_8 + -24.0) * 1.0E-5;
  }

  if (M_idx_3 != 0) {
    t5 = X_idx_21 - ((-X_idx_8 + 24.0) - 0.799999992) / 0.001;
  } else {
    t5 = X_idx_21 - (-X_idx_8 + 24.0) * 1.0E-5;
  }

  if (M_idx_4 != 0) {
    t6 = X_idx_15 - (-X_idx_8 - 0.799999992) / 0.001;
  } else if (M_idx_5 != 0) {
    t6 = X_idx_15 - (-X_idx_8 + pmf_get_inf()) / 0.3;
  } else {
    t6 = X_idx_15 - -X_idx_8 * 1.0E-5;
  }

  if (M_idx_6 != 0) {
    t40 = X_idx_16 - (X_idx_8 - 0.799999992) / 0.001;
  } else {
    t40 = X_idx_16 - X_idx_8 * 1.0E-5;
  }

  if (M_idx_7 != 0) {
    t41 = t11 - ((X_idx_9 + -24.0) - 0.799999992) / 0.001;
  } else if (M_idx_8 != 0) {
    t41 = t11 - ((X_idx_9 + -24.0) + pmf_get_inf()) / 0.3;
  } else {
    t41 = t11 - (X_idx_9 + -24.0) * 1.0E-5;
  }

  if (M_idx_9 != 0) {
    t39 = X_idx_22 - ((-X_idx_9 + 24.0) - 0.799999992) / 0.001;
  } else {
    t39 = X_idx_22 - (-X_idx_9 + 24.0) * 1.0E-5;
  }

  if (M_idx_10 != 0) {
    t38 = X_idx_17 - (-X_idx_9 - 0.799999992) / 0.001;
  } else if (M_idx_11 != 0) {
    t38 = X_idx_17 - (-X_idx_9 + pmf_get_inf()) / 0.3;
  } else {
    t38 = X_idx_17 - -X_idx_9 * 1.0E-5;
  }

  if (M_idx_13 != 0) {
    t11 = X_idx_18 - (X_idx_9 - 0.799999992) / 0.001;
  } else {
    t11 = X_idx_18 - X_idx_9 * 1.0E-5;
  }

  if (M_idx_14 != 0) {
    t37 = t72 - ((X_idx_10 + -24.0) - 0.799999992) / 0.001;
  } else if (M_idx_15 != 0) {
    t37 = t72 - ((X_idx_10 + -24.0) + pmf_get_inf()) / 0.3;
  } else {
    t37 = t72 - (X_idx_10 + -24.0) * 1.0E-5;
  }

  if (M_idx_16 != 0) {
    t68 = X_idx_23 - ((-X_idx_10 + 24.0) - 0.799999992) / 0.001;
  } else {
    t68 = X_idx_23 - (-X_idx_10 + 24.0) * 1.0E-5;
  }

  if (M_idx_17 != 0) {
    t67 = X_idx_19 - (-X_idx_10 - 0.799999992) / 0.001;
  } else if (M_idx_18 != 0) {
    t67 = X_idx_19 - (-X_idx_10 + pmf_get_inf()) / 0.3;
  } else {
    t67 = X_idx_19 - -X_idx_10 * 1.0E-5;
  }

  if (M_idx_19 != 0) {
    X_idx_0 = X_idx_20 - (X_idx_10 - 0.799999992) / 0.001;
  } else {
    X_idx_0 = X_idx_20 - X_idx_10 * 1.0E-5;
  }

  out.mX[0] = 0.0;
  out.mX[1] = -((t32 - (-(U_idx_0 * t31 * 7.0))) / 0.57735026918962584);
  out.mX[2] = -((t33 - U_idx_0 * intrm_sf_mf_17 * 7.0) / 0.66666666666666663);
  out.mX[3] = -(((-(d_efOut[0] * U_idx_0 * 7.0) * 0.33333333333333331 +
                  -(f_efOut[0] * U_idx_0 * 7.0) * 0.33333333333333331) +
                 -(b_efOut[0] * U_idx_0 * 7.0) * 0.33333333333333331) /
                0.33333333333333331);
  out.mX[4] = zc_int12[0ULL] * U_idx_0 * 7.0;
  out.mX[5] = zc_int12[1ULL] * U_idx_0 * 7.0;
  out.mX[6] = zc_int12[2ULL] * U_idx_0 * 7.0;
  out.mX[7] = -0.0;
  out.mX[8] = -((t43 * X_idx_2 + t44 * X_idx_3) + X_idx_1);
  out.mX[9] = -((t46 * X_idx_2 + t47 * X_idx_3) + X_idx_1);
  out.mX[10] = -((t49 * X_idx_2 + t50 * X_idx_3) + X_idx_1);
  out.mX[11] = -(((((X_idx_3 * intrm_sf_mf_17 - X_idx_2 * t31) * 1.5 +
                    -(d_efOut[0] * ((X_idx_11 * -1.0010000000000002E-9 +
    -X_idx_12) + -X_idx_13))) + -(f_efOut[0] * X_idx_12)) + -(b_efOut[0] *
    X_idx_13)) * 7.0);
  out.mX[12] = t4;
  out.mX[13] = t5;
  out.mX[14] = t6;
  out.mX[15] = t40;
  out.mX[16] = t41;
  out.mX[17] = t39;
  out.mX[18] = t38;
  out.mX[19] = t11;
  out.mX[20] = t37;
  out.mX[21] = t68;
  out.mX[22] = t67;
  out.mX[23] = X_idx_0;
  (void)t0;
  (void)t85;
  return 0;
}
