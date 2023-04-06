/*
 * reshapeSizeChecks.h
 *
 * Code generation for function 'reshapeSizeChecks'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "f_doNChem_types.h"

/* Function Declarations */
int32_T b_computeDimsData(const emlrtStack *sp, int32_T nx, real_T varargin_1);
void c_computeDimsData(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2, real_T varargin_3);
void computeDimsData(const emlrtStack *sp, real_T varargin_2, real_T varargin_3);

/* End of code generation (reshapeSizeChecks.h) */
