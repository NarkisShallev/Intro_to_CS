/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 05
*Exercise name: ex5.c
******************************************/
#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
#define MAX_NAME 21
#define MAX_COURSES 5
#define MAX_INPUT 202
/******************************************
* Function Name: ArrayMaxValue
* Input: int array
* Output: int number (The location of the student with the max value)
* Function Operation: The function goes over an array and checks its highest value
******************************************/
int ArrayMaxValue(int array[])
{
	int i;
	int max = 0;
	int student = 0;
	// A loop that passes over the array
	for (i = 0; i < MAX_STUDENTS; i++)
	{

		/* If the value inside the array is greater than the value of max - then max is equal to the value and
		the student's location is updates */
		if (array[i] > max)
		{
			max = array[i];
			student = i;
		}
	}
	// The function returns the location of the student with the max value
	return student;
}
/******************************************
* Function Name: CoursesNum
* Input: 2 int array and 1 char array
* Output: void
* Function Operation: cout the number of courses each student have
******************************************/
void CoursesNum(int nums[MAX_STUDENTS], int grades[MAX_STUDENTS][MAX_COURSES], char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME])
{
	int i;
	int j;
	int num;
	// A loop that goes through all the students
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		num = 0;
		// A loop that goes through the courses and adds 1 to num on each non-empty course
		for (j = 0; (j < MAX_COURSES) && (courses[i][j][0] != '\0'); j++)
		{
			num += 1;
		}
		// The calculation for each student is saved in the array
		nums[i] = num;
	}
}
/******************************************
* Function Name: SumGrade
* Input: 2 int array and 1 char array
* Output: void
* Function Operation: Calculates the sum of grades for each student
******************************************/
void SumGrade(int sums[MAX_STUDENTS], int grades[MAX_STUDENTS][MAX_COURSES], char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME])
{
	int i;
	int j;
	int sum;
	// A loop that goes through all the students
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		sum = 0;
		// A loop that goes through the courses and connects the grade of all courses
		for (j = 0; (j < MAX_COURSES) && (courses[i][j][0] != '\0'); j++)
		{
			sum += grades[i][j];
		}
		// The calculation for each student is saved in the array
		sums[i] = sum;
	}
}
/******************************************
* Function Name: MinGrade
* Input: 2 int array and 1 char array
* Output: void
* Function Operation: Calculates the lowest grade for each student
******************************************/
void MinGrade(int mins[MAX_STUDENTS], int grades[MAX_STUDENTS][MAX_COURSES], char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME])
{
	int i;
	int j;
	int min;
	// A loop that goes through all the students
	for (i = 0; (i < MAX_STUDENTS) && (courses[i][0][0] != '\0'); i++)
	{
		min = 100;

		/* The loop passes all the grades of the student and compares them to min, if there is a grade that
		is smaller than min then min equals it*/
		for (j = 0; (j < MAX_COURSES) && (courses[i][j][0] != '\0'); j++)
		{
			if (grades[i][j] < min)
				min = grades[i][j];
		}
		// The calculation for each student is saved in the array
		mins[i] = min;
	}
}
/******************************************
* Function Name: MaxGrade
* Input: 2 int array and 1 char array
* Output: void
* Function Operation: Calculates the highest grade of each student
******************************************/
void MaxGrade(int maxs[MAX_STUDENTS], int grades[MAX_STUDENTS][MAX_COURSES], char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME])
{
	int i;
	int j;
	int max;
	// A loop that goes through all the students
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		max = 0;

		/* The loop passes all the grades of the student and compares them to max, if there is a grade that
		is bigger than max then max equals it*/
		for (j = 0; (j < MAX_COURSES) && (courses[i][j][0] != '\0'); j++)
		{
			if (grades[i][j] > max)
				max = grades[i][j];
		}
		// The calculation for each student is saved in the array
		maxs[i] = max;
	}
}
/******************************************
* Function Name: AverageGrade
* Input: 2 int array and 1 char array
* Output: void
* Function Operation: Calculates the average grade of each student
******************************************/
void AverageGrade(int averages[MAX_STUDENTS], int grades[MAX_STUDENTS][MAX_COURSES],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME])
{
	int average = 0;
	int i;
	int j;
	int sum;
	int flag;
	// A loop that goes through all the students
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		sum = 0;
		flag = 0;
		// A loop that goes through the courses, connects the grade of all courses and changes the flag to 1
		for (j = 0; (j < MAX_COURSES) && (courses[i][j][0] != '\0'); j++)
		{
			sum += grades[i][j];
			flag = 1;

		}
		// if flag = 1, the function divides the sum into the number of courses
		if (flag == 1)
		{
			average = sum / j;
			// The calculation for each student is saved in the array
			averages[i] = average;
		}
	}
}
/******************************************
* Function Name: FindAllMaxGrade
* Input: 3 char array and 1 int  array
* Output: void
* Function Operation: Calculates for *all students* the maximum grade that the user requests and prints them
******************************************/
void FindAllMaxGrade(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES])
{
	char method;
	char dummy;
	// The menu will print as long as there are students in the array
	if (names[0][0] != '\0')
	{
		printf("Please select the aggregation method:\n");
		printf("\ta. Average grade.\n");
		printf("\tb. Maximal grade.\n");
		printf("\tc. Minimal grade.\n");
		printf("\td. Sum.\n");
		printf("\te. Count.\n");
		printf("\t0. Return the main menu.\n");
		scanf("%c", &method);
		scanf("%c", &dummy);
	}
	// Otherwise, an error message will be printed
	else
		printf("Error: there are no students.\n");
	int averages[MAX_STUDENTS] = { 0 };
	int sums[MAX_STUDENTS] = { 0 };
	int nums[MAX_STUDENTS] = { 0 };
	int maxs[MAX_STUDENTS] = { 0 };
	int mins[MAX_STUDENTS] = { 0 };

	/* when the method is a the program will calculate the average grade, when it's b the program will
	calculate the maximum grade, when it's c the program will calculate the minimum grade, when it's
	d the program will calculate the sum of the grades, when it's e the program will calculate the number of courses
	and when it's 0 the program return the main menu */
	switch (method)
	{
	case 'a':
	{
		// calculate the average grade of each student and print them
		AverageGrade(averages, grades, courses);
		for (int i = 0; (i < MAX_STUDENTS) && (courses[i][0][0] != '\0'); i++)
		{
			printf("%s %s, %d\n", names[i], familyNames[i], averages[i]);
		}
		break;
	}
	case 'b':
	{
		// calculate the maximum grade of each student and print them
		MaxGrade(maxs, grades, courses);
		for (int i = 0; (i < MAX_STUDENTS) && (courses[i][0][0] != '\0'); i++)
		{
			printf("%s %s, %d\n", names[i], familyNames[i], maxs[i]);
		}
		break;
	}
	case 'c':
	{
		// calculate the minimum grade of each student and print them
		MinGrade(mins, grades, courses);
		for (int i = 0; (i < MAX_STUDENTS) && (courses[i][0][0] != '\0'); i++)
		{
			printf("%s %s, %d\n", names[i], familyNames[i], mins[i]);
		}
		break;
	}
	case 'd':
	{
		// calculate the sum of the grades of each student and print them
		SumGrade(sums, grades, courses);
		for (int i = 0; (i < MAX_STUDENTS) && (courses[i][0][0] != '\0'); i++)
		{
			printf("%s %s, %d\n", names[i], familyNames[i], sums[i]);
		}
		break;
	}
	case 'e':
	{
		// calculate the number of courses of each student and print them
		CoursesNum(nums, grades, courses);
		for (int i = 0; (i < MAX_STUDENTS) && (courses[i][0][0] != '\0'); i++)
		{
			printf("%s %s, %d\n", names[i], familyNames[i], nums[i]);
		}
		break;
	}
	// the program return the main menu
	case '0':
	{
		break;
	}
	}
}
/******************************************
* Function Name: FindStudentMaxGrade
* Input: 3 char array and 1 int  array
* Output: void
* Function Operation: Calculates the maximum grade that the user requests and prints the student with the highest score
******************************************/
void FindStudentMaxGrade(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES])
{
	char method;
	char dummy;
	// The menu will print as long as there are students in the array
	if (names[0][0] != '\0')
	{
		printf("Please select the aggregation method:\n");
		printf("\ta. Average grade.\n");
		printf("\tb. Maximal grade.\n");
		printf("\tc. Minimal grade.\n");
		printf("\td. Sum.\n");
		printf("\te. Count.\n");
		printf("\t0. Return the main menu.\n");
		scanf("%c", &method);
		scanf("%c", &dummy);
	}
	// Otherwise, an error message will be printed
	else
		printf("Error: there are no students.\n");
	int averages[MAX_STUDENTS] = { 0 };
	int sums[MAX_STUDENTS] = { 0 };
	int nums[MAX_STUDENTS] = { 0 };
	int maxs[MAX_STUDENTS] = { 0 };
	int mins[MAX_STUDENTS] = { 0 };

	/* when the method is a the program will calculate the average grade, when it's b the program will
	calculate the maximum grade, when it's c the program will calculate the minimum grade, when it's
	d the program will calculate the sum of the grades, when it's e the program will calculate the number of courses
	and when it's 0 the program return the main menu */
	switch (method)
	{
	case 'a':
	{
		// calculate the average grade of each student 
		AverageGrade(averages, grades, courses);
		// Checks which student has the highest calculated grade
		int i = ArrayMaxValue(averages);
		printf("%s %s, %d\n", names[i], familyNames[i], averages[i]);
		break;
	}
	case 'b':
	{
		// calculate the maximum grade of each student
		MaxGrade(maxs, grades, courses);
		// Checks which student has the highest calculated grade and prints it
		int i = ArrayMaxValue(maxs);
		printf("%s %s, %d\n", names[i], familyNames[i], maxs[i]);
		break;
	}
	case 'c':
	{
		// calculate the minimum grade of each student
		MinGrade(mins, grades, courses);
		// Checks which student has the highest calculated grade nd prints it
		int i = ArrayMaxValue(mins);
		printf("%s %s, %d\n", names[i], familyNames[i], mins[i]);
		break;
	}
	case 'd':
	{
		// calculate the sum of the grades of each student
		SumGrade(sums, grades, courses);
		// Checks which student has the highest calculated grade nd prints it
		int i = ArrayMaxValue(sums);
		printf("%s %s, %d\n", names[i], familyNames[i], sums[i]);
		break;
	}
	case 'e':
	{
		// calculate the number of courses of each student
		CoursesNum(nums, grades, courses);
		// Checks which student has the highest calculated grade nd prints it
		int i = ArrayMaxValue(nums);
		printf("%s %s, %d\n", names[i], familyNames[i], nums[i]);
		break;
	}
	// the program return the main menu
	case '0':
	{
		break;
	}
	}
}
/******************************************
* Function Name: CharToInt
* Input: 1 char array and int number
* Output: int
* Function Operation: Converts the grades from char to int
******************************************/
int CharToInt(char array[][MAX_INPUT], int i)
{
	// If there is only one digit in the grade, it is converted to int
	if (strlen(array[i]) == 1)
		return (int)(array[i][0] - '0');

	/* If there is 2 digits in the grade, the function converts the integer digit to int and multiply it by 10.
	Then, convert the unity digit and add it to the result */
	if (strlen(array[i]) == 2)
		return (int)((array[i][0] - '0') * 10 + (array[i][1] - '0'));

	/* If there is 3 digits in the grade, the function converts the hundred's digit to int and multiply it by 100.
	Then. converts the integer digit to int and multiply it by 10. Then, convert the unity digit and add it to the result */
	if (strlen(array[i]) == 3)
		return (int)((array[i][0] - '0') * 100 + (array[i][1] - '0') * 10 + (array[i][2] - '0'));
}
/******************************************
* Function Name: IsGradeCheck
* Input: int array and int number
* Output: 0 or 1
* Function Operation: Checks whether the number is between 0 and 100.
******************************************/
int IsGradeCheck(int array[], int i)
{
	// Checks whether the number is between 0 and 100. If so, the function returns 1. If not, it returns 0.
	if ((array[i] >= 0) && (array[i] <= 100))
		return 1;
	else
		return 0;
}
/******************************************
* Function Name: IsLenCheck
* Input: char array that we want to check
* Output: int 1 or 0
* Function Operation: Checks that the array does not exceed the number of characters we have defined
******************************************/
int IsLenCheck(char array[])
{
	// Checks if the array exceeds the number of characters we have defined. If so, the function returns 0.
	if (strlen(array) > MAX_NAME)
		return 0;
	// Else, the function returns 1
	else
		return 1;
}
/******************************************
* Function Name: IsCharCheck
* Input: char array that we want to check
* Output: int 1 or 0
* Function Operation: Check whether the characters in the array contain letters and spaces only
******************************************/
int IsCharCheck(char array[])
{
	// Check that the name is not empty
	if (strcmp(array, "") == 0)
		return 0;
	// A loop that goes over all the characters in the array
	for (char i = 0; i < strlen(array); i++)
	{

		/* Check whether the characters in the array contain letters and spaces only. If so, the function continues
		the test on all the characters in the array and finally returns 1 */
		if (((array[i] >= 'a') && (array[i] <= 'z')) || ((array[i] >= 'A') && (array[i] <= 'Z')) || (array[i] == ' '))
			continue;
		// If not, the function returns 0. 
		else
			return 0;
	}
	return 1;
}
/******************************************
* Function Name: IsNameCheck
* Input: char array that we want to check
* Output: int 1 or 0
* Function Operation: Sending an array to functions that check the integrity of the array - in terms of
length and characters
******************************************/
int IsNameCheck(char array[])
{
	// If the test of the functions returns normal - the function returns 1
	if ((IsCharCheck(array) == 1) && (IsLenCheck(array) == 1))
		return 1;
	//Else, the function returns 0
	else
		return 0;
}
/******************************************
* Function Name: SplitInput
* Input: A char array with the row input, an int index to start the separation, a char index to stop the separation,
and a dummy char array to save the separated part into it
* Output: int number (The location in the array we reached)
* Function Operation: Separates the large array into different separate parts
******************************************/
int SplitInput(char arrayin[], int start, char stop, char arrayout[])
{
	int i = start;
	int j;
	// Skips the spaces that may be at the beginning of the input
	while (arrayin[i] == ' ')
		i++;
	// Separating part of the input from start to stop or from start to '\0'
	for (i, j = 0; (arrayin[i] != stop) && (arrayin[i] != '\0'); i++, j++)
	{
		arrayout[j] = arrayin[i];
	}
	// return the location in the array we reached
	return i++;
}
/******************************************
* Function Name: SearchStudent
* Input: 4 char array
* Output: int
* Function Operation: Checks whether a student is in the array or not
******************************************/
int SearchStudent(char names[MAX_STUDENTS][MAX_NAME], char nameArray[], char familyNames[MAX_STUDENTS][MAX_NAME],
	char familyArray[])
{
	int flag = 0;
	// A loop passes over the students
	for (int i = 0; i < MAX_STUDENTS; i++)
	{

		/* If the student's name is in The array, The function checks whether its family name is equal to the student's
		last name in the array. If so, the function returns its place in the array and turns the flag to 1 */
		if (strcmp(names[i], nameArray) == 0)
		{
			if (strcmp(familyNames[i], familyArray) == 0)
			{
				flag = 1;
				return i;
			}
		}
	}
	// If the flag is equal to 0, the student is not in an array and the function returns -1
	if (flag == 0)
		return -1;
}
/******************************************
* Function Name: CheckLocation
* Input: 4 char arrays and 2 int ptr
* Output: int
* Function Operation: Checks the location where the input needs to go in relation to existing data in the array
******************************************/
int CheckLocation(char names[MAX_STUDENTS][MAX_NAME], char demoNames[MAX_INPUT], char familyNames[MAX_STUDENTS][MAX_NAME],
	char demoFamilyNames[MAX_INPUT], int *big, int *end)
{
	int flag = 0;
	// A loop passes over the students
	for (int i = 0; i < MAX_STUDENTS; i++)
	{

		/* If there is a name in the array larger than the name in the input, the name will be inserted after
		the large name in the array (big will be the position of the name in the array) */
		if (strcmp(names[i], demoNames) > 0)
		{
			*big = i;
			flag = 1;
			break;
		}

		/* If there is a name in the array equal to the name in the input, the function checks which of their
		family names are larger. If the student's family name in the input is greater, it will be inserted after that
		in the array. If not, before (big will be the position of the family name in the array) */
		else if (strcmp(names[i], demoNames) == 0)
		{
			for (int j = 0; j < MAX_STUDENTS; j++)
			{
				if (strcmp(familyNames[j], demoFamilyNames) > 0)
					*big = j;
				flag = 2;
				break;
			}
		}

		/* If the name on the input is smaller than the name in the array, the name will be inserted at the end of the
		array (end will be the first empty cell in the array) */
		else
		{
			if (names[i][0] == '\0')
			{
				*end = i;
				flag = 3;
				break;
			}
		}
	}
	return flag;
}
/******************************************
* Function Name: SortStudents
* Input: 7 char arrays and 2 int arrays
* Output: void
* Function Operation: Sorting the students who are inserted in the array according to lexicographic order
******************************************/
void SortStudents(char names[MAX_STUDENTS][MAX_NAME], char demoNames[MAX_INPUT], char familyNames[MAX_STUDENTS][MAX_NAME],
	char demoFamilyNames[MAX_INPUT], char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], char demoCourses[MAX_COURSES][MAX_INPUT],
	int grades[MAX_STUDENTS][MAX_COURSES], int demoGradesInt[MAX_COURSES], char demoGradesChar[MAX_COURSES][MAX_INPUT])
{
	int big = 0;
	int end = 0;
	// Checking where the student needs the conference in relation to the rest of the students
	int flag = CheckLocation(names, demoNames, familyNames, demoFamilyNames, &big, &end);
	// If there is a student larger than the student input 
	if ((flag == 1) || (flag == 2))
	{
		// All the students will move one cell to the right
		for (int i = MAX_STUDENTS - 1; i >= big; i--)
		{
			strcpy(names[i], names[i - 1]);
			strcpy(familyNames[i], familyNames[i - 1]);
			for (int j = 0; j < MAX_COURSES; j++)
			{
				strcpy(courses[i][j], courses[i - 1][j]);
				grades[i][j] = grades[i - 1][j];
			}
		}
		// The student will be inserted in front of the larger student
		strcpy(names[big], demoNames);
		strcpy(familyNames[big], demoFamilyNames);
		for (int k = 0; k < MAX_COURSES; k++)
		{
			strcpy(courses[big][k], demoCourses[k]);
			grades[big][k] = demoGradesInt[k];
		}
	}

	/* If the student on the input is larger than all the students in the array, The student will be placed
	in the first empty space in the array*/
	if (flag == 3)
	{
		strcpy(names[end], demoNames);
		strcpy(familyNames[end], demoFamilyNames);
		for (int i = 0; i < MAX_COURSES; i++)
		{
			strcpy(courses[end][i], demoCourses[i]);
			grades[end][i] = demoGradesInt[i];
		}
	}
}
/******************************************
* Function Name: InsertStudent
* Input: 7 char arrays and 2 int arrays
* Output: void
* Function Operation:
******************************************/
void InsertStudent(char names[MAX_STUDENTS][MAX_NAME], char demoNames[MAX_INPUT], char familyNames[MAX_STUDENTS][MAX_NAME],
	char demoFamilyNames[MAX_INPUT], char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], char demoCourses[MAX_COURSES][MAX_INPUT],
	int grades[MAX_STUDENTS][MAX_COURSES], int demoGradesInt[MAX_COURSES], char demoGradesChar[MAX_COURSES][MAX_INPUT])
{
	// If the array is empty, the new student will be placed in the first place in each array and a message will be printed
	if (strcmp(names[0], "\0") == 0)
	{
		strcpy(names[0], demoNames);
		strcpy(familyNames[0], demoFamilyNames);
		for (int i = 0; i < MAX_COURSES; i++)
		{
			strcpy(courses[0][i], demoCourses[i]);
			grades[0][i] = demoGradesInt[i];
		}
		printf("Student \"%s %s\" added.\n", names[0], familyNames[0]);
	}
	else
	{

		/* Otherwise, provided that there is space in the array, the student will be entered into the array using a
		function and a message will be printed to the user */
		if (strcmp(names[MAX_STUDENTS - 1], "\0") == 0)
		{
			SortStudents(names, demoNames, familyNames, demoFamilyNames, courses, demoCourses, grades, demoGradesInt,
				demoGradesChar);
			printf("Student \"%s %s\" added.\n", demoNames, demoFamilyNames);
		}
		// If there is no space in the array, a message will be printed to the user
		else
			printf("Error: there is no more space.");
	}
}
/******************************************
* Function Name: UpdateStudent
* Input: 6 char arrays and 2 int arrays
* Output: void
* Function Operation: Updating courses and grades for students who are in the system
******************************************/
void UpdateStudent(char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], char demoCourses[MAX_COURSES][MAX_INPUT],
	int grades[MAX_STUDENTS][MAX_COURSES], int demoGradesInt[MAX_COURSES], char names[MAX_STUDENTS][MAX_NAME],
	char demoNames[MAX_INPUT], char familyNames[MAX_STUDENTS][MAX_NAME], char demoFamilyNames[MAX_INPUT])
{
	int flag = 0;
	// Checking the student's position in the array
	int i = SearchStudent(names, demoNames, familyNames, demoFamilyNames);

	// If there is a course in the input that is already in the system - the grade of the course's grade is updated 
	for (int k = 0; (k < MAX_COURSES) && (demoCourses[k][0] != '\0'); k++)
	{
		flag = 0;
		for (int j = 0; j < MAX_COURSES; j++)
		{
			if (strcmp(courses[i][j], demoCourses[k]) == 0)
			{
				grades[i][j] = demoGradesInt[k];
				flag = 1;
				break;
			}
		}
		// If the course does not exist, it will be placed in the first empty position in the array
		if (flag == 0)
		{
			for (int j = 0; j < MAX_COURSES; j++)
			{
				if (strcmp(courses[i][j], "\0") == 0)
				{
					for (int m = 0; m < MAX_COURSES - 1; m++)
					{
						strcpy(courses[i][j], demoCourses[k]);
						grades[i][j] = demoGradesInt[k];
						flag = 1;
						break;
					}
				}
				// After an empty place was found and the student was put in, break the loop
				if (flag == 1)
				{
					break;
				}
			}
		}
	}
	// Prints a message to the user about the operation
	if (flag = 1)
	{
		printf("Student \"%s %s\" updated.\n", names[i], familyNames[i]);
		return;
	}
	else
		printf("Error: invalid name or grade.\n");
}
/******************************************
* Function Name: DeleteStudent
* Input: 3 char arrays and 1 int array
* Output: void
* Function Operation: Receives a row from the user with the name and family name of the student who he want to delete.
Checks whether the student exists in the array - if so, deletes it, if not - prints an error message to the user
******************************************/
void DeleteStudent(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES])
{
	char deleteStudentInput[MAX_INPUT] = { '\0' };
	char deleteName[MAX_INPUT] = { '\0' };
	char deleteFamilyName[MAX_INPUT] = { '\0' };
	int start = 0;
	// Receiving a line with the details of the student the user wants that will be deleted
	fgets(deleteStudentInput, MAX_INPUT, stdin);
	// Separates the first name into a dummy array
	start = SplitInput(deleteStudentInput, start, ' ', deleteName);
	// Checks the integrity of the first name. If the test returns with 0, the user receives an error message.
	if (IsNameCheck(deleteName) == 0)
	{
		printf("Error: invalid name.\n");
		return 0;
	}
	// Separates the family name into a dummy array
	start = SplitInput(deleteStudentInput, start, '\n', deleteFamilyName);
	// Checks the integrity of the family name. If the test returns with 0, the user receives an error message.
	if (IsNameCheck(deleteFamilyName) == 0)
	{
		printf("Error: invalid name.\n");
		return 0;
	}
	// Check whether the student exists or does not exist in the system
	int i = SearchStudent(names, deleteName, familyNames, deleteFamilyName);
	// If it does not exist, an error message will be printed
	if (i == -1)
		printf("Error: student name does not exist.\n");
	// Otherwise, the program will delete the student
	else
	{

		/* The program moves all the students in all arrays one cell to the left until they crush the student we want delete */
		for (int j = i + 1; j < MAX_STUDENTS; j++)
		{
			strcpy(names[j - 1], names[j]);
			strcpy(familyNames[j - 1], familyNames[j]);
			for (int k = 0; k < MAX_COURSES; k++)
			{
				strcpy(courses[j - 1][k], courses[j][k]);
				grades[j - 1][k] = grades[j][k];
			}
		}
		// Print a message that the student has deleted
		printf("Student \"%s %s\" deleted.\n", deleteName, deleteFamilyName);
	}
}
/******************************************
* Function Name: InsertUpdateStudent
* Input: 3 char arrays and 1 int array
* Output:int
* Function Operation: Receives a row with student data from the user. Divides the row into 4 arrays using different
functions. Checks whether the student exists in the array (by help of a function) - if he exists, updates the grades
and courses of that student, if none exists - inserts the student (as long as there is place in the array)
******************************************/
int InsertUpdateStudent(char names[MAX_STUDENTS][MAX_NAME], char familyNames[MAX_STUDENTS][MAX_NAME],
	char courses[MAX_STUDENTS][MAX_COURSES][MAX_NAME], int grades[MAX_STUDENTS][MAX_COURSES])
{
	char studentInput[MAX_INPUT] = { '\0' };
	char demoNames[MAX_INPUT] = { '\0' };
	char demoFamilyNames[MAX_INPUT] = { '\0' };
	char demoCourses[MAX_COURSES][MAX_INPUT] = { '\0' };
	char demoGradesChar[MAX_COURSES][MAX_INPUT] = { '\0' };
	int demoGradesInt[MAX_COURSES] = { 0 };
	int start = 0;
	// Receiving a line with the details of the student from the user
	fgets(studentInput, MAX_INPUT, stdin);
	// Separates the first name into a dummy array
	start = SplitInput(studentInput, start, ' ', demoNames);
	// Checks the integrity of the first name. If the test returns with 0, the user receives an error message.
	if (IsNameCheck(demoNames) == 0)
	{
		printf("Error: invalid name or grade.\n");
		return 0;
	}
	// Separates the family name into a dummy array
	start = SplitInput(studentInput, start, ':', demoFamilyNames);
	// Checks the integrity of the family name. If the test returns with 0, the user receives an error message.
	if (IsNameCheck(demoFamilyNames) == 0)
	{
		printf("Error: invalid name or grade.\n");
		return 0;
	}
	// A loop that passes the line we received and separates the courses and the grades into two different arrays
	for (int i = 0; (i < 5); i++)
	{
		// Skip the character that appears before the course name
		start++;
		// Skips the spaces that may be at the beginning of the input
		while (studentInput[start] == ' ')
			start++;
		// Stops the input separation when the line is finished
		if (studentInput[start] == '\n')
		{
			break;
		}
		// Separates the courses into a dummy array
		start = SplitInput(studentInput, start, ',', demoCourses[i]);
		// Checks the integrity of the courses name. If the test returns with 0, the user receives an error message.
		if (IsNameCheck(demoCourses[i]) == 0)
		{
			printf("Error: invalid name or grade.\n");
			return 0;
		}
		// Skip the character that appears before the grade
		start++;
		// Skips the spaces that may be at the beginning of the input
		while (studentInput[start] == ' ')
			start++;
		// Stops the input separation when the line is finished
		if (studentInput[start] == '\n')
		{
			break;
		}
		// Separates the grades into a dummy array
		start = SplitInput(studentInput, start, ';', demoGradesChar[i]);
		// A loop that passes over the char array of grades and checks that the grade is not empty
		if (strcmp(demoGradesChar[i], "") == 0)
		{
			printf("Error: invalid name or grade.\n");
			return 0;
		}
		// A loop that checks whether the digits of the grade are between 0 and 9 only
		for (int j = 0; j < strlen(demoGradesChar[i]); j++)
		{
			if (((demoGradesChar[i][j]) < '0') || (demoGradesChar[i][j] > '9'))
			{
				printf("Error: invalid name or grade.\n");
				return 0;
			}
		}
	}

	/* A loop that passes over the char array of grades, converts it to int array of grade And keeps
	everything in new int array */
	for (int i = 0; i < 5; i++)
	{
		demoGradesInt[i] = CharToInt(demoGradesChar, i);
	}
	// A loop that passes over all grades
	for (int i = 0; i < 5; i++)
	{
		// Checks the integrity of the grades. If the test returns with 0, the user receives an error message.
		if (IsGradeCheck(demoGradesInt, i) == 0)
		{
			printf("Error: invalid name or grade.\n");
			return 0;
		}
	}
	// Check whether the student exists or does not exist in the system
	int i = SearchStudent(names, demoNames, familyNames, demoFamilyNames);
	// If it does not exist it is inserted into the system
	if (i == -1)
		InsertStudent(names, demoNames, familyNames, demoFamilyNames, courses, demoCourses, grades,
			demoGradesInt, demoGradesChar);
	// If it exists, its grades are updated in the system
	else
		UpdateStudent(courses, demoCourses, grades, demoGradesInt, names, demoNames, familyNames, demoFamilyNames);
}