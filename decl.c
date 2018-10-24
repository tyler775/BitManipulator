#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {





 {"isNegOne", (funct_t) isNegOne, (funct_t) test_isNegOne, 1, "! ~ & ^ | +", 5, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"logicalAnd", (funct_t) logicalAnd, (funct_t) test_logicalAnd, 2,
    "~ & ^ | + << >> !", 5, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"bitZor", (funct_t) bitZor, (funct_t) test_bitZor, 2, "| ~", 8, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"isLessNegTwo", (funct_t) isLessNegTwo, (funct_t) test_isLessNegTwo, 1,
    "! ~ & ^ | + << >>", 12, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"decOK", (funct_t) decOK, (funct_t) test_decOK, 1, "! ~ & ^ | + << >>", 5, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"incOK", (funct_t) incOK, (funct_t) test_incOK, 1, "! ~ & ^ | + << >>", 7, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"isBetween", (funct_t) isBetween, (funct_t) test_isBetween, 3,
    "! ~ & ^ | + << >>", 40, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
{"bitSwap", (funct_t) bitSwap, (funct_t) test_bitSwap, 3,
     "! ~ & ^ | + << >>", 25, 3,
    {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"logicalOr", (funct_t) logicalOr, (funct_t) test_logicalOr, 2,
    "~ & ^ | + << >>", 18, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"rotate", (funct_t) rotate, (funct_t) test_rotate,
   2, "! ~ & ^ | + << >>", 22, 4,
  {{TMin, TMax},{0,1},{TMin,TMax}}},
 {"negVal", (funct_t) negVal, (funct_t) test_negVal, 1, "! ~ & ^ | + << >>", 10, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"twocomp2onecomp", (funct_t) twocomp2onecomp,
   (funct_t) test_twocomp2onecomp, 1, "! ~ & ^ | + << >>", 20, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"float_range", (funct_t) float_range, (funct_t) test_float_range, 1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
 {"float_gtOne", (funct_t) float_gtOne, (funct_t) test_float_gtOne, 1,
    "$", 15, 2,
     {{1, 1},{1,1},{1,1}}},
 {"float_exactInt", (funct_t) float_exactInt, (funct_t) test_float_exactInt, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
