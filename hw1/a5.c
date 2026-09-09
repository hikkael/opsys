#include <stdio.h>


int main(){
 char str[] = "Hello";
 char *p = &str[0];
 for(int i=0 ; i < sizeof(str)/sizeof(*p) ; i++){
 printf("%c",*p);
 p++;
}
printf("\n");

p = &str[0];


printf("Lenght of text %ld \n" , sizeof(str)/sizeof(*p));

return 0;
}
