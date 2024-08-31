/*
============================================================================
Name : 21.c
Author : Saurabh Dubey
Description : 21. Write a program, call fork and print the parent and child process id
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

    if(fork()){ //fork return 0 to child process and positive integer pid to parent
        printf("parent_id:%d \n",getpid()); // this will be executed in parent
    }
    else printf("child_id:%d \n",getpid()); // this will be executed in child
 
    return 0;
}
// parent_id:14407 
// child_id:14408 