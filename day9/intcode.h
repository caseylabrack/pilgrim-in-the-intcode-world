// module for evaluating intcode

#ifndef INTCODE_H
#define INTCODE_H

#define INTCODE_MEMORYSIZE 100000
// int_exe parameter
#define INTCODE_RUNMODE_OUTPUT	0 // int_exe yield on output or halt
#define INTCODE_RUNMODE_HALT	1 // int_exe yield only on halt

typedef struct {
	long long* mem;
	int ptr;
	long long rbase;
	long long input;
	long long output;
	int phase;
	int phaseApplyFlag;
	int halted;
} intcomp;

extern long long* intcode_memoryParse (char* mem);
extern intcomp intcode_exe (intcomp m, int runmode);

#endif // INTCODE_H
