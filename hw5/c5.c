#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int input;
    int size;
    int min = 10000;
    int max = -1;


    printf("Enter the number of students: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    printf("Enter the grades: ");
    for (int i = 0; i < size; i++) {
	scanf("%d" , &input);
	arr[i] = input;
    }
;
    for (int i = 0; i < size; i++) {
	if(arr[i] < min) {
	min = arr[i];
	}

	if(arr[i] >max){
	max = arr[i];
	}
    }


   printf("Highest grade: %d \n" , max);
   printf("Lowest grade: %d \n" , min);

    free(arr);

    return 0;
}
