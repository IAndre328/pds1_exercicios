// AULA DE HOJE: ARQUIVOS

// Como um computador é organizado:

/*

                          |___________________|                         
                          |Cpu                |
Dispositivo de entrada -> |Unidade de controle|  -> Dispositivo de saida
                          |Unidade lógica     |
                          |Regitradores       |
                          |___________________|
                          |                   |
                          |                   |
                          |   Memória         |
                          |___________________|

*/

/*
Vamos brincar de arquivo:
*Deve ser aberto ates de usado
*Aberta com o modo, que define quais operações vai fazer (eitura/escrita)

Usa-se FILE*
Use <stdio.h>

FILE* fopen(char* nome_completo, char* modo);
modos:
    r -> read -> leitura
    w -> escrita -> APAGA O QUE JÁ TEM NO ARQUIVO, se tiver
    a -> apendidário -> acrescenta no final do que já tem, cria um novo se não existir

    r+ -> abre para leitura e escrita *O arquivo deve existir
    w+ -> abre um arquivo em branco para ler e escrever -> apaga o que já existe
    a+ -> acresente no final do que já tem, pode ler o resto

    int main(){

        FILE* arquivo = NULL;
        char nome[1000];
        scanf("%s", nome);
        arquivo = fopen(nome, "w");
        fclose(arquivo);

        return 0;

        // Abre o arquivo em outro modo.
        FILE* freopen(char* nome, "R", arquivo);

        // Fim do arquivo eof -> end of file
        feof(arquivo);

        // Leitura
        fscanf(arquivo, "%d", &x);


    }





*/