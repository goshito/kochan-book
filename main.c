/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 15, 2016, 1:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Chapter 10, Exercise 7
 * 
 * Write a function called insertString to insert one character string into
 * another string. The arguments to the function should consist of the source
 * string, the string to be inserted, and the position in the source string
 * where the string is to be inserted. So the call
 * 
 * insertString(text, "per", 10);
 * 
 * with text as originally defined in the previous exercise, results in the
 * character string "per" being inserted inside text, beginning at text[10]. 
 * Therefore, the character
 * string "the wrong person" is stored inside the text array after the function
 * returned.
 */

void insertString(char source[], char insert[], int pos) {
    int sourceSize = strlen(source);
    int insertSize = strlen(insert);
    int strSumSizes = strlen(source) + strlen(insert);
    int i;
    // copy the elements to free space for insert string
    //printf("initial pos = %i\n", pos);
    while (pos < sourceSize) {
        source[pos + insertSize] = source[pos];
        pos++;
    }
    source[pos + insertSize] = '\0';
    /*
    source[pos + insertSize] = source[pos];
    printf("%c", source[pos + insertSize]);
    pos++;
    source[pos + insertSize] = source[pos];
    printf("%c", source[pos + insertSize]);
    pos++;
    source[pos + insertSize] = source[pos];
    printf("%c", source[pos + insertSize]);
    source[pos + insertSize + 1] = '\0';
    */
    //printf("\nposition after array expand = %i\n", pos);
    
    
    pos = (sourceSize - insertSize);    
    i = 0;
    while (i < insertSize) {
        source[pos] = insert[i];
        pos++;
        i++;
    }
    
    /*
    source[pos] = insert[0];
    pos++;
    source[pos] = insert[1];
    pos++;
    source[pos] = insert[2];
    */    
}

int main(int argc, char** argv) {
    char text[] = "the wrong son";
    
    insertString(text, "per", 10);
    printf("%s", text);

    return (EXIT_SUCCESS);
}

/*#include <stdio.h>
#include <string.h>

int main(void) {
    char src_str[] = "the wrong son";
    char str_ins[] = "per";
    int i, ins_pos, new_str_size; 
    
    ins_pos = (strlen(src_str) - (strlen(str_ins)));
    new_str_size = strlen(src_str) + strlen(str_ins);
    
    // free up space for insertion
    i = ins_pos + strlen(str_ins);
    while (i <= new_str_size) {
        src_str[i] = src_str[i];
        i--;
    }
    
    
    while (ins_pos < strlen(src_str)) {        
        src_str[ins_pos] = str_ins[i];
        ins_pos += sizeof(str_ins);
        ins_pos++;
        //i++;
    }
    
    printf("src_str = %s", src_str);
    
    return 0;
}
*/