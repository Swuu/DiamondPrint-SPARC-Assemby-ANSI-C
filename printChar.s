/*
 * Filename: printChar.s
 * Author: Jon Ho
 * 
 * Description: SPARC Assembly routine to print a character at a time.
 *              Called from displayDiamond()
 *  
 * Sources of Help: Lecture reference sheets
 */

	.global printChar	! Declare the symbol to be globally visible so
				! we can call this function from other modules

	.section ".data"	! The data segment begins here
fmt:
	.asciz "%c"

	.section ".text"	! The text segment begins here

/*
 * Function name: printChar()
 * Function prototype: void printChar( char ch );
 * Description: Prints to stdout a character via printf()
 * Parameters:
 *   arg 1: char ch -- the character to print
 * Side Effects: Outputs the character
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: None
 *
 * Registers Used:
 *	%i0 - arg 1 -- the string (single char) passed in to this function
 *
 *	%o0 - param 1 to printf() -- format specifier for character
 *	%o1 - param 2 to printf() -- arg value for format specifier
 */

printChar:
	save	%sp, -96, %sp	! Save caller's window
		
	set	fmt, %o0	! Set the format as %c for character

	mov	%i0, %o1	! Parameter 1 to printf() goes in register %o0
	call	printf, 2	! Make function call specifying # of params
	nop			! Delay slot for call instruction

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
