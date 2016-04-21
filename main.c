/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 21, 2016, 5:06 PM
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

void insertString(char text[], char insert[], int startPos) {
    int  endPos, i, j;
    char buff[20];
    
    // get the characters until start pos
    i = 0;
    while (i < startPos) {
        buff[i] = text[i];
        i++;
    }
    
    // determine when the insertion ends 
    endPos = startPos + strlen(insert);
    
    // copy insert string in the empty space
    j = 0;
    while (i < endPos) {
        buff[i] = insert[j];
        i++;
        j++;
    }
    
    // copy the rest of the chars from the initial string
    while (i < strlen(text) + sizeof(insert)) {
        buff[i] = text[i - strlen(insert)];
        i++;
    }
    
    printf("\n%s", buff);
}

int main(int argc, char** argv) {
    insertString("the wrong son", "per", 10);
    return (EXIT_SUCCESS);
}

