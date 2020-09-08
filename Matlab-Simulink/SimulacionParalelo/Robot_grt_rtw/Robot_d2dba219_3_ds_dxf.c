/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Robot/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Robot_d2dba219_3_ds_dxf.h"
#include "Robot_d2dba219_3_ds_sys_struct.h"
#include "Robot_d2dba219_3_ds_externals.h"
#include "Robot_d2dba219_3_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Robot_d2dba219_3_ds_dxf(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t220, NeDsMethodOutput *t221)
{
  PmRealVector out;
  real_T nonscalar2[8];
  real_T nonscalar3[8];
  real_T intrm_sf_mf_17;
  real_T intermediate_der83;
  real_T intermediate_der94;
  real_T intermediate_der95;
  real_T t19[69];
  real_T t27[1];
  real_T t31[10];
  real_T t33[5];
  real_T t34[5];
  real_T t35[6];
  real_T t36[6];
  real_T t37[6];
  real_T t38[4];
  real_T t91;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t101;
  real_T t103;
  real_T t104;
  real_T t106;
  real_T t107;
  real_T t115;
  real_T t116;
  real_T t117;
  real_T t118;
  real_T t119;
  real_T t120;
  real_T t133;
  real_T t134;
  real_T t136;
  real_T t137;
  real_T t139;
  real_T t140;
  real_T t156;
  real_T t160;
  real_T t183;
  real_T t189;
  real_T t191;
  real_T t206;
  ETTS0 efOut;
  size_t _in1ivar;
  real_T b_efOut[1];
  ETTS0 c_efOut;
  real_T d_efOut[1];
  ETTS0 e_efOut;
  real_T f_efOut[1];
  real_T g_efOut[1];
  real_T h_efOut[1];
  real_T i_efOut[1];
  real_T U_idx_0;
  real_T X_idx_11;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T X_idx_10;
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
  M_idx_2 = t220->mM.mX[2];
  M_idx_3 = t220->mM.mX[3];
  M_idx_4 = t220->mM.mX[4];
  M_idx_5 = t220->mM.mX[5];
  M_idx_6 = t220->mM.mX[6];
  M_idx_7 = t220->mM.mX[7];
  M_idx_8 = t220->mM.mX[8];
  M_idx_9 = t220->mM.mX[9];
  M_idx_10 = t220->mM.mX[10];
  M_idx_11 = t220->mM.mX[11];
  M_idx_13 = t220->mM.mX[13];
  M_idx_14 = t220->mM.mX[14];
  M_idx_15 = t220->mM.mX[15];
  M_idx_16 = t220->mM.mX[16];
  M_idx_17 = t220->mM.mX[17];
  M_idx_18 = t220->mM.mX[18];
  M_idx_19 = t220->mM.mX[19];
  M_idx_23 = t220->mM.mX[23];
  M_idx_24 = t220->mM.mX[24];
  M_idx_25 = t220->mM.mX[25];
  M_idx_26 = t220->mM.mX[26];
  U_idx_0 = t220->mU.mX[0];
  X_idx_0 = t220->mX.mX[0];
  X_idx_1 = t220->mX.mX[1];
  X_idx_2 = t220->mX.mX[2];
  X_idx_3 = t220->mX.mX[3];
  X_idx_8 = t220->mX.mX[8];
  X_idx_9 = t220->mX.mX[9];
  X_idx_10 = t220->mX.mX[10];
  X_idx_11 = t220->mX.mX[11];
  X_idx_12 = t220->mX.mX[12];
  X_idx_13 = t220->mX.mX[13];
  out = t221->mDXF;
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
  t160 = -X_idx_11 + X_idx_8;
  intermediate_der94 = -X_idx_11 + X_idx_9;
  intermediate_der95 = -X_idx_11 + X_idx_10;
  intrm_sf_mf_17 = X_idx_0 * 7.0 + -1.5707963267948966;
  t94 = cos(intrm_sf_mf_17) * 0.66666666666666663;
  t95 = cos(intrm_sf_mf_17 + -2.0943951023931953) * 0.66666666666666663;
  t96 = cos(intrm_sf_mf_17 + 2.0943951023931953) * 0.66666666666666663;
  t97 = -sin(intrm_sf_mf_17) * 0.66666666666666663;
  t98 = -sin(intrm_sf_mf_17 + -2.0943951023931953) * 0.66666666666666663;
  t99 = -sin(intrm_sf_mf_17 + 2.0943951023931953) * 0.66666666666666663;
  t100 = cos(intrm_sf_mf_17);
  t101 = -sin(intrm_sf_mf_17);
  t103 = cos(intrm_sf_mf_17 + -2.0943951023931953);
  t104 = -sin(intrm_sf_mf_17 + -2.0943951023931953);
  t106 = cos(intrm_sf_mf_17 + 2.0943951023931953);
  t107 = -sin(intrm_sf_mf_17 + 2.0943951023931953);
  X_idx_8 = (atan2(fabs(-sin(intrm_sf_mf_17 + 2.0943951023931953)), -cos
                   (intrm_sf_mf_17 + 2.0943951023931953)) * (real_T)(M_idx_25 !=
              0) + -atan2(fabs(-sin(intrm_sf_mf_17 + 2.0943951023931953)), -cos
              (intrm_sf_mf_17 + 2.0943951023931953)) * (real_T)(M_idx_25 == 0))
    + 3.1415926535897931;
  t27[0ULL] = X_idx_8;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)nonscalar2, (void *)t27, (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&b_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)nonscalar3, (void *)&_in1ivar);
  X_idx_8 = (atan2(fabs(-sin(intrm_sf_mf_17)), -cos(intrm_sf_mf_17)) * (real_T)
             (M_idx_23 != 0) + -atan2(fabs(-sin(intrm_sf_mf_17)), -cos
              (intrm_sf_mf_17)) * (real_T)(M_idx_23 == 0)) + 3.1415926535897931;
  t27[0ULL] = X_idx_8;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&c_efOut.mField0, (void *)
    &c_efOut.mField1, (void *)&c_efOut.mField2, (void *)nonscalar2, (void *)t27,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&d_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  X_idx_8 = (atan2(fabs(-sin(intrm_sf_mf_17 + -2.0943951023931953)), -cos
                   (intrm_sf_mf_17 + -2.0943951023931953)) * (real_T)(M_idx_24
              != 0) + -atan2(fabs(-sin(intrm_sf_mf_17 + -2.0943951023931953)),
              -cos(intrm_sf_mf_17 + -2.0943951023931953)) * (real_T)(M_idx_24 ==
              0)) + 3.1415926535897931;
  t27[0ULL] = X_idx_8;
  _in1ivar = 8ULL;
  tlu2_linear_nearest_prelookup((void *)&e_efOut.mField0, (void *)
    &e_efOut.mField1, (void *)&e_efOut.mField2, (void *)nonscalar2, (void *)t27,
    (void *)&_in1ivar);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_value((void *)&f_efOut, (void *)e_efOut.mField0, (void *)
    e_efOut.mField1, (void *)e_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t115 = -sin(intrm_sf_mf_17) * 7.0 * 0.66666666666666663;
  t116 = -sin(intrm_sf_mf_17 + -2.0943951023931953) * 7.0 * 0.66666666666666663;
  t117 = -sin(intrm_sf_mf_17 + 2.0943951023931953) * 7.0 * 0.66666666666666663;
  t118 = -(cos(intrm_sf_mf_17) * 7.0) * 0.66666666666666663;
  t119 = -(cos(intrm_sf_mf_17 + -2.0943951023931953) * 7.0) *
    0.66666666666666663;
  t120 = -(cos(intrm_sf_mf_17 + 2.0943951023931953) * 7.0) * 0.66666666666666663;
  t133 = -sin(intrm_sf_mf_17) * 7.0;
  t134 = -(cos(intrm_sf_mf_17) * 7.0);
  t136 = -sin(intrm_sf_mf_17 + -2.0943951023931953) * 7.0;
  t137 = -(cos(intrm_sf_mf_17 + -2.0943951023931953) * 7.0);
  t139 = -sin(intrm_sf_mf_17 + 2.0943951023931953) * 7.0;
  t140 = -(cos(intrm_sf_mf_17 + 2.0943951023931953) * 7.0);
  X_idx_10 = -cos(intrm_sf_mf_17 + 2.0943951023931953);
  X_idx_0 = fabs(-sin(intrm_sf_mf_17 + 2.0943951023931953)) * fabs(-sin
    (intrm_sf_mf_17 + 2.0943951023931953)) + -cos(intrm_sf_mf_17 +
    2.0943951023931953) * -cos(intrm_sf_mf_17 + 2.0943951023931953);
  t183 = -fabs(-sin(intrm_sf_mf_17 + 2.0943951023931953));
  if (t107 > 0.0) {
    t189 = 1.0;
  } else {
    t189 = t107 < 0.0 ? -1.0 : 0.0;
  }

  if (t107 > 0.0) {
    t206 = 1.0;
  } else {
    t206 = t107 < 0.0 ? -1.0 : 0.0;
  }

  intermediate_der83 = (-(cos(intrm_sf_mf_17 + 2.0943951023931953) * 7.0) *
                        (X_idx_10 / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0)) * t189
                        + -(-sin(intrm_sf_mf_17 + 2.0943951023931953) * 7.0) *
                        (t183 / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0))) * (real_T)
    (M_idx_25 != 0) + -(-(cos(intrm_sf_mf_17 + 2.0943951023931953) * 7.0) *
                        (X_idx_10 / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0)) * t206
                        + -(-sin(intrm_sf_mf_17 + 2.0943951023931953) * 7.0) *
                        (t183 / (X_idx_0 == 0.0 ? 1.0E-16 : X_idx_0))) * (real_T)
    (M_idx_25 == 0);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_derivatives((void *)&g_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t156 = g_efOut[0] * intermediate_der83;
  t189 = -cos(intrm_sf_mf_17);
  t206 = fabs(-sin(intrm_sf_mf_17)) * fabs(-sin(intrm_sf_mf_17)) + -cos
    (intrm_sf_mf_17) * -cos(intrm_sf_mf_17);
  t191 = -fabs(-sin(intrm_sf_mf_17));
  if (t101 > 0.0) {
    X_idx_0 = 1.0;
  } else {
    X_idx_0 = t101 < 0.0 ? -1.0 : 0.0;
  }

  if (t101 > 0.0) {
    t183 = 1.0;
  } else {
    t183 = t101 < 0.0 ? -1.0 : 0.0;
  }

  intermediate_der83 = (-(cos(intrm_sf_mf_17) * 7.0) * (t189 / (t206 == 0.0 ?
    1.0E-16 : t206)) * X_idx_0 + -(-sin(intrm_sf_mf_17) * 7.0) * (t191 / (t206 ==
    0.0 ? 1.0E-16 : t206))) * (real_T)(M_idx_23 != 0) + -(-(cos(intrm_sf_mf_17) *
    7.0) * (t189 / (t206 == 0.0 ? 1.0E-16 : t206)) * t183 + -(-sin
    (intrm_sf_mf_17) * 7.0) * (t191 / (t206 == 0.0 ? 1.0E-16 : t206))) * (real_T)
    (M_idx_23 == 0);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_derivatives((void *)&h_efOut, (void *)c_efOut.mField0,
    (void *)c_efOut.mField1, (void *)c_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  t91 = h_efOut[0] * intermediate_der83;
  X_idx_0 = -cos(intrm_sf_mf_17 + -2.0943951023931953);
  t183 = fabs(-sin(intrm_sf_mf_17 + -2.0943951023931953)) * fabs(-sin
    (intrm_sf_mf_17 + -2.0943951023931953)) + -cos(intrm_sf_mf_17 +
    -2.0943951023931953) * -cos(intrm_sf_mf_17 + -2.0943951023931953);
  X_idx_8 = -fabs(-sin(intrm_sf_mf_17 + -2.0943951023931953));
  if (t104 > 0.0) {
    X_idx_9 = 1.0;
  } else {
    X_idx_9 = t104 < 0.0 ? -1.0 : 0.0;
  }

  if (t104 > 0.0) {
    X_idx_10 = 1.0;
  } else {
    X_idx_10 = t104 < 0.0 ? -1.0 : 0.0;
  }

  intermediate_der83 = (-(cos(intrm_sf_mf_17 + -2.0943951023931953) * 7.0) *
                        (X_idx_0 / (t183 == 0.0 ? 1.0E-16 : t183)) * X_idx_9 +
                        -(-sin(intrm_sf_mf_17 + -2.0943951023931953) * 7.0) *
                        (X_idx_8 / (t183 == 0.0 ? 1.0E-16 : t183))) * (real_T)
    (M_idx_24 != 0) + -(-(cos(intrm_sf_mf_17 + -2.0943951023931953) * 7.0) *
                        (X_idx_0 / (t183 == 0.0 ? 1.0E-16 : t183)) * X_idx_10 +
                        -(-sin(intrm_sf_mf_17 + -2.0943951023931953) * 7.0) *
                        (X_idx_8 / (t183 == 0.0 ? 1.0E-16 : t183))) * (real_T)
    (M_idx_24 == 0);
  _in1ivar = 8ULL;
  tlu2_1d_linear_nearest_derivatives((void *)&i_efOut, (void *)e_efOut.mField0,
    (void *)e_efOut.mField1, (void *)e_efOut.mField2, (void *)nonscalar3, (void *)
    &_in1ivar);
  X_idx_8 = i_efOut[0] * intermediate_der83;
  intermediate_der83 = (-t94 + -t95) + -t96;
  X_idx_9 = (((((t160 - d_efOut[0] * U_idx_0 * 7.0) * t115 + -(t91 * U_idx_0 *
    7.0) * t94) + (intermediate_der94 - f_efOut[0] * U_idx_0 * 7.0) * t116) +
              -(X_idx_8 * U_idx_0 * 7.0) * t95) + (intermediate_der95 - b_efOut
              [0] * U_idx_0 * 7.0) * t117) + -(t156 * U_idx_0 * 7.0) * t96;
  t115 = t94;
  t94 = t95;
  t95 = t96;
  t96 = (-t97 + -t98) + -t99;
  t116 = (((((t160 - d_efOut[0] * U_idx_0 * 7.0) * t118 + -(t91 * U_idx_0 * 7.0)
             * t97) + (intermediate_der94 - f_efOut[0] * U_idx_0 * 7.0) * t119)
           + -(X_idx_8 * U_idx_0 * 7.0) * t98) + (intermediate_der95 - b_efOut[0]
           * U_idx_0 * 7.0) * t120) + -(t156 * U_idx_0 * 7.0) * t99;
  intermediate_der94 = t98;
  intermediate_der95 = t99;
  if (M_idx_26 != 0) {
    t98 = -1000.0;
  } else if (M_idx_2 != 0) {
    t98 = -3.3333333333333335;
  } else {
    t98 = -1.0E-5;
  }

  if (M_idx_3 != 0) {
    t99 = 1000.0;
  } else {
    t99 = 1.0E-5;
  }

  if (M_idx_4 != 0) {
    t117 = 1000.0;
  } else if (M_idx_5 != 0) {
    t117 = 3.3333333333333335;
  } else {
    t117 = 1.0E-5;
  }

  if (M_idx_6 != 0) {
    t118 = -1000.0;
  } else {
    t118 = -1.0E-5;
  }

  if (M_idx_7 != 0) {
    t119 = -1000.0;
  } else if (M_idx_8 != 0) {
    t119 = -3.3333333333333335;
  } else {
    t119 = -1.0E-5;
  }

  if (M_idx_9 != 0) {
    t120 = 1000.0;
  } else {
    t120 = 1.0E-5;
  }

  if (M_idx_10 != 0) {
    X_idx_10 = 1000.0;
  } else if (M_idx_11 != 0) {
    X_idx_10 = 3.3333333333333335;
  } else {
    X_idx_10 = 1.0E-5;
  }

  if (M_idx_13 != 0) {
    X_idx_0 = -1000.0;
  } else {
    X_idx_0 = -1.0E-5;
  }

  if (M_idx_14 != 0) {
    t183 = -1000.0;
  } else if (M_idx_15 != 0) {
    t183 = -3.3333333333333335;
  } else {
    t183 = -1.0E-5;
  }

  if (M_idx_16 != 0) {
    t189 = 1000.0;
  } else {
    t189 = 1.0E-5;
  }

  if (M_idx_17 != 0) {
    t206 = 1000.0;
  } else if (M_idx_18 != 0) {
    t206 = 3.3333333333333335;
  } else {
    t206 = 1.0E-5;
  }

  if (M_idx_19 != 0) {
    t191 = -1000.0;
  } else {
    t191 = -1.0E-5;
  }

  t31[0ULL] = -(X_idx_9 * 1.732050807568877);
  t31[1ULL] = -(t116 * 1.5);
  t31[2ULL] = -(((-(t91 * U_idx_0 * 7.0) * 0.33333333333333331 + -(X_idx_8 *
    U_idx_0 * 7.0) * 0.33333333333333331) + -(t156 * U_idx_0 * 7.0) *
                 0.33333333333333331) * 3.0);
  t31[3ULL] = ((t91 + 0.0 * X_idx_8) + 0.0 * t156) * U_idx_0 * 7.0;
  t31[4ULL] = ((0.0 * t91 + X_idx_8) + 0.0 * t156) * U_idx_0 * 7.0;
  t31[5ULL] = ((0.0 * t91 + 0.0 * X_idx_8) + t156) * U_idx_0 * 7.0;
  t31[6ULL] = -((t133 * X_idx_2 + t134 * X_idx_3) + 0.0 * X_idx_1);
  t31[7ULL] = -((t136 * X_idx_2 + t137 * X_idx_3) + 0.0 * X_idx_1);
  t31[8ULL] = -((t139 * X_idx_2 + t140 * X_idx_3) + 0.0 * X_idx_1);
  t31[9ULL] = -(((-(t91 * ((X_idx_11 * -1.0010000000000002E-9 + -X_idx_12) +
    -X_idx_13)) + -(X_idx_8 * X_idx_12)) + -(t156 * X_idx_13)) * 7.0);
  t33[0ULL] = -(-(U_idx_0 * 3.0200000000000002E-5 * 7.0) * 1.5);
  t33[1ULL] = -t100;
  t33[2ULL] = -t103;
  t33[3ULL] = -t106;
  t33[4ULL] = -((X_idx_3 * 3.0200000000000002E-5 - X_idx_3 *
                 3.0200000000000002E-5) * 10.5);
  t34[0ULL] = -(U_idx_0 * 3.0200000000000002E-5 * 12.124355652982139);
  t34[1ULL] = -t101;
  t34[2ULL] = -t104;
  t34[3ULL] = -t107;
  t34[4ULL] = -((X_idx_2 * 3.0200000000000002E-5 - X_idx_2 *
                 3.0200000000000002E-5) * 10.5);
  t35[0ULL] = -(t115 * 1.732050807568877);
  t35[1ULL] = -(t97 * 1.5);
  t35[2ULL] = t98;
  t35[3ULL] = t99;
  t35[4ULL] = t117;
  t35[5ULL] = t118;
  t36[0ULL] = -(t94 * 1.732050807568877);
  t36[1ULL] = -(intermediate_der94 * 1.5);
  t36[2ULL] = t119;
  t36[3ULL] = t120;
  t36[4ULL] = X_idx_10;
  t36[5ULL] = X_idx_0;
  t37[0ULL] = -(t95 * 1.732050807568877);
  t37[1ULL] = -(intermediate_der95 * 1.5);
  t37[2ULL] = t183;
  t37[3ULL] = t189;
  t37[4ULL] = t206;
  t37[5ULL] = t191;
  t38[0ULL] = -(intermediate_der83 * 1.732050807568877);
  t38[1ULL] = -(t96 * 1.5);
  t38[2ULL] = -(d_efOut[0] * -1.0010000000000002E-9 * -7.0);
  t38[3ULL] = -1.0010000000000002E-9;
  for (_in1ivar = 0ULL; _in1ivar < 10ULL; _in1ivar++) {
    t19[_in1ivar] = t31[_in1ivar];
  }

  t19[10ULL] = -1.0;
  t19[11ULL] = -1.0;
  t19[12ULL] = -1.0;
  for (_in1ivar = 0ULL; _in1ivar < 5ULL; _in1ivar++) {
    t19[_in1ivar + 13ULL] = t33[_in1ivar];
  }

  for (_in1ivar = 0ULL; _in1ivar < 5ULL; _in1ivar++) {
    t19[_in1ivar + 18ULL] = t34[_in1ivar];
  }

  for (_in1ivar = 0ULL; _in1ivar < 6ULL; _in1ivar++) {
    t19[_in1ivar + 23ULL] = t35[_in1ivar];
  }

  for (_in1ivar = 0ULL; _in1ivar < 6ULL; _in1ivar++) {
    t19[_in1ivar + 29ULL] = t36[_in1ivar];
  }

  for (_in1ivar = 0ULL; _in1ivar < 6ULL; _in1ivar++) {
    t19[_in1ivar + 35ULL] = t37[_in1ivar];
  }

  for (_in1ivar = 0ULL; _in1ivar < 4ULL; _in1ivar++) {
    t19[_in1ivar + 41ULL] = t38[_in1ivar];
  }

  out.mX[0] = t19[0];
  out.mX[1] = t19[1];
  out.mX[2] = t19[2];
  out.mX[3] = t19[3];
  out.mX[4] = t19[4];
  out.mX[5] = t19[5];
  out.mX[6] = t19[6];
  out.mX[7] = t19[7];
  out.mX[8] = t19[8];
  out.mX[9] = t19[9];
  out.mX[10] = t19[10];
  out.mX[11] = t19[11];
  out.mX[12] = t19[12];
  out.mX[13] = t19[13];
  out.mX[14] = t19[14];
  out.mX[15] = t19[15];
  out.mX[16] = t19[16];
  out.mX[17] = t19[17];
  out.mX[18] = t19[18];
  out.mX[19] = t19[19];
  out.mX[20] = t19[20];
  out.mX[21] = t19[21];
  out.mX[22] = t19[22];
  out.mX[23] = t19[23];
  out.mX[24] = t19[24];
  out.mX[25] = t19[25];
  out.mX[26] = t19[26];
  out.mX[27] = t19[27];
  out.mX[28] = t19[28];
  out.mX[29] = t19[29];
  out.mX[30] = t19[30];
  out.mX[31] = t19[31];
  out.mX[32] = t19[32];
  out.mX[33] = t19[33];
  out.mX[34] = t19[34];
  out.mX[35] = t19[35];
  out.mX[36] = t19[36];
  out.mX[37] = t19[37];
  out.mX[38] = t19[38];
  out.mX[39] = t19[39];
  out.mX[40] = t19[40];
  out.mX[41] = t19[41];
  out.mX[42] = t19[42];
  out.mX[43] = t19[43];
  out.mX[44] = t19[44];
  out.mX[45] = -((d_efOut[0] + -f_efOut[0]) * 7.0);
  out.mX[46] = -1.0;
  out.mX[47] = 1.0;
  out.mX[48] = -((d_efOut[0] + -b_efOut[0]) * 7.0);
  out.mX[49] = -1.0;
  out.mX[50] = 1.0;
  out.mX[51] = 1.0;
  out.mX[52] = 1.0;
  out.mX[53] = -1.0;
  out.mX[54] = 1.0;
  out.mX[55] = 1.0;
  out.mX[56] = 1.0;
  out.mX[57] = -1.0;
  out.mX[58] = 1.0;
  out.mX[59] = 1.0;
  out.mX[60] = 1.0;
  out.mX[61] = -1.0;
  out.mX[62] = 1.0;
  out.mX[63] = 1.0;
  out.mX[64] = 1.0;
  out.mX[65] = 1.0;
  out.mX[66] = 1.0;
  out.mX[67] = 1.0;
  out.mX[68] = 1.0;
  (void)t0;
  (void)t221;
  return 0;
}
