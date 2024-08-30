#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(){
    int file1_fd1 = open("exp_on_filedescriptor.txt" , O_RDWR);
    if(file1_fd1 == -1){
        perror("opening error");
        return -1;
    }
    
    int file1_fd2 = dup(file1_fd1); // dup will assign fd2 a lowest file descriptor value available
    // and now fd1 and fd2 both point to same file 
    //if i change offset using lseek in fd1 the same will be reflected in fd2.

    int file2_fd1 = open("hard_pointme.txt", O_RDWR);
    if(file2_fd1 == -1){
        perror("opening error");
        return -1;
    }

    int file2_fd2 = dup2(file2_fd1, 42); // in dup2() we can give custome fd value here i gave 42;


    //using fcntl to duplicate file2

    int file2_fd3 = fcntl(file2_fd1, F_DUPFD, 42); //fcntl F_DUPFD will assign lowest number available >= 42
    //since 42 is used above it should assign 43 

    while(1);

    return 0;

}

//output

// h1n1cov@pisces-cetus:/proc/17877$ cd fd
// h1n1cov@pisces-cetus:/proc/17877/fd$ ls
// 0  1  103  2  3  37  38  39  4  42  43  5
// h1n1cov@pisces-cetus:/proc/17877/fd$ ll
// total 0
// dr-x------ 2 h1n1cov h1n1cov  0 Aug 28 23:03 ./
// dr-xr-xr-x 9 h1n1cov h1n1cov  0 Aug 28 23:02 ../
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 0 -> /dev/pts/0
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 1 -> /dev/pts/0
// lr-x------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 103 -> /usr/share/code/v8_context_snapshot.bin
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 2 -> /dev/pts/0
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 3 -> /home/h1n1cov/SS_handson/exp_on_filedescriptor.txt
// lr-x------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 37 -> /usr/share/code/resources/app/node_modules.asar
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 38 -> /home/h1n1cov/.config/Code/logs/20240828T172906/ptyhost.log
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 39 -> 'socket:[61042]'
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 4 -> /home/h1n1cov/SS_handson/exp_on_filedescriptor.txt
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 42 -> /home/h1n1cov/SS_handson/hard_pointme.txt
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 43 -> /home/h1n1cov/SS_handson/hard_pointme.txt
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 23:03 5 -> /home/h1n1cov/SS_handson/hard_pointme.txt
