// https://adventofcode.com/2019/day/7

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"

#define FEEDBACKFLAG "-f"

int arrayHasDupes (int* arr, int length);

int main(int argc, char **argv)
{
	if(argc < 2 || argc > 3) {
		printf("Arguments expected: intcode string and optional -f flag for feedback mode\n");
		return 0;
	}
	
	int feedbackMode = argc==3 ? strcmp(FEEDBACKFLAG, argv[2]) ? 0: 1: 0;

	int* prog = intcode_memoryParse(argv[1]);
	
	int max = 0;
	int input = 0;
	int phases[5];
	intcomp amps[5];

	int* memory[5];
	for(int l = 0; l < 5; l++) memory[l] = malloc(INTCODE_MEMORYSIZE * sizeof(int));

	int poff = feedbackMode ? 5: 0;

	for(int a = 0 + poff; a < 5 + poff; a++) {
		for(int b = 0 + poff; b < 5 + poff; b++) {
			for(int c = 0 + poff; c < 5 + poff; c++) {
				for(int d = 0 + poff; d < 5 + poff; d++) {
					for(int e = 0 + poff; e < 5 + poff; e++) {
						
						phases[0] = a; phases[1] = b; phases[2] = c; phases[3] = d; phases[4] = e;
						if(arrayHasDupes(phases, 5)) continue;
					
						// reuse memory blocks between iterations
						for(int c = 0; c < 5; c++) memcpy(memory[c], prog, INTCODE_MEMORYSIZE * sizeof(int));
	
						for(int i = 0; i < 5; i++) {
							amps[i].mem = memory[i];
							amps[i].ptr = 0;
							amps[i].phase = phases[i];
							amps[i].phaseApplyFlag = 1;
							amps[i].halted = 0;
						}
						
						input = 0;
						int i;
						for(int h = 0; ; h++) {
							i = h % 5;
							amps[i].input = input;
							amps[i] = int_exe(amps[i], INTCODE_RUNMODE_OUTPUT);
							input = amps[i].output;
							if(i==4 && amps[i].halted) break;
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
