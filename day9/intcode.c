#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intcode.h"

long long* intcode_memoryParse (char* mem) {

	long long* m = calloc(INTCODE_MEMORYSIZE, sizeof(long long));
	if(m==NULL) {
		printf("failed to malloc intcode memory\n");
		abort();
	}
	
	char* copy = strdup(mem);
	
	int count = 0;
	
	char* toke = strtok(copy, ",");
	int index = 0;
	while(toke!=NULL) {
		count++;
		m[index] = atoll(toke);
		index++;
		toke = strtok(NULL, ",");
	}
	
	return m;
}

intcomp intcode_exe (intcomp m, int runmode) {
	
	int instruction;
	long long param1, param2, param3;
	char opcode[6], ins[3] = { ' ', ' ', (char)0};	
	
	// intcode go brrrr
	while(1) {
		
		sprintf(opcode, "%05d", m.mem[m.ptr]);
		ins[0] = opcode[3];
		ins[1] = opcode[4];
		sscanf(ins, "%d", &instruction);
		
		if(instruction==99) {
			m.halted = 1;
			break;
		}
		
		// char to int, then test if zero
		//~ param1 = opcode[2] - '0' ? m.mem[m.ptr+1] : m.mem[m.mem[m.ptr+1]]; 
		//~ param2 = opcode[1] - '0' ? m.mem[m.ptr+2] : m.mem[m.mem[m.ptr+2]];
		
		if(opcode[2] - '0'==1) param1 = m.mem[m.ptr+1];
		if(opcode[2] - '0'==0) param1 = m.mem[m.mem[m.ptr+1]];
		if(opcode[2] - '0'==2) param1 = m.mem[m.mem[m.ptr+1]+m.rbase];
		
		if(opcode[1] - '0'==1) param2 = m.mem[m.ptr+2];
		if(opcode[1] - '0'==0) param2 = m.mem[m.mem[m.ptr+2]];
		if(opcode[1] - '0'==2) param2 = m.mem[m.mem[m.ptr+2]+m.rbase];

		param3 = opcode[1] - '0' == 0 ? m.mem[m.ptr+3] : m.mem[m.ptr+3] + m.rbase;

		switch(instruction) {
			
			case 1: 
			//~ m.mem[m.mem[m.ptr+3]] = param1 + param2;
			m.mem[param3] = param1 + param2;
			m.ptr+=4;
			break;
			
			case 2:
			//~ m.mem[m.mem[m.ptr+3]] = param1 * param2;
			m.mem[param3] = param1 * param2;
			m.ptr+=4;
			break;

			case 3:
			if(m.phaseApplyFlag==1) {
				m.mem[m.mem[m.ptr+1]] = m.phase;
				m.phaseApplyFlag = 0;
			} else {
				//~ m.mem[m.mem[m.ptr+1]] = m.input;
				//~ m.mem[opcode[2] - '0' == 0 ? m.mem[m.ptr+1] : m.mem[m.ptr+1]+m.rbase] = m.input;
				if(opcode[2] - '0' == 0) { // position mode
					m.mem[m.mem[m.ptr+1]] = m.input;
				} else { // relative mode
					m.mem[m.mem[m.ptr+1]+m.rbase] = m.input;
					printf("relative mode input detected: %lli\n", m.rbase);
				}
			}
			m.ptr+=2;
			break;
			
			case 4:
			printf("output: %lli\n", param1);
			//~ printf("opcode: %s\n", opcode);
			m.output = param1;
			m.ptr+=2;
			if(runmode==INTCODE_RUNMODE_OUTPUT) return m;		
			break;
			
			case 5:
			m.ptr = param1 ? param2 : m.ptr + 3;
			break;
			
			case 6: 
			m.ptr = param1 ? m.ptr + 3 : param2;
			break;
			
			case 7:
			//~ m.mem[m.mem[m.ptr+3]] = param1 < param2 ? 1 : 0;
			m.mem[param3] = param1 < param2 ? 1 : 0;
			m.ptr += 4;
			break;
			
			case 8:	
			//~ m.mem[m.mem[m.ptr+3]] = param1 == param2 ? 1 : 0;
			m.mem[param3] = param1 == param2 ? 1 : 0;
			m.ptr += 4;
			break;
			
			case 9:	
			m.rbase += param1;
			m.ptr += 2;
			break;
			
			default:
			printf("encountered bad opcode (%s). aborting\n", opcode);
			abort();
			break;		
		}
	}
	
	return m;
}
