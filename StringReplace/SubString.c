/*********************************************************
 * Author: Filip Matic
 * Title: SubString.c 
 * Description: Definition of a set of functions for
 * manipulating C strings and sub strings.
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "substrings.h"

/* RETRUN: length of input string */
int string_length(char* src_string) 
{
    int length;
    
    /* check for valid string */
    if ( src_string == NULL ) return -1;
    
    /* initialize length and index pointer to beginning of string */
    length = 0;
    
    /* 
     * as long as we have not reach the end of the string, increment both the source string
     * pointer and the string length 
     */
    while ( *src_string != '\0' ) {
        src_string++;
        length++;
    }
       
    /* return the length */
    return length;
}


/* Copies up to the specified number of bytes from the source string to the destination string. 
 * if source string is shorter than the length specified, the entire source (excluding the 
 * null character) will be copied to the desination string
 *
 * The resulting destination string will not be null termianted
 *
 * RETURN: number of characters copied. this may be less than the specified length if the 
 *         source string is shorter than length
 */
int substring_copy(char *src_string, char *dest_string, int length) 
{
    int num_chars_copied = 0;
    
    /* if any of the input arguments are NULL, return 0 */
    if ( src_string == NULL || dest_string == NULL ) return 0;

    /* 
     * while the end of the source string has not been reached and the specified copy length
     * is not reached 
     */
    while ( *src_string != '\0' && num_chars_copied < length ) {
        *dest_string = *src_string;     /* copy character */
        src_string ++;                  /* increment source string pointer */
        dest_string++;                  /* increment destination string pointer */
        num_chars_copied++;             /* increment number of characters copies */
    }
     
    return num_chars_copied;
}
    
/* compares the specified number of characters within two inputs strings 
 *
 * RETURN: TRUE if specified numbers of characters exists and match within both input strings,
 *         and specified number of characters exist
 */
bool subtring_compare(char *string1, char *string2, int length) 
{
    int string_index;
    
    /* if any of the input strings are NULL, return FALSE */
    if ( string1 == NULL || string2 == NULL ) return FALSE;
    
    /* for loop to interated throuhg length number of characters in input strings */
    for ( string_index=0; string_index<length; string_index++ ) {
        
        /* if we have reaced the end of either string, return FALSE */
        if ( string1[string_index] == '\0' || string2[string_index] == '\0' ) return FALSE;
        
        /* if characters don't match, return FALSE */
        if ( string1[string_index] != string2[string_index] ) return FALSE;
    }
    
    /* if no characters mismatched and string were long enough, return TRUE */
    return TRUE;
}


/* Determines the if the second input string is a substring within the first input string. 
 *
 * RETURN: pointer to the starting location of substring if found, NULL otherwise
 */

char * find_substring(char *src_string, char *substring) 
{
    int substring_length;
    
    /* if any of the input strings are NULL, return NULL */
    if ( src_string == NULL || substring == NULL ) return NULL;
    
    /* determine length of substring for comparision */
    substring_length = string_length(substring);
    
    /* while we have not reached the end of the string, continue searching for substring */
    while ( *src_string != '\0' ) {
        
        /* check if substring is found at current location */
        if ( subtring_compare(src_string, substring, substring_length) == TRUE ) {
            
            /* if substring is found, return current location */
            return src_string;
        }
        
        /* substring was not found, incerement source string pointer */
        src_string++;
    }
    /* if substring not found, return NULL */
    return NULL;
}

/* Replaces the first occurrence of the substring specified within the source input string 
 * with the replacement input string 
 *
 * RETURN: newly allocated string with replaced substring if substring is present, NULL otherwise
 */
char * replace_substring_once(char *src_string, char *substring, char *replace_string) 
{
    char *substring_start;     /* pointer to sub string location in input string */
    char *new_string;           /* used for newly allcoated result string */
    char *copy_location;        /* pointer used for copy strings into result string */
    int num_chars_copied;       
    
    /* if any of the input arguments are NULL, return NULL */
    if ( src_string == NULL || substring == NULL || replace_string == NULL ) return NULL;
    
    /* find location of the sub_string. if the sub_string does not exist return NULL */
    substring_start = find_substring(src_string, substring);
    if ( substring_start == NULL ) return NULL;
    
    /* allocate space for the new string, don't forget the space for the null character */
    new_string = (char *)malloc(string_length(src_string)-
                                string_length(substring)+
                                string_length(replace_string)+
                                1);
    
    /* check for error in allocating memory, and report error */
    if ( new_string == NULL ) {
        printf("Error: Could not allocate memory.\n");
        
        /* return NULL on error. alternatively, we could have used exit() to terminate program */
        return NULL;
    }
    
    /* initialize copy location */
    copy_location = new_string;
    
    /* copy first part of input string to new string */
    num_chars_copied = substring_copy(src_string, copy_location, substring_start-src_string);
    copy_location += num_chars_copied;
    
    /* copy replacement string to new sring */
    num_chars_copied = substring_copy(replace_string, copy_location, string_length(replace_string));
    copy_location += num_chars_copied;
    
    /* increment src_string pointer to location in source string after sub string occurrence */
    src_string = substring_start + string_length(substring);

    /* copy end of string to new string */
    num_chars_copied = substring_copy(src_string, copy_location, string_length(src_string));    
    copy_location += num_chars_copied;

    /* append null character */
    *copy_location = '\0';
    
    return new_string;
}
