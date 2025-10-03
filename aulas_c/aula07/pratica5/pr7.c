int soma_divisores(unsigned int n){
    int sd = 0;
    
    for (int i = 1; i <= n; i++){
        
        if (n % i == 0){
            sd += i;
        }
        
    }
    
    return sd;
}