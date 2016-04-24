/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 22, 2016, 8:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Chapter 10, Exercise 8
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

/* 1. Get the functions
 * 2. Modify functions if necessary
 * 3. Should the string variables inside funcs be public??? 
 * 4. Should the void functions return values with results
 */

int findString(char s[], char t[]);
void removeString(char string[], int start_pos, int chars_to_remove);
void insertString(char text[], char insert[], int startPos);
void replaceString(char source[], char s1[], char s2[]);


int main(int argc, char** argv) {    
    //char test[] = "the wrong son";
    
    replaceString("text*123", "*", "");
    
    //printf("%s", test);
    return (EXIT_SUCCESS);
}

// Function to find string t inside string s and return found string position
int findString(char s[], char t[]) {
    for ( int i = 0; i <= strlen(s) - strlen(t); i++ ) {
        
        for ( int j = 0; j < strlen(t); j++ ) {
            
            if ( s[i + j] == t[j] ) {
                if ( j == strlen(t) - 1 )
                    return i;
            } else
                break;
        }
        
    }
    return -1;
}

void removeString(char string[], int start_pos, int chars_to_remove) {
    int i, end_point, end_of_string;
    char removal_result[81];
    
    i = 0;
    while (i < start_pos) {
        removal_result[i] = string[i];
        i++;
    }
    
    end_point = i + chars_to_remove;;
    end_of_string = strlen(string);
    
    while (end_point <= end_of_string) {
        removal_result[i] = string[end_point];
        end_point++;
        i++;
    }
    
    int size_string = strlen(string);
    int size_removal_result = strlen(removal_result);
    
    i = 0;
    while (i < size_string) {
        string[i] = removal_result[i];
        i++;
    }   
 
}

void insertString(char text[], char insert[], int startPos) {
    int  endPos, i, j;
    char nameBuff[strlen(text) + strlen(insert) + 1];
    
    i = 0;
    while (i < startPos) {
        nameBuff[i] = text[i];
        i++;
    }
    
    endPos = startPos + strlen(insert);
    
    j = 0;
    while (i < endPos) {
        nameBuff[i] = insert[j];
        i++;
        j++;
    }
    
    while (i < strlen(text) + sizeof(insert)) {
        nameBuff[i] = text[i - strlen(insert)];
        i++;
    }
    
    // allocate space for the new characters
    text = (char*) malloc(strlen(insert) + 1);
    
    // copy result back to initial string    
    strcpy(text, nameBuff);
    
    printf("%s", text);
    free(text);
}

void replaceString(char source[], char s1[], char s2[]) {
    int pos = findString(source, s1);
    char source_tmp[81], s1_tmp[81], s2_tmp[81];
    
    strcpy(source_tmp, source);     // source can't be changed
    //strcpy(s1_tmp, s1);
    //strcpy(s2_tmp, s2);
    if (pos != -1) {
        removeString(source_tmp, pos, strlen(s1));
        insertString(source_tmp, "geo", pos);
    } else {
        printf("\n%s not found in %s", s1, source);
    }    
    
}

// ne e nujno rezultata da se printira, no e dobre
// zashto removeString dava Segmentation Fault

