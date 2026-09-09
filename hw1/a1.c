#include <stdio.h>

int main(){
 int x = 9;
 int *p = &x;
 printf("Address of the integer variable using variable %p \n", &x);
 printf("Address of the integer variable using pointer %p \n", &p);
 return 0;
}
