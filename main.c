/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 10, 2016, 5:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 *  Chapter 9, Exercise 6
 */

/* Replace the dateUpdate function from Program 9.4 with the modified one that
 * uses compound literals as presented in the text. Run the program to verify
 * its proper operation.*/

struct date {
    int month;
    int day;
    int year;
};

// Function to calculate tomorrow's date - using compound literals

struct date dateUpdate(struct date today) {
    
    struct date tomorrow;
    int numberOfDays(struct date d);
    
    if (today.day != numberOfDays(today)) {
        tomorrow = (struct date) {today.month, today.day + 1, today.year};
        /*
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
        */
    } else if (today.month == 12) {     // end of year
        tomorrow = (struct date) {1, 1, today.year + 1};
        /*
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
        */
    } else {                            // end of month
        tomorrow = (struct date) {1, today.month + 1, today.year};
        /*
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
        */
    }
    
    return tomorrow;
}

// Function to find the number of days in a month

int numberOfDays(struct date d) {
    int days;
    bool isLeapYear(struct date d);
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month - 1];
    
    return days;
}

// Function to determine of it's a leap year

bool isLeapYear(struct date d) {
    bool leapYearFlag;
    
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0 )
        leapYearFlag = true;    // It's a leap year
    else
        leapYearFlag = false;   // Not a leap year
    
    return leapYearFlag;
}

int main(int argc, char** argv) {
    struct date dateUpdate(struct date today);
    struct date thisDay, nextDay;
    
    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &thisDay.month, &thisDay.day, &thisDay.year);
    
    nextDay = dateUpdate(thisDay);
    
    printf("Tomorrow's date is %i/%i/%.2i.\n", nextDay.month, nextDay.day, nextDay.year % 100);

    return (EXIT_SUCCESS);
}

