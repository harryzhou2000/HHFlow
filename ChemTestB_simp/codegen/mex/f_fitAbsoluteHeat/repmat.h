/*
 * repmat.h
 *
 * Code generation for function 'repmat'
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
#include "f_fitAbsoluteHeat_types.h"

/* Function Declarations */
void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_2,
              emxArray_real_T *b);
void c_repmat(const emlrtStack *sp, const emxArray_boolean_T *a, real_T
              varargin_1, emxArray_boolean_T *b);
void repmat(const emlrtStack *sp, const emxArray_real_T *a, real_T varargin_1,
            emxArray_real_T *b);

/* End of code generation (repmat.h) */
