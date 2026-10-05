#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int n;
	int input;

	printf("The number of the array is : ");
	scanf("%d" , &n);
	if(n<=0){
		printf("Illegal size of n");
		return 1;
	}

	arr = (int *) calloc(n , sizeof(int));

	if (arr == NULL) {
        	printf("Memory allocation failed! \n");
        	return 1;
    	}

	printf("Array after calloc() : ");
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
	 }
	
	printf("\n");

	int sum = 0;
	printf("Enter %d integers : ", n);	
	
	for (int i = 0; i < n; i++) {	    
	scanf("%d" , &input);
	arr[i] = input;
	sum += arr[i];
	}

	printf("Updated array : ");
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);}
	printf("\n");

	float avg = sum /(float)n;

	printf("Average of the array : %.1f \n" , avg);

	free(arr);

	return 0;


	

}
