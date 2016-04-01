/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 31, 2016, 2:06 PM
 */

// function to return greatest common divisor
int gcd(int u, int v) {
    int temp;
    
    while (v != 0){
        temp = u % v;
        u = v;
        v = temp;
    }
    return u;
}

// function to return the least common multiple
int lcm(int a, int b) {
    int result = a / gcd(a, b) * b;
    return result;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 9
 */
int main(int argc, char** argv) {
    printf("lcm if 15 and 10 = %i", lcm(15, 10));

    return (EXIT_SUCCESS);
}

