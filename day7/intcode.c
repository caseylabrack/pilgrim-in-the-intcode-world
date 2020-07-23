#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"

struct intstruct {
	int* mem;
	int ptr;
	int input;
	int output;
};

intcomp int_init (char* mem, int input) {

	int* m = malloc(INTCODE_MEMORYSIZE * sizeof(int));
	if(m==NULL) {
		printf("failed to malloc intcode memory");
		abort();
	}
	
	// comma delim string to int array
	char* toke = strtok(mem, ",");
	int index = 0;
	while(toke!=NULL) {
		m[index] = atoi(toke);
		index++;
		toke = strtok(NULL, ",");
	}
	
	intcomp prog = malloc(sizeof(struct intstruct));
	prog->mem = m;
	prog->ptr = 0;
	prog->input = input;
	prog->output = 0;
	return prog;
}

void int_exe (intcomp m, int runmode) {
	
	int instruction, param1, param2;
	char opcode[6], ins[3] = { ' ', ' ', (char)0};	
	
	// intcode go brrrr
	while(1) {
		
		sprintf(opcode, "%05d", m->mem[m->ptr]);
		ins[0] = opcode[3];
		ins[1] = opcode[4];
		sscanf(ins, "%d", &instruction);
		
		if(instruction==99) break;
		
		// char to int, then nonzero test
		param1 = opcode[2] - '0' ? m->mem[m->ptr+1] : m->mem[m->mem[m->ptr+1]]; 
		param2 = opcode[1] - '0' ? m->mem[m->ptr+2] : m->mem[m->mem[m->ptr+2]]; 
					
		switch(instruction) {
			
			case 1: 
			m->mem[m->mem[m->ptr+3]] = param1 + param2;
			m->ptr+=4;
			break;
			
			case 2:
			m->mem[m->mem[m->ptr+3]] = param1 * param2;
			m->ptr+=4;
			break;

			case 3:
			m->mem[m->mem[m->ptr+1]] = m->input;			
			m->ptr+=2;
			break;
			
			case 4:
			printf("output: %d\n", param1);
			m->output = param1;
			m->ptr+=2;
			if(runmode==INTCODE_RUNMODE_OUTPUT) return;		
			break;
			
			case 5:
			m->ptr = param1 ? param2 : m->ptr + 3;
			break;
			
			case 6: 
			m->ptr = param1 ? m->ptr + 3 : param2;
			break;
			
			case 7:
			m->mem[m->mem[m->ptr+3]] = param1 < param2 ? 1 : 0;
			m->ptr += 4;
			break;
			
			case 8:	
			m->mem[m->mem[m->ptr+3]] = param1 == param2 ? 1 : 0;
			m->ptr += 4;
			break;
			
			default:
			printf("encountered bad opcode (%s). aborting", opcode);
			abort();
			break;		
		}
	}
}

int int_output (intcomp m) {
	return m->output;
}
