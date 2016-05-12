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
#include <stdbool.h>

/*
 * Chapter 10, Exercise 12
 * 
 * Write a function called strToFloat that converts a character string into a
 * floating point value. Have the function accept an optional leading minus.
 * So, the call
 * 
 * strToFloar("-867.6921");
 * 
 * should return the value -867.6921
 */

// flag the start of the decimal point !!!

double strToFloat(char string[]) { // type cast???
    int i, decimalCount = 0;
    double floatValue, result = 0;
    bool decimalPoint = false;
    
    // handle minus
    if (string[0] == '-') {
       for (i = 1; string[i] >= '.' && string[i] <= '9'; ++i) {
           if (string[i] == '/') { //skip the backslash
                i++;
                continue;
            } else if (string[i] == '.') { //skip the decimal point
                continue;
            }    
           
           floatValue = string[i] - '0';
           result = result * 10 + floatValue;  
       }
       return -result * 0.0001;
    } else {                  // calculate positive floating point number      
        for (i = 0; string[i] >= '.' && string[i] <= '9'; ++i) {
            
            if (string[i] == '/') { //skip the backslash
                i++;
                continue;
            } else if (string[i] == '.') { //skip the decimal period
                decimalPoint = true; // decimal point start
                continue;
            }             
            while (decimalCount < i + decimalCount)
                decimalCount++;
            // count the number of digits after a floating point
            floatValue = string[i] - '0';
            result = result * 10 + floatValue; 
        }
       return result * 0.0001; 
    }    
    
}

int main(int argc, char** argv) {
    printf("%f", strToFloat("867.6921"));

    return (EXIT_SUCCESS);
}

