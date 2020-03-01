/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 06
*Exercise name: ex6.c
******************************************/
#include <stdio.h>
#include "utils.h"
#define SEPARATION_LINES (printf("----------\n"))
/******************************************
* Function Name: PrintCircle
* Input: Person*
* Output: void
* Function Operation: The function prints all the people in the circle
******************************************/
void PrintCircle(Person* head)
{
	Person* after = NULL;
	if (head == NULL)
		return;
	SEPARATION_LINES;
	// Print the first person
	head->Print(head);
	// Setting after so that it is after the head
	after = head->next;
	SEPARATION_LINES;

	/* Print all the other people in the circle in order until we get back to the head.
	using a loop, each time we print after and set it to be the one that follows it */
	while (after != head)
	{
		after->Print(after);
		SEPARATION_LINES;
		after = after->next;
	}
}
/******************************************
* Function Name: SearchBefore
* Input: Person*
* Output: Person*
* Function Operation: The function accepts a person and finds the person in front of him in the circle
******************************************/
struct Person* SearchBefore(Person* this)
{
	Person* before = NULL;
	Person* after = this->next;
	// The search continues as long as no one is in a circle that points on the person who was recieved
	while (after->next != this)
	{

		after = after->next;
	}
	before = after;
	// The person before the person who was recieved is returned
	return before;
}
/******************************************
* Function Name: SearchPersonId
* Input: Person*, int id
* Output: Person*
* Function Operation: The function searchs a person in the circle by ID
******************************************/
struct Person* SearchPersonId(Person* head, int id)
{
	Person* after = NULL;
	// If the head of the circle is the requested person - the function will return it
	if (head->id == id)
		return head;
	// Setting after so that it is after the head
	after = head->next;

	/* Checks if one of the other people in the circle is the requested person in order until we
	get back to the head. using a loop, each time we check after and set it to be the one that follows it */
	while (after != head)
	{
		if (after->id == id)
			return after;
		after = after->next;
	}
	// If the requested person is not found, NULL will be returned
	return NULL;
}