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
 * Chapter 10, Exercise 6 (unsuccessful attempt 1)
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
 */

void removeString(char source[], int start, int count) {    
    char temp[81];
    int i;
    
    i = 0;
    do {
        temp[i] = source[start];        
        i++;
        start++;
    } while (i < count);
        
    /*
    i = 0;
    while (i > start && i < count) {
        temp[i] = source[i];
        ++i;
    }
    */
    printf("\ntemp = %s\n", temp);
}

int main(int argc, char** argv) {
    char str[81] = "the wrong son";
    
    removeString(str, 4, 6);
    
    printf("\n%s", str);

    return (EXIT_SUCCESS);
}