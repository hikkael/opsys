#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>




void cleanup1(){

    printf("CLEANUP 1 \n");
}

void cleanup2(){
    printf("CLEANUP 2 \n");
}


int main()
{
    atexit(cleanup1);
    atexit(cleanup2);


    printf("EXPLANATION WILL BE IN THE DOCUMENT \n");
    exit(1);


    return 0;
}
