#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Chapter 10, Exercise 10
 * 
 * Write a function called dictionarySort that sorts a dictionary, as defined
 * in Programs 10.9 and 10.10, into alphabetical order.
 */
// I have sorted definitions

struct entry {
    char word[15];
    char definition[50];
};

void sort(struct entry dictionary[], int n) {  
    int i, j; 
    char temp[81]; // length not needed? rename it!!!
    
    for (i = 0; i < n - 1; i++)              // redo using a while loop?
        for (j = i + 1; j < n; j++)
            if (strcmp(dictionary[i].definition, dictionary[j].definition) > 0) {     //strcmp
                strcpy(temp, dictionary[i].definition);
                strcpy(dictionary[i].definition, dictionary[j].definition);
                strcpy(dictionary[j].definition, temp);
            }
}

int main(int argc, char** argv) {
    void sort(struct entry dictionary[], int length);
    struct entry dictionary[100] = {
        {"aardvark",    "a burrowing African mammal"       },
        {"abyss",       "a bottomless pit"                 },
        {"acumen",      "mentally sharp; keen"             },
        {"addle",       "to become confused"               },
        {"aerie",       "a high nest"                      },
        {"affix",       "to append; attach"                },
        {"agar",        "a jelly made from seaweed"        },
        {"ahoy",        "a nautical call of greeting"      },
        {"aigrette",    "an ornamental cluster of feathers"},
        {"ajar",        "partially opened"                 }        
    };
    
    sort(dictionary, 10);
    
    for (int i = 0; i < 9; i++) {
        printf("%s\n", dictionary[i].definition);
    }    
    
    return (EXIT_SUCCESS);
}