/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 13, 2016, 8:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Chapter 10, Exercise 6 another attempt using a function from below mentioned
 * url
 * 
 * Write a function called removeString to remove a specified number of charac-
 * ters from a character string. The function should take three areguments:
 * the source string, the starting index number in the source string, and the
 * number of characters to remove. So, if the character array text contains the
 * string "the wrong son", the call
 * 
 * removeString(text, 4, 6);
 * 
 * has the effect of removing the characters "wrong" (the word "wrong" plus the
 * space that follows) from the array text. The resulting string inside the text
 * is the taken "the son".
 * 
 */

/* 
 * Somekind of algorithm to solve this problem:
 * 1. Get the substring function
 * 2. Copy the elements to the temp string
 * 3. study removeString from:
 * http://codereview.stackexchange.com/questions/116004/remove-specified-number-of-characters-from-a-string?newreg=5abb33cd17954eea94fe24a1d64d2b81
 */

void removeString (char text[], int index, int rm_length)
{
    int i;

    for ( i = 0; i < index; ++i )
        if ( text[i] == '\0' )
            return;

    for ( ; i < index + rm_length; ++i )
        if ( text[i] == '\0' ) {
            text[index] = '\0';
            return;
        }

    do {
        text[i - rm_length] = text[i];
    } while ( text[i++] != '\0' );
}

int main(int argc, char** argv) {
    char str[] = "the wrong son";
    
    removeString(str, 4, 6);
    
    printf("%s", str);
    return (EXIT_SUCCESS);
}