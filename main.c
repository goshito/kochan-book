/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 1, 2016, 3:32 PM
 */

/* Modify Program 8.8 so that the value of guess is printed each
time through the while loop. Notice how quickly the value of guess
converges to the square root. What conclusions can you reach about 
the number of iterations through the loop, the number whose square
root is being calculated, and the value of the initial guess? */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 4
 */

// Function to calculate the absolute value of a number
float absoluteValue (float x) {
    if ( x < 0 )
        x = -x;
        return (x);
}

// Function to compute the square root of a number
float squareRoot (float x) {
    const float epsilon = .00001;
    float       guess = 1.0;
    
    while ( absoluteValue ( guess * guess - x ) >= epsilon ) {
        printf("guess = %f\n", guess);
        guess = ( x / guess + guess ) / 2;
    }
        
    return guess;
}

int main(int argc, char** argv) {
    printf("squareRoot (2.0) = %f\n", squareRoot (2.0));
    printf("squareRoot (144.0) = %f\n", squareRoot (144.0));
    printf("squareRoot (17.5) = %f\n", squareRoot (17.5));
    return (EXIT_SUCCESS);
}
