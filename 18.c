/*
============================================================================
Name : 18.c
Author : Saurabh Dubey
Description : 18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

struct Student{
    int roll_no;
    char name[30];
};

int main(){
    struct Student s1,s2,s3;

    s1.roll_no = 11;
    strcpy(s1.name, "hashtag-sau");
    s2.roll_no = 12;
    strcpy(s2.name, "virat");
    s3.roll_no = 20;
    strcpy(s3.name, "rohit");

    int fd;
    fd =open("Student", O_RDWR);
    if(fd == -1){                       // if file doesn't exists
        fd = open("Student", O_CREAT, 0666); //create and 3 three records
        fd =open("Student", O_RDWR);
        if(write(fd, &s1, sizeof(s1)) < 0) {
            perror("write error");
            return 0;
        }
        write(fd, &s2, sizeof(s2));
        write(fd, &s3, sizeof(s3));
    }


    int which_rec;
    printf("enter 1 to 3 which record? ");
    scanf("%d",&which_rec);


    struct Student s;

    struct flock lock;
    lock.l_type = F_RDLCK; lock.l_start = sizeof(s) * (which_rec -1) ; lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(s); lock.l_pid = getpid(); //configured lock setting for record locking.

    printf("acquiring read lock\n");
    fcntl(fd, F_SETLKW, &lock); //acquiring lock and then read
    printf("acquired read lock\n");

    lseek(fd,sizeof(s) * (which_rec -1), SEEK_SET); //setting pointer to correct location
    read(fd,&s,sizeof(s)); //reading and printing 
    printf("**Record no.%d **\n",which_rec);
    printf("*Name: %s \n",s.name);
    printf("*Roll no %d \n", s.roll_no);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock); // released the lock
    printf("released read lock\n");

    int f;
    printf("want to edit record? enter 0 or 1: ");
    scanf("%d",&f);
    if(f == 0) return 0;

    

    lock.l_type = F_WRLCK;
    printf("acquiring write lock\n");
    fcntl(fd,F_SETLKW, &lock);
    printf("acquired write lock\n");

    int roll;
    char name[30];
    printf("enter name: ");
    scanf("%s",name);
    printf("enter roll: ");
    scanf("%d",&roll);

    s.roll_no = roll;
    strcpy(s.name, name);
    
    lseek(fd,sizeof(s) * (which_rec -1), SEEK_SET);
    write(fd,&s, sizeof(s));
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK, &lock);
    printf("released write lock");

return 0;
}

// enter 1 to 3 which record? 1
// acquiring read lock
// acquired read lock
// **Record no.1 **
// *Name: hashtag-sau 
// *Roll no 46 
// released read lock
// want to edit record? enter 0 or 1: 1
// acquiring write lock
// acquired write lock
// enter name: hashtag-sau
// enter roll: 46