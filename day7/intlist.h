#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct intlist_struct {
	int head;
	struct intlist_struct* tail;
}* IntList;

extern IntList intlist_new (int data, IntList list);
extern void intlist_append (int data, IntList list);
extern IntList intlist_last (IntList list);
extern int intlist_shift (IntList* list);
extern void intlist_print (IntList list);
