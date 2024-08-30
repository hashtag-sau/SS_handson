#include<bits/stdc++.h>
#include <fcntl.h>    
#include <unistd.h> 

using namespace std;

int main(){
    char file_name[] = "iwillbeshownon_fdtable_x.txt";

    
    for(int i = 0; i < 5; i++){

        file_name[23] = '0' + i;

        int fd = creat(file_name, 0666);
        if(fd == -1) {
            perror("creat");
        }

        cout<<"fd value for file"<<i<<": "<<fd;

    }

    while(1);


    return 0;

}

// /proc/15782$ cd fd
// h1n1cov@pisces-cetus:/proc/15782/fd$ ls
// 0  1  103  2  3  38  39  4  5  6  7
// h1n1cov@pisces-cetus:/proc/15782/fd$ ll
// total 0
// dr-x------ 2 h1n1cov h1n1cov  0 Aug 28 00:14 ./
// dr-xr-xr-x 9 h1n1cov h1n1cov  0 Aug 28 00:13 ../
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 0 -> /dev/pts/0
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 1 -> /dev/pts/0
// lr-x------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 103 -> /usr/share/code/v8_context_snapshot.bin
// lrwx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 2 -> /dev/pts/0
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 3 -> /home/h1n1cov/SS_handson/iwillbeshownon_fdtable_0.txt
// lr-x------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 38 -> /usr/share/code/resources/app/node_modules.asar
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 39 -> /home/h1n1cov/.config/Code/logs/20240827T215546/ptyhost.log
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 4 -> /home/h1n1cov/SS_handson/iwillbeshownon_fdtable_1.txt
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 5 -> /home/h1n1cov/SS_handson/iwillbeshownon_fdtable_2.txt
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 6 -> /home/h1n1cov/SS_handson/iwillbeshownon_fdtable_3.txt
// l-wx------ 1 h1n1cov h1n1cov 64 Aug 28 00:14 7 -> /home/h1n1cov/SS_handson/iwillbeshownon_fdtable_4.txt
