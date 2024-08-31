#include<stdio.h>
#include<unistd.h>

int main(){
    printf("executing ls -Rl command \n");
    if(!fork()){ //in child

        char *args[] = {"ls","-Rl", NULL};
        if(execvp("ls",args) == -1){ 
            perror("error execl");
            return -1;
        }
    }
    wait(0);
    printf("\n executed");
    return 0;
}
