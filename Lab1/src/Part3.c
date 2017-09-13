/*
 * Part3.c
 *
 *  Created on: Aug 31, 2016
 *      Author: ivnqm2
 */
#include<stdio.h>
#include<math.h>

int main(void)
{
	float Op1 , Op2 , Ans;
	int Opr;

	printf("Enter Operand 1, then Operator, then Operand 2 (e.g. 4+5) \n");
	scanf("%f", &Op1);
	Opr = getchar();
	scanf("%f", &Op2);

	//Gets the Operands and Operator from the user

	switch(Opr)
	{
	case '+' :
		Ans = Op1 + Op2;
		break;
	case '-' :
		Ans = Op1 - Op2;
		break;
	case '*' :
		Ans = Op1 * Op2;
		break;
	case '/' :
		if( Op2 == 0 )
		{
			printf("Error! Division by Zero! \n");
			return 0;
		}
		// If user divides by zero they are closed out of the program, we can not stand for such nonsense
		Ans = Op1 / Op2;
		break;
	default :
		printf("Wrong Format! Please re-enter! \n");
		// If user puts incorrect format the are closed out of the program, mistakes will not be tolerated
		return 0;
	}

	printf("%f %c %f = %f \n", Op1 , Opr , Op2 , Ans);

	// Based on info entered by the user, the program decides the correct switch statement to perform the correct type of math. The results are then dissplayed

	return 0;
}


