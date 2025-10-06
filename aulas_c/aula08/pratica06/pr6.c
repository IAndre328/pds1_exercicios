int contaocorrencias(char* a, int tamanho, char c) {
    // escreva sua solução aqui
    
    int codCaractereRef = c;
    int ocorrencias = 0;
    
    for (int i = 0; i < tamanho; i++){
        int caracterAnalise = a[i];
        
        if (caracterAnalise == codCaractereRef){
            ocorrencias++;
        }
        
    }
    
    return ocorrencias;
    
}