#ifndef INTCODE_H
#define INTCODE_H

#define maxmemsize 1000

typedef struct {
	int* mem;
	int ptr;
	int input;
	int output;
} intcomp;

extern intcomp int_init (char* mem, int in);
extern void int_tick (intcomp* m);
extern void int_exe (intcomp* m);

#endif /* INTCODE_H */
