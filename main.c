/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 1, 2016, 3:04 PM
 */

/* Modify Program 8.4 so the value of triangularNumber is returned by 
 * the function. Then go back to Program 5.5 and change that program
 * so that it calls the new version of the calculateTriangularNumber
 * function. */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int calculateTriangularNumber (int n) {
    int i, triangularNumber = 0;
    
    for ( i = 1; i <= n; ++i )
        triangularNumber += i;
        
    return triangularNumber;
}

int main(int argc, char** argv) {
    int n, number, triangularNumber, counter;
    
    int calculateTriangularNumber (int n);
    
    for ( counter = 1; counter <= 5; ++counter ) {
        printf("What triangular number do you want? ");
        scanf("%i", &number);
        triangularNumber = calculateTriangularNumber (number);
        
        /*triangularNumber = 0;
        
        for ( n = 1; n <= number; ++n )
            triangularNumber += n;*/
            
        printf("Triangular number %i is %i\n\n", number, triangularNumber);
    }

    return (EXIT_SUCCESS);
}

