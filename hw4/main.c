#include "math_utils.h"
#include <stdio.h>

int main(){
	int a;
	printf("Input number you want squared : ");
	scanf("%d", &a);
	int result = square(a);
	printf("%d squared is %d \n" , a , result);

}
