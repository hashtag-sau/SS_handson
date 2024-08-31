/*
============================================================================
Name : 20.c
Author : Saurabh Dubey
Description : 20. Find out the priority of your running program. Modify the priority with nice command.
Date: 28th Aug, 2024.
============================================================================
*/#include<stdio.h>
#include<unistd.h>

int main(){
    printf("pid of process: %d \n",getpid());
    while(1);
    return 0;
}

 // PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
 //  8899 h1n1cov   20   0    2776    984    892 R 100.0   0.0   1:13.85 a.out

//  $ renice -n -10 -p 8899
// renice: failed to set priority for 8899 (process ID): Permission denied
// h1n1cov@pisces-cetus:~$ sudo renice -n -10 -p 8899
// [sudo] password for h1n1cov:
// 8899 (process ID) old priority 0, new priority -10

