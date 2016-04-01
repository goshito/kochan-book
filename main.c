/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 1, 2016, 1:50 PM
 */

/* Modify Program 8.4 so the value of triangularNumber is returned by 
 * the function. Then go back to Program 5.5 and change that program
 * so that it calls the new version of the calculateTriangularNumber
 * function. */
 
 /* I have removed printf from inside the function, and added tree new
  * variables in which to store the result returned from the 
  * calculateTriangularNumber function. I also defined the function as
  * an int (insted of void as it was. The tree new variables correspond
  * to the parameters given to the function. */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 2
 */

int calculateTriangularNumber (int n) {
    int i, triangularNumber = 0;
    
    for ( i = 1; i <= n; ++i )
        triangularNumber += i;
        
    return triangularNumber;
}

int main(int argc, char** argv) {
    int ten, twenty, fifty;
    
    ten = calculateTriangularNumber (10);
    twenty = calculateTriangularNumber (20);
    fifty = calculateTriangularNumber (50);
    
    printf ("ten = %i\ntwenty = %i\nfifty = %i\n", ten, twenty, fifty);

    return (EXIT_SUCCESS);
}

