/*
============================================================================
Name : 29.c
Author : Saurabh Dubey
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int main() {
    int curr_schedule;
    curr_schedule = sched_getscheduler(0); // can pass pid of any process and zero for self
    if (curr_schedule == -1) {
        perror("getscheduler error");
        return -1;
    }
    
    if(curr_schedule == SCHED_RR) printf("current schedule is RR\n");
    else if(curr_schedule == SCHED_FIFO) printf("current schedule is FIFO\n");
    else  printf("current schedule is %d \n", curr_schedule);

    int new_schedule;
    printf("enter to modify current schedule policy for fifo(1) and RR(2): ");
    scanf("%d",&new_schedule);

    struct sched_param schedule_param;

    schedule_param.sched_priority = 5;

    if(sched_setscheduler(0, new_schedule, &schedule_param) == -1){
        perror("setsheduler error");
        return -1;
    }
    

    curr_schedule = sched_getscheduler(0); // can pass pid of any process and zero for self
    if (curr_schedule == -1) {
        perror("getscheduler error");
        return -1;
    }
    if(curr_schedule == SCHED_RR) printf("current schedule is RR\n");
    else if(curr_schedule == SCHED_FIFO) printf("current schedule is FIFO\n");
    else  printf("current schedule is %d", curr_schedule);


    return 0;
}
//without sudo
// current schedule is 0 
// enter to modify current schedule policy for fifo(1) and RR(2): 1
// setsheduler error: Operation not permitted

//with sudo
// sudo ./a.out
// [sudo] password for h1n1cov:
// current schedule is 0 
// enter to modify current schedule policy for fifo(1) and RR(2): 1
// current schedule is FIFO