void mediaMovel(int N, float v[], int k, float m[]){
    
    for (int j = 0; j < N - (k - 1); j++){
        float somaTemp = 0;
        for (int i = 0; i < k; i++){
            
            somaTemp += v[j + i];
        
        }
        
        m[j] = somaTemp / k;
    }
    
}