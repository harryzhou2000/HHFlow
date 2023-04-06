/*
 * useConstantDim.c
 *
 * Code generation for function 'useConstantDim'
 *
 */

/* Include files */
#include "useConstantDim.h"
#include "eml_int_forloop_overflow_check.h"
#include "f_fitAbsoluteHeat.h"
#include "f_fitAbsoluteHeat_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 32,  /* lineNo */
  "useConstantDim",                    /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 99,  /* lineNo */
  "ndlooper",                          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 167, /* lineNo */
  "looper",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 168,/* lineNo */
  "looper",                            /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

/* Function Definitions */
void useConstantDim(const emlrtStack *sp, emxArray_real_T *varargin_2)
{
  int32_T b;
  int32_T k;
  int32_T b_b;
  int32_T subsb_idx_1;
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &x_emlrtRSI;
  if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
    b = varargin_2->size[1];
    c_st.site = &y_emlrtRSI;
    if ((1 <= varargin_2->size[1]) && (varargin_2->size[1] > 2147483646)) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < b; k++) {
      c_st.site = &ab_emlrtRSI;
      b_b = varargin_2->size[0];
      if (0 <= b_b - 2) {
        subsb_idx_1 = k + 1;
      }

      for (b_k = 0; b_k <= b_b - 2; b_k++) {
        varargin_2->data[(b_k + varargin_2->size[0] * (subsb_idx_1 - 1)) + 1] *=
          varargin_2->data[b_k + varargin_2->size[0] * k];
      }
    }
  }
}

/* End of code generation (useConstantDim.c) */
