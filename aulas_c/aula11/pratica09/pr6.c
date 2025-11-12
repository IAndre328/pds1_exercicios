#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 21

void freeArray(char** arr, int qtdLinhas){
    
    for (int i = 0; i < qtdLinhas; i++) {
        free(arr[i]);
    }
    free(arr);
    
}

int readPersonsWithFile(char*** persons, int* qtdPersons, FILE* file){

    char buffer[TAM_MAX_NOME];

    while (fgets(buffer, TAM_MAX_NOME, file) != NULL){

        buffer[strcspn(buffer, "\n")] = 0;

        char** tempArray = (char**)realloc(*persons, (*qtdPersons + 1) * sizeof(char*));

        if (tempArray == NULL){

            printf("Erro ao alocar memória");
            return 1;
        }  

        *persons = tempArray;

        (*persons)[*qtdPersons] = strdup(buffer);
        //printf("Pessoa %d\n",(*persons)[*qtdPersons]);

        (*qtdPersons)++;
    }

    return 0;
}


// Corrected function: Sorts the array alphabetically using Selection Sort and strcmp.
void sortAlphabetic(char** persons, int qtdPersons){
    
    // We use a simple Selection Sort algorithm
    for (int i = 0; i < qtdPersons - 1; i++){
        int minIndex = i; // Finding the smallest element (alphabetically)
        
        for(int j = i + 1; j < qtdPersons; j++){
            // strcmp returns < 0 if persons[j] comes before persons[minIndex]
            if(strcmp(persons[j], persons[minIndex]) < 0) {
                minIndex = j;
            }
        }
        
        // Swap the pointers only if the minimum element is not already at position i
        if (minIndex != i) {
            char* temp = persons[i];
            persons[i] = persons[minIndex];
            persons[minIndex] = temp;
        }
    }
}

int main(){

    FILE* file;
    file = fopen("case.txt", "r");

    if (file == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char** persons = NULL;
    int qtdPersons = 0;

    int readVector = readPersonsWithFile(&persons, &qtdPersons, file);
    
    sortAlphabetic(persons, qtdPersons);

    for (int i = 0; i < qtdPersons; i++) {
        printf("%s\n", persons[i]);
    }

    freeArray(persons, qtdPersons);
    fclose(file);
    return 0;
}