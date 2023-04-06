/*
 * bLUSGS_naive_terminate.c
 *
 * Code generation for function 'bLUSGS_naive_terminate'
 *
 */

/* Include files */
#include "bLUSGS_naive_terminate.h"
#include "_coder_bLUSGS_naive_mex.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void bLUSGS_naive_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void bLUSGS_naive_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (bLUSGS_naive_terminate.c) */
