/*
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 35, /* lineNo */
  "sparse/mtimes",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 216,/* lineNo */
  "sfmtimes",                          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 232,/* lineNo */
  "sfmtimes_vector",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 241,/* lineNo */
  "sfmtimes_vector",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 252,/* lineNo */
  "sfmtimes_vector",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 258,/* lineNo */
  "sfmtimes_vector",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pathName */
};

static emlrtRTEInfo q_emlrtRTEI = { 29,/* lineNo */
  23,                                  /* colNo */
  "sparse/mtimes",                     /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 35,/* lineNo */
  9,                                   /* colNo */
  "mtimes",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\mtimes.m"/* pName */
};

/* Function Definitions */
void sparse_mtimes(const emlrtStack *sp, const emxArray_real_T *a_d, const
                   emxArray_int32_T *a_colidx, const emxArray_int32_T *a_rowidx,
                   int32_T a_m, int32_T a_n, const emxArray_real_T *b,
                   emxArray_real_T *c)
{
  int32_T nap;
  int32_T acol;
  real_T bc;
  int32_T a;
  int32_T apend1;
  boolean_T overflow;
  int32_T ap;
  int32_T c_tmp;
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
  if (a_n != b->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &q_emlrtRTEI, "MATLAB:innerdim",
      "MATLAB:innerdim", 0);
  }

  st.site = &jc_emlrtRSI;
  nap = c->size[0];
  c->size[0] = a_m;
  emxEnsureCapacity_real_T(&st, c, nap, &wb_emlrtRTEI);
  for (nap = 0; nap < a_m; nap++) {
    c->data[nap] = 0.0;
  }

  if ((a_n != 0) && (a_m != 0) && (a_colidx->data[a_colidx->size[0] - 1] - 1 !=
       0)) {
    b_st.site = &kc_emlrtRSI;
    c_st.site = &lc_emlrtRSI;
    if (a_n > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (acol = 0; acol < a_n; acol++) {
      bc = b->data[acol];
      a = a_colidx->data[acol];
      apend1 = a_colidx->data[acol + 1];
      nap = apend1 - a_colidx->data[acol];
      if (nap >= 4) {
        apend1 = ((apend1 - nap) + ((nap / 4) << 2)) - 1;
        c_st.site = &mc_emlrtRSI;
        overflow = ((a_colidx->data[acol] <= apend1) && (apend1 > 2147483643));
        if (overflow) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (ap = a; ap <= apend1; ap += 4) {
          c_tmp = a_rowidx->data[ap - 1] - 1;
          c->data[c_tmp] += a_d->data[ap - 1] * bc;
          c->data[a_rowidx->data[ap] - 1] += a_d->data[ap] * bc;
          c_tmp = a_rowidx->data[ap + 1] - 1;
          c->data[c_tmp] += a_d->data[ap + 1] * bc;
          c_tmp = a_rowidx->data[ap + 2] - 1;
          c->data[c_tmp] += a_d->data[ap + 2] * bc;
        }

        nap = a_colidx->data[acol + 1] - 1;
        a = apend1 + 1;
        c_st.site = &nc_emlrtRSI;
        overflow = ((apend1 + 1 <= nap) && (nap > 2147483646));
        if (overflow) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (ap = a; ap <= nap; ap++) {
          c_tmp = a_rowidx->data[ap - 1] - 1;
          c->data[c_tmp] += a_d->data[ap - 1] * bc;
        }
      } else {
        apend1--;
        c_st.site = &oc_emlrtRSI;
        overflow = ((a_colidx->data[acol] <= apend1) && (apend1 > 2147483646));
        if (overflow) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (ap = a; ap <= apend1; ap++) {
          c_tmp = a_rowidx->data[ap - 1] - 1;
          c->data[c_tmp] += a_d->data[ap - 1] * bc;
        }
      }
    }
  }
}

/* End of code generation (mtimes.c) */
