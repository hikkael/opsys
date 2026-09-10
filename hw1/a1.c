#include <stdio.h>

int main(){
 int x = 9;
 int *p = &x;
 printf("Address of the integer variable using variable %p \n", &x);
 printf("Address of the integer variable using pointer %p \n", &p);
 
 *p = 11;
 
printf("New value that I definiteley did not forgot about is %d \n" , *p);

return 0;
}
