#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"

IntList intlist_new (int data, IntList list) {
	IntList link = malloc(sizeof(struct intlist_struct));
	if(link==NULL) abort();
	link->head = data;
	link->tail = list;
	return link;
}

void intlist_append (int data, IntList list) {
	IntList ll = intlist_last(list);
	ll->tail = intlist_new(data, NULL);
}

IntList intlist_last (IntList list) {
	if(list->tail==NULL) {
		return list;
	} else {
		return intlist_last(list->tail);
	}
}

// remove first element from list and return its value
int intlist_shift (IntList* list) {
	int value = (*list)->head;
	IntList newstart = (*list)->tail;
	free(*list);
	*list = newstart;	
	return value;
}

void intlist_print (IntList list) {
	if(list==NULL) return;
	printf("printing list...");
	while(list->tail!=NULL) {
		printf("list item: %d\n", list->head);
		return intlist_print(list->tail);
	} 
	printf("list item: %d\ndone printing\n", list->head);
}
