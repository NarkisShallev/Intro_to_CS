/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex2.c
******************************************/
#include <stdio.h>
int main()
{
int mission;
printf("Please enter the mission number:\n");
scanf("%d", &mission);
// Converts a binary number with 6 charts into a number in a decimal base
if (mission==1)
{
	char bit1, bit2, bit3, bit4, bit5, bit6;
	int result;
	printf("Enter six digits binary number:\n");
	scanf(" %c%c%c%c%c%c", &bit1, &bit2, &bit3, &bit4, &bit5, &bit6);
	// Treatment in case of a negative number conversion
	if (bit1 == '1')
	{
		// Convert '1' to '0' and vice versa according to the "complementary to 2" method
		bit1 = '0';
		if (bit2 == '0')
			bit2 = '1';
		else 
			bit2 = '0';
		if (bit3 == '0')
			bit3 = '1';
		else
			bit3 = '0';
		if (bit4 == '0')
			bit4 = '1';
		else
			bit4 = '0';
		if (bit5 == '0')
			bit5 = '1';
		else
			bit5 = '0';
		if (bit6 == '0')
			bit6 = '1';
		else
			bit6 = '0';
		// Conversion of char to int
		 bit1 = (int) (bit1 - '0');
		 bit2 = (int) (bit2 - '0');
		 bit3 = (int) (bit3 - '0');
		 bit4 = (int) (bit4 - '0');
		 bit5 = (int) (bit5 - '0');
		 bit6 = (int) (bit6 - '0');
		// Convert to decimal base
		result = bit1 * 32 + bit2 * 16 + bit3 * 8 + bit4 * 4 + bit5 * 2 + bit6 * 1;
		// Add 1 to the result according to the "complementary to 2" method
		result++;
		// Add a negative sign
		result *= (-1);
		printf("%d\n", result);
	}
	else
	{
		// Conversion of char to int
		bit1 = (int)(bit1 - '0');
		bit2 = (int)(bit2 - '0');
		bit3 = (int)(bit3 - '0');
		bit4 = (int)(bit4 - '0');
		bit5 = (int)(bit5 - '0');
		bit6 = (int)(bit6 - '0');
		// Convert to decimal base
		result = bit1 * 32 + bit2 * 16 + bit3 * 8 + bit4 * 4 + bit5 * 2 + bit6 * 1;
		printf("%d\n", result);
	}
}
// Receiving a ASCII code as an integer and printing the number and the corresponding letter as a small letter and a large letter
else if (mission == 2)
{
	int number;
	char capital=0;
	printf("Enter ASCII code of some character:\n");
	scanf("%d", &number);
	// Handles input of ASCII code between a and z
	if ((number >= 'a') && (number <= 'z'))
	{
		printf("The number is: %d \n", number);
		printf("The letter is: %c \n", number);
		// Find the big letter by subtracting the difference between a and A from the number
		capital = number - ('a' - 'A');
		printf("The capital letter is: %c \n", capital);
	}
	// Handles input of ASCII code between A and Z
	else if ((number >= 'A') && (number <= 'Z'))
	{
		char letter;
		printf("The number is: %d \n", number);
		// Find the small letter by adding the difference between a and A from the number
		letter = number + ('a' - 'A');
		printf("The letter is: %c \n", letter);
		printf("The capital letter is: %c \n", number);
	}
	// Handles input does not have an English letter in the ASCII table
	else
	{
		printf("The number is: %d \n", number);
	}
}
//Receiving a decimal number and printing the number to the left and the right of the decimal point, and the sum of the digits in odd places
else if (mission == 3)
{
	float number;
	int integer;
	float fractional;
	int newFractional;
	int newNumber;
	int digit1;
	int digit3;
	int digit4;
	int digit6;
	int digits;
	printf("Enter a real number:\n");
	scanf("%f", &number);
	// Rounding the number up
	number += 0.0005;
	// Printing the number to the left of the decimal point
	integer = (int)number;
	printf("The integer part: %d \n", integer);
	// Printing the number to the right of the decimal point
	fractional = number - integer;
	fractional *= 1000;
	newFractional = (int)fractional;
	printf("The fractional part: %d \n", newFractional);
	// Printing the sum of the digits in odd places
	number = number * 1000;
	newNumber = (int)number;
	digit1 = newNumber / 100000;
	digit3 = (newNumber / 1000) % 10;
	digit4 = (newNumber / 100) % 10;
	digit6 = newNumber % 10;
	digits = digit1 + digit3 + digit4 + digit6;
	printf("The sum of odd digits: %d \n", digits);
}
// Receiving two integers and action of the crazy calculator and performing the action on the input
else if (mission == 4)
{
	int number1;
	int number2;
	char action;
	int result;
	float newNumber1;
	float newNumber2;
	float newResult;
	printf("Welcome to the crazy calculator:\n");
	printf("Enter two numbers:\n");
	scanf("%d%d", &number1, &number2);
	printf("Enter an action from: {! @ # \\ %%}:\n");
	scanf(" %c", &action);
	// Create Calculator
	switch (action)
	{
		// addition
		case '!':
			result = number1 + number2;
			printf("%d %c %d = %d\n", number1, action, number2, result);
			break;
		// subtraction
		case '@':
			result = number1 - number2;
			printf("%d %c %d = %d\n", number1, action, number2, result);
			break;
		// Multiplication 
		case '#':
			result = number1 * number2;
			printf("%d %c %d = %d\n", number1, action, number2, result);
			break;
		// Divide with residual
		case '\\':
			newNumber1 = (float)number1;
			newNumber2 = (float)number2;
			newResult = newNumber1 / newNumber2;
			printf("%d %c %d = %f\n", number1, action, number2, newResult);
			break;
		// Divide without residual
		case '%':
			result = number1 / number2;
			printf("%d %c %d = %d\n", number1, action, number2, result);
			break;
		// Treatment Action input not appear in the calculator
		default:
			printf("The action '%c' is not \"good\" for me!\n", action);
	}
}
// Create a quadratic equation by input of 3 integers
else if (mission == 5)
{
	int a, b, c;
	printf("Enter three coefficients:\n");
	scanf("%d %d %d", &a, &b, &c);
	// Case of a positive
	if (a > 0)
		// Hide the 1
		if (a == 1)
			printf("x^2");
		else
			printf("%dx^2", a);
	// Case of a negative
	if (a < 0)
		// Hide the -1
		if (a == -1)
			printf("-x^2");
		else
			printf("%dx^2", a);
	// Case of b positive
	if (b > 0)
	{
		// Hide the 1 and start without +
		if ((a == 0) && (b == 1))
			printf("x");
		// Start without +
		if ((a == 0) && (b != 1))
			printf("%dx", b);
		else
			printf("+%dx", b);
	}
	// Case of b negative
	if (b < 0)
		// Hide the -1
		if (b == -1)
			printf("-x");
		else
			printf("%dx", b);
	// Case of c positive
	if (c > 0)
	{
		// Start without +
		if (a == 0 && b == 0)
			printf("%d = 0\n", c);
		else
			printf("+%d = 0\n", c);
	}
	// Case of c negative
	if (c < 0)
		printf("%d = 0\n", c);
	// Down line
	if ((c == 0) || (c == 0) && (b == 0))
		// Case of 0 = 0
		if ((a == 0) && (b == 0) && (c == 0))
			printf("0 = 0\n");
		else
			printf(" = 0\n");
}
// Error message for input not 1-5
else
	printf("Error\n");
return 0;
}