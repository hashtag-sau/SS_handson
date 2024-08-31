/*
============================================================================
Name : 10.c
Author : Saurabh Dubey
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

        int fd = open("growme_lseek", O_RDWR);
        if(fd == -1){
            perror("opening error");
            return -1;
        }

        char x[] = "iamTenByte";
        if(write(fd,x,10) < 0){
            perror("write error");
            return -1;
        }
        //after this offset will be 10;

        int newoffset = lseek(fd, 10, SEEK_CUR); // seekcur indicates to increase offset from current offset
        if(newoffset < 0){
            perror("lseek error");
            return -1;
        }

        char y[] = "iamOneByte"; // this is also ten byte
        if(write(fd,y,10) < 0){
            perror("write error");
            return -1;
        }
        return 0;
}

//output
// od -x growme_lseek 
// 0000000 6169 546d 6e65 7942 6574 0000 0000 0000
// 0000020 0000 0000 6169 4f6d 656e 7942 6574
// 0000036