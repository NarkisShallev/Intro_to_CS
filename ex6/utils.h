#ifndef UTILS_H
#define UTILS_H

#include "person.h"

void PrintCircle(Person* head);
//more functions declarations
struct Person* SearchBefore(Person* this);
struct Person* SearchPersonId(Person* head, int id);
#endif
