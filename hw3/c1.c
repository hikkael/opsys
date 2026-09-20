#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t p = fork();
    if( p == 0){
        printf("Child pid is %d \n" , getpid());
        exit(0);
    }
    else{   
       printf("Parent pid is %d \n" , getpid());
       
    }
    return 0;
}

