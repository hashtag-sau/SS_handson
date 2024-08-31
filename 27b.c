#include<stdio.h>
#include<unistd.h>

int main(){
    printf("executing ls -Rl command \n");
    if(!fork()){ //in child
        if(execlp("/bin/ls","ls", "-Rl", NULL) == -1){
            perror("error execl");
            return -1;
        }
    }
    wait(0);
    printf("\n executed");
    return 0;
}
