/*
 * Filename: displayDiamond.s
 * Author: Jon Ho
 * Userid: cs30xbn
 * Description: SPARC Assembly routine to print a diamond pattern with
 *              different ASCII characters ranging from 32 - 126.
 *              Called from main()
 * Date: Oct. 14 2013
 * Sources of Help: Lecture and reference sheets
 */

	.global displayDiamond	! Declare symbol to be globally visible
				! so we can call this function from
				! other modules

	.section ".text"	! The text segment begins here

/*
 * Function name: displayDiamond()
 * Function prototype:
 * 	void displayDiamond( long width, long height, long borderCh,
 * 			     long diamondCh );
 * Description: Control logic with loops with printChar to display diamond.
 * Parameters:
 * 	arg 1: long width -- Width of diamond
 * 	arg 2: long height -- Height of diamond
 * 	arg 3: long borderCh -- The character for border
 * 	arg 4: long diamondCh -- The character for diamond
 *
 * Side Effects: Prints diamond out to terminal
 * Error Conditions: Checked from main, displays the types of errors
 * Return Value: None
 *
 * Registers Used:
 * 	%i0 - arg 1 -- Width of diamond
 * 	%i1 - arg 2 -- Height of diamond
 * 	%i2 - arg 3 -- Border Character
 * 	%i3 - arg 4 -- Diamond Character
 *
 * 	%l0 - local value for row
 * 	%l1 - local value for column
 * 	%l2 - local value for border count
 * 	%l3 - scratch local register to hold intermediate values
 * 	%l4 - scratch local register to hold intermediate values
 * 	%l5 - scratch local register to hold intermediate values
 *
 * 	%o0 - Out register to hold param 1
 * 	%o1 - Out register to hold param 2
 */

NL = '\n'	! The newline character

displayDiamond:
	save	%sp, -96, %sp	! Save caller's window

	clr	%l0	! Initialize as 0
	clr	%l1	! Initialize as 0
	clr	%l2	! Initialize as 0
	clr	%l3	! Initialize as 0
	clr	%l4	! Initialize as 0

	mov	1, %l1		! %l1 is now 1 for column value
	cmp	%l1, %i0	! Opp Logic, if col > width skip loop
	bg	error_exit
	nop

TopRowOuterBorder:
	mov	%i2, %o0	! Move border char to function call
	call	printChar, 1	! Specify # of params for printChar
	nop

	add	%l1, 1, %l1		! Increment col by 1
	cmp	%l1, %i0		! Compare col to width
	ble	TopRowOuterBorder	! Continue loop
	nop

				! Else loop is over
TopRowOuterBorderExit:
	mov	NL, %o0		! Move newline char to function call
	call	printChar, 1	! Specify # of params
	nop

	mov	1, %l0		! %l0 is now 1 for row value
	sub	%i1, 2, %l4	! %l4 is now height - 2
	cmp	%l0, %l4	! Opp logic, if row > height - 2, skip loop
	bg	error_exit
	nop

TopDiamondHalf:
	sub	%i0, %l0, %l2	! outer = (width - row)
	mov	%l2, %o0	! Move outer to be divided
	mov	2, %o1		! Will divide by 2
	call	.div		! Divided by 2
	nop

	mov	%o0, %l2	! outer = (width - row) / 2
	cmp	%l2, 1		! Opp Logic, if outer < 1, skip loop
	bl	error_exit
	nop

FirstInnerLoop:
	mov	%i2, %o0	! Move border char to function call
	call	printChar, 1	! Specify # of params for printChar
	nop

	add	%l2, -1, %l2	! Decrement outer by 1
	cmp	%l2, 1		! Compare outer to 1
	bge	FirstInnerLoop	! Continue loop
	nop

				! Else loop is over

FirstInnerLoopExit:
	mov	1, %l3		! inner = 1
	cmp	%l3, %l0	! Opp logic, if inner > row, skip loop
	bg	error_exit
	nop

SecondInnerLoop:
	mov	%i3, %o0	! Move diamond char to function call
	call	printChar, 1	! Specify # of params for printChar
	nop

	add	%l3, 1, %l3	! Increment inner by 1
	cmp	%l3, %l0	! Compare inner to row
	ble	SecondInnerLoop	! Continue loop
	nop

				! Else loop is over

SecondInnerLoopExit:
	sub	%i0, %l0, %l2	! outer = (width - row)
	mov	%l2, %o0	! Move outer to be divided
	mov	2, %o1		! Will divide by 2
	call	.div		! Divided by 2
	nop

	mov	%o0, %l2	! outer = (width - row) / 2
	cmp	%l2, 1		! Opp logic, if outer < 1, skip loop
	bl	error_exit	
	nop

ThirdInnerLoop:
	mov	%i2, %o0	! Move border char to function call
	call	printChar, 1	! Specify # of params for printChar
	nop

	add	%l2, -1, %l2	! Decrement outer by 1
	cmp	%l2, 1		! Compare outer to 1
	bge	ThirdInnerLoop	! Continue loop
	nop

				! Else loop is over
ThirdInnerLoopExit:
	mov	NL, %o0		! Move newline char to function call
	call	printChar, 1	! Specify # of params
	nop

	add	%l0, 2, %l0	! Increment row by 2
	cmp	%l0, %l4	! Compare row to height - 2
	ble	TopDiamondHalf	! Redo 3 inner loops
	nop

				! Else TopHalf Loop is over

TopDiamondHalfExit:
	mov	%i1, %l0	! row = height
	cmp	%l0, %g0	! compare row to 0
	bl	error_exit	! Opp logic, row < 0, skip loop
	nop

BotDiamondHalf:
	sub	%i0, %l0, %l2	! outer = (width - row)
	mov	%l2, %o0	! Move outer to be divided
	mov	2, %o1		! Will divide by 2
	call	.div		! Divided by 2
	nop

	mov	%o0, %l2	! outer = (width - row) / 2
	cmp	%l2, 1		! Opp logic, if outer < 1, skip loop
	bl	error_exit
	nop

firstinnerloop:
	mov	%i2, %o0	! Move border char to function call
	call	printChar, 1	! Specify # of params
	nop

	add	%l2, -1, %l2	! Decrement by 1
	cmp	%l2, 1		! Compare outer to 1
	bge	firstinnerloop	! Continue loop
	nop

				! Else loop is over
firstinnerloopexit:
	mov	1, %l3		! inner = 1
	cmp	%l3, %l0	! Opp loic, if inner > row, skip loop
	bg	error_exit
	nop

secondinnerloop:
	mov	%i3, %o0	! Move diamond char to function call
	call	printChar, 1	! Specify # of params
	nop

	add	%l3, 1, %l3	! Increment inner by 1
	cmp	%l3, %l0	! Compare inner to row
	ble	secondinnerloop	! Continue loop
	nop

				! Else loop is over

secondinnerloopexit:
	sub	%i0, %l0, %l2	! outer = (width - row)
	mov	%l2, %o0	! Move outer to be divided
	mov	2, %o1		! Will divide by 2
	call	.div		! Divided by 2
	nop

	mov	%o0, %l2	! outer = (width - row) / 2
	cmp	%l2, 1		! Opp logic, if outer < 1, skip loop
	bl	error_exit
	nop

thirdinnerloop:
	mov	%i2, %o0	! Move border char to function call
	call	printChar, 1	! Specify # of params
	nop

	add	%l2, -1, %l2	! Decrement outer by 1
	cmp	%l2, 1		! Compare outer to 1
	bge	thirdinnerloop	! Continue loop
	nop

				! Else loop is over

thirdinnerloopexit:
	mov	NL, %o0		! Move newline char to function call
	call	printChar, 1	! Specify # of params for printChar
	nop

	sub	%l0, 2, %l0	! Decrement row by 2
	cmp	%l0, %g0	! Compare row to 0
	bge	BotDiamondHalf	! Redo 3 inner loops
	nop

				! Else middle to bot is done, end loop

BotDiamondHalfExit:
	mov	1, %l1		! col = 1
	cmp	%l1, %i0	! Opp logic, if col > width, skip loop
	bg	error_exit	
	nop

BotRowOuterBorder:
	mov	%i2, %o0	! Move border char to function call
	call	printChar, 1	! Specify # of params
	nop

	add	%l1, 1, %l1	! Increment col by 1
	cmp	%l1, %i0	! Compare col to width
	ble	BotRowOuterBorder	! Continue loop
	nop

BotRowOuterBorderExit:
	mov	NL, %o0		! Move newline char to function call
	call	printChar, 1	! Specify # of params
	nop

error_exit:
	ret			! Return from subroutines
	restore			! Restore caller's window; in "ret" delay slot
