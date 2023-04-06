/*
 * f_fitAbsoluteHeat_terminate.c
 *
 * Code generation for function 'f_fitAbsoluteHeat_terminate'
 *
 */

/* Include files */
#include "f_fitAbsoluteHeat_terminate.h"
#include "_coder_f_fitAbsoluteHeat_mex.h"
#include "f_fitAbsoluteHeat.h"
#include "f_fitAbsoluteHeat_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void f_fitAbsoluteHeat_atexit(void)
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

void f_fitAbsoluteHeat_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (f_fitAbsoluteHeat_terminate.c) */
