/*
 ============================================================================
 Name        : 3220Lab2.c
 Author      : Ian Naeger
 Version     :
 Copyright   : N/A
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {

	int i = 1;
	int k;
	char input;
	unsigned short FacIn;
	unsigned long FacOut = 1;
	unsigned int LeapIn;
	int check;
	float MaxIn1 , MaxIn2 , MaxOut;
	int DivIn1 , DivIn2;
	float DivOut;

	while( i == 1)
	{
		printf("Please select an option: \na. Factorial of a Number \nb. Leap Year or Not \nc. Maximum \nd. Division of Two Numbers \ne. EXIT \n");
		//scanf("%c", &input);
		input = getchar();
		getchar();
		//input = 1;
		switch(input)
		{
		case 'a' :
				printf("Enter a number to be find its factorial:\n");
				scanf("%hu" ,&FacIn );
				getchar();

				if( FacIn >= 21 )
				{
					printf("Error!!! Number too large!\n");
					break;
				}

				for(k=1; k<=FacIn; k++)
				{
					FacOut = FacOut * k;
				}

				printf("%hu! = %lu\n", FacIn , FacOut);
				break;
		case 'b' :
				printf("Enter a year to check if it is a Leap Year or not:\n");
				scanf("%hu", &LeapIn);
				getchar();

				check = LeapIn % 4;

				if( check == 0)
				{
					printf("%hu is a Leap Year!\n", LeapIn);
				}
				else
				{
					printf("%hu is not a Leap Year...\n", LeapIn);
				}
				break;
		case 'c' :
				printf("Input two numbers to find which one is the maximum: \nEnter the First Number:\n");
				scanf("%f", &MaxIn1);
				getchar();
				printf("Enter the Second Number:\n");
				scanf("%f", &MaxIn2);
				getchar();

				MaxOut = (MaxIn1 > MaxIn2) ? 1 : 2;
				if(MaxOut == 1)
				{
					printf("%f is the maximum\n", MaxIn1);
				}
				else
				{
					printf("%f is the maximum\n", MaxIn2);
				}
				break;
		case 'd' :
				printf("Input two numbers to divide: \nEnter the First Number:\n");
				scanf("%d", &DivIn1);
				getchar();
				printf("Enter the Second Number:\n");
				scanf("%d", &DivIn2);
				getchar();

				DivOut = (float)DivIn1 / (float)DivIn2;
				printf("%d / %d = %f\n", DivIn1 , DivIn2 , DivOut);
				break;
		case 'e' :
				return 0;
				break;
		default :
				printf("Wrong Format! Please re-enter! \n");
				break;
		}
	}

	return 0;
}
