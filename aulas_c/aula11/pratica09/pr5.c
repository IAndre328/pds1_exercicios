#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 31

typedef struct{
    char name[TAM_MAX_NOME];
    int age;
}PEOPLE;

int readVectorWithPeople(PEOPLE** persons, int* qtdPerson, FILE* file){
    
    char nameBuffer[TAM_MAX_NOME];
    char ageBuffer[sizeof(int)];


    while (fgets(nameBuffer, TAM_MAX_NOME, file) != NULL){

        fgets(ageBuffer, sizeof(int), file);

        nameBuffer[strcspn(nameBuffer, "\n")] = 0;
        ageBuffer[strcspn(ageBuffer, "\n")] = 0;

        PEOPLE* tempArray = realloc(*persons, (*qtdPerson + 1) * sizeof(PEOPLE));

        if (tempArray == NULL){

            printf("Erro ao alocar memória");
            return 1;
        }    
            
        *persons = tempArray;

        strcpy((*persons)[*qtdPerson].name, nameBuffer);
        (*persons)[*qtdPerson].age = atoi(ageBuffer);

        
        
        printf("Nome %s\n", (*persons)[*qtdPerson].name);
        printf("idade %d\n", (*persons)[*qtdPerson].age);

      
        (*qtdPerson)++;
    }
    

    return 0;
}

int returnIndexYounger(PEOPLE* persons, int qtdPersons){

    int maiorIndex = 0;

    for (int i = 1; i < qtdPersons; i++)
        if (persons[i].age < persons[maiorIndex].age) maiorIndex = i;
    
    return maiorIndex;

}

int returnIndexOlder(PEOPLE* persons, int qtdPersons){

    int maiorIndex = 0;

    for (int i = 1; i < qtdPersons; i++)
        if (persons[i].age > persons[maiorIndex].age) maiorIndex = i;
    
    return maiorIndex;

}

int main(){

    FILE* file;
    file = fopen("case.txt", "r");

    if (file == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    PEOPLE* persons = NULL;
    int qtdPerson = 0;

    
    int readVector = readVectorWithPeople(&persons, &qtdPerson, file);

    int indexYounger = returnIndexYounger(persons, qtdPerson);
    int indexOlder = returnIndexOlder(persons, qtdPerson);

    printf("%s\n", persons[indexYounger].name);
    printf("%s\n", persons[indexOlder].name);

    free(persons);
    fclose(file);
    return 0;
}
