#include <stdio.h>



int swap(int *a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}





int main(){

 int x = 49;
 int y = 3;
 printf("Before swap x=%d and y=%d ," , x ,y);
 swap(&x, &y);
 printf("after swap x=%d and y=%d ," , x ,y); 
 return 0;}

