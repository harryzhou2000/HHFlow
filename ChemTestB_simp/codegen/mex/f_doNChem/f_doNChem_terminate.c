/*
 * f_doNChem_terminate.c
 *
 * Code generation for function 'f_doNChem_terminate'
 *
 */

/* Include files */
#include "f_doNChem_terminate.h"
#include "_coder_f_doNChem_mex.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void f_doNChem_atexit(void)
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

void f_doNChem_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (f_doNChem_terminate.c) */
