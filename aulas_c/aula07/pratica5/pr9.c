#include <math.h>
int soma_digitos_pares(unsigned int n){
   int soma = 0;
   int digito;
   
   while (n > 0){
       digito = n % 10;
       
       if (digito % 2 == 0){
           soma += digito;
       }
       
       n /= 10;
   }
   return soma;
    
}