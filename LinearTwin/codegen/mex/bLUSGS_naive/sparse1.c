/*
 * sparse1.c
 *
 * Code generation for function 'sparse1'
 *
 */

/* Include files */
#include "sparse1.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = { 13,  /* lineNo */
  "sparse",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 68,  /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 67,  /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 52,  /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 51,  /* lineNo */
  "sparse/sparse",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "sparse",                            /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pName */
};

/* Function Definitions */
void sparse(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
            emxArray_boolean_T *y_d, emxArray_int32_T *y_colidx,
            emxArray_int32_T *y_rowidx, int32_T *y_m, int32_T *y_n, int32_T
            *y_maxnz)
{
  int32_T mInt;
  int32_T nInt;
  int32_T i;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &i_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mInt = varargin_1->size[0];
  nInt = varargin_1->size[1];
  b_st.site = &m_emlrtRSI;
  if (varargin_1->size[0] >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  b_st.site = &l_emlrtRSI;
  if (varargin_1->size[1] >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:toolbox:SparseMaxSize", "Coder:toolbox:SparseMaxSize", 2, 12,
      MAX_int32_T);
  }

  *y_m = varargin_1->size[0];
  *y_n = varargin_1->size[1];
  i = y_d->size[0];
  y_d->size[0] = 1;
  emxEnsureCapacity_boolean_T(&st, y_d, i, &mb_emlrtRTEI);
  y_d->data[0] = false;
  i = y_colidx->size[0];
  y_colidx->size[0] = varargin_1->size[1] + 1;
  emxEnsureCapacity_int32_T(&st, y_colidx, i, &mb_emlrtRTEI);
  loop_ub = varargin_1->size[1];
  for (i = 0; i <= loop_ub; i++) {
    y_colidx->data[i] = 0;
  }

  y_colidx->data[0] = 1;
  i = y_rowidx->size[0];
  y_rowidx->size[0] = 1;
  emxEnsureCapacity_int32_T(&st, y_rowidx, i, &mb_emlrtRTEI);
  y_rowidx->data[0] = 1;
  b_st.site = &k_emlrtRSI;
  for (loop_ub = 0; loop_ub < nInt; loop_ub++) {
    b_st.site = &j_emlrtRSI;
    if ((1 <= mInt) && (mInt > 2147483646)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    y_colidx->data[loop_ub + 1] = 1;
  }

  *y_maxnz = 1;
}

/* End of code generation (sparse1.c) */
