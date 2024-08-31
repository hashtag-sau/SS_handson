/*
============================================================================
Name : 27.c
Author : Saurabh Dubey
Description : 27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
    printf("executing ls -Rl command \n");
    if(!fork()){ //in child
        if(execl("/bin/ls","ls", "-Rl", NULL) == -1){
            perror("error execl");
            return -1;
        }
    }
    wait(0);
    printf("\n executed");
    return 0;
}

// executing ls -Rl command 
// .:
// total 176
// -rw-rw-r-- 1 h1n1cov h1n1cov  1390 Aug 31 11:59 10.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  2724 Aug 31 12:01 11.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1262 Aug 31 12:04 12.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1076 Aug 31 12:07 13.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1278 Aug 31 12:17 14.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  4229 Aug 31 12:21 15.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1314 Aug 29 23:29 16a.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1201 Aug 29 23:28 16b.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   752 Aug 30 15:28 17a.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1285 Aug 30 21:12 17b.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  2941 Aug 30 18:28 18.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   707 Aug 30 18:30 19.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1011 Aug 31 11:29 1.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   532 Aug 31 12:49 20.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   636 Aug 30 18:48 21.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   760 Aug 31 12:22 22.c
// -rw-rw-r-- 1 h1n1cov h1n1cov    41 Aug 30 19:04 22_parentAndchild_writeme.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov   555 Aug 31 00:55 23.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   918 Aug 31 00:48 24.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   638 Aug 31 01:39 25.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   521 Aug 31 14:39 26.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   305 Aug 31 14:58 27a.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  2112 Aug 31 11:31 2.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1564 Aug 31 11:26 3.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   692 Aug 31 11:35 4b.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   524 Aug 31 11:33 4.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  2082 Aug 31 11:38 5.c
// -rw-rw-r-- 1 h1n1cov h1n1cov   870 Aug 31 11:41 6.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1065 Aug 31 11:44 7.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  1661 Aug 31 11:45 8.c
// -rw-rw-r-- 1 h1n1cov h1n1cov  2375 Aug 31 11:55 9.c
// -rwxrwxr-x 1 h1n1cov h1n1cov 16168 Aug 31 14:58 a.out
// -rw-rw-r-- 1 h1n1cov h1n1cov     6 Aug 29 23:17 a_shared_file.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov   143 Aug 28 18:15 copyfrom.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov   143 Aug 28 18:41 copyto.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 31 01:48 exe_for26.c
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 27 22:56 exp_on_filedescriptor.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov    30 Aug 28 22:20 growme_lseek
// -rw-rw-r-- 3 h1n1cov h1n1cov    31 Aug 27 22:23 hard_pointme.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 28 00:13 iwillbeshownon_fdtable_0.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 28 00:13 iwillbeshownon_fdtable_1.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 28 00:13 iwillbeshownon_fdtable_2.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 28 00:13 iwillbeshownon_fdtable_3.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 28 00:13 iwillbeshownon_fdtable_4.txt
// prw-rw-r-- 1 h1n1cov h1n1cov     0 Aug 27 22:22 myfifofile
// -rw-rw-r-- 1 h1n1cov h1n1cov   279 Aug 28 18:57 readme_linebyline.txt
// lrwxrwxrwx 1 h1n1cov h1n1cov    14 Aug 27 22:22 softLinkto_pointme.txt -> ../pointme.txt
// -rw-rw-r-- 1 h1n1cov h1n1cov   108 Aug 30 18:10 Student
// -rw-rw-r-- 1 h1n1cov h1n1cov     8 Aug 30 15:40 ticket

//  executed