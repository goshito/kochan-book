/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 26, 2016, 3:05 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * You can extend even further the usefulness of the replaceString function
 * from the preceding exercise if you have it return a value that indicates 
 * whether the replacement succeeded, which means that the string was found
 * inside the source strinf. So, if the function returns true if the replace-
 * ment succeeds and false if it does not, the loop
 * 
 * do
 *  stillFound = replaceString(text, " ", "");
 * while(stillFound = true);
 * 
 * could be used to remove all blank spaces from text, for example.
 * Incorporate this change into the replaceString function and try it with var-
 * ious character strings to ensure that it works properly.
 */

int findString(char s[], char t[]);
void removeString(char string[], int start_pos, int chars_to_remove);
void insertString(char text[], char insert[], int startPos);
bool replaceString(char source[], char s1[], char s2[]);

int main(int argc, char** argv) {
    bool stillFound;    
    char name[81] = "georgi valeriev toshev georgiev";
    
    do 
        stillFound = replaceString(name, " ", "");
    while (stillFound = true);
    
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
    
    while (i < strlen(text) + strlen(insert) + 1) {
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

bool replaceString(char source[], char s1[], char s2[]) {
    int pos = findString(source, s1); // 
    char source_tmp[81];
    
    strcpy(source_tmp, source);     // source can't be changed
    //strcpy(s1_tmp, s1);
    //strcpy(s2_tmp, s2);
    
    // !!! while loop for the blank spaces here
    
    if (pos != -1) {
        removeString(source_tmp, pos, strlen(s1));
        insertString(source_tmp, s2, pos);
        return true;
    } 
    else 
        false;
    
}

/* Notes
 * copy source_tmp back to source
 */

