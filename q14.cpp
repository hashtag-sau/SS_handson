#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>

using namespace std;

int main(){
    string file = "";
    int magic_number_size = 4;
    char buffer[magic_number_size];
    cout<<"enter the file\n";
    cin>>file;
    cout<<file.c_str();

    int file_fd = open(file.c_str(), O_RDONLY);
    if( file_fd == -1){
        perror("error opening file");
        return -1;
    }

    int num_read = read(file_fd, buffer, magic_number_size); //read first 4 bytes of file

    if(num_read < 4) {
        cout<<"file size less than 4 bytes";
        return -1;
    }

     if (memcmp(buffer, "\x7F\x45\x4C\x46", magic_number_size) == 0) {
        cout<<"ELF executable file\n";
    } else if (memcmp(buffer, "\xFF\xD8\xFF\xE0", magic_number_size) == 0 || memcmp(buffer, "\xFF\xD8\xFF\xE1", magic_number_size) == 0) {
        cout<<"JPEG image file\n";
    } else if (memcmp(buffer, "\x89\x50\x4E\x47", magic_number_size) == 0) {
        cout<<"PNG image file\n";
    } else if (memcmp(buffer, "\x25\x50\x44\x46", magic_number_size) == 0) {
        cout<<"PDF document\n";
    } else if (memcmp(buffer, "\x23\x69\x6e\x63", magic_number_size) == 0) {
        cout<<"cpp file\n";
    } else if (memcmp(buffer, "\x25\x50\x44\x46", magic_number_size) == 0) {
        cout<<"PDF document\n";
    }
    else {
        cout<<"some other file type";
    }

    return 0;
}

//output

// enter the file
// ../Pictures/pic1.png                                       
// ../Pictures/pic1.pngPNG image file
// h1n1cov@pisces-cetus:~/SS_handson$ ./a.out 
// enter the file
// a.out
// a.outELF executable file