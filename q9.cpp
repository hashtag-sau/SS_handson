#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/stat.h> // this has stat(filepath, struct stat) system call, which is required for know files metadata
                    // adds the metadata for file in stat variable

using namespace std;

int main(){
    struct stat file_metadata; // st_mode, st_ino, st_dev, st_uid, st_gid, st_atime, st_ctime, st_nlink, st_mtime etc. these are member 

    if(stat("../pointme.txt", &file_metadata) == -1){
        perror("error in getting stat");
        return -1;
    }
    cout<<"inode: "<<file_metadata.st_ino<<endl;
    cout<<"hardlink: "<<file_metadata.st_nlink<<endl;
    cout<<"uid: "<<file_metadata.st_uid<<endl;
    cout<<"gid: "<<file_metadata.st_gid<<endl;
    cout<<"size: "<<file_metadata.st_size<<endl;
    cout<<"block size:"<<file_metadata.st_blksize<<endl;
    cout<<"number of blocks"<<file_metadata.st_blocks<<endl;
    cout<<"time of last access"<<file_metadata.st_atime<<endl;
    cout<<"time of last modified"<<file_metadata.st_mtime<<endl;
    cout<<"time of last change"<< file_metadata.st_ctime<<endl;

return 0;

}

//output

// inode: 7244339
// hardlink: 3
// uid: 1000
// gid: 1000
// size: 31
// block size:4096
// number of blocks8
// time of last access1724777605
// time of last modified1724777598
// time of last change1724777598