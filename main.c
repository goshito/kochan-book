/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 8, 2016, 2:13 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 9, Exercise 3
 * Solved without struct functions
 */

/*
 * Write a function elapsed_time that takes as its arguments two time structures
 * and returns a time structure that represents the elapsed time (in hours,
 * minutes, and seconds) between the two times. So the call
 * 
 * elapsed_time(time1, time2)
 * 
 * where time1 represents 3:45:15 and time2 represents 9:44:03, should return a
 * time structure that represents 5 hours, 58 minutes, and 48 seconds. Be 
 * careful with times that cross midnight. 
 */

/*
 * Algorithm that I will use:
 * 1. Define/declare the struct that will hold the time
 * 2. For each 60 seconds passed a minute should be added 
 *    For each 60 minutes passed an hour should be added.
 *    I need a function to update elapsed time until it reaches time 2
 *    Maybe a loop
 * 3. Allow the user to enter time1 and time2 and store them appropriately
 * 4. Determine how to calculate the elapsed time between time1 and time2
 */

struct time {
    int hour;
    int minutes;
    int seconds;
};
/*
struct time timeUpdate(struct time t) {
    ++t.seconds;
    
    if (t.seconds == 60) {      // next minute
        t.seconds = 0;
        ++t.minutes;
        
        if (t.minutes == 60) {  // next hour
            t.minutes = 0;
            ++t.hour;
            if (t.hour == 24)   // midnight
                t.hour = 0;
        }
        
    }
    
    return t;
}
*/

int absoluteValue(int x) {
    if (x <= 0)
        x = -x;
    return x;
}

int main(int argc, char** argv) {
    struct time time1, time2, elapsed_time;
    const int hours_per_day[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    
    
    //enter time1
    printf("Enter time1 (hh:mm:ss): \n");
    scanf("%i:%i:%i", &time1.hour, &time1.minutes, &time1.seconds);
    
    //enter time2
    printf("Enter time2 (hh:mm:ss): \n");
    scanf("%i:%i:%i", &time2.hour, &time2.minutes, &time2.seconds);
    
    elapsed_time.hour = time2.hour - time1.hour;
    elapsed_time.minutes = time2.minutes - time1.minutes;
    elapsed_time.seconds = time2.seconds - time1.seconds;
    
    if (elapsed_time.minutes < 0) {
        elapsed_time.hour += elapsed_time.minutes;
        elapsed_time.minutes += 60;
    }
    
    if (elapsed_time.seconds < 0) {
        elapsed_time.minutes -= 1;
        elapsed_time.seconds += 60;
    }
    
    printf("%i:%i:%i\n", elapsed_time.hour, elapsed_time.minutes, elapsed_time.seconds);
        
    return (EXIT_SUCCESS);
}

