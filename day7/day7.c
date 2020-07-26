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
	
	IntList list = intlist_new(1, intlist_new(2, intlist_new(3, NULL)));
	intlist_append(4, list);
	
	printf("shifted value: %d\n", intlist_shift(&list));
	intlist_print(list);
	
	return 0;
}
