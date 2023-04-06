/*
 * reshapeSizeChecks.c
 *
 * Code generation for function 'reshapeSizeChecks'
 *
 */

/* Include files */
#include "reshapeSizeChecks.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jb_emlrtRSI = { 109,/* lineNo */
  "computeDimsData",                   /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = { 116,/* lineNo */
  9,                                   /* colNo */
  "computeDimsData",                   /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"/* pName */
};

static emlrtRSInfo qb_emlrtRSI = { 18, /* lineNo */
  "indexDivide",                       /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\eml\\eml\\+coder\\+internal\\indexDivide.m"/* pathName */
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T b_numerator;
  uint32_T b_denominator;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      b_numerator = ~(uint32_T)numerator + 1U;
    } else {
      b_numerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      b_denominator = ~(uint32_T)denominator + 1U;
    } else {
      b_denominator = (uint32_T)denominator;
    }

    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)b_numerator;
    } else {
      quotient = (int32_T)b_numerator;
    }
  }

  return quotient;
}

int32_T b_computeDimsData(const emlrtStack *sp, int32_T nx, real_T varargin_1)
{
  int32_T calclen;
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  i = (int32_T)varargin_1;
  if (i > 0) {
    st.site = &qb_emlrtRSI;
    calclen = div_s32(&st, nx, i);
    if (calclen > nx) {
      emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }
  } else {
    calclen = 0;
  }

  return calclen;
}

void c_computeDimsData(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2, real_T varargin_3)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  st.site = &jb_emlrtRSI;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  st.site = &jb_emlrtRSI;
  if (varargin_3 != varargin_3) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }
}

void computeDimsData(const emlrtStack *sp, real_T varargin_2, real_T varargin_3)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  st.site = &jb_emlrtRSI;
  if (varargin_3 != varargin_3) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }
}

/* End of code generation (reshapeSizeChecks.c) */
