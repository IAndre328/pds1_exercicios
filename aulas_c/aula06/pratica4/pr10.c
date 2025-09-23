

#include <stdio.h>

int calc (float num1, char operador, float num2){
    
    printf("%f %c %f\n", num1, operador, num2);
    
    switch(operador){
        
        case '+':
            printf("%.2f + %.2f = %.2f", num1, num2, (num1 + num2));
            break;
            
        case '-':
            printf("%.2f - %.2f = %.2f", num1, num2, (num1 - num2));
            break;
            
        case '*':
            printf("%.2f * %.2f = %.2f", num1, num2, (num1 * num2));
            break;
            
        case '/':
            if (num2 == 0){
                printf ("Erro! Divisão por zero não é permitida.");
                return 1;
            } else {
                
                printf("%.2f / %.2f = %.2f", num1, num2, (num1 / num2));
            }
            break;
        
        default:
            printf("Operador inválido!");
            return 1;
            break;
    }

}


int main(){
    
    float n1, n2;
    char op;
    
    // printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    
    // printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op);
    
    // printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    
    
    int result = calc(n1, op, n2);
    
    if (result == 1){
        return 1;
    }
    
    return 0;
}