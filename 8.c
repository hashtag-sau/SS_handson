/*
============================================================================
Name : 17a.c
Author : Saurabh Dubey
Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int readme;
    char buffer[1000]; //hope each line of file has less than 1000 characters

    readme = open("readme_linebyline.txt", O_RDONLY);

    int numchar_read; //number of characters readed in one line

    int i =0;
    do{
        numchar_read = 0;
        i = 0;
        do{
            numchar_read += read(readme, buffer+i, 1); //reading char by char until newline is encountered
            i++;
        }while(buffer[i-1] != '\n' && numchar_read != 0); //if end of file is reached read returns 0 and numchar_read will become zero

        if(numchar_read < 0){
            perror("read error");
            return -1;
        }

        if(write(1,buffer,numchar_read) < 0){
            perror("write on stdout error");
            return -1;
        }

        sleep(1);
    }while(numchar_read != 0); 

    return 0;
}

//output 

//  g++ q8.cpp 
// h1n1cov@pisces-cetus:~/SS_handson$ ./a.out 
// your program should read my contents with following rules
// 1. it should read line by line and not the whole file at once
// 2. it should read and output it before reading my next line
// 3. you should follow both the rules mentioned above
// your program will crash if you ignore my rules