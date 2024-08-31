/*
============================================================================
Name : 17b.c
Author : Saurabh Dubey
Description : Write a program to simulate online ticket reservation. 
Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

struct Ticket{
int ticket_num;
};

int main() {
    struct Ticket T;
    struct flock lock;

    int fd;
    fd = open("ticket", O_RDWR, 0666);
    lock.l_type = F_WRLCK; lock.l_start = 0; lock.l_len = 0; lock.l_whence = SEEK_SET;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLKW, &lock); //set lock
    read(fd,&T, sizeof(T));    //read the ticket
    T.ticket_num++;    //increment by one
    write(fd,&T,sizeof(T)); //write back to file

    lock.l_type = F_UNLCK; 
    fcntl(fd, F_SETLK, &lock); //unlocking
    printf("Ticket num: %d",T.ticket_num);

    return 0;

}

//output
// gcc 17a.c 
// h1n1cov@pisces-cetus:~/SS_handson$ ./a.out 
// Ticket no: 42
// h1n1cov@pisces-cetus:~/SS_handson$ gcc 17b.c 
// h1n1cov@pisces-cetus:~/SS_handson$ ./a.out 
// Ticket num: 43