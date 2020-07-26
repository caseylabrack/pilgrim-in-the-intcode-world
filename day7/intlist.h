// linked lists module for integers

#ifndef INTLIST_H
#define INTLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct intlist_struct* IntList;

extern IntList intlist_new (int data, IntList list);
extern void intlist_append (int data, IntList list);
extern IntList intlist_last (IntList list);
extern int intlist_shift (IntList* list);
extern void intlist_print (IntList list);
extern int intlist_length (IntList list);
extern IntList intlist_nth (IntList list, int index);
extern int intlist_getvalue (IntList list);

#endif // INTLIST_H
