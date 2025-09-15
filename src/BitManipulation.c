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
	//Start from start position, and set to 0 recursively
	//until the end position is reached
	for(int pos = start; pos <= end; pos++){
		num &= ~(0x1 << pos);
	}
	return num;
}

int RotateLeft(int num, int d)
{
	//Get the size of the number, so that this function
	//is more dynamic. Allows for datatype of num to change
	int bitLength = (sizeof(num)*8);

	//Get MSB. Then left shift the number, and add MSB
	//Loop for d times
	for(int i = 0; i < d; i++){
		int MSB = (num & 0x1 << (bitLength - 1)) ? 1 : 0;

		num = (num << 1) + MSB;
	}
	return num;
}

int SwapOddEvenBits(int num)
{
	//Extract the odd and even bits
	int odd = num & 0x55555555;
	int even = num & 0xAAAAAAAA;

	//Left shift odd, Right shift even
	odd = odd << 1;
	even = even >> 1;

	//Put the shifted odd and even together using an
	//inclusive or
	return (odd | even);
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
	//printf("%d\n", ToggleBit(995283, 1));	//00...00111100101111110100 1 1

	//printf("%d\n", GetMSB(18));
	//printf("%d\n", GetMSB(0));
	//printf("%d\n", GetMSB(-283));	//00...011100101
	
	//printf("%d\n", ClearBitRange(73, 1, 3));
	//printf("%d\n", ClearBitRange(100, 0, 32));	//00...001100100
	//printf("%d\n", ClearBitRange(-5, 1, 3));	//11...1111 101 1

	//printf("%d\n", RotateLeft(5, 1));
	//printf("%d\n", RotateLeft(5, 2));
	//printf("%d\n", RotateLeft(-2, 1));	//11...1110

	printf("%d\n", SwapOddEvenBits(23));
	printf("%d\n", SwapOddEvenBits(-1));	//11 ... 11 11 11 11 11 11 11 11 11
	printf("%d\n", SwapOddEvenBits(3276));	//00 ... 00 00 00 11 00 11 00 11 00
	
	/** ---------------------- **/
	return 0;
}