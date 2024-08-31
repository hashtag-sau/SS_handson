#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    const char *filename = "exp_on_filedescriptor.txt";
    int fd;
    int flags = O_RDWR;

    fd = open(filename, flags);
    if(fd == -1) {
        perror("open error");
    }
    else printf("file opened and fd = %d",fd);



    flags = O_EXCL; // meaning of O_EXCL is "error if create and file already exists" 
    fd = open(filename,flags);
    if(fd == -1){
        perror("open error with O_EXCL");
    }

    return 0;
}

//file opened and fd = 3