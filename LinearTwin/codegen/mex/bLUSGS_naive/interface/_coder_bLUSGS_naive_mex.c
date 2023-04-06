/*
 * _coder_bLUSGS_naive_mex.c
 *
 * Code generation for function '_coder_bLUSGS_naive_mex'
 *
 */

/* Include files */
#include "_coder_bLUSGS_naive_mex.h"
#include "_coder_bLUSGS_naive_api.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_initialize.h"
#include "bLUSGS_naive_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void bLUSGS_naive_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
void bLUSGS_naive_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        12, "bLUSGS_naive");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "bLUSGS_naive");
  }

  /* Call the function. */
  bLUSGS_naive_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&bLUSGS_naive_atexit);

  /* Module initialization. */
  bLUSGS_naive_initialize();

  /* Dispatch the entry-point. */
  bLUSGS_naive_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  bLUSGS_naive_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_bLUSGS_naive_mex.c) */
