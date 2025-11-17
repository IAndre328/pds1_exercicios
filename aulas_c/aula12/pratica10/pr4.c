#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define TAM_MAX_BUFFER 51

void free_address(struct address *addr){
   
    if (addr == NULL) return;
    
    if (addr->line != NULL) free(addr->line);
   
    free(addr);
    
}

void free_user(struct user *user){

    if (user == NULL) return; 

    if (user->name != NULL) free(user->name);
    if (user->addr != NULL) free_address(user->addr);
    
    free (user);

}

void free_user_database(struct user **db, int n){
    
    
    if((db) == NULL) return;
    
    
    for(int i = 0; i < n; i++){
        if(db[i] != NULL) free_user(db[i]);
    
    
    }
    
    free(db);
}

struct address *create_address(const char *input){
    
    //Temps
    char tempBuffer[TAM_MAX_BUFFER];
    char* tempPart[3];
    memset(tempPart, 0, 3 * sizeof(char*));
    int tempNumber = 0;
    int tempZipcode = 0;
    
    //Vetor a ser retornado
    struct address* newAddress = malloc(sizeof(struct address));
    
    if (newAddress == NULL) return NULL;
    
    memset(newAddress, 0, 1 * sizeof(struct address));
    
    strcpy(tempBuffer, input);
    
    char* part = strtok(tempBuffer, "|");
    if (part == NULL) {
        free_address(newAddress);
        return NULL;
    }
    
    int i = 0;
    while(part != NULL && i < 3){
        tempPart[i] = part;
        printf("%s\n", tempPart[i]);
        
        
        part = strtok(NULL, "|");
        i++;
    }

    for (int j = 0; j < 3; j++) if (tempPart[j] == NULL){
        
        free_address(newAddress);
        return NULL;
        
    };
    
   (*newAddress).line = (char*)malloc((strlen(tempPart[0]) + 1) * sizeof(char));
   
   if ((*newAddress).line == NULL){
       
       free_address(newAddress);
        return NULL;
       
   }
   
   strcpy(newAddress->line, tempPart[0]);
   
   //printf("%s\n", newAddress->line);
   
   (*newAddress).number = atoi(tempPart[1]);
   (*newAddress).zipcode = atoi(tempPart[2]);
    
    return newAddress;
    
}

struct user *create_user(const char *input){

   

    //temps
    char* bufferInput = malloc(strlen(input) + 1);
    char* tempPart[3];
    memset(tempPart, 0, 3 * sizeof(char*));

    
    if (bufferInput == NULL){
        free(bufferInput);
        return NULL;
    }
    
    strcpy(bufferInput, input);

    char* part = strtok(bufferInput, "#");
    if (part == NULL) return NULL;

    
    int i = 0;
    while(part != NULL){
        tempPart[i] = part;
        //printf("%s", tempPart[i]);
        
        if (part == NULL) return NULL;

        part = strtok(NULL, "#");
        i++;
    }

    
    for (int j = 0; j < 3; j++) if (tempPart[j] == NULL){
        
        return NULL;
        
    };

    struct user* usuario = malloc(sizeof(struct user));
    if (usuario == NULL) return NULL;

    (*usuario).name = malloc(strlen(tempPart[0]) + 1);
    
    if((*usuario).name == NULL){
        free_user(usuario);
        return NULL;
    }
    
    strcpy((*usuario).name, tempPart[0]);
    
    (*usuario).idade = atoi(tempPart[1]);
    (*usuario).addr = create_address(tempPart[2]);
    
    free(bufferInput);
    return usuario;

}

struct user **create_user_database(int n){
    
    struct user** db = NULL;
    
    db = calloc(n, sizeof(struct user *));
    
    if (db == NULL){
        
        return NULL;
        
    }
    
    char input[TAM_MAX_BUFFER];
    
    struct user* readUser = NULL;
    for (int k = 0; k < n; k++){
        
        fgets(input, TAM_MAX_BUFFER, stdin);
        
        input[strcspn(input, "\n")] = 0;
        
        readUser = create_user(input);
        
        if (readUser == NULL){
            
            free_user_database(db, n);
            return NULL;
            
        }
        
        db[k] = readUser;
        
    }
    
    return db;
    
}