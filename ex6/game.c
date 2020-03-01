/******************************************
*Student name: Narkis kremizi
*Student ID: 205832447
*Course Exercise Group: 06
*Exercise name: ex6.c
******************************************/
#include <stdio.h>
#include "game.h"
#include "utils.h"
#define ADD_MESSAGE (printf("Add a person to the game? (0|1)\n"))
#define VICTORY_MESSAGE (printf("Ah, ha, ha, ha, stayin' alive, stayin' alive! Ah, ha, ha, ha, \
\"%s\" stayin' alive!\n", head->name))
#define KILL_PERSON_MESSAGE (printf("%s kills %s", head->name, head->next->name))
#define KILL_KID_MESSAGE (printf(" and %s", head->next->kids[i]))
#define COWARD_MESSAGE (printf("Is there a coward in here? (0|1)\n"))
#define COWARD_ID_MESSAGE (printf("Insert your ID, you, lame pudding-heart coward:\n"))
#define LET_THE_WORLD_KNOW_MESSAGE (printf("Let the world know that you are a coward, %s!\n", coward->name))
#define LATE_MESSAGE (printf("Are you late? (0|1)\n"))
#define BEST_FRIEND_ID_MESSAGE (printf("Insert your best friend's ID:\n"))
#define ID_NOT_FOUND_MESSAGE (printf("No Such ID: %d\n", id))
#define ENTER (printf("\n"))
/******************************************
* Function Name: InitTheHungerGame
* Input: nothing
* Output: Person*
* Function Operation: The function creates the circle at the beginning of each game and returns
the head of the circle
******************************************/
Person* InitTheHungerGame()
{
	Person* head = NULL;
	Person* last = NULL;
	int answer = 0;
	// A question for the user whether to add a person to a circle
	ADD_MESSAGE;
	scanf("%d", &answer);
	// If he wants to add, because the circle is empty we will create the first person in it
	if (answer == 1)
	{
		// Creating the first person
		head = CreatePerson();
		// If the creation fails, NULL will be returned
		if (head == NULL)
			return NULL;
		answer = 0;
	}
	// If it does not want to add, the circle is null and therefore will be returned NULL
	else
		return NULL;
	// A question for the user whether to add a person to a circle
	ADD_MESSAGE;
	scanf("%d", &answer);
	// If he wants to add, we will produce the second person who will appear after the head
	if (answer == 1)
	{
		// Creating the second person
		head->CreateNext(head, 0);
		last = head->next;
		// If the creation fails, the head will be returned
		if (last == NULL)
			return head;
		answer = 0;
		// A question for the user whether to add a person to a circle
		ADD_MESSAGE;
		scanf("%d", &answer);
	}
	// If he does not want to add, the head will be returned + Closure
	else
	{
		head->next = head;
		return head;
	}

	/* Now, using a loop, we'll ask the user over and over if he wants to add a person to the circle. As long as
	he wants (ADD = 1) a new person will be created and added after the last person */
	while (answer == 1)
	{
		answer = 0;
		// Create a new person after the last person in the circle
		last->CreateNext(last, 0);
		last = last->next;
		// If the creation fails, the head will be returned
		if (last == NULL)
			return head;
		// A question for the user whether to add a person to a circle
		ADD_MESSAGE;
		scanf("%d", &answer);
	}
	// Closure
	last->next = head;
	// The function returns the head of the circle
	return head;
}
/******************************************
* Function Name: InsertLaters
* Input: Person*
* Output: void
* Function Operation: the  function get the laters into the  circle after their best friend
******************************************/
void InsertLaters(Person* head)
{
	int answer = 0;
	int id = 0;
	Person* late = NULL;
	Person* bestFriend = NULL;
	Person* after = NULL;
	// If the circle is empty, NULL will be returned
	if (head == NULL)
		return;
	// A question for the user whether he wants to add late person
	LATE_MESSAGE;
	scanf("%d", &answer);
	// As long as there are lates that want to get in the circle
	while (answer == 1)
	{
		answer = 0;
		// Receiving the late's best friend's ID from the user
		BEST_FRIEND_ID_MESSAGE;
		scanf("%d", &id);
		// Use a function that searches for a person by ID
		bestFriend = SearchPersonId(head, id);
		// If no such person is found, an error message will be printed to the user
		if (bestFriend == NULL)
		{
			answer = 0;
			ID_NOT_FOUND_MESSAGE;
			// A question for the user whether he wants to add late person
			LATE_MESSAGE;
			scanf("%d", &answer);
			if (answer == 0)
				break;
			else
				continue;
		}
		// Creation of the late person
		late = CreatePerson();
		// The late get into the circle after his best friend and the circle is being closed again
		after = bestFriend->next;
		bestFriend->next = late;
		late->next = after;
		// A question for the user whether he wants to add late person
		LATE_MESSAGE;
		scanf("%d", &answer);
	}
}
/******************************************
* Function Name: RemoveCowards
* Input: Person*
* Output: Person*
* Function Operation: The function removes all cowards from the circle
******************************************/
Person* RemoveCowards(Person* head)
{
	int answer = 0;
	int id = 0;
	Person* coward = NULL;
	Person* afterCoward = NULL;
	// If the circle is empty, NULL will be returned
	if (head == NULL)
		return NULL;
	// A question for the user whether there are cowards in the circle
	COWARD_MESSAGE;
	scanf("%d", &answer);
	// As long as there are cowards in the circle
	while (answer == 1)
	{
		answer = 0;
		// Receiving the coward's ID from the user
		COWARD_ID_MESSAGE;
		scanf("%d", &id);
		// Use a function that searches for a person by ID
		coward = SearchPersonId(head, id);
		// If no such person is found, an error message will be printed to the user
		if (coward == NULL)
		{
			answer = 0;
			ID_NOT_FOUND_MESSAGE;
		}
		// If the head of the circle is a coward, he leaves the circle and a new head is set for the circle
		if (coward == head)
		{
			//newHead = head->next;
			answer = 0;
			LET_THE_WORLD_KNOW_MESSAGE;
			head = head->SelfDestruct(head);
			// If the circle is empty, NULL will be returned
			if (head == NULL)
				return NULL;
		}

		/* If another person in the circle is a coward, he leaves the circle and the circle continues
		from the one after him */
		else if ((coward != head) && (coward != NULL))
		{
			answer = 0;
			// A message to the world that the coward has left the circle
			LET_THE_WORLD_KNOW_MESSAGE;
			afterCoward = coward->SelfDestruct(coward);
		}
		// A question for the user whether there are cowards in the circle
		COWARD_MESSAGE;
		scanf("%d", &answer);
	}
	// After removing all cowards from the circle, the head of the circle is returned
	return head;
}
/******************************************
* Function Name: LetTheHungerGameBegin
* Input: Person*
* Output: void
* Function Operation: The function begins the game - the circle begins from the head of the circle
and continues a round in which each person kills the person that follows him. In the end one person
remains and he is the winner.
******************************************/
void LetTheHungerGameBegin(Person* head)
{
	// The game starts only if the circle is not empty
	while (head != NULL)
	{
		// If there is only one person in the circle - he wins automatically
		if (head->next == head)
		{
			VICTORY_MESSAGE;
			// free the last one's memory
			head->SelfDestruct(head);
			break;
		}
		// If there is more than one person in The circle
		else
		{

			/* As long as there is any person that appears after head the game continues
			(we still do not have a winner) */
			while (head->next != head)
			{
				// Print who killed who
				KILL_PERSON_MESSAGE;
				for (int i = 0; i < (head->next->numOfKids); i++)
				{
					KILL_KID_MESSAGE;
				}
				ENTER;
				// The one found after the person who is killed is the new head
				head->KillNext(head);
				head = head->next;
			}
			// The last person left wins
			VICTORY_MESSAGE;
			// free the last one's memory
			head->SelfDestruct(head);
			break;
		}
	}
}