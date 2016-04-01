/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 30, 2016, 9:59 PM
 */

/*
 * Write a function that raises an integer to a positibe integer power. Call
 * the function x_to_the_n taking two integer arguments x and n. Have the func-
 * return a long int, which represents the results of calculating xn.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 7
 */

long int x_to_the_n(int x, int n){
    long int result;
    result = x;
    int i = 1;
    while (i < n) {
        result *= x;
        ++i;
    }
    return result;
}

int main(int argc, char** argv) {
    printf("%li", x_to_the_n(2, 4));

    return (EXIT_SUCCESS);
}

