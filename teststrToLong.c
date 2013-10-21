/*
 * Filename: teststrToLong.c
 * Author: Jon Ho
 * Userid: cs30xbn
 * Description: Unit test program to test the function strToLong.
 * Date: Oct. 14 2013
 * Sources of Help: Lecture reference sheets, pa1.pdf.
 */

#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa1.h"    /* For strToLong() function prototype */
#include "test.h"   /* For TEST() macro and stdio.h */

/*
 * long strToLong( char *str, int base );
 *
 * Returns long int if parsed correctly.
 * Fails if parsed incorrectly or inequality.
 *
 * Precondition: None
 */

void
teststrToLong()
{
  printf("Testing strToLong()\n");

  /* Test working general cases */
  TEST( strToLong("0", BASE) == 0 );
  TEST( strToLong("122", BASE) == 122 );
  TEST( strToLong("1111112", BASE) == 1111112 );

  /* Test failing general cases */
  TEST( strToLong("123abc", BASE));
  TEST( strToLong("abc", BASE));
  TEST( strToLong("---", BASE));
  TEST( strToLong("123", BASE) == 124);

  /* Test failing special cases */
  TEST( strToLong("  ", BASE) == 0 );
  TEST( strToLong("1.2", BASE) == 0);

  /* Test with different bases */
  // Supposed to work
  TEST( strToLong("0", 20) == 0 );
  TEST( strToLong("0", 16) == 0 );
  TEST( strToLong("0", 14) == 0 );

  // Not supposed to work
  TEST( strToLong("1", 20) == 0);
  TEST( strToLong("5", 100) == 0);
  TEST( strToLong("100", 5) == 0);

  printf("Finished running tests on strToLong()\n");
}

int
main()
{
  teststrToLong();

  return 0;
}
