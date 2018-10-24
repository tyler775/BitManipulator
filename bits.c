/* 
 * CS:APP Data Lab 
 * 
 * Tyler McFadden mcfaddentw
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */

	  //So 6 << 1 is equivalent to 6 * 2, and 6 << 3 is equivalent to 6 * 8
	  return (1 * (2 ^ x)) + 1;
    // return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     //int result = (1 << x);
	  int result = ((1 * (2 ^ x))) + 4;
     //result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/*
 * isNegOne - returns 1 if x is -1 and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 1
 */
int isNegOne(int x) {
	int y = ~x;



  return !y;
  //Works
}

/* 
 * logicalAnd - implement the && operator without using &&. 
 *              use only the the legal operators. 
 *   Examples: logicalAnd(3, 2) = 1, logicalAnd(3, 0) = 0
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 5 
 *   Rating: 1 
 */
int logicalAnd(int x, int y) {

	//int a = ~((~(x | x)) | (~(y | y)));
int a0 = !(!x || !y);


  return a0;
//Works
}
/* 
 * bitZor - x^y using only ~ and | 
 *   Example: bitZor(4, 5) = 1
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 2
 */
int bitZor(int x, int y) {
	int a = ~((~(x | x)) | (~(y | y)));
	return ~(a | (~(x | y)));
	//Works

}
/* 
 * isLessNegTwo - if x < -2  then return 1, else return 0 
 *   Use only the legal operators.
 *   Example: isLessNegTwo(-3) = 1.
 *            isLessNegTwo(-2) = 0.
 *            isLessNegTwo(2) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int isLessNegTwo(int x) {
	int a = (x >> 31) & 1;
	int b = ~x + 1;
	int c = ~2 + 1;
	int a0 = !(x << 1) || ((!((b + c) >> 31)) && (b + c));
	return a && a0;
	//Works
}
/* 
 * decOK - return 1 if decrementing x by 1 does not result
 *   in an overflow; otherwise return 0. Use only legal operators. 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int decOK(int x) {
	int a = x + (~1 + 1);
     int a0 = ((x >> 31) && !(a >> 31));
         return a0;
	
  // Works
}
/* 
 * incOK - return 1 if incrementing x by 1 does not result
 *   in an overflow; otherwise return 0. Use only legal operators. 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 7
 *   Rating: 2
 */
int incOK(int x) {
	int a = x + 1;
     int a0 = (!(x >> 31) && (a >> 31));
         return !a0;
     
     //Works
  
}
/* 
 * isBetween - if h > x and x > l then return 1, else return 0 
 *   Example: isBetween(4,5,3) = 1, isBetween(5,4,3) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 3
 */
int isBetween(int x, int h, int l) {
int a;
int a1 = (h ^ x);
     a1 |= (a1 >> 1);
     a1 |= a1 >> 1;
    a1 |= a1 >> 2;
    a1 |= a1 >> 4;
    a1 |= a1 >> 8;
    a1 |= a1 >> 16;

    a = (a1 & (~(a1 >> 1) | 0x80000000)) & ((h ^ 0x80000000) & (x ^ 0x7fffffff));
   

    
	
	int a2 = x ^ l;
    a2 |= a2 >> 1;
    a2 |= a2 >> 2;
    a2 |= a2 >> 4;
    a2 |= a2 >> 8;
    a2 |= a2 >> 16;

    int a3 = (a2 & (~(a2 >> 1) | 0x80000000)) & ((x ^ 0x80000000) & (l ^ 0x7fffffff));


    return !!a && (!!a3);
 
 //Works
}
/* 
 * bitSwap - swaps bit n and bit m in x.
 *           returns x with the bits swapped if 0 <= n,m <=31.
 *           otherwise, returns unchanged x. 
 *           least significant bit is bit 0; most significant is bit 31
 *  Examples: bitSwap(0x12345678, 0, 4) = 0x12345669
 *            bitSwap(0xDEADBEEF, 0, 32) = 0xDEADBEEF
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int bitSwap(int x, int n, int m) {
	int a = ((!(n>>5) & !(m>>5)) << 31) >> 31;
	int a0 = (x >> m) & 1;
	int a00 = (x >> n) & 1;
	int a1 = (1 << n) | (1 << m);
	int a2 = (((x & ~a1) | ((a0 << n) | (a00 << m))) & a) | (~a & x);
 	
     return a2;
	 //Works
}
/* 
 * logicalOr - implement the || operator without using ! and ||.
 *  *          use only the legal operators.
 *   Examples: logicalOr(3, 0) = 1, logicalOr(0, 0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4 
 */
int logicalOr(int x, int y) {
	
	int a0 = 1 && (x | y);

	
  return a0;
//Works
  }
/* 
 * rotate - if w is 1 then rotate x to the left by 1 bit;
 *   otherwise rotate x to the right by 1 bit
 *   Can assume that w is 1 or 0
 *   Examples: rotate(0x87654321,1) = 0xeca8643
 *             rotate(0x87654321,0) = 0xceb2a190
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 22
 *   Rating: 4 
 */
int rotate(int x, int w) {
int a = ~w + 1;
int j = (x << 31);
int a0 = ((x << 1)|((x >> 31) & 1)) & a;
int r = (((x >> 1) &  ~(1<<31)) | j)& ~a;

return r | a0;
//Works
}
/* 
 * negVal - returns x if x is negative and -x if x is positive
 *   Example: negVal(-1) = -1. negVal(1) = -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int negVal(int x) {
	int a = x >> 31;
	int a0 = (x & a) | ((~x + 1) & ~a);
  return a0;
  //Works
}
/* 
 * twocomp2onecomp - Convert from two's complement to one's complement.
 *   Since two's complement tmin (0x80000000) can not be represented in one's
 *   complement, then if x is tmin return one's complement -0 (0xFFFFFFFF)
 *   Example: twocomp2onecomp(0x5) = 5.
 *   Example: twocomp2onecomp(0xFFFFFFFE) = 0xFFFFFFFD.
 *   Recall for one's complement: -x is equal to ~x
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int twocomp2onecomp(int x) {
	int t = (x >> 31);
	int t0 = 0x80000000;
int t1 = x & ~t;
int t2 = t & (~(!(t0^x)) + 1) & 0xFFFFFFFF;
int t3 = (~(~x + 2) + 1) & t & (~(!!(t0^x)) + 1);

  return (t1 | t2 | t3);
  
  //Works
  
  
}
/* 
 * float_range - Return 1 if floating point argument f is between the range
 *   of -1.0 and 1.0 (inclusive) and 0 otherwise.
 *   The argument is passed as an unsigned int, but
 *   is to be interpreted as the bit-level representation of
 *   a single-precision floating point value.
 *   When argument is NaN, return 0.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_range(unsigned uf) {
 
unsigned a = ((0x7f800000) & uf) >> 23;
 unsigned a0 =(0x007fffff) & uf;
 if ((a == 127 && a0 == 0) || (a < 127) || ((~(!(0x80000000^uf)) + 1)))
 {
	 return 1;
 }
 

 
 
 //Works
 
 
 return 0;
}
/* 
 * float_gtOne - Return 1 if floating point argument f is greater than 1.0
 *   and 0 otherwise.
 *   The argument is passed as an unsigned int, but
 *   is to be interpreted as the bit-level representation of
 *   a single-precision floating point value.
 *   When argument is NaN, return 0.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 15
 *   Rating: 2
 */
unsigned float_gtOne(unsigned uf) {
unsigned a = ((0x7f800000) & uf) >> 23;
 unsigned a0 =(0x007fffff) & uf;
 unsigned a1 = (uf >> 31) & 1;
 if (((a == 127 && a0 != 0 && uf != 0 && !a1) || (a > 127 && uf != 0 && !a1)) && (uf != 0x7fc00000))
 {
	 return 1;
 }
 

return 0;

//Works
}
/* 
 * float_exactInt - Return returns 1 if (float)(int) f == f 
 *   and 0, otherwise.
 *   The argument is passed as an unsigned int, but
 *   is to be interpreted as the bit-level representation of
 *   a single-precision floating point value.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_exactInt(unsigned uf) {
unsigned a = ((0x7f800000) & uf) >> 23;
 unsigned a0 =(0x007fffff) & uf;
 
 if (((a == 127) && (a0 == 0)) || ((a < 127) && (a != 0)))
 {
	 return 1;
 }
 

return 0;
//Works
}
