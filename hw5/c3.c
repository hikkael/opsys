#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int initial_size = 10;
    int new_size = 5;
    int input;    

    arr = (int *)calloc(initial_size ,  sizeof(int));

    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

	printf("Enter 10 integers:");
    for (int i = 0; i < initial_size; i++) {
	scanf("%d" , &input);
	arr[i] = input;
    }
	printf("\n");
   
     int *new_arr = (int *)realloc(arr, new_size * sizeof(int));

   if (new_arr == NULL) {
        printf("Memory reallocation failed!\n");
        free(arr);
	return 1;
    }

	printf("Array after resizing: ");	
   for (int i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]);
	
    }
	printf("\n");


    free(new_arr);

    return 0;
}
