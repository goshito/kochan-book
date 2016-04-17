/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 15, 2016, 10:51 PM
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

/* 
 * Program to insert v char in georgitoshev string
 * The insert will be done by creating a second string in which to copy the
 * first one excluding character from startPos till endPos. 
 * 1. Copy initial string till startPos is reached, ignore to copy characters
 * untill endPos is reached and then continue copy till the end of the string
 */

// this program can insert only one char, the bufferString needs to be copied 
// back to the original one

int main(int argc, char** argv) {
    char name[] = "georgitoshev";
    char insertInital ='v';
    int startPos, endPos, i;
    char nameBuff[20];
    
    // Copy initial string untill insert pos is reached
    startPos = 6;
    i = 0;
    while (i < startPos) {
        nameBuff[i] = name[i];
        i++;
    } // now it's time to instert the initial
    
    endPos = startPos + sizeof(insertInital);
    
    nameBuff[i] = insertInital;
    i++; // go to the next char
    
    while (i < strlen(name) + sizeof(insertInital)) {
        nameBuff[i] = name[i - 1];
        i++;
    }
    
    printf("\n%s", nameBuff);
    
    return (EXIT_SUCCESS);
}