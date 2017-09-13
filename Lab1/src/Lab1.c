/*
 ============================================================================
 Name        : Lab1.c
 Author      : Ian Naeger
 Version     :
 Copyright   : N/A
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(void)
{
	double radius , /*area*/ circumference;

	printf("Enter the radius of the circle: \n");
	scanf("%lf", &radius);

	//Gets radius from User

// More
// Comments
// More 
// Fun!!!

	printf("This is a test comment\n");

//	area = radius * radius * PI;
//	printf("Area of the circle is: %f \n" , area);

	circumference = 2 * PI * radius;
	printf("Circumference of the circle is: %f \n" , Circumference);
	//Calculates and prints Area of the Circle

	return 0;
}
