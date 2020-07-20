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
	
	// string to int array
	char* toke = strtok(argv[1], ",");
	int index = 0;
	while(toke!=NULL) {
		m[index] = atoi(toke);
		index++;
		toke = strtok(NULL, ",");
	}
	
	int ptr = 0, instruction, param1, param2;
	char opcode[6], ins[3] = { ' ', ' ', (char)0};	
	
	while(1) {
		
		sprintf(opcode, "%05d", m[ptr]);
		ins[0] = opcode[3];
		ins[1] = opcode[4];
		sscanf(ins, "%d", &instruction);
		
		if(instruction==99) break;

		if(instruction==3) { 
			int userinput;
			printf("\nTEST INPUT: ");
			scanf("%d", &userinput);
			m[m[ptr+1]] = userinput;			
			ptr+=2;
		}
		
		param1 = opcode[2] - '0' ? m[ptr+1] : m[m[ptr+1]];

		if(instruction==4) {
			if(m[ptr+2]==99) printf("final "); 
			printf("output: %d\n", param1);
			ptr+=2;			
		}
		
		param2 = opcode[1] - '0' ? m[ptr+2] : m[m[ptr+2]];
		
		if(instruction==1) {
			m[m[ptr+3]] = param1 + param2;
			ptr+=4;
		}
		
		if(instruction==2) {
			m[m[ptr+3]] = param1 * param2;
			ptr+=4;	
		}
	}
	
	return 0;
}
