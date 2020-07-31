// https://adventofcode.com/2019/day/9

#include <stdio.h>
#include <limits.h>
#include "intcode.h"

int main(int argc, char **argv)
{
	if(argc!=2) {
		printf("argument expected: path to textfile holding intcode string");
		return 1;
	}
	
	FILE * fp;
	char intcodeString[10000];
	fp = fopen (argv[1], "r+");	
	fscanf(fp, "%[^\n]", intcodeString);
	fclose(fp);
			
	intcomp prog;
	prog.mem = intcode_memoryParse(intcodeString);
	prog.ptr = 0;
	prog.rbase = 0;
	prog.input = 1;
	prog.output = 0;
	prog.phaseApplyFlag = 0;
	prog.halted = 0;
	
	prog = intcode_exe(prog, INTCODE_RUNMODE_HALT);
	
	printf("prog output: %lli\n", prog.output);	
	
	return 0;
}

