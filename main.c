/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 12, 2016, 7:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Chapter 10, Exercise 3
 * 
 * The countWords function from Programs 10.7 and 10.8 incorrectly counts a word
 * that contains an apostrophe as two separate words. Modify this function to
 * correctly handle this situation. Also, extend the function to count a 
 * sequence of positive or negative numbers, including any embedded commas and
 * periods, as a single word.
 */

/* Algorithm to solve this problem:
 * 1. Copy, paste the countWords and alphabetic functions
 * 2. Test count words with apostrophe situation
 * 3. countWords function doesn't work with scanf input
 * 4. Testing char by char input - input works but why funny characters appear
 *      after echoed input
 * 5. Try to count array filled up with getchar - success
 * 6. Determine the funny characters that appear below input echo
 *      will try to put a null string at the end of the test array - worked.
 *      The funny characters were garbage value I guess
 * 7. Deal with the apostrophe by adding else if within countWords
 * 8. Deal with commas periods and sequence of numbers to be represented as
 *      a word. - It worked but I don't like it much (too long)
 * 9. Deal with sequence of negative numbers
 */

// Function to determine if a character is alphabetic

bool alphabetic(const char c) {
    if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
        return true;
    else
        return false;
}

// Function to count the number of words in a string

int countWords(const char string[]) {
    int i, wordCount = 0;
    bool lookingForWord = true, alphabetic(const char c);
    
    for (i = 0; string[i] != '\0'; ++i)
        if (alphabetic(string[i]) || string[i] == '.' || string[i] == ',' || string[i] == '-' || (string[i] >= 48 && string[i] <= 57)) {
            if (lookingForWord) {
                ++wordCount;
                lookingForWord = false;
            }
        } else if (string[i] == '\'') {
            if (lookingForWord) {
                ++wordCount;
                lookingForWord = false;
            }
        } else 
            lookingForWord = true;
    
    return wordCount;
}

/* Program is modified by me to accept input and count the words from it, char
 * by char because with scanf it didn't work. */
int main(int argc, char** argv) {
    char test[81];
    int i;
    int countWords(const char string[]);
    
    i = 0;
    while ((test[i] = getchar()) != '\n') {        
        i++;
    }
    /* put a null character at the end of the filled array to deal with funny
     * that appear after echoed input
     */
    test[i + 1] = '\0';
    
    printf("\n%s", test);
    
    printf("\n%i words counted", countWords(test));

    return (EXIT_SUCCESS);
}

