// https://adventofcode.com/2019/day/7

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"
#include "intlist.h"

int main(int argc, char **argv)
{
	if(argc!=2) {
		printf("Argument expected: intcode string\n");
		return 0;
	}
	
	int userinput;
	printf("\nTEST INPUT: ");
	scanf("%d", &userinput);
	
	intcomp ampA = int_init(argv[1], userinput);
	int_exe(ampA, INTCODE_RUNMODE_HALT);

	IntList list = intlist_new(1, NULL);
	intlist_append(2, list);
	intlist_append(3, list);
	printf("shift out this value: %d\n", intlist_shift(&list));
	printf("second value is: %d\n", intlist_getvalue(intlist_nth(list, 1)));
	intlist_print(list);
	
	return 0;
}
