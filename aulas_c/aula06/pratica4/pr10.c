#include <stdio.h>


int calc(double num1, char op, double num2){
    
    
    
    switch(op){
        
        case '+':
            printf("%.2lf + %.2lf = ", (num1 + num2));
            break;
            
        case '-':
            printf("%.2lf - %.2lf = ", (num1 - num2));
            break;
            
        case '*':
            printf("%.2lf * %.2lf = ", (num1 * num2));
            break;
            
        case '/':
            if (num2 == 0){
                printf ("Erro! Divisao por zero nao e permitida.");
                return 1;
            } else {
                
                printf("%.2lf / %.2lf = ", (num1 / num2));
            }
            break;
        
        default:
            printf("Operador invalido!");
            return 1;
            break;
    }
    
}


int main(){
    
    float n1, n2;
    char op;
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    
    calc(n1, op, n2);
    
    if (calc(n1, op, n2) == 1){
        return 1;
    }
    
    return 0;
}