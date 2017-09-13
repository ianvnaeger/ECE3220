/*
 * Part2.c
 *
 *  Created on: Sep 7, 2016
 *      Author: ivnqm2
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
	unsigned short input;
	int choice , i , k , r;
	unsigned long long p = 1;
	unsigned long long output = 0;
	int b[16];
	// Declaration of Variable Independence

	printf("Enter a Decimal Number to be made Binary:\n");
	scanf("%hu", &input);
	printf("How would you like the number converted? \n1. Arithmetic \n2. Bitwise \n");
	scanf("%d", &choice);
	// Gets the decimal number and the convertion type from the user

	if( choice == 1 )
	{
	    while( input != 0 )
	    { 
	        r = input % 2; 
	        input = input / 2;
	        output = output + (r * p); 
	        p = p * 10; 
	    } 
		// Uses Arithmetic method to calculate the binary version of the number, it takes a lot of math and adding
	    
		printf("%hu in binary is: \n%.16llu\n", input , output);
		// Prints out a pretty Binary number
	}
	else
	{
		printf("%hu in binary is: \n", input);

		for(i =  16; i >= 0; i--)
		{
			k = input >> i;

			if(k & 1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
		//Actually really cool, takes a number and determines if it should trigger the binary number place it is then does that until it gets to zero
	}

	return 0;
}
