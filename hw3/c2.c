#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t p = fork();
    int status1;
    if( p == 0){
        printf("Child 1 pid is %d \n" , getpid());
        exit(0);
    }
    else{   
        wait(&status1);

        pid_t p2 = fork();
        int status2;
        if(p2 == 0){
            printf("Child 2 pid is %d \n" , getpid());
            exit(1);
        }
        else{
            waitpid(p2 , &status2 , 0);
            printf("Parent pid is %d \n" , getpid());
        }
       
    }
    return 0;
}
