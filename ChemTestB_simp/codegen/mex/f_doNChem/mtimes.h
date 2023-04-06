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
#include "f_doNChem_types.h"

/* Function Declarations */
void b_mtimes(const emlrtStack *sp, const emxArray_real_T *A, const
              emxArray_real_T *B, emxArray_real_T *C);
void mtimes(const emlrtStack *sp, const emxArray_real_T *A, const
            emxArray_real_T *B, emxArray_real_T *C);

/* End of code generation (mtimes.h) */
