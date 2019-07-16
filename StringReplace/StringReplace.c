/*********************************************************
 * Author: Filip Matic
 * Title: StringReplace.c 
 * Description: Main functionality for simple C program that search each line of an input
 * file for a user specified string, and replaces one ocurrence of that 
 * string with a user specified replacement string. The resulting
 * modified text will be printed to the stadard output.
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "substrings.h"

/* declare a fixed size character array to store lines read from an input file */
#define MAX_LINE_BUFFER_SIZE 1000
char lineBuffer[MAX_LINE_BUFFER_SIZE];


int main(int argc, char *argv[]) 
{
	FILE *inputFile;
    char *resultString;
    
    
     /* check for the correct number of commandline arguments. If incorrect */
     /* provide a simple usage message to the assist the user */
     
	if( argc != 4 ) {
		printf("\nUsage: %s inputFile searchString replaceString \n\n", argv[0]);
        return -1;
	}
	
    /* open the designated input file for reading, and output an error message 
     * if unsuccesful */
    inputFile = fopen(argv[1], "r");
    if( inputFile == NULL ) {
        printf("Error: Input File %s cannot be opened.\n", argv[1]);
        return -1;
    }
    
    /* continue to read one line at a time from the input file */
    while( fgets(lineBuffer, sizeof(lineBuffer), inputFile) ) 
    {
        resultString = replace_substring_once(lineBuffer, argv[2], argv[3]);
        
        /* if result string is not NULL, printf string and free memory used for string */
        if( resultString != NULL ) {
            printf("%s", resultString);
            free(resultString);
        }
        else {
            /* otherwise, print original string */
            printf("%s", lineBuffer);
        }
    }
    
    /* close the input file, we are done using it */
    fclose(inputFile);
	
	return 0;
}
