/*
 ============================================================================
 Name        : gcd_2022.c
 Author      : Ciaran
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "gcd_asm.h"

long long int gcd_c(long long int x, long long int y);


int main(void) {

	long long int x, y, gcd;

	x = 153;
	y = 68;
	printf("Numbers are: %lld\t and %lld\n", x, y);

	gcd = gcd_c(x, y);

	printf("GCD (C function) = %lld\n", gcd);

	gcd = gcd_asm(x, y);
	printf("GCD (ASM code) = %lld\n", gcd);

	return EXIT_SUCCESS;
}

long long int gcd_c(long long int x, long long int y)
{
	long long int n, temp;

	while (y > 0)
	{
	    if (x < y)
	      {
	      temp = x;
	      x = y;
	      y = temp;
	      }
	    n = x - y;
		x = y;
		y = n;
	}
	return x;
}
