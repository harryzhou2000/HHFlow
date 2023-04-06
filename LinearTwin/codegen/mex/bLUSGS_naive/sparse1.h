/*
 * sparse1.h
 *
 * Code generation for function 'sparse1'
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
#include "bLUSGS_naive_types.h"

/* Function Declarations */
void sparse(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
            emxArray_boolean_T *y_d, emxArray_int32_T *y_colidx,
            emxArray_int32_T *y_rowidx, int32_T *y_m, int32_T *y_n, int32_T
            *y_maxnz);

/* End of code generation (sparse1.h) */
