int mdc(int a, int b){
    int menor = a < b ? a : b;
    int divisor;
    
    for (int i = 1; i <= menor; i++){
        
        if ((a % i == 0) && (b % i ==0)){
            divisor = i;
        }
        
    }
    return divisor;
}