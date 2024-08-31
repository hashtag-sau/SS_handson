#include<stdio.h>
#include<unistd.h>

int main(){
    if(fork()){ //parent
        printf("parent process pid: %d \n", getpid());
        return 0;
    }

    else{ // child
        printf("**before orphan**\n");
        printf("child's parent pid: %d \n", getppid());
        printf("child process pid:%d\n", getpid());
        sleep(100);
        printf("**after orphan**\n");
        printf("child process pid:%d\n", getpid());
        printf("child's parent pid: %d \n", getppid());
    }
    return 0;
}

// parent process pid: 150316 
// **before orphan**
// child's parent pid: 150316 
// child process pid:150317
// h1n1cov@pisces-cetus:~/SS_handson$ **after orphan**
// child process pid:150317
// child's parent pid: 1 

//proc folder status
// /proc/150590$ cat status
// Name:	a.out
// Umask:	0002
// State:	S (sleeping)
// Tgid:	150590
// Ngid:	0
// Pid:	150590
// PPid:	1 //ppid 1 indicates it is orphan
