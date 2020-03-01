/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex2.c
******************************************/
#include <stdio.h>
#include <math.h>
// The up limit of unsigned long int
#define MAX 0xffffffff
/******************************************
* Function Name: Collatz
* Input: long int number
* Output: void 
* Function Operation: The function recieves a number and prints series of numbers according
to the rules of Collatz Conjecture.
The function also prints the number of steps that it uses in the current run and overall
******************************************/
void Collatz(long int n)
{
	int steps = 0;

	/* I used a static variable because I needed a variable that won't restart after one run,
	to count the total steps the function used */
	static int totalSteps;
	// In case of 1 input the function doesn't print an arrow
	if (n == 1) 
		printf("%ld", n);
	// In case of other input the function prints an arrow
	else
		printf("%ld->", n);

	/* A loop that applies the Collatz Conjecture - if the number is even, the function divides it
	in 2, if it's odd, the function multiplies it by 3 and adds 1.
	the loop ends when the number equal to 1 */
	while (n != 1)
	{
		// If the number is even, the function divides it in 2
		if (n % 2 == 0)
			n /= 2;
		// If the number is odd, the function multiplies it by 3 and adds 1
		else
			n = (3 * n) + 1;
		// Counting the steps that the function uses in the current run
		steps++;
		// Printing an arrow after any number except from 1
		if (n != 1)
			printf("%ld->", n);
		else
			printf("%ld", n);
		// Counting the steps that the function uses overall
		totalSteps++;
	}
	printf("\n");
	printf("num of steps: %d\n", steps);
	printf("total num of steps: %d\n", totalSteps);
	return;
}
/******************************************
* Function Name: CollatzNoPrint
* Input: long int number
* Output: unsigned long int
* Function Operation: The function recieves a number and checks if the Collatz Conjecture
is exists for it in this way - if the steps that the function used is less than the up limit of 
unsigned long int, the function return the steps' number, else, the function will stop the checking and return 0
******************************************/
unsigned long int CollatzNoPrint(long int n)
{
	int steps = 0;

	/* A loop that applies the Collatz Conjecture - if the number is even, the function divides it
	in 2, if it's odd, the function multiplies it by 3 and adds 1.
	the loop ends when the number equal to 1 */
	while (n != 1)
	{
		// If the number is even, the function divides it in 2
		if (n % 2 == 0)
			n /= 2;
		// If the number is odd, the function multiplies it by 3 and adds 1
		else
			n = (3 * n) + 1;
		// Counting the steps that the function uses in the current run
		steps++;
	}

	/* if te steps that the function used is less than the up limit of unsigned long int,
	the function return the steps' number */
	if (steps < MAX)
		return steps;
	// else, the function will stop the checking and return 0
	else
		return 0;
}
/******************************************
* Function Name: ProofCollatzUntill
* Input: long int numbers
* Output: void
* Function Operation: The function checks with the CollatzNoPrint function all the numbers
from 1 to the input of the function, and prints the steps' number for each number. If a number stops the
CollatzNoPrint function, the ProofCollatzUntill function will print "you might wanna check (number) and win 500$"
******************************************/
void ProofCollatzUntill(long int n)
{
	int i;
	long int check;
	// In case of 0 or negative input numbers the function returns nothing
	if (n <= 0)
		return;
	printf("passed: 1 (num of steps: 0)\n");
	/* A loop that checks with the CollatzNoPrint function all the numbers from 1 to the input of the function */
	for (i = 2; i < n; i++)
	{
		check = CollatzNoPrint((long int)i);
		// for steps return, the function prints the steps' number for each number
		if (check != 0)
			printf("passed: %d (num of steps: %lu)\n", i, check);
		// for 0 return, the function prints "you might wanna check (number) and win 500$"
		else
			printf("you might wanna check %d and win 500$ :)\n", i);
	}
	return;
}
/******************************************
* Function Name: Fermat
* Input: int power and int blocker
* Output: void
* Function Operation: The function prints all the triplets a^n + b^n = c^n between 1-stop
(first sorted by a and then by b). If there is no triplet, the function prints "meh :("
******************************************/
void Fermat(int n, int stop)
{
	int a;
	int b;
	int c;
	int flag = 0;
	// A loop that passes over each a from 1 to stop
	for (a = 1; a < stop; a++)
	{
		// A loop that passes over each b from a to stop (in order to sort first by a and then by b)
		for (b = a; b < stop; b++)
		{
			// A loop that passes over each c from 1 to stop
			for (c = 1; c < stop; c++)
			{
				// The function prints all the triplets a^n + b^n = c^n 
				if (pow(a, n) + pow(b, n) == pow(c, n))
				{
					printf("Eureka! %d^%d + %d^%d = %d^%d\n", a, n, b, n, c, n);
					// The flag checks if we went into the loop
					flag = 1;
				}
			}
		}
	}
	// If there is no triplet, (That is, if we did not went into the loop) the function prints "meh :("
	if (flag == 0)
		printf("meh :(\n");
	return;
}
/******************************************
* Function Name: Complementary
* Input: long int number and int modulo3
* Output: int
* Function Operation: The function works in the same way as modulo 3 and checks if the input is divided
by 3 or not - if it returns 0, the number is divided by 3. Else, it's not.
******************************************/
int Complementary(long int n, int modulo3)
{
	// when the number is 0 the function end its action and return modulo3
	if (n == 0)
		return modulo3;

	/* if the digit of the number equal to 1, it returns values in accordance to modulo3 - 1 for 0,
	2 for 1 and 0 for 2 */
	if (n % 10 == 1)
	{
		if (modulo3 == 0)
			modulo3 = 1;
		else if (modulo3 == 1)
			modulo3 = 2;
		else if (modulo3 == 2)
			modulo3 = 0;
	}

	/* if the digit of the number equal to 2, it returns values in accordance to modulo3 - 2 for 0,
	0 for 1 and 1 for 2 */
	 else if (n % 10 == 2)
	{
		if (modulo3 == 0)
			modulo3 = 2;
		else if (modulo3 == 1)
			modulo3 = 0;
		else if (modulo3 == 2)
			modulo3 = 1;
	}

	/* if the digit of the number equal to 3, it returns values in accordance to modulo3 - 0 for 0,
	1 for 1 and 2 for 2 */
	 else if (n % 10 == 3)
	 {
		 if (modulo3 == 0)
			 modulo3 = 0;
		 else if (modulo3 == 1)
			 modulo3 = 1;
		 else if (modulo3 == 2)
			 modulo3 = 2;
	 }
	// As long as the number is different from 0, the function divides the number by 10 and checks the next digit
	return Complementary(n / 10, modulo3);
}
/******************************************
* Function Name: IsDividedBy3Rec
* Input: long int number
* Output: int
* Function Operation: The function returns if the input is divided by 3 or not with help from Complementary function
******************************************/
int IsDividedBy3Rec(long int n)
{
	// If modulo3 = 0 the function returns 1 which means the number is divided by 3
	if (Complementary(n, 0) == 0)
		return 1;
	// Else, the function returns 0 which means the number isn't divided by 3
	else
		return 0;
}
/******************************************
* Function Name: SumDigits
* Input: long int number
* Output: int
* Function Operation: The function calculates the sum of the digits of the number input 
******************************************/
int SumDigits(long int n)
{
	int sum = 0;
	// As long as the number is not 0, the function separates and connects its digits
	while (n != 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	// when the number is 0 the function end its action and return the sum of the digits
	return sum;
}
/******************************************
* Function Name: IsDividedBy3Iter
* Input: long int number
* Output: int
* Function Operation: The function returns if the input is divided by 3 or not with help from SumDigits function
******************************************/
int IsDividedBy3Iter(long int n)
{

	/* The function calculates the sum of the digits of the number (with help from SumDigits function) 
	until the sum will be less than 10 */
	while (n >= 10)
		n = SumDigits(n);
	// if the digits' sum of the number is 3, 6 or 9, the function returns 1 which means the number is divided by 3
	if ((n == 3) || (n == 6) || (n == 9))
		return 1;
	// if not, the function returns 0 which means the number is not divided by 3
	else
		return 0;
}
/******************************************
* Function Name: FindCommonDigit
* Input: 2 long int numbers 
* Output: int
* Function Operation: The function recieves 2 numbers and checks if they have same digit.
If they haven't, the function returns -1. Else, the function returns the most right digit.
******************************************/
int FindCommonDigit(long int n1, long int n2)
{
	// If one of the numbers is 0 and the function didn't find they had same digit, the function returns -1
	if ((n1 == 0) || (n2 == 0))
		return -1;
	// Else, the function returns the most right digit.
	else
	{
		// If the last digit of n1 is the same as the last digit of n2, the function returns it
		if ((n1 % 10) == (n2 % 10))
			return n1 % 10;

		/* If it's not the same, the function check which of the last digits' numbers is bigger and
		divides its number by 10 */
		else
		{
			if ((n1 % 10) > (n2 % 10))
				n1 /= 10;
			else
				n2 /= 10;
			// As long as the number is different from 0, the function checks each digit
			return FindCommonDigit(n1, n2);
		}
	}
}
/******************************************
* Function Name: CountDigit
* Input: long int number and int number
* Output: int
* Function Operation: The function recieves a number and a digit and returns the number
of times the digit appears in the number
******************************************/
int CountDigit(long int n, int d)
{
	// when the number is 0 the function end its action
	if (n == 0)
		return 0;

	/* As long as the number is different from 0, the function checks if the right digit of the number
	is the same as the input digit. If it's the same, the function returns 1, divides the number by 10 and
	checks the next digit */
	if ((n % 10) == d)
		return 1 + CountDigit(n / 10, d);
	// If it's *not* the same, the function returns 0, divides the number by 10 and checks the next digit
	else
		return 0 + CountDigit(n / 10, d);
}
/******************************************
* Function Name: PrintReverse
* Input: int number
* Output: void
* Function Operation: The function recieves a number and prints it upside down
******************************************/
void PrintReverse(long int n)
{
	// when the number is 0 the function descending line and end its action
	if (n == 0)
	{
		printf("\n");
		return;
	}
	// As long as the number is different from 0, the function separates each digit from the end and prints it 
	else
	{
		printf("%ld", n % 10);
		PrintReverse(n / 10);
		return;
	}
}