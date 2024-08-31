/*
============================================================================
Name : 17a.c
Author : Saurabh Dubey
Description : 9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modificati
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h> // this has stat(filepath, struct stat) system call, which is required for know files metadata
                    // adds the metadata for file in stat variable

int main(){
    struct stat file_metadata; // st_mode, st_ino, st_dev, st_uid, st_gid, st_atime, st_ctime, st_nlink, st_mtime etc. these are member 

    if(stat("../pointme.txt", &file_metadata) == -1){
        perror("error in getting stat");
        return -1;
    }
    // cout<<"inode: "<<file_metadata.st_ino<<endl;
    // cout<<"hardlink: "<<file_metadata.st_nlink<<endl;
    // cout<<"uid: "<<file_metadata.st_uid<<endl;
    // cout<<"gid: "<<file_metadata.st_gid<<endl;
    // cout<<"size: "<<file_metadata.st_size<<endl;
    // cout<<"block size:"<<file_metadata.st_blksize<<endl;
    // cout<<"number of blocks"<<file_metadata.st_blocks<<endl;
    // cout<<"time of last access"<<file_metadata.st_atime<<endl;
    // cout<<"time of last modified"<<file_metadata.st_mtime<<endl;
    // cout<<"time of last change"<< file_metadata.st_ctime<<endl;

    printf("inode: %lu\n", file_metadata.st_ino);
    printf("hardlink: %lu\n", file_metadata.st_nlink);
    printf("uid: %u\n", file_metadata.st_uid);
    printf("gid: %u\n", file_metadata.st_gid);
    printf("size: %lld\n", (long long)file_metadata.st_size);
    printf("block size: %ld\n", file_metadata.st_blksize);
    printf("number of blocks: %lld\n", (long long)file_metadata.st_blocks);
    printf("time of last access: %ld\n", (long)file_metadata.st_atime);
    printf("time of last modified: %ld\n", (long)file_metadata.st_mtime);
    printf("time of last change: %ld\n", (long)file_metadata.st_ctime);


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