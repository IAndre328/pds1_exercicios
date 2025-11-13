#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_BUFFER 51

struct address {
    char *line;
    int number;
    int zipcode;
};

struct user {
    char *name;
    int idade;
    struct address *addr;
};

void free_address(struct address *addr){
   
        free((*addr).line);
   
    free(addr);
    
}

void free_user(struct user *user){

    free((*user).name);
    free_address(((*user).addr));

}

struct address *create_address(const char *input){
    
    //Temps
    char tempBuffer[TAM_MAX_BUFFER];
    char* tempPart[3];
    int tempNumber = 0;
    int tempZipcode = 0;
    
    //Vetor a ser retornado
    struct address* newAddress = malloc(sizeof(struct address));
    
    strcpy(tempBuffer, input);
    
    char* part = strtok(tempBuffer, "|");
    
    int i = 0;
    while(part != NULL && i < 3){
        tempPart[i] = part;
        //printf("%s\n", tempPart[i]);
        
        part = strtok(NULL, "|");
        i++;
    }

    
   (*newAddress).line = (char*)malloc((strlen(tempPart[0]) + 1) * sizeof(char));
   strcpy(newAddress->line, tempPart[0]);
   
   //printf("%s\n", newAddress->line);
   
   (*newAddress).number = atoi(tempPart[1]);
   (*newAddress).zipcode = atoi(tempPart[2]);
    
    return newAddress;
    
}

struct user *create_user(const char *input){

    //temps
    char bufferInput[strlen((*input)) + 1];
    char* tempPart[3];

    char* part = strtok(*input, "#");

    int i = 0;
    while(part != NULL){
        tempPart[i] = part;

        part = strtok(NULL, "#");
        i++;
    }

    struct user* usuario = (struct user*)malloc(sizeof(struct user));

    strcpy((*usuario).name, tempPart[0]);
    (*usuario).idade = atoi(tempPart[1]);
    (*usuario).addr = create_address(tempPart[2]);

}