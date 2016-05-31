/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   insEntry.c
 * Author: georgi
 *
 * Created on May 29, 2016, 2:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*Chapter 11, Exercise 2
 * 
 * Write a function called insertEntry to insert a new entry into a linked list. Have
the procedure take as arguments a pointer to the list entry to be inserted (of type
struct entry as defined in this chapter), and a pointer to an element in the list
after which the new entry is to be inserted.
 */

struct entry {
    int value;
    struct entry *next;
};
//function to insert an entry into the linked list
void insertEntry(struct entry *insert, struct entry *after) {
    insert->value = 250;
    insert->next = after->next;
    after->next = insert;
}
//function to display the contents of the linked list
void printList(struct entry *list_pointer) {
    
    while (list_pointer != (struct entry *) 0) {
        printf("%i", list_pointer->value);
        list_pointer = list_pointer->next;
        if (list_pointer)
            printf(",");
    }
    
}

int main(int argc, char** argv) {
    
    struct entry n1, n2, n3, *list_start = &n1;
    struct entry n21; // this will be inserted
    struct entry *ptr_n2 = &n2, *ptr_n21 = &n21;    
    
    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;
    
    n3.value = 300;
    n3.next = (struct entry *) 0;
    
    //display the linked list before insert
    printList(list_start);
    //insert n21 after n2
    insertEntry(ptr_n21, ptr_n2);
    //display the linked list
    printList(list_start);
    
    return (EXIT_SUCCESS);
}

/* 
 * 1. create linked list with ?sample elements 
 * 2. Program works, now set the variables readable names
 *       
 */