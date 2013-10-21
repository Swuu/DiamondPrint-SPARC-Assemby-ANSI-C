/*
 * Filename: checkRange.s
 * Author: Jon Ho
 * Userid: cs30xbn
 * Description: SPARC Assembly routine to check if the arg is within the range.
 * 		Called from main() and displayX
 * Date: Oct. 14, 2013
 * Sources of Help: Lecture and reference sheet
 */

	.global checkRange	! Declares the symbol to be globally visible so
				! we can call this function from other modules

	.section ".text"	! The text segment begins here

/*
 * Function name: checkRange()
 * Function prototype:
 * 	int checkRange( long value, long minRange, long maxRange );
 * Description: This module will check to make sure the value of the first
 * 		argument is within the range of minRange and maxRange,
 * 		inclusive.
 * Parameters:
 * 	arg 1: long value - Number to check in range
 * 	arg 2: long minRange - Minimum value that arg 1 can be
 * 	arg 3: long maxRange - Maximum value that arg 1 can be
 *
 * Side Effects: None
 * Error Conditions: If not in range, handle error message in main.
 * Return Value: 0 if not in range, non-zero value for in range.
 *
 * Registers used:
 * 	%i0 - arg 1 -- Number to check; also used for return
 * 	%i1 - arg 2 -- Minimum value
 * 	%i2 - arg 3 -- Maximum value
 */

checkRange:
	save	%sp, -96, %sp	! Save caller's window

	cmp	%i0, %i1
	bge	else_if		! In range from min branch to else_if
				! to check max range
	nop

				! "If" begins here
	ba	out_range	! Branch to out_range to return 0
	nop

else_if:
	cmp	%i0, %i2
	ble	in_range	! In range from max, it is valid value
				! Branch to in_range to return 1
	nop

				! "Else-if" begins here
	ba	out_range	! Branch to out_range to return 0
	nop

out_range:
	mov	0, %i0		! Move 0 to be returned in %i0
	ba	end_check
	nop

in_range:
	mov	1, %i0		! Move 1 to be returned in %i0
	ba	end_check
	nop

end_check:
	ret			! Return from subroutines
	restore			! Restore caller's window; in "ret" delay slot
