/*
============================================================================
Name : 22.c
Author : Saurabh Dubey
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd;
    fd = open("22_parentAndchild_writeme.txt", O_RDWR);
    if(fd < 0) perror("error opening file");

    if(fork()){
        char str1[] = "parent is writing";
        write(fd,str1,sizeof(str1));
    }
    else{
        char str2[] = "being written by child";
        write(fd,str2,sizeof(str2));
    }

    return 0;

}