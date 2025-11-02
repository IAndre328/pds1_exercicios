#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "instant.h"

typedef struct instant{
    int hour;
    int minute;
    int second;
    
};

int instant_check(struct instant i){

    if (
        i.hour < 0 ||
        i.minute < 0 ||
        i.second < 0
    ) return 0;
    
    if (
        i.hour > 23 ||
        i.minute > 59 ||
        i.second > 59
    ) return 0;
    
    return 1;
}

int instant_parse(const char* str, struct instant *init){

    int h, m, s;
    int caracteres_lidos;

    int resultado = sscanf(str, "%d:%d:%d%n", &h, &m ,&s, &caracteres_lidos);

    if(resultado != 3 || (size_t)caracteres_lidos != strlen(str)){
        return 1;
    }

    struct instant temp;
    temp.hour = h;
    temp.minute = m;
    temp.second = s;

    // Se tiver valores estranhos ira retornar 2
    if(instant_check(temp) != 1) return 2;

    init->hour = h;
    init->minute = m;
    init->second = s;

    return 0;
}

int instant_compare(struct instant i1, struct instant i2){

    //110022
    long long concatTime1 = (i1.hour * 10000) + (i1.minute * 100) + (i1.second);
    long long concatTime2 = (i2.hour * 10000) + (i2.minute * 100) + (i2.second);

    // Se i1 for mais cedo
    if(concatTime1 < concatTime2) return -1;

    // se i1 for mais tarde
    else if(concatTime1 > concatTime2) return 1;
    
    // se i1 for o mesmo horário
    else return 0;

}

void instant_read_vector(struct instant *v, int n){

    char str[12];
    for (int i = 0; i < n; i++){

        do{

            scanf("%11s", str);
            str[strcspn(str, "\n")] = 0; 


        } while (instant_parse(str, &v[i]) != 0);
        
        

    }
    

}

struct instant instant_largest(const struct instant *v, int n){

    struct instant maior;

    
    int maxIndex = 0;

    for (int k = 1; k < n; k++){
        
        maior = v[maxIndex];

        if(instant_compare(v[k],v[maxIndex]) == 1)
            maxIndex = k;

    }

    maior = v[maxIndex];

    return maior;    
        
}

const int NINSTANTS = 5;

int main(void) {
  struct instant v[NINSTANTS];
  instant_read_vector(v, NINSTANTS);
  struct instant maior = instant_largest(v, NINSTANTS);
  printf("Maior instante: %02d:%02d:%02d\n",
         maior.hour, maior.minute, maior.second);
}
