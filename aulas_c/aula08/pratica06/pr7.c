void removechar(char* a, int tamanho, char c){
    // escreva sua solução aqui
    int codCaractereRef = c;
    
    
    
    int done = 0;
    int i = 0;
    int iniDepois = 0;
    char tempAntes[50];
    char tempDepois[50];
    
    
    while ((i < tamanho){
        int caracterAnalise = a[i];

        
        if (done < 1){
            if (caracterAnalise == codCaractereRef){
                done++;
                
                iniDepois = i;
                
                a[i] = (char)32;
                
                tempAntes[i + 1] = a[tamanho];
                
            }
            tempAntes[i] = a[i];

  
        i++;
    }
        
    
}
