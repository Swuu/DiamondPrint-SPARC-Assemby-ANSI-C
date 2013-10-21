/*
 * Filename: isOdd.s
 * Author: Jon Ho
 * Userid: cs30xbn
 * Description: This is a SPARC assembly routine to check if an integer
 *              is odd.
 *              Called from main()
 * Date: Oct. 14 2013
 * Sources of Help: Lecture and course book
 */

	.global isOdd	! Declares the symbol to be globally visible
			! so we can call this function from other modules

	.section ".text"	! The text segment begins here

/*
 * Function name: isOdd()
 * Function prototype: isOdd( long value );
 * Description: Takes the parameter and checks if it is odd.
 * Parameters:
 * 	arg 1: long value -- Check if value is odd.
 *
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 not odd, 1 is odd
 *
 * Registers used:
 * 	%i0 - arg 1 -- Check if odd, also used as return
 *
 * 	%o0 - Copy arg 1 to here
 * 	%o1 - Move value 2 to here
 */

isOdd:
	save	%sp, -96, %sp	! Save the caller's window

	mov	%i0, %o0	! Parameter value goes to %o0
	mov	2, %o1		! 2 goes to %o1
	call	.rem		! Call modulus subroutine
	nop

	mov	%o0, %i0	! Return value goes in %i0

	ret			! Return value goes in %i0
	restore			! Restore caller's window;
				! in "ret" delay slot
