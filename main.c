/*
 * Chapter 10, Exercise 6 solved with function
 * 
 * Remove some elements from an array
 */

#include <stdio.h>
#include <string.h>

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

int main(void) {
    char test[] = "the wrong son";
    
    removeString(test, 4, 6);
    
    printf("test = %s", test);
    
    return 0;
}