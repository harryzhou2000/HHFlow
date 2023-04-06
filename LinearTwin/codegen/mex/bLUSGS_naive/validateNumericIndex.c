/*
 * validateNumericIndex.c
 *
 * Code generation for function 'validateNumericIndex'
 *
 */

/* Include files */
#include "validateNumericIndex.h"
#include "bLUSGS_naive.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo h_emlrtRTEI = { 11,/* lineNo */
  27,                                  /* colNo */
  "sparse_validateNumericIndex",       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\private\\validateNumericIndex.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 12,/* lineNo */
  27,                                  /* colNo */
  "sparse_validateNumericIndex",       /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\private\\validateNumericIndex.m"/* pName */
};

/* Function Definitions */
void sparse_validateNumericIndex(const emlrtStack *sp, int32_T upperBound, const
  emxArray_real_T *idx)
{
  int32_T i;
  int32_T k;
  real_T d;
  i = idx->size[1];
  for (k = 0; k < i; k++) {
    d = idx->data[k];
    if ((!(muDoubleScalarFloor(d) == d)) || muDoubleScalarIsInf(d) || (!(d > 0.0)))
    {
      emlrtErrorWithMessageIdR2018a(sp, &h_emlrtRTEI,
        "Coder:MATLAB:badsubscript", "Coder:MATLAB:badsubscript", 0);
    }

    if (!(d <= upperBound)) {
      emlrtErrorWithMessageIdR2018a(sp, &i_emlrtRTEI,
        "Coder:builtins:IndexOutOfBounds", "Coder:builtins:IndexOutOfBounds", 6,
        6, d, 12, 1, 12, upperBound);
    }
  }
}

/* End of code generation (validateNumericIndex.c) */
