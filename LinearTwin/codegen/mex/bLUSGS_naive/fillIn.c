/*
 * fillIn.c
 *
 * Code generation for function 'fillIn'
 *
 */

/* Include files */
#include "fillIn.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 14, /* lineNo */
  "sparse/fillIn",                     /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\fillIn.m"/* pathName */
};

/* Function Definitions */
void sparse_fillIn(const emlrtStack *sp, coder_internal_sparse *this)
{
  int32_T b;
  int32_T c;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = this->colidx->size[0];
  st.site = &ub_emlrtRSI;
  if ((1 <= this->colidx->size[0] - 1) && (this->colidx->size[0] - 1 >
       2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (c = 0; c <= b - 2; c++) {
    this->colidx->data[c] = 1;
  }

  this->colidx->data[this->colidx->size[0] - 1] = 1;
}

/* End of code generation (fillIn.c) */
