/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 3, 2016, 12:41 PM
 */

/* Rewrite the functions developed in the last four exercise to use global
 variables instead of arguments. For example, the preceding exercise should
 now sort a globally defined array. */

#include <stdio.h>
#include <stdlib.h>

/*
 * Rewrite of exercise 10
 */

int i;

int isPrime(int n) {
    //int i;
    
    if(n <= 1)
        return 0;
    else if (n <= 3)
        return 1;
    else if (n % 2 == 0 ||n % 3 == 0)
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

