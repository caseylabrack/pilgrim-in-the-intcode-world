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
} intcomp;

extern intcomp int_init (char* mem, int input);
extern void int_exe (intcomp* m, int runmode);

#endif /* INTCODE_H */
