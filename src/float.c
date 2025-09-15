#include <stdio.h>
#include <float.h>


float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
    /* DO NOT CHANGE THE DECLARATION OF "f" (This will be converted to float later) */
    unsigned int f = 0; // DO NOT CHANGE
    /*------------------------------------------------------------------------------*/
    
    /* Start Coding Here */

    f = fraction;   //Start with putting in the fraction

    f |= exponent << 23;    //Inclusive or the exponent, after left shifting it by 23 spaces

    f |= sign_bit << 31;    //Inclsive or the sign bit, after left shifting it by 31 spaces
    
    /*-------------------*/
    
    /* DO NOT CHANGE THE RETURN VALUE (This returns the binary representation of "f" as float) */
    return *((float*)&f); // DO NOT CHANGE
    /* ----------------------------------------------------------------------------------------*/
}

/**
 * Create all test cases inside of the main function below.
 * 
 * Run the test cases by running:
 * > make
 * > ./build/float
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/

    printf("f = %g\n", construct_float_sf(0x00, 0x81, 0x300000));
    printf("f = %g\n", construct_float_sf(0x01, 0x81, 0x300000));
    printf("f = %g\n", construct_float_sf(0x00, 0x7F, 0x200000));
    printf("f = %g\n", construct_float_sf(0x01, 0x7F, 0x200000));
    printf("f = %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));
    printf("f = %g\n", construct_float_sf(0x01, 0x76, 0x299B6F));
    printf("f = %g\n", construct_float_sf(0x00, 0x89, 0xABCDEF));
    printf("f = %g\n", construct_float_sf(0x01, 0x89, 0xABCDEF));
    printf("f = %g\n", construct_float_sf(0x00, 0x90, 0x7973C0));
    printf("f = %g\n", construct_float_sf(0x01, 0x90, 0x7973C0));

	
	/** ---------------------- **/
	return 0;
}

