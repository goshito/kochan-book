/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 31, 2016, 2:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*Chapter 8, Exercise 10
 * Write a function prime that returns 1 if its argument is a prime number
 * and returns 0 otherwise.
 */

int isPrime(int n) {
    int i;
    
    if (n <= 1)
        return 0;
    else if (n <= 3)
        return 1;
    else if (n % 2 == 0 || n % 3 == 0)
        return 0;
    
    i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6;
    }
    return 1;
}

int main(int argc, char** argv) {
    printf("%i", isPrime(7));
    

    return (EXIT_SUCCESS);
}

