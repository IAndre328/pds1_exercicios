#include <stdio.h>



int validaAno(int d, int m, short b){
    
    switch (m){
        // Os dias com 30 dias
        case 4:
        case 6:
        case 9:
        case 11:

            if (d <= 30){

                printf("Data valida");

            }else{

                printf("Data invalida");

            }

            break;
        
        // Os meses com 31 dias
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:

            if (d <= 31){

                printf("Data valida");

            }else{

                printf("Data invalida");

            }
            break;
        
        // Fevereiro
        case 2:
           if (b == 1){
            if (d <= 29){

                printf("Data valida");

            }else{

                printf("Data invalida");

            }
           }else {
                if (d <= 28){

                printf("Data valida");

            }else{

                printf("Data invalida");

            }
           }
           
            
            break;
        default:   

            printf("Data invalida");
            break;
    }
}


int verifAno(int d, int m, int a){
    short bisexto = 0;
    if (
        ((a % 4) == 0) && ((a % 100) != 0) ||
        ((a % 400) == 0)
    ){
        bisexto = 1;
        validaAno(d, m, bisexto);
    } else{
        validaAno(d, m, bisexto);
    }
    
}


int main(int argc, char const *argv[]){
    
    int dia;
    int mes;
    int ano;

    scanf("%d %d %d", &dia, &mes, &ano);

    if (
        dia <= 0 ||
        mes <= 0 ||
        ano <= 0
        ){
        printf("Data invalida");
    } else {

        verifAno(dia, mes, ano);
    }
    




    return 0;
}
