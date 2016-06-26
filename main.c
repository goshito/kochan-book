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

/*Chapter 11, Exercise 3
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

int main(int argc, char** argv) {
    void print_list(struct entry *list_pointer);
    void insert_entry(struct entry *insert, struct entry *after);    
    
    struct entry n0, n1, n2, n3, start;
    
    start.next = &n1;
    
    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;
    
    n3.value = 300;
    n3.next = (struct entry *) 0;
    
    //display the linked list before insert
    print_list(start.next);
    
    //insert n0
    n0.value = 50;
    //
    insert_entry(&n0, &start);
    //display the linked list after insertion of an element at the beginning
    print_list(start.next);
    
    return (EXIT_SUCCESS);
}

//
void insert_entry(struct entry *insert, struct entry *after) {
    
    insert->next = after->next;
    after->next = insert;
    
}

// function to display the contents of a linked list
void print_list(struct entry *list_pointer) {
    
    while (list_pointer != (struct entry *) 0) {
        printf("%i, ", list_pointer->value);
        list_pointer = list_pointer->next;
    }
    printf("\n");
    
}



/* 
 * 1. create linked list with ?sample elements 
 * 2. Program works, now set the variables readable names
 * 
 * struct entry *ptr_n2 = &n2, *ptr_n21 = &n21; and *list_start..
 * are these necessary?
 * 3. I will remove list_start pointer
 *       
 */