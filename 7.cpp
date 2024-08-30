#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>

using namespace std;

int main(){
    int copyfrom, copyto; // my filedescriptors
    char buffer[1024];

    copyfrom = open("copyfrom.txt" , O_RDONLY);
    int numchar_read = 0;
    numchar_read = read(copyfrom, buffer, 1024); // hope our file has than 1024 char. 
    if(numchar_read < 0) {
        perror("read error");
        return -1;
    }

    copyto = open("copyto.txt", O_WRONLY);
    if(write(copyto, buffer, numchar_read) < 0) {
        perror("write error");
    }
    cout<<"sucessfully copied";
    return 0;
}

//i manually created two files i.e copyfrom.txt and copyto.txt and added contents to copyfrom.txt and kept copyto.txt empty
//after running program the content of copyfrom.txt was copied to copyto.txt