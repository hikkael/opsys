#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p = fork();
    int e;
    if( p == 0){
        e = execl("/usr/bin/ls", "ls", NULL);
        exit(0);
    }
    else{
        wait(NULL);

        int p2 = fork();
        if(p2 == 0){
            e = execl("/usr/bin/date" , "date" , NULL);
            exit(0);
        }

        wait(NULL);
        printf("Parent process is done \n");
       
    }
    return 0;
}
