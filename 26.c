/*
============================================================================
Name : 26.c
Author : Saurabh Dubey
Description : 26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
    char exe_file[] = "../fibrecurr";

    printf("executing %s \n", exe_file);

    if(!fork()){ //in child
        if(execl(exe_file, exe_file, NULL) == -1) { //since execl replaces the current process we call it in child wait for it.
            perror("error:");
            return -1;
        }
    }
    
    wait(0);
    printf("executed");
    return 0;

}

//output
// executing ../fibrecurr 
// Fibonacci(40) = 334155
// Time taken: 0.807958 seconds
// executed