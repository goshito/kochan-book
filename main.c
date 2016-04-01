/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 30, 2016, 10:25 PM
 */

/*
 * An equation of the form
 * ax^2 + bx + c = 0
 * is known as a quadratic equation. The values of a, b, and c in the preceding
 * example represent constant values. So
 * 4x^2 - 17x - 15 = 0
 * represents a quadratic equation where a = 4, b = -17, and c = 15. The values
 * of x that satisfy a particular quadratic equation, known as the roots of
 * the equation, can be calculated by substituting the the values of a, b,
 * and c into the following two formulas:
 *      
 *      If the value of b^2 - 4ac called discriminant, is less than zero, the
 *      roots of the equation, x1 and x2, are imaginary numbers.
 *      
 *      Write a program to solve a quadratic equation. The progra should allow
 *      the user to enter the values of a, b, and c. If the discriminant is
 *      less than zero, a message should be displayed that the roots are 
 *      imaginary; otherwise, the program should then proceed to calculate
 *      and display the two roots of the equation.(Note: Be certain to make use
 *      of the squareRoot function that you developed in this chapter.)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 8
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
    
    while (absoluteValue(guess * guess -x) >= epsilon)
        guess = (x / guess + guess) / 2.0;
    return guess;
}

// Function to calculate x to the n-th power
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

// Function to get the values of a, b, and c and return solution
void solveQuadraticEquation(void){
    float x, x1, x2;
    int a, b, c;
    
    printf("a = "); scanf("%i", &a);
    printf("b = "); scanf("%i", &b);
    printf("c = "); scanf("%i", &c);
    int D = (x_to_the_n(b, 2)) - 4 * (a * c);
    
    printf("D = %i\n", D);
    
    if (D < 0)
        printf("The roots of the equation, x1 and x2, are imaginary numbers\n");
    else if (D == 0) {
        x = -b / (2 * a);
        printf("x = %f\n", x);
    }    
    else {
        x1 = ( -b + (squareRoot(D)) ) / (2 * a);
        x2 = ( -b - (squareRoot(D)) ) / (2 * a);
        printf("x1 = %f\nx2 = %f\n", x1, x2);
    }
}

int main(int argc, char** argv) {
    solveQuadraticEquation();

    return (EXIT_SUCCESS);
}

