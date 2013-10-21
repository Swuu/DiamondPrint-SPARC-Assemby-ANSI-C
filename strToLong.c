/*
 * Filename: strToLong.c
 * Author: Jon Ho
 * Userid: cs30xbn
 * Description: This is a C routine to convert command line args to long
 *              type with the base provided in the parameter. This routine
 *              will also do error checking and error reporting if parameter
 *              cannot be converted.
 *              Called from main()
 * Date: Oct. 14, 2013
 * Sources of Help: Lecture and reference sheets
 */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "pa1.h"

/*
 * Function name: strToLong()
 * Function prototype: long strToLong( char *str, int base );
 * Description: Converts a string into a long int with respect to base
 * Parameters: char* str - The string to convert
 *             int base - Convert with respect to this value
 * Side Effects: Returns a converted string to long int
 * Error Conditions: Checks for valid input, string can be converted
 *                   Out of range error, not in long int domain
 *                   Output which argument caused the error
 * Return Value: A string converted to long int
 */

#define CONVERTING "\n\tConverting \"%s\" base \"%d\""
#define NOT_INT "\n\t\"%s\" is not an integer\n"

long strToLong( char *str, int base )
{
  /* Local variables */
  long num = 0;
  char *endptr;
  char errMsg[BUFSIZ];
  
  /*
   * Variable is from errno.h
   * Used to determine range error
   */
  errno = 0;

  /*
   * Pass in address of endptr
   * Not the pointer itself
   */
  num = strtol(str, &endptr, base);

  /* Out of Range Error Checking */
  if(errno != 0)
  {
    /*
     * Error Reporting
     * Using perror you type a message, that message is then followed
     * by "yourmessage: Type of error\n"
     * e.g. yourmsg: Result too large
     */
    (void)snprintf(errMsg, BUFSIZ, CONVERTING, str, base);
    perror(errMsg);
  }
  /* Incorrect arg form so cannot parse correctly */
  else if(*endptr != '\0')
  {
    /* Error Reporting */
    errno = 1;
    (void) fprintf(stderr, NOT_INT, str);
  }
  
  /* Valid parse, return num */
  return num;
}
