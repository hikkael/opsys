#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
    pid_t p1 , p2;
    int status1 , status2;
    p1 = fork();

    if(p1 < 0){
        exit(1);
    }
    else if( p1 == 0){
        exit(0);
    }
    else{   
        

        pid_t p2 = fork();
        if(p2 <0){
            exit(1);
        }
        else if(p2 == 0){
            exit(0);
        }

        waitpid(p1 , &status1, 0);

        if(WIFEXITED(status1)){
            int exitstatus1 = WEXITSTATUS(status1);
            
            if(exitstatus1 == 0){
                printf("Child 1 exited normaly with status %d \n", status1);
            }
            else{
                printf("Child 1 exited abnormaly with status %d \n", status1);
            }
        }

        waitpid(p2 , &status2, 0);

        if(WIFEXITED(status2)){
            int exitstatus2 = WEXITSTATUS(status2);
            
            if(exitstatus2 == 0){
                printf("Child 2 exited normaly with status %d \n", status2);
            }
            else{
                printf("Child 2 exited abnormaly with status %d \n", status2);
            }
        }


        
       
    }
    return 0;
}
