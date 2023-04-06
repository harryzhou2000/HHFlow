/*
 * bLUSGS_naive_initialize.c
 *
 * Code generation for function 'bLUSGS_naive_initialize'
 *
 */

/* Include files */
#include "bLUSGS_naive_initialize.h"
#include "_coder_bLUSGS_naive_mex.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void bLUSGS_naive_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (bLUSGS_naive_initialize.c) */
