/*
============================================================================
Name : 1.c
Author : Saurabh Dubey
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>  
#include<unistd.h>
#include<sys/stat.h> //for mkfifo

int main(){

    char target_file_path[]  = "../pointme.txt";
    char softlink_name[] = "softLinkto_pointme.txt";
    char hardlink_name[] = "hard_pointme.txt";
    char fifofile_name[] = "myfifofile";

    if(symlink(target_file_path, softlink_name) == -1){
        perror("symlink");
    } 

    if(link(target_file_path, hardlink_name) == -1){
        perror("hardlink error");
    }

    
    if (mkfifo(fifofile_name, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

return 0;




}