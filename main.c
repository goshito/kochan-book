/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 3, 2016, 1:12 PM
 */

/* Rewrite the functions developed in the last four exercise to use global
 variables instead of arguments. For example, the preceding exercise should
 now sort a globally defined array. */

#include <stdio.h>
#include <stdlib.h>

int i, n, sum;
int array[5] = {1, 2, 3, 4, 5};

int arraySum(int array[], int n);

/*
 * Rewrite of Exercise 11
 */
int main(int argc, char** argv) {
    
    n = 5;
    
    arraySum(array, n);
    
    printf("%i", arraySum(array, 5));

    return (EXIT_SUCCESS);
}

int arraySum(int array[], int n) {
    i = 0;
    sum = 0;
    
    while (i < n) {
        sum += array[i];
        i++;
    }
    return sum;
}


