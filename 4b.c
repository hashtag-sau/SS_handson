/*
============================================================================
Name : 4b.c
Author : Saurabh Dubey
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    const char *filename = "exp_on_filedescriptor.txt";
    int fd, flags;
    

    flags = O_EXCL; //  O_EXCL means "if try to create file and if that file already exitst then it gives error" 
    fd = open(filename,flags);
    if(fd == -1){
        perror("open error with O_EXCL");
    }

    return 0;
}