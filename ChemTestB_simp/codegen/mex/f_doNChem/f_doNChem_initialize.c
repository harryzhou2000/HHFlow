/*
 * f_doNChem_initialize.c
 *
 * Code generation for function 'f_doNChem_initialize'
 *
 */

/* Include files */
#include "f_doNChem_initialize.h"
#include "_coder_f_doNChem_mex.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void f_doNChem_initialize(void)
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

/* End of code generation (f_doNChem_initialize.c) */
