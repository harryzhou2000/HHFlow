/*
 * bLUSGS_naive.h
 *
 * Code generation for function 'bLUSGS_naive'
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
void bLUSGS_naive(const emlrtStack *sp, const coder_internal_sparse A, const
                  emxArray_real_T *b, real_T bsize, emxArray_real_T *x);

/* End of code generation (bLUSGS_naive.h) */
