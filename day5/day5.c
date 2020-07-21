// https://adventofcode.com/2019/day/5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxmemsize 1000

int main(int argc, char **argv)
{
	if(argc!=2) {
		printf("Argument expected: intcode string\n");
		return 0;
	}
	
	int m[maxmemsize];
	
	// comma delim string to int array
	char* toke = strtok(argv[1], ",");
	int index = 0;
	while(toke!=NULL) {
		m[index] = atoi(toke);
		index++;
		toke = strtok(NULL, ",");
	}
	
	int ptr = 0, instruction, param1, param2, userinput;
	char opcode[6], ins[3] = { ' ', ' ', (char)0};	
	
	// intcode go brrrr
	while(1) {
		
		sprintf(opcode, "%05d", m[ptr]);
		ins[0] = opcode[3];
		ins[1] = opcode[4];
		sscanf(ins, "%d", &instruction);
		
		if(instruction==99) break;
		
		// char to int, then nonzero test
		param1 = opcode[2] - '0' ? m[ptr+1] : m[m[ptr+1]]; 
		param2 = opcode[1] - '0' ? m[ptr+2] : m[m[ptr+2]]; 
			
		switch(instruction) {
			
			case 1: 
			m[m[ptr+3]] = param1 + param2;
			ptr+=4;
			break;
			
			case 2:
			m[m[ptr+3]] = param1 * param2;
			ptr+=4;
			break;

			case 3:
			printf("\nTEST INPUT: ");
			scanf("%d", &userinput);
			m[m[ptr+1]] = userinput;			
			ptr+=2;
			break;
			
			case 4:
			printf("output: %d\n", param1);
			ptr+=2;		
			break;
			
			case 5:
			ptr = param1 ? param2 : ptr + 3;
			break;
			
			case 6: 
			ptr = param1 ? ptr + 3 : param2;
			break;
			
			case 7:
			m[m[ptr+3]] = param1 < param2 ? 1 : 0;
			ptr += 4;
			break;
			
			case 8:	
			m[m[ptr+3]] = param1 == param2 ? 1 : 0;
			ptr += 4;
			break;		
		}
	}
	
	return 0;
}
