// https://adventofcode.com/2019/day/7

#include <stdio.h>
#include "intcode.h"

int main(int argc, char **argv)
{
	if(argc!=2) {
		printf("Argument expected: intcode string\n");
		return 0;
	}
	
	int userinput;
	printf("\nTEST INPUT: ");
	scanf("%d", &userinput);

	
	intcomp ampA = int_init(argv[1], userinput);
	
	int_exe(&ampA);
		
	return 0;
}
