// https://adventofcode.com/2019/day/7

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"

int arrayHasDupes (int* arr, int length);

int main(int argc, char **argv)
{
	if(argc!=2) {
		printf("Argument expected: intcode string\n");
		return 0;
	}
	
	int max = 0;
	int input = 0;
	int phases[5];
	intcomp amps[5];
	
	for(int a = 0; a < 5; a++) {
		for(int b = 0; b < 5; b++) {
			for(int c = 0; c < 5; c++) {
				for(int d = 0; d < 5; d++) {
					for(int e = 0; e < 5; e++) {
						phases[0] = a; phases[1] = b; phases[2] = c; phases[3] = d; phases[4] = e;
						if(arrayHasDupes(phases, 5)) continue;
						
						for(int i = 0; i < 5; i++) {
							amps[i].mem = intcode_memoryParse(argv[1]);
							amps[i].ptr = 0;
							amps[i].phase = phases[i];
							amps[i].phaseApplyFlag = 1;
						}
						
						input = 0;
	
						for(int h = 0; h < 5; h++) {
							amps[h].input = input;
							amps[h] = int_exe(amps[h], INTCODE_RUNMODE_OUTPUT);
							input = amps[h].output;
						}
						
						max = amps[4].output > max ? amps[4].output : max;
					}
				}
			}
		}
	}
	
	printf("solution: %d\n", max);
	
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
