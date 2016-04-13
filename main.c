/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 13, 2016, 1:32 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 10, Exercise 4
 * 
 * Write a function called substring to extract a portion of a character string.
 * The function should be called as follows:
 * 
 * substring(source, start, count, result);
 * 
 *  where source is the character string from which you are extractong the sub-
 * string, start is an index number into source indicating the first character
 * of the substring, count is the number of characters to be extracted from the
 * source string, and result is an array of characters that is to contain the
 * extracted substring. For example, the call
 * 
 * substring("character", 4, 3, result);
 * 
 * extracts the substring "act" (three character starting with character number
 * 4) from the string "character" and places the result in result.
 * 
 * Be certain the function inserts a null character at the end of the substring
 * in result array. Also, have the function check that the requested number of
 * characters does, in fact, exist in the string. If this is not the case, have
 * the function end the substring when it reaches the end of the source string.
 * So, for example, call such as
 * 
 * substring("two words", 4, 20, result);
 * 
 * should just place the string "words" inside the result array, even though 20
 * characters were requested by the call.
 */

void substring(char source[], int start, int count, char result[]) {
    int i;
    
    i = 0;
    while (i < count) {
        result[i] = source[start];
        i++;
        start++;
    }
    result[i] = '\0';
} 

int main(int argc, char** argv) {
    char str[81];
    
    substring("character", 4, 3, str);
    
    printf("%s", str);
    
    return (EXIT_SUCCESS);
}

