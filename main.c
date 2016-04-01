/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on March 31, 2016, 3:48 PM
 */

/*A matrix M with i rows, j columns can be transposed into a matrix N having j rows
and i columns by simply setting the value of N a,b equal to the value of M b,a for all
relevant values of a and b.
a. Write a function transposeMatrix that takes as an argument a 4 x 5 matrix
and a 5 x 4 matrix. Have the function transpose the 4 x 5 matrix and store
the results in the 5 x 4 matrix. Also write a main routine to test the function.*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 8, Exercise 12b
 * 101th try...FUCKnSHit
 * Is it possible to create a variable length multidimensional array in C??
 */

void transposeMatrix(int row, int column, int matrix[row][column]) {
    // Should I create a new matrix to hold the transposed matrix given
    // as argument to the function???
    int r, c; // These variables will be used for printing the matrix
    
    // Transpose the matrix
    for (row = 0; row < column; row++) {
        for (column = 0; column < row; column++)
            matrix[row][column] = matrix[column][row];
    }
    // Display the transposed matrix
    for (r = 0; r < c; r++) {
        for (c = 0; c < r; c++) {
            printf("%i", matrix[r][c]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int sampleMatrix[4][5] = {
        { 1, 2, 3, 4, 5 },
        { 5, 4, 3, 2, 1 },
        { 2, 3, 4, 5, 6 },
        { 9, 8, 7, 6, 5 }
    };
    int transposedMatrix[5][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}        
    };
    
    transposeMatrix(4, 5, sampleMatrix);

    return (EXIT_SUCCESS);
}

