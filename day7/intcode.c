#include "intcode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

intcomp int_init (char* mem, int in) {

			printf("exe.....");

	
	int m[maxmemsize];
	
	// comma delim string to int array
	char* toke = strtok(mem, ",");
	int index = 0;
	while(toke!=NULL) {
		m[index] = atoi(toke);
		index++;
		toke = strtok(NULL, ",");
	}

	intcomp prog = {m, 0, in, 0};	
	return prog;
}

void int_tick (intcomp* m) {
	//~ printf("
}

void int_exe (intcomp* m) {
	
	
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
			printf("ptr is %d", m->ptr);
			m->mem[m->mem[m->ptr+1]] = m->input;			
			m->ptr+=2;
			break;
			
			case 4:
			printf("output: %d\n", param1);
			m->ptr+=2;		
			break;
			
			case 5:
			printf("ptr is %d", m->ptr);
			m->ptr = param1 ? param2 : m->ptr + 3;
			break;
			
			case 6: 
			printf("ptr is %d", m->ptr);
			m->ptr = param1 ? m->ptr + 3 : param2;
			break;
			
			case 7:
			printf("ptr is %d", m->ptr);
			m->mem[m->mem[m->ptr+3]] = param1 < param2 ? 1 : 0;
			m->ptr += 4;
			break;
			
			case 8:	
			printf("ptr is %d", m->ptr);
			m->mem[m->mem[m->ptr+3]] = param1 == param2 ? 1 : 0;
			m->ptr += 4;
			break;		
		}
	}
}
