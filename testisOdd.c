/*
 * Filename: testisOdd.c
 * Author: Jon Ho
 * 
 * Description: Unit test program to test the function isOdd.
 *  
 * Sources of Help: Lecture and reference sheets, pa1.pdf.
 */

#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa1.h"    /* For isOdd() function prototype */
#include "test.h"   /* For TEST() macro and stdio.h */

/*
 * int isOdd( long num );
 *
 * Returns 1 if odd
 * Returns 0 otherwise
 *
 * Precondition: Assume given integers such that they are all working input
 *               and not something like floating points.
 */

void
testisOdd()
{
  printf("Testing isOdd()\n");

  /* Test 0 */
  TEST( isOdd(0) == 0 );

  /* Test negative values */
  // Supposed to work
  TEST( isOdd(-1) != 0 );
  TEST( isOdd(-3) != 0 );
  TEST( isOdd(-5) != 0 );

  // Not supposed to work
  TEST( isOdd(-2) == 0 );
  TEST( isOdd(-4) == 0 );
  TEST( isOdd(-256) == 0 );

  /* Test positive values */
  //Supposed to work
  TEST( isOdd(1) != 0 );
  TEST( isOdd(3) != 0 );
  TEST( isOdd(517) != 0);

  // Not supposed to work
  TEST( isOdd(2000) == 0 );
  TEST( isOdd(10000) == 0 );
  TEST( isOdd(2) == 0 );

  // Test LONG_MIN and LONG_MAX
  // LONG_MIN is even apparently
  TEST( isOdd(LONG_MIN) == 0 );
  // LONG_MAX is odd
  TEST( isOdd(LONG_MAX) != 0 );
  
  printf("Finished running tests on isOdd()\n");
}

int
main()
{
  testisOdd();

  return 0;
}
