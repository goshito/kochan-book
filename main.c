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
 * until endPos is reached and then continue copy till the end of the string
 *      
 *      20042016 - test different positions of the inserted char - working
 *      
 */
int main(int argc, char** argv) {
    char name[] = "georgitoshev";
    char insertInital[] = "valeriev";
    int startPos, endPos, i, j;
    char nameBuff[20];
    
    // Copy initial string until insert pos is reached
    startPos = 6;
    i = 0;
    while (i < startPos) {      // copy string until start insert pos is reached
        nameBuff[i] = name[i];
        i++;
    } // now it's time to insert the initial
    
    endPos = startPos + strlen(insertInital);
    j = 0;
    while (i < endPos) {
        nameBuff[i] = insertInital[j]; // a while loop is needed here for strings
        i++; // go to the next char
        j++;
    }
    
    // copy the rest of the string after insertion
    while (i < strlen(name) + sizeof(insertInital)) {   
        nameBuff[i] = name[i - strlen(insertInital)]; //why i - 1? -Because of strlen 
        i++;
    }
    
    printf("\n%s", nameBuff);
    
    return (EXIT_SUCCESS);
}

