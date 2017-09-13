/*
 * Part2.c
 *
 *  Created on: Aug 31, 2016
 *      Author: ivnqm2
 */
#include<stdio.h>
#include<math.h>

int main(void)
{
	float buy , sell , profit;

	printf("Enter the cost of the item: \n");
	scanf("%f", &buy);
	printf("Enter the selling price of the item: \n");
	scanf("%f", &sell);

	//Gets cost and selling price of the item from the user

	profit = sell - buy;

	//Calculates if the user made a profit

	if( profit > 0 )
	{
		printf("Congratulations! You've made a profit of %f\n", profit);
	}
	else if( profit <= 0)
	{
		printf("Oh no! You made a loss of: %f\n", profit);
	}

	//Based on the value of profit, the program determines if the use made a profit or lost money, and gives the appropriate message

	return 0;
}
