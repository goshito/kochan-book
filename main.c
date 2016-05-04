/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on May 3, 2016, 7:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 10, Exercise 11
 * 
 * Extend the strToInt function from Program 10.11 so that if the first charac-
 * ter of the string is a minus sign, the value that follows is taken as a nega-
 * tive number.
 */

int strToInt(const char string[]) { 
    int i, intValue, result = 0;
    
    if (string[0] == '-') {
       for (i = 1; string[i] >= '0' && string[i] <= '9'; ++i) {
           intValue = string[i] - '0';
           result = result * 10 + intValue;  
       }
       return -result;
    } else {
        for (i = 0; string[i] >= '0' && string[i] <= '9'; ++i) {
           intValue = string[i] - '0';
           result = result * 10 + intValue; 
        }
       return result; 
    }    
    
}

int main(int argc, char** argv) {
    int strToInt(const char string[]);
    
    printf("%i\n", strToInt("-245"));
    printf("%i\n", strToInt("100") + 25);
    printf("%i\n", strToInt("13x5"));

    return (EXIT_SUCCESS);
}