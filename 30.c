/*
============================================================================
Name : 17a.c
Author : Saurabh Dubey
Description : 30. Write a program to run a script at a specific time using a Daemon process.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main(){

    if (!fork()) {
        setsid ();
        chdir ("/home/h1n1cov/SS_handson"); 
        umask (0);

        while(1){ // this daemon will run every 60 seconds between 9am to 3pm
            time_t now;
            struct tm *local_time;
            time(&now);
            local_time = localtime(&now);
        
            int current_hour = local_time->tm_hour;
            
            int start_hour = 9;
            int end_hour = 15;
            if(current_hour>=start_hour && current_hour<=end_hour){

                if(execl("daemon_script.sh","daemon_script.sh", NULL) == -1){ 
                    perror("error execl");
                    return -1;
                }

            }
            sleep(60);
        }
        return 0;
    }
return 0;
}