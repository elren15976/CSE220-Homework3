#include <stdio.h>
#include <stdlib.h>
#include <bit.h>

// Students should fill in bodies of the functions below.

int ToggleBit(int num, int pos)
{
	//An exclusive OR toggles the bit at the certain location
	return num ^= 0x1 << pos;
}

int GetMSB(int num)
{
	//Get the size of the number, so that this function
	//is more dynamic. Allows for datatype of num to change
	int bitLength = (sizeof(num)*8);

	//Start from left of bitstring, and check to the right
	//until first "1" is found
	for(int pos = bitLength - 1; pos >= 0; pos--){
		if(num & 0x1 << pos){
			return pos;
		}
	}

	return -1;
}

int ClearBitRange(int num, int start, int end)
{
	return 0;
}

int RotateLeft(int num, int d)
{
	return 0;
}

int SwapOddEvenBits(int num)
{
	return 0;
}

/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./build/bit"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/
	//printf("%d\n", ToggleBit(9, 0));
	//printf("%d\n", ToggleBit(9, 3));
	//printf("%d\n", ToggleBit(995283, 1));

	printf("%d\n", GetMSB(-283));
	printf("%d\n", GetMSB(18));
	printf("%d\n", GetMSB(0));
	
	
	/** ---------------------- **/
	return 0;
}