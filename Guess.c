/*********************************************************
 * Author: Filip Matic
 * Title: Guess.c 
 * Description: Generates a random number (1-100) that the
 * user must guess correctly. Provides guidance if the guess
 * is incorrect.  
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
// Declare variables
int RandNum;
int Guess;

	// Generate Random Number
	srand ( time(NULL) );
	RandNum = rand() % 100 +1 ;

	do {
	  printf("Guess the number(1 to 100):");
	  scanf("%d",&Guess);

	if ( RandNum<Guess ) puts ("Lower");	// Display Lower if the random Number is lower than guessed value. 
	else 
	if ( RandNum>Guess ) puts ("Higher");	// Display Higher if the random Number is higher than guessed value. 
	}
	while ( RandNum!=Guess );

	puts ("Correct");	// Display Correct when the user guesses the number. 
	return 0;
}
