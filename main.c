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

void insertString(char source_str[], char str_to_insert[], int pos) {
    
    // go to i-th position
    int i = 0;
    while (i <= pos) {
        i++;
    }
    
    while (i < strlen(source_str)) {
        source_str[i] = ' ';
    }
    printf("%s", source_str);
}

int main(int argc, char** argv) {
    char text[] = "the wrong son";
    
    insertString(text, "per", 10);

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