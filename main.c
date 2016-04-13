/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 13, 2016, 3:30 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 10, Exercise 5 (unsuccessful attempt 1)
 * 
 * Write a function called findstring to determine if one character string exists
 * inside another string. The first argument to the function should be the char-
 * acter string that is to be searched and the second argument is the string you
 * are interested in finding. If the function finds the specified string, have
 * return the location in the source string where the string was found. If the
 * function does not find the string, have it return -1. So for example, the call
 * 
 * index = findstring("a chatterbox", "hat");
 * 
 * searches the string "a chatterbox" for the string "hat". Because "hat" does
 * exist inside the source string, the function returns 3 to indicate the star-
 * ting position inside the source string where "hat" was found.
 * 
 */

/*
 * Algorith to solve the problem:
 * 1. if str1[i] == str2[i] && str1[i+1] == str2[i+1] 
 * 2. Copy each character that matches in a new array
 * 3. compare character by character???
 * 4. How to determine lenght of a string
 */

int findString(char s1[], char s2[]) {
    char result[81];
    int i = 0;
    int keepGoing = 1;
    
    while (keepGoing) {
        if (s2[i] == s1[1] && s2[i+1] == s1[i + 1]) {
            result[i] = s2[i];
            i++;
        } else {
            keepGoing = 0;
        }
    }
    
    printf("%s", result);
    
}

int main(int argc, char** argv) {
    findString("a chatterbox", "hat");

    return (EXIT_SUCCESS);
}

