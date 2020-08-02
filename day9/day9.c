// https://adventofcode.com/2019/day/9

#include <stdio.h>
#include <stdlib.h>
#include "intcode.h"

int main(int argc, char **argv)
{
	if(argc!=3) {
		printf("arguments expected: path to textfile holding intcode string and input\n");
		return 1;
	}
	
	FILE * fp;
	char intcodeString[INTCODE_PROGRAM_MAX];
	fp = fopen (argv[1], "r+");	
	fscanf(fp, "%[^\n]", intcodeString);
	fclose(fp);
			
	intcomp prog;
	prog.mem = intcode_memoryParse(intcodeString);
	prog.ptr = 0;
	prog.rbase = 0;
	prog.input = atoll(argv[2]);
	prog.output = 0;
	prog.phaseApplyFlag = 0;
	prog.halted = 0;
	
	prog = intcode_exe(prog, INTCODE_RUNMODE_HALT);
	
	printf("solution: %lli\n", prog.output);	
	
	return 0;
}

