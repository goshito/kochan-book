/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 30, 2016, 9:02 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* 
 * Chapter 10, Exercise 9
 * 
 * You can extend even further the usefulness of the replaceString function
 * from the preceding exercise if you have it return a value that indicates whe-
 * ther the replacement succeeded, which means that the string to be replaced
 * was found inside the source string. So, if the function returns ture if the
 * replacement succeeds and false if it does not, the loop
 * 
 * do
 *      stillFound = replaceString(text, " ", "");
 * while (stillFound = true);
 * 
 * could be used to remove all blank spaces from text, for example.
 * Incorporate this change into the replaceStrings function and try it with var-
 * ious character strings to ensure that it works properly.
 */

// function to search for a substring, returns position ot -1 if not found
int findString(char srch_in[], char srch_for[]) {
    int i, j;
    
    i = 0;
    while (i <= strlen(srch_in) - strlen(srch_for)) {
        
        j = 0;
        while (j <= strlen(srch_for)) {            
            if (srch_in[i + j] == srch_for[j]) {
                if (j == strlen(srch_for) - 1)
                    return i;
            } else
                break;
            j++;
        }
        
        i++;
    }
    return -1;
}
// function to remove n characters from string from start position on
void removeString(char string[], int start, int n) {
    char *buffer;
    int i, j;
    
    buffer = (char *) malloc(strlen(string));
    // get the chars until start position
    i = 0;
    while (i < start) {
        buffer[i] = string[i];
        i++;
    }
    // get rid of some chars by not copying them in the buffer    
    // continue to copy in the buffer
    
    while (i < strlen(string)) {
        buffer[i] = string[i + n];
        i++;
    }
    
    strcpy(string, buffer);
    
    free(buffer);
}
//function to insert string into text[] from start position on
void insertString(char text[], char insert[], int start) {
    int strs_len = strlen(text) + strlen(insert), i, j;
    char buffer[strs_len];
    
    i = 0;
    while (i < start) {
        buffer[i] = text[i];
        i++;
    }
    j = 0;
    while (i < strlen(insert) + start) {
        buffer[i] = insert[j];
        i++;
        j++;
    } // i = 13
    while (i < strs_len) {
        buffer[i] = text[i - strlen(insert)];
        i++;
    }
    buffer[i] = '\0';
    
    strcpy(text, buffer);
    
}

bool replaceString(char source[], char s1[], char s2[]) {       
    int foundat = findString(source, s1);
    if (foundat == -1)
        return false;
    else {
        removeString(source, foundat, strlen(s2) + 1);
        insertString(source, s2, foundat);
    }
    return true;
}

int main(int argc, char** argv) {
    char test[] = "georgi valeriev toshev";
    bool stillFound;
    
    int findString(char srch_in[], char srch_for[]);
    void removeString(char string[], int start, int n);
    void insertString(char text[], char insert[], int start);
    bool replaceString(char source[], char s1[], char s2[]);
    
    do {
        stillFound = replaceString(test, " ", "");
    } while (stillFound == true);
     
    printf("%s", test);

    return (EXIT_SUCCESS);
}

