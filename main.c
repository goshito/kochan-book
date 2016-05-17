/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on May 13, 2016, 11:30 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Chapter 10, Exercise 14
 * 
 * Write a function called intToStr that converts an integer value into a 
 * character string. Be certain the function handles negative integers properly.
 */

void intToStr(int value, char str[]) { 
    int value_tmp, digit_count, digit, i, origin_value;
    //backup original value for later use
    origin_value = value;
    // treat value as positive for the convert, will add minus to str[0] later
    if (value < 0) {
        value = -value;
    }
    
    // make a copy of value because I need to use original value later
    value_tmp = value;
    
    // count the number of digits
    for (digit_count = 0; value_tmp >= 1; digit_count++) {
        value_tmp /= 10;
    }
    
    //extract the digits and handle minus situation
    if (origin_value < 0) {
        i = digit_count;
        str[0] = '-';
    }
    else
        i = digit_count - 1;
    do {
        digit = value % 10;
        str[i] = digit + '0';
        value = value / 10;
        i--;
    } while (value >= 1);
}
int main(int argc, char** argv) {
    void intToStr(int value, char str[]);
    char numStr[100];
    
    intToStr(-1234, numStr);
    
    printf("%s\n", numStr);

    return (EXIT_SUCCESS);
}

// backup from before adding else condition

