// module for evaluating intcode

#ifndef INTCODE_H
#define INTCODE_H

#define INTCODE_MEMORYSIZE 1000
// int_exe parameter
#define INTCODE_RUNMODE_OUTPUT	0 // int_exe yield on output or halt
#define INTCODE_RUNMODE_HALT	1 // int_exe yield only on halt

//~ typedef struct intstruct* intcomp;

typedef struct {
	int* mem;
	int ptr;
	int input;
	int output;
	int phase;
	int phaseNeeded;
} intcomp;

//~ extern intcomp int_init (char* mem, int input);
extern int* intcode_memoryParse (char* mem);
extern void int_exe (intcomp* m, int runmode);
//~ extern int int_output (intcomp m);

#endif // INTCODE_H
