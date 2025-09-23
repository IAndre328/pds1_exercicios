#include <stdio.h>

int verifValor(float a, float b, float c){
    
    if (
        a >= b + c ||
        b >= a + c ||
        c >= a + b
        ){
            
           return 1; 
           
    } else {
        
        return 0;
        
    }
    
}


int verifTri(float a, float b, float c){
    
    if (
        a == b && 
        b == c
        ){
        
        printf("Triangulo equilatero");
        
    }else if (
        (a == b && a != c) ||
        (a != b && a == c) ||
        (b == c && a != b)
        ){
        
        printf("Triangulo isosceles");
        
    } else {
        
        printf("Triangulo escaleno");
        
    }
}

int main(){
    
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    
    if (
        a <= 0 ||
        b <= 0 ||
        c <= 0
        ){
            
            printf("Valores invalidos");
            return 1;
        
    } else if(verifValor(a, b, c) == 1){
        
        printf("Triangulo invalido");
        return 1;
        
    } else {
        
        verifTri(a, b, c);
        
    }
    
    
    
    return 0;
}