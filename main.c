/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 31, 2016, 3:23 PM
 */

/* 
 *  Write a function called arraySum that takes two arguments: an integer array and
the number of elements in the array. Have the function return as its result the sum
of the elements in the array.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 11
 */

int arraySum(int array[], int n) {
    int i, sum = 0;
    
    i = 0;
    while (i < n) {
        sum += array[i];
        i++;
    }
    
    return sum;               
}

int main(int argc, char** argv) {
    int arr[] = {1, 2, 3, 4, 5};
    
    printf("%i", arraySum(arr, 5));

    return (EXIT_SUCCESS);
}

