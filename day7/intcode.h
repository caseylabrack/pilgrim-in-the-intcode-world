// module for evaluating intcode

#ifndef INTCODE_H
#define INTCODE_H

#define INTCODE_MEMORYSIZE 1000
// int_exe parameter
#define INTCODE_RUNMODE_OUTPUT	0 // int_exe yield on output or halt
#define INTCODE_RUNMODE_HALT	1 // int_exe yield only on halt

typedef struct {
	int* mem;
	int ptr;
	int input;
	int output;
	int phase;
	int phaseApplyFlag;
	int halted;
} intcomp;

extern int* intcode_memoryParse (char* mem);
extern intcomp int_exe (intcomp m, int runmode);

#endif // INTCODE_H
