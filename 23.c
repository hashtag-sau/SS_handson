/*
============================================================================
Name : 23.c
Author : Saurabh Dubey
Description : 23. Write a program to create a Zombie state of the running program.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
    if(fork()){ //parent
        printf("parent process pid: %d \n", getpid());
        sleep(100);
        return 0;
    }

    else{ // child
        printf("child's parent pid: %d \n", getppid());
        printf("child process pid:%d\n", getpid());
        return 0;
    }
    return 0;
}
// parent process pid: 150887 
// child's parent pid: 150887 
// child process pid:150888

// /proc/150888$ cat status
// Name:	a.out
// State:	Z (zombie)
// Tgid:	150888
// Ngid:	0
// Pid:	150888
// PPid:	150887
