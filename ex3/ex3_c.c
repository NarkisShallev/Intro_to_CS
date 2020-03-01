/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex3.c
******************************************/
#include <stdio.h>
#include <math.h>
int main()
{
int mission;
printf("please enter a mission number:\n");
scanf("%d", &mission);
// Finish program for input = 0
while (mission != 0)
{
	// Receiving a number and checking whether it is preliminary
	if (mission == 1)
	{
		char efficiency;
		printf("please enter the mission type:\n");
		scanf(" %c", &efficiency);
		// Check whether the input is preliminary by dividing the number in all the smaller numbers
		if (efficiency == 'a')
		{
			int number;
			int result;
			int i = 2;
			printf("please enter a number:\n");
			scanf("%d", &number);
			// Treatment in the case of 0,1 or 2 input and other numbers
			if ((number == 0) || (number == 1))
				printf("NO\n");
			else if (number == 2)
				printf("YES\n");
			else
			{
				// Dividing the number in all the smaller numbers, if remainder=0, the number is prime
				while (i < number)
				{
					result = number % i;
					if (result == 0)
					{
						printf("NO\n");
						break;
					}
					else
						i += 1;
				}
				if (result != 0)
					printf("YES\n");
			}
		}
		// Check whether the input is preliminary by dividing the number in numbers to its root
		else if (efficiency == 'b')
		{
			int number;
			int squareRoot;
			int result;
			int i = 2;
			printf("please enter a number:\n");
			scanf("%d", &number);
			// Calculate the root of the number
			squareRoot = sqrt(number);
			// Treatment in the case of 0,1 or 2 input and other numbers
			if ((number == 0) || (number == 1))
				printf("NO\n");
			else if ((number == 2) || (number == 3))
				printf("YES\n");
			else
			{
				// Dividing the number in numbers to its root, if remainder=0, the number is prime
				while (i <= squareRoot)
				{
					result = number % i;
					if (result == 0)
					{
						printf("NO\n");
						break;
					}
					else
						i += 1;
				}
				if (result != 0)
					printf("YES\n");
			}
		}
		// Check whether the input is preliminary by dividing the number in *odd* numbers to its root
		else
		{
			int number;
			int squareRoot;
			int result;
			int i = 3;
			printf("please enter a number:\n");
			scanf("%d", &number);
			// Calculate the root of the number
			squareRoot = sqrt(number);
			// Treatment in the case of 0 and 1 input
			if ((number == 0) || (number == 1))
				printf("NO\n");
			// Treatment in the case of even numbers input
			else if (number % 2 == 0)
			{
				if (number == 2)
					printf("YES\n");
				else
					printf("NO\n");
			}
			// Treatment in the case 3 input
			else if (number == 3)
				printf("YES\n");
			// Treatment in the case of other numbers input
			else
			{
				// Dividing the number in odd numbers to its root (+1 so that root 5 will also meet the condition of the loop), if remainder=0, the number is prime
				while (i <= (squareRoot+1))
				{
					result = number % i;
					if (result == 0)
					{
						printf("NO\n");
						break;
					}
					else
						i += 2;
				}
				if (result != 0)
					printf("YES\n");
			}
		}
	}
	// Receiving two numbers and printing all numbers from 1-100 divided by them
	if (mission == 2)
	{
		int number1;
		int number2;
		int min;
		int i=1;
		int result1;
		int result2;
		printf("please enter two numbers:\n");
		scanf("%d%d", &number1, &number2);
		printf("[");
		// Find the smallest number of the two
		if (number1 > number2)
			min = number2;
		else
			min = number1;
		// Check which numbers from 1-100 are divided by the numbers we received
		while (i <= 100)
		{
			result1 = i % number1;
			result2 = i % number2;
			if ((result1 == 0) || (result2 == 0))
			{
				// Prints the first number without a comma
				if (i == min)
					printf("%d", i);
				else
					printf(", %d", i);
			}
			i += 1;
		}
		printf("]\n");
	}
	printf("please enter a mission number:\n");
	scanf("%d", &mission);
}
/* Run time for case a: python 3.38451409 seconds c 0.06929398 seconds
Run time for case b: python 0.01741505 seconds c 0.00406194 seconds
Run time for case c: python 0.01597404 seconds  c 0.00411296 seconds*/
}