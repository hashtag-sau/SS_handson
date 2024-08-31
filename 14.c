/*
============================================================================
Name : 14.c
Author : Saurabh Dubey
Description : 14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    char file[100];
   struct stat file_status;
    printf("enter the file\n");
    scanf("%s",file);
    if(lstat(file, &file_status) < 0){
        perror("error getting file");
        return 0;
    }

    if (S_ISREG(file_status.st_mode)) printf("regular file.\n");
    else if (S_ISLNK(file_status.st_mode)) printf("symbolic link.\n");
    else if (S_ISFIFO(file_status.st_mode)) printf("FIFO (named pipe).\n");
    else if (S_ISDIR(file_status.st_mode)) printf("directory.\n");
    else if (S_ISSOCK(file_status.st_mode)) printf("socket.\n");
    else if (S_ISCHR(file_status.st_mode)) printf("character device file.\n");
    else if (S_ISBLK(file_status.st_mode)) printf("block device file.\n");
    else printf("unknown type.\n");

    return 0;
}

// enter the file
// ../SS_handson
// directory.
