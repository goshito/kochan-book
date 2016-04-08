/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 7, 2016, 11:18 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 9, Exercise 2 
 * 
 * In certain applications, particularly in the financial
 * area, it is often necessary to calculate the number of elapsed days between
 * two dates. For example, the number of days between July 2, 2005, and July
 * 16, 2005, is obviously 14. But how many days are between August 8, 2004, 
 * and February 22, 2005? This calculation requires a bit more thought.
 * Luckily, a formula can be used to calculate the number of days between two
 * dates. This is affected by computing the value of N for each of the two 
 * dates and then taking the difference, where N is calculated as follows:
 * 
 * N = 1461 x f(year, month) / 4 + 153 x g(month) / 5 + day
 * 
 * where
 * 
 * f(year, month)   =   year - 1        if month <= 2
 *                      year            otherwise
 * 
 * g(month)  =       month + 13        if month <= 2
 *                   month + 1         otherwise
 *                  
 * 
 * As an example of applying the formula, to calculate the number of days 
 * between August 8, 2004, and February 22, 2005, you can calculate the values
 * of N1 and N2 by substituing the appropriate values into the preceding formula
 * as shown:
 * 
 * N1 = 1461 x f(2004, 8) / 4 + 153 x g(8) / 5 + 3
 * !!!(I think at the end of the above expression should be 8 instead of 3)
 * = (1461 x 2004) / 4 + (153 x 9) / 5 + 3
 * = 2,927,844 / 4 + 1,377 / 5 + 3
 * = 731,961 + 275 + 3
 * = 732,239
 * 
 * N2 = 1461 x f(2005, 2) / 4 + 153 x g(2) / 5 + 21
 * !!!(I think at the end of the above expression should be 22 instead of 21)
 * = (1461 x 2004) / 4 + (153 x 15) / 5 + 21
 * = 2,927,844 / 4 + 2,295 / 5 + 21
 * = 731,961 + 459 + 21
 * = 732,441
 * 
 * Number of elapsed days   = N2 - N1 = 732,441 - 732,239 = 202
 * 
 * So the number of days between the two dates is shown to be 202. The 
 * preceding for mula is applicable for any dates after March 1, 1900 (1 must 
 * be added to N for dates between March 1, 1700, and February 28, 1800).
 * 
 * Write a program that permits the user to tye in two dates and then calculates
 * the number of elapsed days between the two dates. Try to structure the 
 * program logically into separate functions. For example, you should have a
 * function that accepts as an argument a date structure and returns the values
 * of N computed as shown preciously. This function can then be called twice,
 * once for each date, and the difference taken to determine the number of
 * elapsed days.
 */

/* Algorithm:
 * 1. User input of the two dates
 *      - store the dates in two separate structures or one structure??
 *        I will store them in two structure date variables
 * 2. Calculate the number of elapsed days between the two dates
 *  */

struct date {
        int month;
        int day;
        int year;
    };

// Function to calculate f(year, month) and return the value of year !!!(Should the function take structure??)

int f(int year, int month) {
    if (month <= 2)
        return year - 1;
    else
        return year;
}

// Function to calculate g(month) !!!(Should the function take structure??)

int g(int month) {
    if (month <= 2)
        return month + 13;
    else
        return month + 1;
}

// Function to calculate N

int calcDays(struct date date) {
    int n;
    
    n = 1461 * f(date.year, date.month) / 4 + 153 * g(date.month) / 5 + date.day;
    
    return n;
}

int main(int argc, char** argv) {
    int n1, n2, elapsed_days;
    
    struct date date1, date2;
        
    printf("Enter date #1(mm/dd/yyyy): \n");
    scanf("%i/%i/%i", &date1.month, &date1.day, &date1.year);
    getchar();
    printf("Enter date #2(mm/dd/yyyy): \n");
    scanf("%i/%i/%i", &date2.month, &date2.day, &date2.year);
    getchar();
    
    elapsed_days = calcDays(date2) - calcDays(date1);
    
    /*
    n1 = 1461 * f(date1.year, date1.month) / 4 + 153 * g(date1.month) / 5 + date1.day;
    n2 = 1461 * f(date2.year, date2.month) / 4 + 153 * g(date2.month) / 5 + date2.day;
    elapsed_days = n2 - n1;
    */
    
    printf("elapsed_days=%i\n", elapsed_days);

    return (EXIT_SUCCESS);
}

