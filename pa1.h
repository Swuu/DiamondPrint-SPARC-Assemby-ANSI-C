#ifndef PA1_H
#define PA1_H

#define BASE 10
#define WIDTH_MIN 3
#define WIDTH_MAX 21
#define HEIGHT_MIN 1
#define HEIGHT_MAX 19
#define ASCII_MIN 33
#define ASCII_MAX 126

/* Local function prototypes for PA1 (written in Assembly or C) */
long strToLong( char* str, int base );
int checkRange( long value, long minRange, long maxRange );
void displayDiamond( long width, long height, long borderCh, long diamondCh );
int isOdd( long value );

/*
 * void printChar( char ch );
 *
 * Only called from an Assembly routine. Not needed in any C routine.
 * Would get a lint message about function declared but not used.
 */

#endif /* PA1_H */
