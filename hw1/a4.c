#include <stdio.h>


int main(){
int x = 10;
int *p = &x;
int **pp = &p;

printf(" Value of the integer using  pointer %d \n" , *p);
printf(" Value of the integer using double pointer %d \n" , *(*pp));

return 0;
}
