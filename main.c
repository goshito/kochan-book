
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on May 4, 2016, 1:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>
//#include <math.h>

/*
 * Chapter 10, Exercise 12 Attempting to DRY 14052016 1857
 * 
 * Write a function called strToFloat that converts a character string into a
 * floating point value. Have the function accept an optional leading minus.
 * So, the call
 * 
 * strToFloar("-867.6921");
 * 
 * should return the value -867.6921
 */

// 

double strToFloat(char string[]) { // type cast???
    int i = 0, j, decpnt;
    double floatValue, result = 0;
    
    // handle minus
    if (string[0] == '-')
        i++;
    else {
       for (i; string[i] >= '.' && string[i] <= '9'; ++i) {
           if (string[i] == '/') { //skip the backslash
                i++;
                continue;
            } else if (string[i] == '.') { //skip the decimal point
                if (string[0] == '-')
                    decpnt = i - 1; // mark start of decimal point(-1 because for i = 1)
                else
                    decpnt = i;
                continue;
            }    
           
           floatValue = string[i] - '0';
           result = result * 10 + floatValue;  
       }
       
       for (j = 0; result >= 1; j++) {
            result /= 10;
        }
        // place the decimal point
        for (int m = 0; m < decpnt; m++) {
            result *= 10;
        } 
       if (string[0] == '-')
           return -result;
       else
           return result;
    }   
    
}

int main(int argc, char** argv) {
    printf("%f", strToFloat("-121.93")); // working

    return (EXIT_SUCCESS);
}

/*
 * Ideas:
 * 
 * 1. Decimal count isn't used 
 */