#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() 
{ 

    pid_t p1 = fork();
    pid_t p2 = fork();

    if(p1 == 0){
        if(p2 == 0){
            printf("Child process of p1: %d -> Child Process p2 : %d \n" ,p1, p2 );
        }
        else{
            printf("Child process of p1: %d -> Parent Process p2 : %d \n" ,p1, p2 );
        }
    }
    else{
        if(p2 == 0){
            printf("Parent process of p1: %d -> Child Process p2 : %d \n" ,p1, p2 );
        }
        else{
            printf("Parent process of p1: %d -> Parent Process p2 : %d \n" ,p1, p2 );
        }

        wait(NULL);  
    }


    return 0; 

} 

