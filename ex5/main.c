/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex5.c
******************************************/
#include <stdio.h>
#include <string.h>
#include "ex5.h"
#define MAX_STUDENTS 50
#define MAX_NAME 21
#define MAX_COURSES 5
#define MAX_INPUT 201
int main ()
{
	int operation;
	char dummy;
	// printing the main menu
	printf("Please select the operation:\n");
	printf("\t0. Exit.\n");
	printf("\t1. Insert or update student grades.\n");
	printf("\t2. Delete student information.\n");
	printf("\t3. Print the student with maximal computed grade.\n");
	printf("\t4. Print all the students with their computed grades.\n");
	printf("\t5. Print the menu.\n");
	char names [MAX_STUDENTS][MAX_NAME] = { '\0' };
	char familyNames [MAX_STUDENTS][MAX_NAME] = { '\0' };
	char courses [MAX_STUDENTS][MAX_COURSES][MAX_NAME] = { '\0' };
	int grades[MAX_STUDENTS][MAX_COURSES] = { 0 };
	scanf("%d", &operation);
	// recieving the enter
	scanf("%c", &dummy);
	// when the operation is 0 the program ends
	while (operation != 0)
	{
		/* when the operation is 1 - the program inserts and updates a student, when it's 2 - the program deletes a student,
		when it's 3 - the program prints the student with maximal computed grade, when it's 4 - the program prints all the
		students with their computed grades and when it's 5 the program prints the menu */
		switch (operation)
		{
			case 1:
			{
				InsertUpdateStudent(names, familyNames, courses, grades);
				break;
			}
			case 2:
			{
				DeleteStudent(names, familyNames, courses, grades);
				break;
			}
			case 3:
			{
				FindStudentMaxGrade(names, familyNames, courses, grades);
				break;
			}
			case 4:
			{
				FindAllMaxGrade(names, familyNames, courses, grades);
				break;
			}
			case 5:
			{
				printf("Please select the operation:\n");
				printf("\t0. Exit.\n");
				printf("\t1. Insert or update student grades.\n");
				printf("\t2. Delete student information.\n");
				printf("\t3. Print the student with maximal computed grade.\n");
				printf("\t4. Print all the students with their computed grades.\n");
				printf("\t5. Print the menu.\n");
				break;
			}
			// when the user doesn't choose one of the options the program prints an error message.
			default:
			{
				printf("Error: unrecognized operation.\n");
				break;
			}
		}
		// while the operation isn't 5, the program prints a message and recievs another operation from the user
		if (operation != 5)
			printf("Select the next operation (insert 5 for complete menu).\n");
		scanf("%d", &operation);
		// recieving the enter
		scanf("%c", &dummy);
	}
return 0;
}