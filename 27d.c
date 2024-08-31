#include<stdio.h>
#include<unistd.h>

int main(){
    printf("executing ls -Rl command \n");
    if(!fork()){ //in child

        char *args[] = {"ls","-Rl", NULL};
        if(execv("/bin/ls",args) == -1){ //execv needs path. And arguments as array of string terminated by NULL
            perror("error execl");
            return -1;
        }
    }
    wait(0);
    printf("\n executed");
    return 0;
}
