/*
============================================================================
Name : 17a.c
Author : Saurabh Dubey
Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
============================================================================
*/
#include<sys/time.h>
#include<unistd.h>
#include<stdio.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A"(dst));
    return dst;
}

int main(){
    long long int start, end;
    int pid;
    start = rdtsc();
    pid = getpid();
    end = rdtsc();
    printf("cpu time is: %llu \n",end - start); //gives number of cpu cycles
    
}
//cpu time is: 11252 