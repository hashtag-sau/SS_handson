/*
============================================================================
Name : 6.c
Author : Saurabh Dubey
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
    
    char buffer[1024];
    int i = 0, numchar_read =0; 
    do{ // we will keep reading input char by char till we encounter new line

        numchar_read += read(0,buffer+i, 1);
        i++;
    }while((buffer[i-1] != '\n'));

    if(numchar_read <= 0) {
        perror("error in reading");
        return -1;
    }

    if(write(1,buffer, numchar_read) < 0) {
        perror("error writing ");
        return -1;
    }

    return 0;
}

//output
// hi how are you??
// hi how are you??