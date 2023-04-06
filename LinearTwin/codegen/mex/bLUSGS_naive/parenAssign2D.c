/*
 * parenAssign2D.c
 *
 * Code generation for function 'parenAssign2D'
 *
 */

/* Include files */
#include "parenAssign2D.h"
#include "bLUSGS_naive.h"
#include "bLUSGS_naive_data.h"
#include "bLUSGS_naive_emxutil.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 119, /* lineNo */
  "parenAssign2DNumericImpl",          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 115,/* lineNo */
  "parenAssign2DNumericImpl",          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 110,/* lineNo */
  "parenAssign2DNumericImpl",          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 89, /* lineNo */
  "parenAssign2DNumericImpl",          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 87, /* lineNo */
  "parenAssign2DNumericImpl",          /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 329,/* lineNo */
  "realloc",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 337,/* lineNo */
  "realloc",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 342,/* lineNo */
  "realloc",                           /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 245,/* lineNo */
  "shiftRowidxAndData",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 246,/* lineNo */
  "shiftRowidxAndData",                /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 264,/* lineNo */
  "incrColIdx",                        /* fcnName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pathName */
};

static emlrtRTEInfo v_emlrtRTEI = { 239,/* lineNo */
  13,                                  /* colNo */
  "sparse/numel",                      /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 325,/* lineNo */
  1,                                   /* colNo */
  "parenAssign2D",                     /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 326,/* lineNo */
  1,                                   /* colNo */
  "parenAssign2D",                     /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "parenAssign2D",                     /* fName */
  "E:\\Program Files\\Polyspace\\R2020a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\parenAssign2D.m"/* pName */
};

/* Function Definitions */
void parenAssign2DNumericImpl(const emlrtStack *sp, coder_internal_sparse_1
  *this, const emxArray_real_T *r, const emxArray_real_T *c, int32_T sm, int32_T
  sn)
{
  emxArray_int32_T *rowidxt;
  emxArray_boolean_T *dt;
  int32_T cidx;
  real_T d;
  int32_T ridx;
  real_T nt;
  int32_T i;
  int32_T mid_i;
  int32_T low_i;
  int32_T n;
  boolean_T thisv;
  int32_T high_i;
  int32_T low_ip1;
  int32_T idx;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &db_emlrtRSI;
  if ((1 <= sn) && (sn > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  emxInit_int32_T(sp, &rowidxt, 1, &gc_emlrtRTEI, true);
  emxInit_boolean_T(sp, &dt, 1, &hc_emlrtRTEI, true);
  for (cidx = 0; cidx < sn; cidx++) {
    d = c->data[cidx];
    st.site = &cb_emlrtRSI;
    if ((1 <= sm) && (sm > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ridx = 0; ridx < sm; ridx++) {
      nt = r->data[ridx];
      i = (int32_T)d;
      mid_i = i - 1;
      if (this->colidx->data[mid_i] < this->colidx->data[i]) {
        low_i = this->colidx->data[mid_i] - 1;
        n = (int32_T)nt;
        if (n < this->rowidx->data[low_i]) {
          thisv = false;
        } else {
          high_i = this->colidx->data[i];
          low_i = this->colidx->data[mid_i];
          low_ip1 = this->colidx->data[mid_i];
          while (high_i > low_ip1 + 1) {
            mid_i = (low_i >> 1) + (high_i >> 1);
            if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
              mid_i++;
            }

            if (n >= this->rowidx->data[mid_i - 1]) {
              low_i = mid_i;
              low_ip1 = mid_i;
            } else {
              high_i = mid_i;
            }
          }

          thisv = (this->rowidx->data[low_i - 1] == n);
        }
      } else if (this->colidx->data[mid_i] == this->colidx->data[i]) {
        low_i = this->colidx->data[mid_i] - 1;
        thisv = false;
      } else {
        low_i = 0;
        thisv = false;
      }

      thisv = (thisv && this->d->data[low_i - 1]);
      n = this->colidx->data[this->colidx->size[0] - 1] - 1;
      high_i = this->colidx->data[this->colidx->size[0] - 1] - 1;
      if (thisv) {
        this->d->data[low_i - 1] = true;
      } else {
        idx = low_i + 1;
        if (this->colidx->data[this->colidx->size[0] - 1] - 1 == this->maxnz) {
          st.site = &bb_emlrtRSI;
          mid_i = rowidxt->size[0];
          rowidxt->size[0] = this->rowidx->size[0];
          emxEnsureCapacity_int32_T(&st, rowidxt, mid_i, &gc_emlrtRTEI);
          low_ip1 = this->rowidx->size[0];
          for (mid_i = 0; mid_i < low_ip1; mid_i++) {
            rowidxt->data[mid_i] = this->rowidx->data[mid_i];
          }

          mid_i = dt->size[0];
          dt->size[0] = this->d->size[0];
          emxEnsureCapacity_boolean_T(&st, dt, mid_i, &hc_emlrtRTEI);
          low_ip1 = this->d->size[0];
          for (mid_i = 0; mid_i < low_ip1; mid_i++) {
            dt->data[mid_i] = this->d->data[mid_i];
          }

          bigProduct(this->m, this->n, &low_ip1, &mid_i);
          if (mid_i == 0) {
            b_st.site = &eb_emlrtRSI;
            bigProduct(this->m, this->n, &low_ip1, &mid_i);
            if (mid_i != 0) {
              emlrtErrorWithMessageIdR2018a(&b_st, &v_emlrtRTEI,
                "Coder:toolbox:SparseNumelTooBig",
                "Coder:toolbox:SparseNumelTooBig", 0);
            }

            low_ip1 = this->m * this->n;
            if (this->colidx->data[this->colidx->size[0] - 1] + 9 <= low_ip1) {
              low_ip1 = this->colidx->data[this->colidx->size[0] - 1] + 9;
            }

            if (1 >= low_ip1) {
              low_ip1 = 1;
            }
          } else if (1 >= this->colidx->data[this->colidx->size[0] - 1] + 9) {
            low_ip1 = 1;
          } else {
            low_ip1 = this->colidx->data[this->colidx->size[0] - 1] + 9;
          }

          mid_i = this->rowidx->size[0];
          this->rowidx->size[0] = low_ip1;
          emxEnsureCapacity_int32_T(&st, this->rowidx, mid_i, &ic_emlrtRTEI);
          for (mid_i = 0; mid_i < low_ip1; mid_i++) {
            this->rowidx->data[mid_i] = 0;
          }

          mid_i = this->d->size[0];
          this->d->size[0] = low_ip1;
          emxEnsureCapacity_boolean_T(&st, this->d, mid_i, &ic_emlrtRTEI);
          for (mid_i = 0; mid_i < low_ip1; mid_i++) {
            this->d->data[mid_i] = false;
          }

          this->maxnz = low_ip1;
          b_st.site = &fb_emlrtRSI;
          if ((1 <= low_i) && (low_i > 2147483646)) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (k = 0; k < low_i; k++) {
            this->rowidx->data[k] = rowidxt->data[k];
            this->d->data[k] = dt->data[k];
          }

          b_st.site = &gb_emlrtRSI;
          if ((low_i + 1 <= n) && (n > 2147483646)) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (k = idx; k <= high_i; k++) {
            this->rowidx->data[k] = rowidxt->data[k - 1];
            this->d->data[k] = dt->data[k - 1];
          }

          this->rowidx->data[low_i] = (int32_T)nt;
          this->d->data[low_i] = true;
        } else {
          st.site = &ab_emlrtRSI;
          low_ip1 = (this->colidx->data[this->colidx->size[0] - 1] - low_i) - 1;
          if (low_ip1 > 0) {
            b_st.site = &hb_emlrtRSI;
            memmove((void *)&this->rowidx->data[low_i + 1], (void *)
                    &this->rowidx->data[low_i], (uint32_T)((size_t)low_ip1 *
                     sizeof(int32_T)));
            b_st.site = &ib_emlrtRSI;
            memmove((void *)&this->d->data[low_i + 1], (void *)&this->d->
                    data[low_i], (uint32_T)((size_t)low_ip1 * sizeof(boolean_T)));
          }

          this->d->data[low_i] = true;
          this->rowidx->data[low_i] = (int32_T)nt;
        }

        st.site = &y_emlrtRSI;
        low_ip1 = i + 1;
        mid_i = this->n + 1;
        b_st.site = &jb_emlrtRSI;
        if ((low_ip1 <= mid_i) && (mid_i > 2147483646)) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (k = low_ip1; k <= mid_i; k++) {
          this->colidx->data[k - 1]++;
        }
      }
    }
  }

  emxFree_boolean_T(&dt);
  emxFree_int32_T(&rowidxt);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (parenAssign2D.c) */
