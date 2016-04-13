/*
 * Chapter 10, Exercise 5 solved wit help from stackoverflow
 * http://stackoverflow.com/questions/1369802/substring-algorithm?rq=1
 * 
 * Write a function called findstring to determine if one character string exists
 * inside another string. The first argument to the function should be the char-
 * acter string that is to be searched and the second argument is the string you
 * are interested in finding. If the function finds the specified string, have
 * return the location in the source string where the string was found. If the
 * function does not find the string, have it return -1. So for example, the call
 * 
 * index = findstring("a chatterbox", "hat");
 * 
 * searches the string "a chatterbox" for the string "hat". Because "hat" does
 * exist inside the source string, the function returns 3 to indicate the star-
 * ting position inside the source string where "hat" was found.
 * 
 */

#include <stdio.h>
#include <string.h>

int isSubstring(char s[], char t[]) {
    for ( int i = 0; i <= strlen(s) - strlen(t); i++ ) {
        
        for ( int j = 0; j < strlen(t); j++ ) {
            
            if ( s[i + j] == t[j] ) {
                if ( j == strlen(t) - 1 )
                    return i;
            } else
                break;
        }
        
    }
    return -1;
}

int main(void) {
    printf("%i", isSubstring("a chatterbox", "hat"));
    
    return 0;
}