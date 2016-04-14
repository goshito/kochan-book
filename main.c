/* 
 * Chapter 10, exercise 6 - Remove elements from an array
 * The purpose of this program is to remove some elements from an array
 * I am trying to accomplish that by copying the the elements that should 
 * remain after deletion to another string. Then I will copy the second string
 * back into the first one.
 *  
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[81];
    int start_pos, chars_to_remove, end_point, end_of_string, i, j;
    char removal_result[81];
    
    printf("Enter string: ");
    gets(str);
    //scanf("%s", str);
    
    printf("\nFrom which character to start removal?\n");
    scanf("%i", &start_pos);
    
    printf("\nHow many chars would you like to remove?\n");
    scanf("%i", &chars_to_remove);
    
    // Copy entered string elements until start position is reached
    i = 0;
    while (i < start_pos) {
        removal_result[i] = str[i];
        i++;
    }
    
    end_point = i + chars_to_remove;
    end_of_string = strlen(str);
    
    while (end_point <= end_of_string) {
        removal_result[i] = str[end_point];
        end_point++;
        i++;
    }
    
    printf("Here's what you've done: %s", removal_result);
    
    // Now copy the processed string back to the original one
    int size_str = strlen(str);
    int size_removal_result = strlen(removal_result);
    
    // Move elements back to original string
    i = 0;
    while (i < size_str) {
        str[i] = removal_result[i];
        i++;
    }
    
    printf("\n copy string result = %s", str);
    
    /*
    printf("\nsize_str = %i", size_str);
    printf("\nsize_removal_result = %i", size_removal_result);
    */
    return 0;
}
/*     printf("\nend_point: %i\n", end_point);
    printf("\nend of string: %i\n", end_of_string); */
