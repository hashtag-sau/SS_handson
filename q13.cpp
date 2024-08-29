#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/select.h>

using namespace std;

int main(){
    fd_set readfds;
    struct timeval timeout;

    FD_SET(0,&readfds); // adding stdin in fd set 

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;


    cout<<"enter input within 10 seconds \n";

    int is_selected = select(0 + 1, &readfds, NULL, NULL, &timeout);
    if(is_selected == -1) {
        perror("select error");
        return -1;
    }
    if(is_selected == 0){
        cout<<"no input recieved ";
    }
    else{
        cout<<"input recieved";
    }

    
    
    return 0;
}

// output
// enter input within 10 seconds 
// hello world
// input recieved