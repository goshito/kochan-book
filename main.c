/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 15, 2016, 1:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Chapter 10, Exercise 7
 * 
 * Write a function called insertString to insert one character string into
 * another string. The arguments to the function should consist of the source
 * string, the string to be inserted, and the position in the source string
 * where the string is to be inserted. So the call
 * 
 * insertString(text, "per", 10);
 * 
 * with text as originally defined in the previous exercise, results in the
 * character string "per" being inserted inside text, beginning at text[10]. 
 * Therefore, the character
 * string "the wrong person" is stored inside the text array after the function
 * returned.
 */

void insertString(char source[], char insert[], int pos) {
    int sourceSize = strlen(source);
    int insertSize = strlen(insert);
    int strSumSizes = strlen(source) + strlen(insert);
    
    source[pos + insertSize] = source[pos];
    //printf("%c", source[pos + insertSize]);
    pos++;
    source[pos + insertSize] = source[pos];
    //printf("%c", source[pos + insertSize]);
    pos++;
    source[pos + insertSize] = source[pos];
    //printf("%c", source[pos + insertSize]);
    source[pos + insertSize + 1] = '\0';
    
    pos = (sourceSize - insertSize);
    source[pos] = insert[0];
    pos++;
    source[pos] = insert[1];
    pos++;
    source[pos] = insert[2];
}

int main(int argc, char** argv) {
    char text[] = "the wrong son";
    
    insertString(text, "per", 10);
    printf("%s", text);

    return (EXIT_SUCCESS);
}