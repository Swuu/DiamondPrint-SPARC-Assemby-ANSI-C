/*
 * Filename: main.c
 * Author: Jon Ho
 * 
 * Description: This is the driver of the program. This program will take in
 *              command line arguments and make function calls using them as
 *              arguments. The result of this program is to print out a
 *              diamond pattern with different ASCII characters ranging from
 *              32 to 126. If the arguments aren't valid then errors will be 
 *              printed out to the user, and the usage will be explained 
 *              to the user.
 *  
 * Sources of Help: Lecture and reference sheets
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "pa1.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: Call functions using the command line arguments to design a
 *              diamond pattern. argv[0] is the program name, next 2 in argv[]
 *              determine the size of the diamond in width and height. The last
 *              2 are then the ASCII characters to fill and border the pattern.
 * Parameters: int argc - The count of command line arguments.
 *             char *argv[] - The vector (array) of the command line args.
 * Side Effects: Outputs diamond parameterized by the command line args.
 * Error Conditions: Error statements are not buffered, they are printed
 *                   through stderr, but the program does not stop execution.
 *                   Therefore when an error occurs an error statement will be
 *                   printed onto the terminal.
 * Return Value: 0 indicating successful execution.
 */

#define USG "\nUsage: %s width height border_ch diamond_ch\n"              \
            "    width      (must be odd within the range of [%d - %d])\n" \
            "    height     (must be odd within the range of [%d - %d])\n" \
            "               (must be less than width)\n"                   \
            "    border_ch  (must be an ASCII value within the range"      \
            " [%d - %d])\n"                                                \
            "               (must be different than diamond_ch)\n"         \
            "    diamond_ch (must be an ASCII value within the range"      \
            " [%d - %d])\n"                                                \
            "               (must be different than border_ch)\n"          \
            "\n"

#define WIDTH_RANGE  "\n\twidth(%ld) must be within the range of [%d - %d]\n"

#define WIDTH_ODD    "\n\twidth(%ld) must be an odd number.\n\n"

#define HEIGHT_RANGE "\n\theight(%ld) must be within the range of [%d - %d]\n"

#define HEIGHT_ODD   "\n\theight(%ld) must be an odd number.\n"

#define HEIGHT_LESS_WIDTH "\n\theight(%ld) must be less than width(%ld)\n\n"

#define BR "\n\tborder_ch(%ld) must be an ASCII code in the range [%d - %d]\n"

#define DR "\n\tdiamond_ch(%ld) must be an ASCII code in the range [%d - %d]\n"

#define DIF_CHAR "\n\tborder_ch(%ld) and diamond_ch(%ld) must be different\n\n"

#define NL "%c"
int main(int argc, char *argv[])
{
  // Initially no errors
  int noError = 1;
  
  /* Print usage message */
  if(argc != 5)
  {
    (void)fprintf(stderr, USG, argv[0], WIDTH_MIN, WIDTH_MAX, HEIGHT_MIN,
        HEIGHT_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX);

    return 0;
  }

  /* Check width */
  long width = strToLong(argv[1], BASE);
  if(errno == 0)
  {
    /* Returns 0 if out of range, returns 1 if in range */
    int range = checkRange(width, WIDTH_MIN, WIDTH_MAX);
    /* Returns 1 if odd, returns 0 if not odd */
    int odd = isOdd(width);
    
    /* Print out of range error message */
    if(!range)
    {
      (void)fprintf(stderr, WIDTH_RANGE, width, WIDTH_MIN, WIDTH_MAX);
      noError = 0;
    }
    if(!odd)
    {
      (void)fprintf(stderr, WIDTH_ODD, width);
      noError = 0;
    }
  }
  else
    noError = 0;

  /* Check height */
  long height = strToLong(argv[2], BASE);
  if(errno == 0)
  {
    /* Returns 0 if out of range, returns 1 if in range */
    int range = checkRange(height, HEIGHT_MIN, HEIGHT_MAX);
    /* Returns 1 if odd, returns 0 if not odd */
    int odd = isOdd(height);

    /* Print out of range error message */
    if(!range)
    {
      (void)fprintf(stderr, HEIGHT_RANGE, height, HEIGHT_MIN, HEIGHT_MAX);
      noError = 0;
    }
    if(!odd)
    {
      (void)fprintf(stderr, HEIGHT_ODD, height);
      noError = 0;
    }
    if(height > width)
    {
      (void)fprintf(stderr, HEIGHT_LESS_WIDTH, height, width);
      noError = 0;
    }
  }
  else
    noError = 0;

  /* Check border character */
  long borderChar = strToLong(argv[3], BASE);
  if(errno == 0)
  {
    /* Returns 0 if out of range, returns 1 if in range */
    int range = checkRange(borderChar, ASCII_MIN, ASCII_MAX);
    
    /* Print out of range error message */
    if(!range)
    {
      (void)fprintf(stderr, BR, borderChar, ASCII_MIN, ASCII_MAX);
      noError = 0;
    }
  }
  else
    noError = 0;

  /* Check diamond character */
  long diamondChar = strToLong(argv[4], BASE);
  if(errno == 0)
  {
    /* Returns 0 if out of range, returns 1 if in range */
    int range = checkRange(diamondChar, ASCII_MIN, ASCII_MAX);

    /* Print out of range error message */
    if(!range)
    {
      (void)fprintf(stderr, DR, diamondChar, ASCII_MIN, ASCII_MAX);
      noError = 0;
    }
    if(borderChar == diamondChar)
    {
      (void)fprintf(stderr, DIF_CHAR, borderChar, diamondChar);
      noError = 0;
    }
  }
  else
    noError = 0;

  // If there's no error then go ahead and display the diamond
  if(noError)
  {
    displayDiamond(width, height, borderChar, diamondChar);
    (void)printf("\n");
  }

  return 0;
}
