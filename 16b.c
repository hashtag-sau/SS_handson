/*
============================================================================
Name : 16b.c
Author : Saurabh Dubey
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    struct flock lock;
    int file_fd;
    file_fd = open("a_shared_file.txt", O_RDWR);
    if(file_fd == -1){
        perror("unable to open");
        return -1;
    }

    lock.l_type = F_RDLCK; lock.l_start = 0; lock.l_len = 0; lock.l_whence = SEEK_SET; //SEEK_SET means from start of file and len=0 means lock whole file.
    lock.l_pid = getpid(); //if process is killed/terminated without releasing the lock. then kernel can see that invalid pid and relase the lock.
    
    printf("trying to READ lock \n");
    fcntl(file_fd, F_SETLKW, &lock); // acuqires lock and can wait also.
    printf("lock aquired \n");

    getchar();

    lock.l_type =F_UNLCK; // unlocking
    fcntl(file_fd, F_SETLK, &lock); // realease lock without waiting. 
    printf("lock realesed \n");

    


return 0;
    
}

