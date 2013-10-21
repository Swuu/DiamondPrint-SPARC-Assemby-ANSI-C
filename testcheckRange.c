/*
 * Filename: testcheckRange.c
 * Author: Joe Jane Student
 * Userid: cs30xXX
 * Description: Unit test program to test the function checkRange.
 * Date: Jan. 1, 1970
 * Sources of Help: List all the people, books, websites, etc. that you
 *                  used to help you write the code in this source file.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int checkRange( long value, long minRange, long maxRange );
 *
 * Returns 1 if value is within minRange and maxRange, inclusive.
 * Returns 0 otherwise.
 *
 * Precondition: Assume minRange is less than or equal to maxRange.
 */

void
testcheckRange()
{
    printf( "Testing checkRange()\n" );

    /* Test around 0 with range of size 0. */
    TEST( checkRange( -1, 0, 0 ) == 0 );
    TEST( checkRange( 0, 0, 0 ) != 0 );
    TEST( checkRange( 1, 0, 0 ) == 0 );

    /* Test around a negative range of size > 1. */
    TEST( checkRange( -100, -99, -90 ) == 0 );
    TEST( checkRange( -99, -99, -90 ) != 0 );
    TEST( checkRange( -90, -99, -90 ) != 0 );
    TEST( checkRange( -89, -99, -90 ) == 0 );

    /* Test around a positive range of size 1. */
    TEST( checkRange( 99, 100, 101 ) == 0 );
    TEST( checkRange( 100, 100, 101 ) != 0 );
    TEST( checkRange( 101, 100, 101 ) != 0 );
    TEST( checkRange( 102, 100, 101 ) == 0 );

    /* Test MIN and MAX int values with range of size 0. */
    TEST( checkRange( LONG_MIN, LONG_MIN, LONG_MIN ) != 0 );
    TEST( checkRange( LONG_MAX, LONG_MAX, LONG_MAX ) != 0 );

    /* Test a random value in the the full range of MIN and MAX int. */
    TEST( checkRange( rand(), LONG_MIN, LONG_MAX ) != 0 );

    printf( "Finished running tests on checkRange()\n" );
}

int
main()
{
    testcheckRange();

    return 0;
}
