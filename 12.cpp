#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(){
    int fd1 = open("exp_on_filedescriptor.txt" , O_RDWR);
    if(fd1 == -1){
        perror("opening error");
        return -1;
    }
    int fd2 = open("hard_pointme.txt", O_RDONLY);
    if(fd2 == -1){
        perror("opening error");
        return -1;
    }

    int flag_fd1 = fcntl(fd1, F_GETFL); //return status flags, which tells in which mode file is opened
    if(flag_fd1 == -1){
        perror("error getting ");
        return -1;
    }

    cout<<"file1 access mode: "<<(flag_fd1 & O_ACCMODE)<<endl;

    int flag_fd2 = fcntl(fd2, F_GETFL); //return status flags, which tells in which mode file is opened
    if(flag_fd2 == -1){
        perror("error getting ");
        return -1;
    }

    cout<<"file2 access mode: "<<(flag_fd2 & O_ACCMODE);

    return 0;
}
//output 
// file1 access mode: 2 //2 means Read write mode
// file2 access mode: 0 // 0 means read only mode