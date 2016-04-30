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

/* 
 * Chapter 10, Exercise 8 - solved, fixed blankspace bug
 * 
 * Using the findString, removeString, and insertString functions from preced-
 * ing exercises, write a function called replaceString that takes three char-
 * acter string arguments as follows
 * 
 * replaceString(source, s1, s2);
 * 
 * and that replaces s1 inside source with the character string s2. The function
 * should call the findString function to locate s1 inside source, then call the
 * removeString function to remove s1 from source, and finally call the 
 * insertString function to insert s2 into source at the proper location.
 * So, the function call
 * 
 * replaceString(text, "*", "");
 * 
 * has the effect of removing the first asterisk inside the text array because
 * the replacement string is the null string. 
 * 
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

void replaceString(char source[], char s1[], char s2[]) {       
    int foundat = findString(source, s1);
    removeString(source, foundat, strlen(s2) + 1);
    insertString(source, s2, foundat);
}

int main(int argc, char** argv) {
    char test[] = "georgi toshev";
    
    int findString(char srch_in[], char srch_for[]);
    void removeString(char string[], int start, int n);
    void insertString(char text[], char insert[], int start);
    void replaceString(char source[], char s1[], char s2[]);
    
    replaceString(test, " ", ""); // doesn't work with blank space - fixed
    printf("%s", test);

    return (EXIT_SUCCESS);
}

