#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

using namespace std;

int main(){
    string file = "";
   struct stat file_status;
    cout<<"enter the file\n";
    cin>>file;
    if(lstat(file.c_str(), &file_status) < 0){
        perror("error getting file");
        return 0;
    }

    if (S_ISREG(file_status.st_mode)) printf("regular file.\n");
    else if (S_ISLNK(file_status.st_mode)) printf("symbolic link.\n");
    else if (S_ISFIFO(file_status.st_mode)) printf("FIFO (named pipe).\n");
    else if (S_ISDIR(file_status.st_mode)) printf("directory.\n");
    else if (S_ISSOCK(file_status.st_mode)) printf("socket.\n");
    else if (S_ISCHR(file_status.st_mode)) printf("character device file.\n");
    else if (S_ISBLK(file_status.st_mode)) printf("block device file.\n");
    else printf("unknown type.\n");

    return 0;
}
