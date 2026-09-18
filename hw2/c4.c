#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p = fork();
    int e;
    if( p == 0){
        e = execl("/usr/bin/grep", "grep" ,"vorpal",  "test.txt", NULL);
        exit(0);
    }
    else{

        wait(NULL);
        printf("Parent process is done \n");
       
    }
    return 0;
}
