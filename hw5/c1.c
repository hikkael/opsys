#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main(){
	int *arr;
	int n;
	int input;

	printf("The number of elements to be summed is : ");
	scanf("%d" , &n);
	if(n<=0){
		printf("Illegal size of n");
		return 1;
	}

	arr = (int *) malloc(n * sizeof(int));

	 if (arr == NULL) {
        	printf("Memory allocation failed! \n");
        	return 1;
    	}


	int sum = 0;

	for (int i = 0; i < n; i++) {
	printf("arr[%d]  = ", i);	    
	scanf("%d" , &input);
	arr[i] = input;
	sum += arr[i];	
}


	printf("SUM = %d \n",sum);
	
	free(arr);

	return 0;


	

}
