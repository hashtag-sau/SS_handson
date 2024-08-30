/*
============================================================================
Name : 17a.c
Author : Saurabh Dubey
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
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
    int fd;
    struct Ticket T;
    T.ticket_num = 42;
    fd = open("ticket", O_CREAT|O_RDWR, 0666);
    write(fd, &T, sizeof(T));
    close(fd);

    fd = open("ticket", O_RDONLY);
    read(fd, &T, sizeof(T));
    printf("Ticket no: %d\n", T.ticket_num);
    close(fd);

}