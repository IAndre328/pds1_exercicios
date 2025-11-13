#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "address.h"

struct address {
    char *line;
    int number;
    int zipcode;
};

#define TAM_MAX_BUFFER 101

void free_address(struct address *addr){
   
        free((*addr).line);
   
    free(addr);
    
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