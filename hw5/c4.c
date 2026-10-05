#include <stdio.h>
#include <stdlib.h>



void print_string(char **arr , int size){
   int string_size = 50;
   for(int i = 0 ; i<size ; i++){
   printf("String %d is:%s\n", i+1 , arr[i]);    
   }       
  return;
}


int main() {
    char **arr;
    int initial_size = 3;
    int string_size = 50;
    char  input;

    arr = (char **)calloc(initial_size ,  sizeof(char *));


    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    for(int i = 0 ; i<initial_size ; i++){
	char *str;
	str = (char *) calloc(string_size , sizeof(char));
	if (str == NULL) {
        printf("String memory allocation failed!\n");
        return 1;}
	arr[i] = str;
	printf("Input string %d :" , i+1);
	
	for(int j = 0 ; j<string_size ; j++){
	scanf("%c", &input);
	if(input == '\n'){
	break;	
	}
	str[j] =input;
	}	

	}	

    print_string(arr , initial_size);	    


   int new_size = initial_size + 2;
   char ** new_arr  = (char **) realloc(arr , new_size * sizeof(char *));

   if (new_arr == NULL) {
        printf("Memory reallocation failed!\n");
        for(int i = 0 ; i < initial_size ; i++){
   		free(arr[i]);
    	}
	free(arr);
	return 1;
    }

    for(int i = initial_size ; i<new_size ; i++){
        char *str;
        str = (char *) calloc(string_size , sizeof(char));
        if (str == NULL) {
        printf("String memory allocation failed!\n");
        return 1;}
        new_arr[i] = str;
        printf("Input string %d :" , i+1);

        for(int j = 0 ; j<string_size ; j++){
        scanf("%c", &input);
        if(input == '\n'){  
        break;  
        }
        str[j] =input;
        }
        

        }       

    print_string(new_arr , new_size);       




    for(int i = 0 ; i < initial_size ; i++){
    free(new_arr[i]);
    }


    free(new_arr);

    return 0;
}

