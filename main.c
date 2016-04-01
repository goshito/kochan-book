/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 29, 2016, 1:52 PM
 */

/* 
 * Chapter 8, Exercise 5
 * I can't understand the fuckin' maths in this exercise 
 */

#include <stdio.h>
#include <stdlib.h>

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
    
    /* Here is a solution from http://www.linuxquestions.org/questions/programming-9/simple-c-program-but-stuck-please-help-732707/:
     * while ( absoluteValue( 1 - (guess*guess)/x )  >=  epsilon )
     * Is it correct???
    */
    while ( absoluteValue (guess * guess -x) >= epsilon ) {
        printf("guess = %f\n", guess);
        guess = ( x / guess + guess ) / 2.0;
        printf ("guess after assignment = %f\n", guess);
    }
    return guess;
}

/*
 * 
 */
int main(int argc, char** argv) {
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));

    return (EXIT_SUCCESS);
}

