/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on May 13, 2016, 9:44 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Chapter 10, Exercise 13
 * 
 * If c is a lowercase character, the expression
 * c -'a' + 'A'
 * produces the uppercase equivalent of c, assuming an ASCII character set.
 * Write a function called uppercase that converts all lowercase characters in 
 * a string into their uppercase equivalents. 
 */

/*
 * Algorithm:
 * 
 * 1. C = c - 'a' + 'A (67 = 99 - 97 + 65)
 * 2. create a buff string to hold the uppercase letters
 * 3. copy buff string back to original string 
 * 4. convert???
 */

void uppercase(char string[]) {
    char buffStr[strlen(string) + 1];
    
    for (int i = 0; i < strlen(string); i++) {
        buffStr[i] = string[i] - 97 + 65; //copying and converting to u
    }
    //printf("%s\n", buffStr);
    //printf("sizeof buffStr = %d\n", sizeof(buffStr));
    
    strcpy(string, buffStr);
}

int main(int argc, char** argv) {
    //printf("%c\n", 'd' - 'a' + 'A');
    void uppercase(char string[]);
    char name[] = "georgi"; //printf("%li", sizeof(name));   
    
    //printf("%s\n", uppercase(name)); // invalid use of void expression
    uppercase(name);
    printf("%s\n", name); //printf("sizeof name = %d\n", sizeof(name));

    return (EXIT_SUCCESS);
}

