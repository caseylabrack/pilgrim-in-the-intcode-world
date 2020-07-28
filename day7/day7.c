// https://adventofcode.com/2019/day/7

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"
#include "intlist.h"

int arrayHasDupes (int* arr, int length);

int main(int argc, char **argv)
{
	if(argc!=2) {
		printf("Argument expected: intcode string\n");
		return 0;
	}
	
	int phaseSeq[] = {4,2,2,1,0};
	
	
	printf("has dupes? %d\n", arrayHasDupes(phaseSeq, 5));
	
	int userinput;
	printf("\nTEST INPUT: ");
	scanf("%d", &userinput);
	
	//~ int* mem = ;
	
	intcomp prog = {intcode_memoryParse(argv[1]), 0, userinput, 0, 0, 0};
	
	//~ int phase = 4;
	
	//~ printf("mem is %d...%d...%d...%d...\n", mem[0], mem[1], mem[2], mem[3]);
	//~ intcomp ampA; 
	//~ ampA->mem = mem;
	//~ ampA->ptr = 0;
	//~ ampA->input = userinput;
	//~ ampA->output = 0; 
	//~ ampA->phase = 0;
	//~ ampA->phaseNeeded = 0;
	
	//~ printf("user input is %d\n", ampA->input);
						
	//~ int_init(strdup(argv[1]), userinput);
	int_exe(&prog, INTCODE_RUNMODE_HALT);
	
	return 0;
}

int arrayHasDupes (int* arr, int length) {
	
	int test;
	
	for(int i = 0; i < length; i++) {
		test = arr[i];
		for(int j = i+1; j < length; j++) {
			if(arr[i]==arr[j]) return 1; // true; contains a duplicate
		}
	}
	
	return 0; // false
}
