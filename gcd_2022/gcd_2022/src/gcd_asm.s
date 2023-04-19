/*
 ============================================================================
 Name        : gcd_2022.c
 Author      : Roisin Mitchell (21193762)
 Version     : 1.0
 Description : Greatest common denominator
 ============================================================================
 */

.globl   gcd_asm
.p2align 2
.type    gcd_asm,%function

gcd_asm:
		//Setting up the stack
		sub		sp, sp, #16
		str		x9, [sp, #16]


loop_check:
		// if (y == 0) branch to return
		cbz		x1, return

		// if (x > y) branch to loop
		cmp		x0, x1
		b.ge	loop_body

		//else
		mov		x9, x0 //temp = x;
		mov		x0, x1 //x = y;
		mov		x1, x9 //y = temp;


loop_body:
		sub		x9, x0, x1 //n = x - y;
		mov		x0, x1 // x = y;
		mov		x1, x9 // y = n;

		//Go to loop check
		b		loop_check


return:
		//Restoring stack
		ldr		x9, [SP, #16]
		add		sp, sp, #16

		//Branch to return address
		br		x30

