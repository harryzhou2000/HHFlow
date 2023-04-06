/*
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void sparse_mtimes(const emlrtStack *sp, const emxArray_real_T *a_d, const
                   emxArray_int32_T *a_colidx, const emxArray_int32_T *a_rowidx,
                   int32_T a_m, int32_T a_n, const emxArray_real_T *b,
                   emxArray_real_T *c);

/* End of code generation (mtimes.h) */
