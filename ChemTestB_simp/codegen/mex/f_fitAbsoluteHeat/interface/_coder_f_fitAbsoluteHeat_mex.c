/*
 * _coder_f_fitAbsoluteHeat_mex.c
 *
 * Code generation for function '_coder_f_fitAbsoluteHeat_mex'
 *
 */

/* Include files */
#include "_coder_f_fitAbsoluteHeat_mex.h"
#include "_coder_f_fitAbsoluteHeat_api.h"
#include "f_fitAbsoluteHeat.h"
#include "f_fitAbsoluteHeat_data.h"
#include "f_fitAbsoluteHeat_initialize.h"
#include "f_fitAbsoluteHeat_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void f_fitAbsoluteHeat_mexFunction(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
void f_fitAbsoluteHeat_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
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
                        17, "f_fitAbsoluteHeat");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "f_fitAbsoluteHeat");
  }

  /* Call the function. */
  f_fitAbsoluteHeat_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&f_fitAbsoluteHeat_atexit);

  /* Module initialization. */
  f_fitAbsoluteHeat_initialize();

  /* Dispatch the entry-point. */
  f_fitAbsoluteHeat_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  f_fitAbsoluteHeat_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_f_fitAbsoluteHeat_mex.c) */
