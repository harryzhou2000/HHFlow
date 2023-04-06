/*
 * _coder_f_doNChem_mex.c
 *
 * Code generation for function '_coder_f_doNChem_mex'
 *
 */

/* Include files */
#include "_coder_f_doNChem_mex.h"
#include "_coder_f_doNChem_api.h"
#include "f_doNChem.h"
#include "f_doNChem_data.h"
#include "f_doNChem_initialize.h"
#include "f_doNChem_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void f_doNChem_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */
void f_doNChem_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[7])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4, 9,
                        "f_doNChem");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "f_doNChem");
  }

  /* Call the function. */
  f_doNChem_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&f_doNChem_atexit);

  /* Module initialization. */
  f_doNChem_initialize();

  /* Dispatch the entry-point. */
  f_doNChem_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  f_doNChem_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_f_doNChem_mex.c) */
