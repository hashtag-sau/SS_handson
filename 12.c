/*
============================================================================
Name : 12.c
Author : Saurabh Dubey
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd1 = open("exp_on_filedescriptor.txt" , O_RDWR);
    if(fd1 == -1){
        perror("opening error");
        return -1;
    }
    int fd2 = open("hard_pointme.txt", O_RDONLY);
    if(fd2 == -1){
        perror("opening error");
        return -1;
    }

    int flag_fd1 = fcntl(fd1, F_GETFL); //return status flags, which tells in which mode file is opened
    if(flag_fd1 == -1){
        perror("error getting ");
        return -1;
    }

    printf("file1 access mode: %d \n",(flag_fd1 & O_ACCMODE));

    int flag_fd2 = fcntl(fd2, F_GETFL); //return status flags, which tells in which mode file is opened
    if(flag_fd2 == -1){
        perror("error getting ");
        return -1;
    }

    printf("file2 access mode: %d \n",(flag_fd2 & O_ACCMODE));

    return 0;
}
//output 
// file1 access mode: 2 //2 means Read write mode
// file2 access mode: 0 // 0 means read only mode