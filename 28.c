/*
============================================================================
Name : 28.c
Author : Saurabh Dubey
Description : 28. Write a program to get maximum and minimum real time priority. 
Date: 28th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sched.h>

int main() {
    int max, min;

    max = sched_get_priority_max(SCHED_RR);
    min = sched_get_priority_min(SCHED_RR);

    printf("Real-time priority of SCHED_RR\n");
    printf("Maximum priority: %d\n", max);
    printf("Minimum priority: %d\n", min);

    return 0;
}
