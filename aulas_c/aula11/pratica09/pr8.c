#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_BUFFER 11

typedef struct{
    int day, month, year;
    unsigned long long concatDate;
}DATE;

int insertDateInVector(DATE** date, DATE newDate,int* qtdDate){
    
    if (
        (newDate.day < 0) || (newDate.day > 31) ||
        (newDate.month < 0) || (newDate.month > 12) ||
        (newDate.year < 0)
        ) {
            
            return 1;
        }
    
    
    DATE* tempArrayDate = (DATE*)realloc(*date, (*qtdDate + 1) * sizeof(DATE));
    
    if (tempArrayDate == NULL) {
        
        perror("Erro ao realocar a memória");
        return 1;
    }
    
    *date = tempArrayDate;
    
    (*date)[*qtdDate].day = newDate.day;
    (*date)[*qtdDate].month = newDate.month;
    (*date)[*qtdDate].year = newDate.year;
    
    (*date)[*qtdDate].concatDate = (newDate.year * 100000) + (newDate.month * 100) + (newDate.day);
        
    (*qtdDate)++;
    
    return 0;
}

int readVectorWithFile(DATE** date, int* qtdDate, FILE* file){
    
    char buffer[TAM_MAX_BUFFER];
    
    DATE tempDate;
    int tempDay = 0;
    int tempMonth = 0;
    int tempYear = 0;
    
    while(fgets(buffer, TAM_MAX_BUFFER, file) != NULL){
        
        sscanf(buffer, "%d/%d/%d", &tempDay, &tempMonth, &tempYear);
        
        tempDate.day = tempDay;
        tempDate.month = tempMonth;
        tempDate.year = tempYear;
        
        int idiv = insertDateInVector(date, tempDate, qtdDate);
        if (idiv == 1) return 1;
        
        
        //printf("dia %d\n mes %d\n ano %d\n", tempDay, tempMonth, tempYear);
        
    }
    
    
    
}

int returnNewestIndex(DATE* date, int qtdDate){
    int newestIndex = 0;
    
    for (int i = 1; i < qtdDate; i++){
        if (date[i].concatDate > date[newestIndex].concatDate) newestIndex = i;
    }
    
    return newestIndex;
}

int main(){
    
    FILE* file;
    file = fopen("datas.txt", "r");
    
    if(file == NULL){
        perror("Não foi possível abrir o arquivo");
        return 1;
    }
    
    DATE* date = NULL;
    int qtdDate = 0;
    
    int rvwf = readVectorWithFile(&date, &qtdDate, file);
    if (rvwf == 1) return 1;
    
    // Fazer Essa função
    int rni = returnNewestIndex(date, qtdDate);
    
    if (date[rni].day < 10) printf("0%d/", date[rni].day);
        else printf("%d/", date[rni].day);
    
    if (date[rni].month < 10) printf("0%d/", date[rni].month);
        else printf("%d/", date[rni].month);
        
    if (date[rni].year < 10) printf("0%d", date[rni].year);
        else printf("%d", date[rni].year);
    
    
    
    fclose(file);
    return 0;
}