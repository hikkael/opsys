// Part 1: Program that creates a zombie process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t p = fork();

    if (p == 0) {
        printf("Child Process : %d Terminated. \n", getpid());
        exit(0);
    } 
    else {

        printf("Parent Process  %d will now sleep for 20 seconds \n", getpid());
        printf("Open a new terminal window and run ps aux | grep c5 to see the zombie child.\n");
        
        sleep(20); 
        
        printf("Parent Terminated.\n");
    }

    return 0;
}
