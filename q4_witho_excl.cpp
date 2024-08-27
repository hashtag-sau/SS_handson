#include<bits/stdc++.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main(){
    const char *filename = "exp_on_filedescriptor.txt";
    int fd, flags;
    

    flags = O_EXCL; //  O_EXCL means "if try to create file and if that file already exitst then it gives error" 
    fd = open(filename,flags);
    if(fd == -1){
        perror("open error with O_EXCL");
    }

    return 0;
}