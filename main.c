/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 1, 2016, 10:10 PM
 */

/* Modify the sord function from Program 8.12 to taka a third argument 
 * indicating wheter the array is to be sorted in ascending or descending
 * order. Then modify the sort algorithm to correctly sort the array into
 * the indicated order. */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 13
 */

void sort(int a[], int n, char choice);

int main(int argc, char** argv) {
    
    int arr[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};
    
    // Array before the sort
    for(int i = 0; i < 16; i++)
        printf("%i ", arr[i]);
    
    printf("\n");
    
    sort(arr, 16, 'a'); //'a' for ascending or 'd' for descending
    
    // Array after the sort
    for(int i = 0; i < 16; i++)
        printf("%i ", arr[i]);

    return (EXIT_SUCCESS);
}

void sort(int a[], int n, char choice) {
    int temp;
    
    for(int i = 0; i < n - 1; i++) {            
        for(int j = i + 1; j < n; j++) {
            if (choice == 'a') {
                if (a[i] > a[j]) {          
                   temp = a[i];
                   a[i] = a[j];
                  a[j] = temp;                                        // j = j + 1 (j++)
                }
            } else if (choice == 'd') {
                if (a[i] < a[j]) {          
                   temp = a[i];
                   a[i] = a[j];
                  a[j] = temp;                                        // j = j + 1 (j++)
                }
            }
        }
    }
}


