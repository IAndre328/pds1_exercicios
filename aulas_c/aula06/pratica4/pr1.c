#include <stdio.h>

int main(){
    
    int n1,n2,n3,n4,n5;
    
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
    
    //Maior
    if (
        n1 > n2 && 
        n1 > n3 &&
        n1 > n4 &&
        n1 > n5
        ){
            
        printf("Maior: %d\n", n1);
        
    } else if(
        
        n2 > n3 && 
        n2 > n4 &&
        n2 > n5
        ){
        
        printf("Maior: %d\n", n2);
        
    }else if (
        n3 > n4 && 
        n3 > n5
        ){
        
        printf("Maior: %d\n", n3);
        
    } else if (
        n4 > n5
        ){
            
        printf("Maior: %d\n", n4);
        
    } else {
        printf("Maior: %d\n", n5);
    }
    
    
    // Menor
    if (
        n1 < n2 && 
        n1 < n3 &&
        n1 < n4 &&
        n1 < n5
        ){
            
        printf("Menor: %d\n", n1);
        
    } else if(
        
        n2 < n3 && 
        n2 < n4 &&
        n2 < n5 
        ){
        
        printf("Menor: %d\n", n2);
        
    }else if (
        n3 < n4 && 
        n3 < n5
        ){
        
        printf("Menor: %d\n", n3);
        
    } else if (
        n4 < n5
        ){
            
        printf("Menor: %d\n", n4);
        
    } else {
        printf("Menor: %d\n", n5);
    }
    
    
    // Divisiveis por 3
    int divPor3 = 0;
    
    if (n1 % 3 == 0){
        divPor3++;
    }
    if (n2 % 3 == 0){
        divPor3++;
    }
    if (n3 % 3 == 0){
        divPor3++;
    }
    if (n4 % 3 == 0){
        divPor3++;
    }
    if (n5 % 3 == 0){
        divPor3++;
    }
    
    printf("Quantidade de divisiveis por 3: %d", divPor3);
}