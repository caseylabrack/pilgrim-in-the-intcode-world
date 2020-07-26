// https://adventofcode.com/2019/day/2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxmemsize 1000

void memPrint (int m[]);
int intcode (int m[]);

int main(int argc, char **argv)
{
	if(argc!=3) {
		printf("Two arguments expected: intcode string and part 2 input. \n");
		return 0;
	}

	int mem[maxmemsize];
	for(int i = 0; i < maxmemsize; i++) mem[i] = -1; // initialize
	
	// comma delim string to int array
	char* toke = strtok(argv[1], ",");
	int index = 0;
	while(toke!=NULL) {
		mem[index] = atoi(toke);
		index++;
		toke = strtok(NULL, ",");
	}

	int c[maxmemsize];
	int noun, verb;
	for(noun = 0; noun < 100; noun++) {
		for(verb = 0; verb < 100; verb++) {
			for(int l = 0; l < maxmemsize; l++) c[l] = mem[l]; // working copy
			
			c[1] = noun;
			c[2] = verb;
			
			if(intcode(c)==atoi(argv[2])) goto BREAKLOOPS;
		}
	}
	BREAKLOOPS:
	
	mem[1] = 12;
	mem[2] = 2;
	
	printf("\nSolution 1: %d\n", intcode(mem));	
	printf("Solution 2: %d\n", 100 * noun + verb);
	
	return 0;
}

// inspect state of intcode program
void memPrint (int m[]) {
	int index = 0;	
	while(m[index]!=-1) {	
		printf("%d\n", m[index]);
		index++;
	}
}

int intcode (int m[]) {
	int ptr = 0;	
	while(m[ptr]!=99 && m[ptr]!=-1) {
		
		switch(m[ptr]) {
		
			case 1:
			m[m[ptr+3]] = m[m[ptr+1]] + m[m[ptr+2]];
			break;
			
			case 2:
			m[m[ptr+3]] = m[m[ptr+1]] * m[m[ptr+2]];
			break;
			
			default:
			printf("bad opcode: %d\n", m[ptr]);
			abort();
			break;
		}
		
		ptr+=4;
	}
	
	return m[0];
}
