#include<bits/stdc++.h>
#include <fcntl.h>    
#include <unistd.h> 

using namespace std;

int main(){
    const char *file_name = "exp_on_filedescriptor.txt";
    int fd = creat(file_name, 0666);
    if(fd == -1) {
        perror("creat");
    }

    cout<<"fd value: "<<fd; //cout was fd value: 3

    while(1);


    return 0;

}

// ** file descriptor table for this process ***

// /proc/6076$ cd fd
// h1n1cov@pisces-cetus:/proc/6076/fd$ ls
// 0  1  103  2  3  38  39
// h1n1cov@pisces-cetus:/proc/6076/fd$ ll
// total 0
// dr-x------ 2 h1n1cov h1n1cov  0 Aug 27 22:56 ./
// dr-xr-xr-x 9 h1n1cov h1n1cov  0 Aug 27 22:56 ../
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 0 -> /dev/pts/0
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 1 -> /dev/pts/0
// lr-x------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 103 -> /usr/share/code/v8_context_snapshot.bin
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 2 -> /dev/pts/0
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 3 -> /home/h1n1cov/SS_handson/exp_on_filedescriptor.txt   *****here is our file***
// lr-x------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 38 -> /usr/share/code/resources/app/node_modules.asar
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 27 22:57 39 -> /home/h1n1cov/.config/Code/logs/20240827T215546/ptyhost.log
