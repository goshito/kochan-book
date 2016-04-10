/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 10, 2016, 1:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 9, Exercise 4
 */

/* N = 1461 x f(year, month) / 4 + 153 x g(month) / 5 + day
 * If you take the value of N as computed in exercise 2, subtract 621,049 from
 * it, and then take the result modulo 7, you get a number from 0 to 6 that
 * represents the day of the week (Sunday through Saturday, respectively) on
 * whihc the particular day falls. For example, the value of N computed for
 * August 8, 2004, is 732,239 as derived previously. 732,239 - 621,049 gives
 * 11,190, and 111,190 % 7 gives 2, indicating that this date falls on Tuesday.
 * 
 * Use the functions developed in the previous exercise to develop a program
 * that displays the day of the week on which a particular date falls. Make
 * certain that the program displays the day of the week in English (such as
 * "Monday"). */

struct date {
        int month;
        int day;
        int year;
    };

// Function to calculate f(year, month) and return the value of year 

int f(int year, int month) {
    if (month <= 2)
        return year - 1;
    else
        return year;
}

// Function to calculate g(month) 

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
    int n, week_day;
    struct date date;
    
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%i/%i/%i", &date.month, &date.day, &date.year);
    
    n = calcDays(date);
    week_day = (n - 621049) % 7;
    
    if (week_day == 0)
        printf("Sunday");
    else if (week_day == 1)
        printf("Monday");
    else if (week_day == 2)
        printf("Tuesday");
    else if (week_day == 3)
        printf("Wednesday");
    else if (week_day == 4)
        printf("Thrusday");
    else if (week_day == 5)
        printf("Friday");
    else if (week_day == 6)
        printf("Saturday");
    else
        printf("!!! Critical Error !!!\n MUHAHAHAHAHAHA");

    return (EXIT_SUCCESS);
}

