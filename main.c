/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 1, 2016, 3:27 PM
 */

/* Modify Program 8.8 so the value of epsilon is passed as an argument to
 * the function. Try experimenting with different values of epsilon to
 * see the effect that it has on the value of square root */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

// Function to calculate the absolute value of a number
float absoluteValue (float x) {
    if ( x < 0 )
        x = -x;
        return (x);
}

// Function to compute the square root of a number
float squareRoot (float x, const float epsilon) {
    //const float epsilon = .00001;
    float       guess = 1.0;
    
    while ( absoluteValue ( guess * guess - x) >= epsilon )
        guess = ( x / guess + guess ) / 2;
        
    return guess;
}

int main(int argc, char** argv) {
    printf("squareRoot (2.0) = %f\n", squareRoot (2.0, .01000));
    printf("squareRoot (144.0) = %f\n", squareRoot (144.0, 00001));
    printf("squareRoot (17.5) = %f\n", squareRoot (17.5, 00001));

    return (EXIT_SUCCESS);
}

