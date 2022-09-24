/*
 * pointer.c - Source file with your solutions to the Lab.
 *             This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>. The included file, "common.c" contains a function declaration
 * that should prevent a compiler warning. In general, it's not good practice
 * to ignore compiler warnings, but in this case it's OK.
 */

#ifndef COMMON_H
#include "common.h"
#endif

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

#if 0
You will provide your solution to this homework by
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
     However, you are allowed to combine constants to values greater
     than 255 or less than 0. e.g. 250 + 250 = 500, so long as
     the operator you are using to combine the constants is listed as
     "legal" at the top of the method you are writing.
  2. Function arguments and local variables (no global variables).
  3. Any operators listed as "allowed" at the top of the method you are writing.
  4. casting.

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc. (unless
     otherwise stated).
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions (unless otherwise stated).
  5. Use any operators not "allowed" at the top of the method you are writing.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has *undefined* behavior when shifting by a negative amount or an amount
     greater than or equal to the number of bits in the value being shifted.
     e.g. For x >> n, shifts by n < 0 or n >= *size of x* are undefined
     e.g. if x is a 32-bit int, shifts by >= 32 bits are undefined
     Undefined means you do not know what result you will get from the operation.
#endif

/*
 * STEP 2: Modify the following functions according the coding rules.
 */

/*
 * Return the size of an integer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, eFDIStc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int intSize() {
  //uses the pointers from beginning and subtracting
  //their values to get the size of the int in bytes
  int intArray[10];
  int * intPtr1;//first element
  int * intPtr2;//second element
  long int x, y;
  int z;
  // Write code to compute size of an integer.

  intPtr1= intArray;
  intPtr2= intPtr1+1;
  x= (long int)intPtr1;
  y= (long int)intPtr2;
  z= y-x;//subtracting addresses of pointer elements

  return z;
}

/*
 * Return the size of a double in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */

int doubleSize() {
  //similar concept to size method by subtracting beginning
  //you get the size of the double in bytes. difference is using double * not int *
  double doubArray[10];
  double * doubPtr1;
  double * doubPtr2;
  int result;
  // Write code to compute size of a double.

  doubPtr1= doubArray;
  doubPtr2= doubPtr1+1;
  result= (int)((long int)doubPtr2-(long int)doubPtr1);

  return result;
}

/*
 * Return the size of a pointer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */

int pointerSize() {
  //similar concept to size of int and double but this time flipped
  //int * pointers then subtracted to get the full size end-beginning
  int * ptrArray[10];
  int ** ptrPtr1;
  int ** ptrPtr2;
  int result;
  // Write code to compute size of a pointer.

  ptrPtr1= ptrArray;
  ptrPtr2= ptrPtr1+1;
  result= (int)((long int)ptrPtr2-(long int)ptrPtr1);

  return result;
}

/*
 * Given pointers to two distinct variables write a function to swap the values
 * of said variables.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */

void swapInts(int * ptr1, int * ptr2) {
  //swapping pointers by creating a temporary variable to set pnt1 to then swaping them
  int test;

  test=*ptr1;
  *ptr1=*ptr2;
  *ptr2=test;
}

/*
 * Modify intArray[5] to be the value 449 using only intArray and pointer arithmetic.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, ~= etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */

int changeValue() {
  //since pnt1 is the beginning of th array ont2 adds five to get array[5]
  //then simply set pnt2 which is poiting to array[5] to 449
  int intArray[10];
  int * intPtr1=intArray;
  int * intPtr2;
  // Remember not to use constants greater than 255.
  // Remember to use * to dereference. You cannot use '[<index>]' syntax.

  // replace the line below to use pointer arithmetic
intPtr2=intPtr1+5;
*intPtr2=255+194;

 return intArray[5];
}

/*
 * Return 1 if the addresses stored in ptr1 and ptr2 are within the
 * *same* 64-byte aligned  block of memory. Check the spec for examples if you are
 * confused about what this means. Return zero otherwise.
 * Operators / and % and loops are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */

int withinSameBlock(int * ptr1, int * ptr2) {
  //within same block if their addys r the same except the last 6 so right shift 6 and compare
  long int x,y;
  int result;

  x= ((long int)ptr1-1)>>6;
  y= ((long int)ptr2-1)>>6;
  result= !(x^y);

  return result;
}

/*
 * Return 1 if ptr points to an element within the specified intArray, 0 otherwise.
 * Pointing anywhere in the array is fair game, ptr does not have to
 * point to the beginning of an element. Check the spec for examples if you are
 * confused about what this method is determining.
 * size is the size of intArray in number of ints. Can assume size != 0.
 * Operators / and % and loops are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */

int withinArray(int * intArray, int size, int * ptr) {
  // intarry points to the first element, if either max-sub right shift 31 or
  //sub right shift 31 not then itll return 1 which meansthe pointer is withinArray
  //the specified array and 0 if not
  int max,result;
  long int sub;

  max= size*4-1;
  sub=(long int)ptr-(long int)intArray;
  result= !(sub>>31)*!((max-sub)>>31);
  return result;
}

/*
 * In C characters are are terminated by the null character ('\0')
 * given a pointer to the start of the string return the length of this string.
 * (The null character is not counted as part of the string length.)
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *   Control constructs: for, while
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /, %
 *   Unary integer operators: ~, -
 */

int stringLength(char * s) {
  // using a for loup to run until there is null character '\0', count is incremated
  //return count as length
  int count;
  count=0;

  for(; *s != '\0'; ++s)
  count++;

  return count;
}

/*
 * Returns the length of the initial portion of str1 which consists only of characters that are part of str2.
 * The search does not include the terminating null-characters of either strings, but ends there.
 *
 * Example, stringSpan("abcdefgh", "abXXcdeZZh"); // returns 5
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *   Control constructs: for, while
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /, %
 *   Unary integer operators: ~, -
 */

int stringSpan(char * str1, char * str2) {
  // runs through the string and if both match it continues running keeping count
  //once a character doesnt match it ends and returns the length of matching chars
  int i,j,length,detectedChar;
  length=0;
  detectedChar=0;


  for (i=0; i!='\0'; i++)
  {
    detectedChar=length;

    for(j=0; j!='\0'; j++)
    {
      if(str1[i]==str2[j])
      length++;
    }
    if(detectedChar>=length)
        break;
  }


  return length;

}

/*
 * Change the value pointed to by ptr byte-by-byte so that when returned as an integer
 * the value is 449449.
 *
 * Hint: Remember that an int is 4 bytes.
 *
 * Hint: Remember how little endian works for data storage, how is it different between an multiple bytes(int) and a single byte?
 *
 * Hint: It will be easiest to start convert 449449 into binary form and starting seeing how the endian works from there.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *   Unary integer operators: !
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */

int endianExperiment(int * ptr) {
  //449449= 0x0006DBA9
  //using point bytes each byte of 4 is equivalent to 449449 which is then
  //added together as returned as a hex
  char *bytePtr;
  bytePtr= (char*) ptr;
  // Your code here
  *bytePtr=0xA9;
  bytePtr++;
  *bytePtr=0xDB;
  bytePtr++;
  *bytePtr=0x06;
  bytePtr++;
  *bytePtr=0x00;
  bytePtr++;

  return *ptr;
}

/*
 * Selection sort is a sorting algorithim that works by partitioning the array into
 * a sorted section and unsorted section. Then it repeatedly selects the minimum element
 * from the unsorted section and moves it to the end of the sorted section.
 *
 * So the pseudo-code might look something like this:
 * arr - an array
 * n - the length of arr
 *
 * for i = 0 to n - 1
 *   minIndex = i
 *   for  j = i + 1 to n
 *       if arr[minIndex] > arr[j]
 *           minIndex = j
 *       end if
 *   end for
 *   Swap(arr[i], arr[minIndex])
 * end for
 *
 * Implement selection sort below, it might be helpful to use the swapInts function you
 * defined earlier.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *   Control constructs: for, while, if
 *   Function calls: swapInt()
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /
 *   Unary integer operators: ~, -
 */


void selectionSort(int arr[], int arrLength) {
  //runs through thr array and takes the minimum and moves it to the end of the
  //sorted array
  int i, j, min_index,x;
  // Your code here

  for(i=0; i< arrLength-1; i++)
  {
    min_index=i;
    for(j=i+1; j<arrLength; j++)
    {
      if(arr[min_index]> arr[j])
      min_index=j;
    }
     x= arr[min_index];
     arr[min_index]=arr[i];
     arr[i]=x;
  }
}
