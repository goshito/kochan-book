/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 30, 2016, 2:21 PM
 */

/* Modify Program 8.8 so that the squareRoot function accepts a double
 precision argument and returns the result as a double precision value. Be
 Certain to change the value of the variable epsilon to reflect the fact that
 double precision values are now being used.*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 6
 */
// Function to calculate the absolute value of a number
double absoluteValue(double x) {
    if (x < 0)
        x = -x;
    return x;    
}

// Function to compute the square root of a number
double squareRoot(double x) {
    const double epsilon = .00001;
    double guess = 1.0;
    
    while ( absoluteValue(guess * guess -x) >= epsilon )
        guess = ( x / guess + guess ) / 2.0;
    return guess;
}
int main(int argc, char** argv) {
    printf("squareRoot (2.0) = %f\n", squareRoot(2.0));
    printf("squareRoot (144.0) = %f\n", squareRoot(144.0));
    printf("squareRoot (17.5) = %f\n", squareRoot(17.5));

    return (EXIT_SUCCESS);
}

