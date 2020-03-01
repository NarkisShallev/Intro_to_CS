/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 06
*Exercise name: ex6.c
******************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include "person.h"
#include "utils.h"
#define MAX_NAME 80
#define NAME_MESSAGE (printf("Name:\n"))
#define ID_MESSAGE (printf("ID:\n"))
#define NUM_OF_KIDS_MESSAGE (printf("Num of kids:\n"))
#define KIDS_NAME_MESSAGE (printf("Kid #%d name:\n", i + 1))
void Print(struct Person* this);
void KillNext(struct Person* this);
struct Person* SelfDestruct(struct Person* this);
void CreateNext(struct Person* this, int isNextNext, ...);
/******************************************
* Function Name: Print
* Input: Person*
* Output: void
* Function Operation: Printing a person with all his details
******************************************/
void Print(struct Person* this)
{
	printf("Name: %s\n", this->name);
	printf("ID: %d\n", this->id);
	// A loop that goes through all the children and prints them
	for (int i = 0; i < (this->numOfKids); i++)
		printf("Kid #%d: %s\n", i + 1, this->kids[i]);
}
/******************************************
* Function Name: KillNext
* Input: Person*
* Output: void
* Function Operation: The function kills the person after the person from whom it was activated by
using the suicide function. Then, the function returns the person after the person who was killed
******************************************/
void KillNext(struct Person* this)
{
	Person* afterThis = NULL;
	afterThis = this->next;
	// Using the suicide function to kill the one after this
	afterThis->SelfDestruct(afterThis);
}
/******************************************
* Function Name: SelfDestruct
* Input: Person*
* Output: Person*
* Function Operation: The function frees all the memory of a particular person (suicide) and
returns the person who follows him in the circle
******************************************/
struct Person* SelfDestruct(struct Person* this)
{
	Person* afterThis = NULL;
	Person* beforeThis = NULL;
	// Save the next one in the circle
	afterThis = this->next;
	if (afterThis == this)
		afterThis = NULL;
	else
	{
		// Save the next of the next
		beforeThis = SearchBefore(this);
		beforeThis->next = afterThis;
	}
	// A loop that passes over all the children and releases their memory
	for (int i = 0; i < this->numOfKids; i++)
		free(this->kids[i]);
	// Release the memory of the array in which the children are saved
	free(this->kids);
	// Release the memory of the person's name
	free(this->name);
	// Release the memory of the structure itself
	free(this);
	// returns the person who follows in the circle the particular person who committed suicide 
	return afterThis;
}
/******************************************
* Function Name: CreateNext
* Input: Person*, int
* Output: void
* Function Operation: The function allocates memory for a new person, positions it after
the person from whom it was activated
******************************************/
void CreateNext(struct Person* this, int isNextNext, ...)
{

	/* If the boolean variable returns 0, it means there is no additional parameter that is
	not known in the function */
	if (isNextNext == 0)
	{

		/* A new person will be created using the create person function and added after the
		last person who entered the circle */
		this->next = CreatePerson();
		return;
	}

	/* Else, if the boolean variable returns 1, it means there is additional parameter that is
	not known in the function and it should be put in the circle */
	else
	{
		// Declaration of the unknown variable that needs to be extracted
		va_list afterThis;

		/* Initialization of the variable at the address of the first unknown parameter By the
		end of the address of the last known parameter*/
		va_start(afterThis, isNextNext);

		/* A new person will be created using the create person function and added after the
		last person who entered the circle */
		this->next = CreatePerson();

		/* As long as the last person in the circle does not NULL pointer people will be added to
		the end of the circle */
		while (this->next != NULL)
			this->next->next = va_arg(afterThis, Person*);
		// free the variable
		va_end(afterThis);
	}
}
/******************************************
* Function Name: InitPersonValues
* Input: Person*
* Output: void
* Function Operation: The function initializes all fields in the structure
******************************************/
void InitPersonValues(Person* person)
{
	person->name = NULL;
	person->id = 0;
	person->numOfKids = 0;
	person->kids = NULL;
	person->next = NULL;
	person->Print = NULL;
	person->KillNext = NULL;
	person->SelfDestruct = NULL;
	person->CreateNext = NULL;
}
/******************************************
* Function Name: CreatePerson
* Input: nothing
* Output: Person*
* Function Operation: The function creates a new person based on data from the user. It assigns it a memory
and then with the help of another function it places it inside a circle.
******************************************/
Person* CreatePerson()
{
	int flag = 0;
	int i;
	// Create a temporary array to receive all names before dynamic allocation
	char tempArray[MAX_NAME] = { '\0' };
	// Dynamic allocation to a new person's structure
	Person* person = (Person*)malloc(sizeof(Person));
	// If the allocation failed - return NULL
	if (person == NULL)
		return NULL;
	// Initialization of all fields in the structure
	InitPersonValues(person);

	// Getting a person's name from the user into a temporary array
	NAME_MESSAGE;
	scanf("%s", &tempArray);
	// Dynamic allocation to a person's name
	person->name = (char*)malloc((strlen(tempArray) + 1) * sizeof(char));
	// If the allocation failed - return NULL and the memory allocated so far will be free
	if (person->name == NULL)
	{
		free(person);
		return NULL;
	}
	// Getting the name into its dynamic allocation person structure
	strcpy(person->name, tempArray);
	// Getting a person's ID from the user into the person structure
	ID_MESSAGE;
	scanf("%d", &person->id);
	// Getting a person's num of kids from the user into the person structure
	NUM_OF_KIDS_MESSAGE;
	scanf("%d", &person->numOfKids);
	// Dynamic allocation of the array in which children's names will be allocated
	person->kids = (char**)calloc((person->numOfKids), sizeof(char*));
	// If the allocation failed - return NULL and the memory allocated so far will be free
	if (person->kids == NULL)
	{
		free(person->name);
		free(person);
		return NULL;
	}
	// In case a person has children - they will be allocated a dynamic memory
	if ((person->numOfKids) > 0)
	{

		/* Getting a person's kid's name from the user into a temporary array and then into the dynamically
		allocated array using a loop */
		for (i = 0; i < person->numOfKids; i++)
		{
			KIDS_NAME_MESSAGE;
			scanf("%s", &tempArray);
			person->kids[i] = (char*)malloc((strlen(tempArray) + 1) * sizeof(char));
			// If the allocation failed - the loop stops
			if (person->kids[i] == NULL)
			{
				flag = 1;
				break;
			}
			strcpy(person->kids[i], tempArray);
		}
		// If the allocation failed return NULL and the memory allocated so far will be free
		if (flag == 1)
		{
			for (int j = 0; j < i; j++)
				free(person->kids[j]);
			free(person->kids);
			free(person->name);
			free(person);
			return NULL;
		}
	}
	// Connect function pointers to their functions
	(person->Print) = Print;
	(person->KillNext) = KillNext;
	(person->SelfDestruct) = SelfDestruct;
	(person->CreateNext) = CreateNext;
	return person;
}