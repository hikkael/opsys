#include <stdio.h>


int main(){

int arr[] = {1,4,5,8,6};
int *p = arr;


for(int i = 0 ; i < 5 ; i++){
        printf("Value of arr[%d] is %d when printing using pointer  \n" , i , *(p+i));
}
for(int i = 0 ; i < 5 ; i++){
        printf("Value of arr[%d] is %d when printing using variable  \n" , i , *(arr+i));
}

for(int i = 0 ; i < 5 ; i++){
        *(p+i) = 2* arr[i];
	printf("Value of modified arr[%d] is %d \n" , i , *(p+i));
}

return 0;
}


