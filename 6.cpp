#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

int main(){
    
    char buffer[1024];
    int i = 0, numchar_read =0; 
    do{ // we will keep reading input char by char till we encounter new line

        numchar_read += read(0,buffer+i, 1);
        i++;
    }while((buffer[i-1] != '\n'));

    if(numchar_read <= 0) {
        perror("error in reading");
        return -1;
    }

    if(write(1,buffer, numchar_read) < 0) {
        perror("error writing ");
        return -1;
    }

    return 0;
}

//output
// hi how are you??
// hi how are you??