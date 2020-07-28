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
	
	printf("has dupes? %d\n", arrayHasDupes(phaseSeq, 5));
	
	int max = 0;
	
	intcomp amps[5];
	int phases[] = {1,0,4,3,2};
	
	for(int i = 0; i < 5; i++) {
		intcomp prog = {intcode_memoryParse(argv[1]), 0, 0, 0, phases[i], 1};
		amps[i] = prog;
	}
	
	int input = 0;
	
	for(int h = 0; h < 5; h++) {
		amps[h].input = input;
		amps[h] = int_exe(amps[h], INTCODE_RUNMODE_OUTPUT);
		input = amps[h].output;
	}
	
	printf("output: %d\n", amps[4].output);
	
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
