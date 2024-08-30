#include <bits/stdc++.h>
#include<unistd.h>
#include<sys/stat.h> //for mkfifo
using namespace std;
int main(){

    string target_file_path  = "../pointme.txt";
    string softlink_name = "softLinkto_pointme.txt";
    string hardlink_name = "hard_pointme.txt";
    string fifofile_name = "myfifofile";

    if(symlink(target_file_path.c_str(), softlink_name.c_str()) == -1){
        perror("symlink");
    } 

    if(link(target_file_path.c_str(), hardlink_name.c_str()) == -1){
        perror("hardlink error");
    }

    
    if (mkfifo(fifofile_name.c_str(), 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

return 0;




}