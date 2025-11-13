#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_user(struct user *user){

}

void free_address(struct address *addr){
   
        free((*addr).line);
   
    free(addr);
    
}

struct user *create_user(const char *input){

    

}