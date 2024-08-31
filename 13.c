/*
============================================================================
Name : 17a.c
Author : Saurabh Dubey
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main(){
    fd_set readfds;
    struct timeval timeout;

    FD_SET(0,&readfds); // adding stdin in fd set 

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;


    printf("enter input within 10 seconds \n");

    int is_selected = select(0 + 1, &readfds, NULL, NULL, &timeout);
    if(is_selected == -1) {
        perror("select error");
        return -1;
    }
    if(is_selected == 0){
        printf("no input recieved ");
    }
    else{
        printf("input recieved");
    }

    
    
    return 0;
}

// output
// enter input within 10 seconds 
// hello world
// input recieved