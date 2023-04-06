/*
 * bLUSGS_naive.c
 *
 * Code generation for function 'bLUSGS_naive'
 *
 */

/* Include files */
#include "bLUSGS_naive.h"
#include "assertValidSizeArg.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "not.h"
#include "parenAssign2D.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "tril.h"
#include "triu.h"
#include "validateNumericIndex.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8,     /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 10,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 13,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 14,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 15,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 20,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 21,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 23,  /* lineNo */
  "bLUSGS_naive",                      /* fcnName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 28,  /* lineNo */
  "colon",                             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 103, /* lineNo */
  "colon",                             /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 288, /* lineNo */
  "eml_float_colon",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 266, /* lineNo */
  "sparse/parenAssign",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 66,  /* lineNo */
  "sparse/parenAssign2D",              /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 77,  /* lineNo */
  "parenAssign2DNumeric",              /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 78,  /* lineNo */
  "parenAssign2DNumeric",              /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 81,  /* lineNo */
  "parenAssign2DNumeric",              /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 18, /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 405, /* lineNo */
  15,                                  /* colNo */
  "assert_pmaxsize",                   /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 59,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  21,                                  /* lineNo */
  12,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  20,                                  /* lineNo */
  12,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 9, /* lineNo */
  14,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 5, /* lineNo */
  1,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 8, /* lineNo */
  20,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 577,/* lineNo */
  13,                                  /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 6,/* lineNo */
  5,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 103,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 1,/* lineNo */
  10,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 20,/* lineNo */
  12,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 10,/* lineNo */
  16,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 10,/* lineNo */
  38,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "bLUSGS_naive",                      /* fName */
  "E:\\projects\\HHFlow\\LinearTwin\\bLUSGS_naive.m"/* pName */
};

/* Function Definitions */
void bLUSGS_naive(const emlrtStack *sp, const coder_internal_sparse A, const
                  emxArray_real_T *b, real_T bsize, emxArray_real_T *x)
{
  real_T size_vec[2];
  real_T r;
  boolean_T rEQ0;
  emxArray_boolean_T *b_r;
  real_T q;
  int32_T i;
  int32_T nm1d2;
  coder_internal_sparse_1 maskAdiag;
  emxArray_real_T *y;
  emxArray_real_T *b_y;
  int32_T istart;
  emxArray_real_T *D_d;
  emxArray_int32_T *D_colidx;
  emxArray_int32_T *D_rowidx;
  emxArray_real_T *L_d;
  int32_T y_tmp;
  emxArray_int32_T *L_colidx;
  emxArray_int32_T *L_rowidx;
  emxArray_real_T *U_d;
  emxArray_int32_T *U_colidx;
  real_T ndbl;
  emxArray_int32_T *U_rowidx;
  real_T apnd;
  emxArray_real_T *this_d;
  real_T cdiff;
  emxArray_int32_T *this_colidx;
  emxArray_int32_T *this_rowidx;
  emxArray_boolean_T *t0_d;
  emxArray_int32_T *t0_colidx;
  emxArray_int32_T *t0_rowidx;
  int32_T D_m;
  int32_T D_n;
  int32_T n;
  int32_T this_m;
  int32_T this_n;
  int32_T L_m;
  int32_T L_n;
  int32_T k;
  emxArray_real_T *b_x;
  emxArray_real_T *r1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  size_vec[0] = b->size[0];
  size_vec[1] = 1.0;
  r = b->size[0];
  if (bsize == 0.0) {
    if (b->size[0] == 0) {
      r = bsize;
    }
  } else if (muDoubleScalarIsNaN(bsize)) {
    r = rtNaN;
  } else if (b->size[0] == 0) {
    r = 0.0 / bsize;
  } else if (muDoubleScalarIsInf(bsize)) {
    if (bsize < 0.0) {
      r = bsize;
    }
  } else {
    r = muDoubleScalarRem(b->size[0], bsize);
    rEQ0 = (r == 0.0);
    if ((!rEQ0) && (bsize > muDoubleScalarFloor(bsize))) {
      q = muDoubleScalarAbs((real_T)b->size[0] / bsize);
      rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
               2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = bsize * 0.0;
    } else {
      if (bsize < 0.0) {
        r += bsize;
      }
    }
  }

  if (!(r == 0.0)) {
    emlrtErrorWithMessageIdR2018a(sp, &e_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  emxInit_boolean_T(sp, &b_r, 2, &w_emlrtRTEI, true);
  i = b_r->size[0] * b_r->size[1];
  b_r->size[0] = b->size[0];
  b_r->size[1] = b->size[0];
  emxEnsureCapacity_boolean_T(sp, b_r, i, &w_emlrtRTEI);
  nm1d2 = b->size[0] * b->size[0];
  for (i = 0; i < nm1d2; i++) {
    b_r->data[i] = false;
  }

  c_emxInitStruct_coder_internal_(sp, &maskAdiag, &db_emlrtRTEI, true);
  st.site = &emlrtRSI;
  sparse(&st, b_r, maskAdiag.d, maskAdiag.colidx, maskAdiag.rowidx, &maskAdiag.m,
         &maskAdiag.n, &maskAdiag.maxnz);
  i = (int32_T)(((real_T)b->size[0] + (bsize - 1.0)) / bsize);
  emlrtForLoopVectorCheckR2012b(1.0, bsize, b->size[0], mxDOUBLE_CLASS, i,
    &d_emlrtRTEI, sp);
  emxFree_boolean_T(&b_r);
  emxInit_real_T(sp, &y, 2, &jb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_y, 2, &kb_emlrtRTEI, true);
  for (istart = 0; istart < i; istart++) {
    r = (real_T)istart * bsize + 1.0;
    st.site = &b_emlrtRSI;
    q = (r + bsize) - 1.0;
    b_st.site = &p_emlrtRSI;
    if (muDoubleScalarIsNaN(r) || muDoubleScalarIsNaN(q)) {
      y_tmp = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, y, y_tmp, &y_emlrtRTEI);
      y->data[0] = rtNaN;
    } else if (q < r) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else if ((muDoubleScalarIsInf(r) || muDoubleScalarIsInf(q)) && (r == q)) {
      y_tmp = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, y, y_tmp, &y_emlrtRTEI);
      y->data[0] = rtNaN;
    } else if (muDoubleScalarFloor(r) == r) {
      y_tmp = y->size[0] * y->size[1];
      y->size[0] = 1;
      nm1d2 = (int32_T)muDoubleScalarFloor(q - r);
      y->size[1] = nm1d2 + 1;
      emxEnsureCapacity_real_T(&b_st, y, y_tmp, &y_emlrtRTEI);
      for (y_tmp = 0; y_tmp <= nm1d2; y_tmp++) {
        y->data[y_tmp] = r + (real_T)y_tmp;
      }
    } else {
      c_st.site = &q_emlrtRSI;
      ndbl = muDoubleScalarFloor((q - r) + 0.5);
      apnd = r + ndbl;
      cdiff = apnd - q;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
          (muDoubleScalarAbs(r), muDoubleScalarAbs(q))) {
        ndbl++;
        apnd = q;
      } else if (cdiff > 0.0) {
        apnd = r + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }

      d_st.site = &r_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI, "Coder:MATLAB:pmaxsize",
          "Coder:MATLAB:pmaxsize", 0);
      }

      y_tmp = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = n;
      emxEnsureCapacity_real_T(&c_st, y, y_tmp, &bb_emlrtRTEI);
      if (n > 0) {
        y->data[0] = r;
        if (n > 1) {
          y->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (k = 0; k <= nm1d2 - 2; k++) {
            y_tmp = k + 1;
            y->data[k + 1] = r + (real_T)y_tmp;
            y->data[(n - k) - 2] = apnd - (real_T)y_tmp;
          }

          if (nm1d2 << 1 == n - 1) {
            y->data[nm1d2] = (r + apnd) / 2.0;
          } else {
            y->data[nm1d2] = r + (real_T)nm1d2;
            y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
          }
        }
      }
    }

    st.site = &b_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    if (muDoubleScalarIsNaN(r) || muDoubleScalarIsNaN(q)) {
      y_tmp = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, b_y, y_tmp, &y_emlrtRTEI);
      b_y->data[0] = rtNaN;
    } else if (q < r) {
      b_y->size[0] = 1;
      b_y->size[1] = 0;
    } else if ((muDoubleScalarIsInf(r) || muDoubleScalarIsInf(q)) && (r == q)) {
      y_tmp = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, b_y, y_tmp, &y_emlrtRTEI);
      b_y->data[0] = rtNaN;
    } else if (muDoubleScalarFloor(r) == r) {
      y_tmp = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      nm1d2 = (int32_T)muDoubleScalarFloor(q - r);
      b_y->size[1] = nm1d2 + 1;
      emxEnsureCapacity_real_T(&b_st, b_y, y_tmp, &y_emlrtRTEI);
      for (y_tmp = 0; y_tmp <= nm1d2; y_tmp++) {
        b_y->data[y_tmp] = r + (real_T)y_tmp;
      }
    } else {
      c_st.site = &q_emlrtRSI;
      ndbl = muDoubleScalarFloor((q - r) + 0.5);
      apnd = r + ndbl;
      cdiff = apnd - q;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
          (muDoubleScalarAbs(r), muDoubleScalarAbs(q))) {
        ndbl++;
        apnd = q;
      } else if (cdiff > 0.0) {
        apnd = r + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int32_T)ndbl;
      } else {
        n = 0;
      }

      d_st.site = &r_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI, "Coder:MATLAB:pmaxsize",
          "Coder:MATLAB:pmaxsize", 0);
      }

      y_tmp = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      b_y->size[1] = n;
      emxEnsureCapacity_real_T(&c_st, b_y, y_tmp, &bb_emlrtRTEI);
      if (n > 0) {
        b_y->data[0] = r;
        if (n > 1) {
          b_y->data[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (k = 0; k <= nm1d2 - 2; k++) {
            y_tmp = k + 1;
            b_y->data[k + 1] = r + (real_T)y_tmp;
            b_y->data[(n - k) - 2] = apnd - (real_T)y_tmp;
          }

          if (nm1d2 << 1 == n - 1) {
            b_y->data[nm1d2] = (r + apnd) / 2.0;
          } else {
            b_y->data[nm1d2] = r + (real_T)nm1d2;
            b_y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
          }
        }
      }
    }

    st.site = &b_emlrtRSI;
    b_st.site = &t_emlrtRSI;
    c_st.site = &u_emlrtRSI;
    d_st.site = &v_emlrtRSI;
    sparse_validateNumericIndex(&d_st, maskAdiag.m, y);
    d_st.site = &w_emlrtRSI;
    sparse_validateNumericIndex(&d_st, maskAdiag.n, b_y);
    d_st.site = &x_emlrtRSI;
    parenAssign2DNumericImpl(&d_st, &maskAdiag, y, b_y, y->size[1], b_y->size[1]);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  emxInit_real_T(sp, &D_d, 1, &eb_emlrtRTEI, true);
  emxInit_int32_T(sp, &D_colidx, 1, &eb_emlrtRTEI, true);
  emxInit_int32_T(sp, &D_rowidx, 1, &eb_emlrtRTEI, true);
  emxInit_real_T(sp, &L_d, 1, &fb_emlrtRTEI, true);
  emxInit_int32_T(sp, &L_colidx, 1, &fb_emlrtRTEI, true);
  emxInit_int32_T(sp, &L_rowidx, 1, &fb_emlrtRTEI, true);
  emxInit_real_T(sp, &U_d, 1, &gb_emlrtRTEI, true);
  emxInit_int32_T(sp, &U_colidx, 1, &gb_emlrtRTEI, true);
  emxInit_int32_T(sp, &U_rowidx, 1, &gb_emlrtRTEI, true);
  emxInit_real_T(sp, &this_d, 1, &ib_emlrtRTEI, true);
  emxInit_int32_T(sp, &this_colidx, 1, &ib_emlrtRTEI, true);
  emxInit_int32_T(sp, &this_rowidx, 1, &ib_emlrtRTEI, true);
  emxInit_boolean_T(sp, &t0_d, 1, &lb_emlrtRTEI, true);
  emxInit_int32_T(sp, &t0_colidx, 1, &lb_emlrtRTEI, true);
  emxInit_int32_T(sp, &t0_rowidx, 1, &lb_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  sparse_times(&st, A.d, A.colidx, A.rowidx, A.m, A.n, maskAdiag.d,
               maskAdiag.colidx, maskAdiag.rowidx, maskAdiag.m, maskAdiag.n, D_d,
               D_colidx, D_rowidx, &D_m, &D_n);
  st.site = &d_emlrtRSI;
  sparse_tril(&st, A.d, A.colidx, A.rowidx, A.m, A.n, this_d, this_colidx,
              this_rowidx, &this_m, &this_n);
  st.site = &d_emlrtRSI;
  sparse_not(&st, maskAdiag.colidx, maskAdiag.rowidx, maskAdiag.m, maskAdiag.n,
             t0_d, t0_colidx, t0_rowidx, &y_tmp, &n, &nm1d2);
  st.site = &d_emlrtRSI;
  sparse_times(&st, this_d, this_colidx, this_rowidx, this_m, this_n, t0_d,
               t0_colidx, t0_rowidx, y_tmp, n, L_d, L_colidx, L_rowidx, &L_m,
               &L_n);
  st.site = &e_emlrtRSI;
  sparse_triu(&st, A.d, A.colidx, A.rowidx, A.m, A.n, this_d, this_colidx,
              this_rowidx, &this_m, &this_n);
  st.site = &e_emlrtRSI;
  sparse_not(&st, maskAdiag.colidx, maskAdiag.rowidx, maskAdiag.m, maskAdiag.n,
             t0_d, t0_colidx, t0_rowidx, &y_tmp, &n, &nm1d2);
  st.site = &e_emlrtRSI;
  sparse_times(&st, this_d, this_colidx, this_rowidx, this_m, this_n, t0_d,
               t0_colidx, t0_rowidx, y_tmp, n, U_d, U_colidx, U_rowidx, &k,
               &istart);
  i = this_d->size[0];
  this_d->size[0] = U_d->size[0];
  emxEnsureCapacity_real_T(sp, this_d, i, &x_emlrtRTEI);
  nm1d2 = U_d->size[0];
  emxFree_int32_T(&t0_rowidx);
  emxFree_int32_T(&t0_colidx);
  emxFree_boolean_T(&t0_d);
  c_emxFreeStruct_coder_internal_(&maskAdiag);
  for (i = 0; i < nm1d2; i++) {
    this_d->data[i] = -U_d->data[i];
  }

  emxInit_real_T(sp, &b_x, 1, &hb_emlrtRTEI, true);
  i = b_x->size[0];
  b_x->size[0] = b->size[0];
  emxEnsureCapacity_real_T(sp, b_x, i, &ab_emlrtRTEI);
  nm1d2 = b->size[0];
  for (i = 0; i < nm1d2; i++) {
    b_x->data[i] = 0.0;
  }

  emxInit_real_T(sp, &r1, 1, &ib_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  sparse_mtimes(&st, this_d, U_colidx, U_rowidx, k, istart, b_x, r1);
  if (r1->size[0] != b->size[0]) {
    emlrtSizeEqCheck1DR2012b(r1->size[0], b->size[0], &b_emlrtECI, sp);
  }

  st.site = &f_emlrtRSI;
  sparse_plus(&st, D_d, D_colidx, D_rowidx, D_m, D_n, L_d, L_colidx, L_rowidx,
              L_m, L_n, this_d, this_colidx, this_rowidx, &this_m, &this_n);
  nm1d2 = r1->size[0];
  for (i = 0; i < nm1d2; i++) {
    r1->data[i] += b->data[i];
  }

  st.site = &f_emlrtRSI;
  sparse_mldivide(&st, this_d, this_colidx, this_rowidx, this_m, this_n, r1, b_x);
  nm1d2 = L_d->size[0];
  for (i = 0; i < nm1d2; i++) {
    L_d->data[i] = -L_d->data[i];
  }

  st.site = &g_emlrtRSI;
  sparse_mtimes(&st, L_d, L_colidx, L_rowidx, L_m, L_n, b_x, r1);
  emxFree_int32_T(&L_rowidx);
  emxFree_int32_T(&L_colidx);
  emxFree_real_T(&L_d);
  if (r1->size[0] != b->size[0]) {
    emlrtSizeEqCheck1DR2012b(r1->size[0], b->size[0], &emlrtECI, sp);
  }

  st.site = &g_emlrtRSI;
  sparse_plus(&st, D_d, D_colidx, D_rowidx, D_m, D_n, U_d, U_colidx, U_rowidx, k,
              istart, this_d, this_colidx, this_rowidx, &this_m, &this_n);
  nm1d2 = r1->size[0];
  emxFree_int32_T(&U_rowidx);
  emxFree_int32_T(&U_colidx);
  emxFree_real_T(&U_d);
  emxFree_int32_T(&D_rowidx);
  emxFree_int32_T(&D_colidx);
  emxFree_real_T(&D_d);
  for (i = 0; i < nm1d2; i++) {
    r1->data[i] += b->data[i];
  }

  st.site = &g_emlrtRSI;
  sparse_mldivide(&st, this_d, this_colidx, this_rowidx, this_m, this_n, r1, b_x);
  st.site = &h_emlrtRSI;
  nm1d2 = b_x->size[0];
  b_st.site = &id_emlrtRSI;
  assertValidSizeArg(&b_st, size_vec);
  n = b_x->size[0];
  emxFree_int32_T(&this_rowidx);
  emxFree_int32_T(&this_colidx);
  emxFree_real_T(&this_d);
  emxFree_real_T(&r1);
  if (1 > b_x->size[0]) {
    n = 1;
  }

  if (b->size[0] > muIntScalarMax_sint32(nm1d2, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (b->size[0] != b_x->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  i = x->size[0] * x->size[1];
  x->size[0] = b->size[0];
  x->size[1] = 1;
  emxEnsureCapacity_real_T(sp, x, i, &cb_emlrtRTEI);
  nm1d2 = b->size[0];
  for (i = 0; i < nm1d2; i++) {
    x->data[i] = b_x->data[i];
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bLUSGS_naive.c) */
