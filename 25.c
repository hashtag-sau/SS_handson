/*
============================================================================
Name : 25.c
Author : Saurabh Dubey
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){
    int pid_child[3];

    if((pid_child[0] = fork()) == 0){ 
        printf("child1 created\n");
        return 0;
    }
    else if((pid_child[1] = fork()) == 0){
        printf("child2 created\n");
        printf("child 2 going to sleep for 5 \n");
        sleep(5);
        printf("child 2 wokeup \n");
        return 0;
    }
    else if((pid_child[2] = fork()) == 0){
        printf("child3 created\n");
        return 0;
    }

    sleep(1);
    printf("wating for child 2\n");
    waitpid(pid_child[1],NULL,0);
    printf("child2 executed");

    return 0;
}