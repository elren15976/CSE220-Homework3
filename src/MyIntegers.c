#include <stdio.h>
#include <stdlib.h>
#include <integer.h>

// FILL IN THE BODY OF THIS FUNCTION.
// Feel free to create any other functions you like; just include them in this file.



void repr_convert(char source_repr, char target_repr, unsigned int repr) {
	//if invalid source or target, print error and return
	if((source_repr != 'S' && source_repr != '2') ||
	   (target_repr != 'S' && target_repr != '2')){
		printf("error\n");
		return;
	}
	//Edge case where represented number is 0
	else if (repr == 0x0){
		//Do nothing
	}
	//Edge case where two's complement is 10000...000,
	//which cannot be represented in magnitude form
	else if(source_repr == '2' && target_repr == 'S' && repr == (0x1 << (sizeof(repr)*8 - 1))){
		printf("undefined\n");
		return;
	}
	//Converting from S to 2 and 2 to S is very similar
	//Flip all bits and add 1. Then flip the MSB to
	//preserve sign
	else if((source_repr == 'S' && target_repr == '2') ||
	   (source_repr == '2' && target_repr == 'S')){
		repr = (~repr) + 1;
		repr ^= 0x1 << (sizeof(repr)*8 - 1);
	}


	printf("%08x\n", repr);
}


/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./build/integer"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/

	//repr_convert('S', '2', 0x80000001);
	//repr_convert('S', '2', 0x80000000);
	//repr_convert('2', '2', 0x59f2ca50);
	//repr_convert('F', '2', 0x00394812);
	//repr_convert('2', 'S', 0x80000000);
	//repr_convert('2', 'S', 0x00000000);
	//repr_convert('S', '2', 0x00000000);
	//repr_convert('2', 'S', 0xffffffff);
	//repr_convert('2', 'S', 0xe874c27a);
	//repr_convert('2', 'A', 0x9bc4c27a);
	//repr_convert('S', 'S', 0xe87acd7a);

	
	/** ---------------------- **/
	return 0;
}
