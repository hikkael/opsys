#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t p1 = fork();
    int status1, status2;
    if( p1 == 0){
        exit(0);
    }
    else{   
        wait(&status1);

        pid_t p2 = fork();
        if(p2 == 0){
            exit(0);
        }
        else{
            waitpid(p2 , &status2 , 0);
            printf("Child 1 end status is %d \n" , status1);
            printf("Child 2 end status is %d \n",status2); 
        }
       
    }
    return 0;
}
