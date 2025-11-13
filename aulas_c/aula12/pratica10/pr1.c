#include <stdio.h>
#include <stdlib.h>

void free_array(void* array){
    free(array);
}


float* read_array(int* n){
    
    
    scanf("%d", n);
    
    printf("N armazenado: %d\n", *n);
    
    float* array = (float*) malloc(*n * sizeof(float));
   
    
    
    for (int i = 0; i < *n; i++)
        scanf("%f", &array[i]);

    return array;
}


