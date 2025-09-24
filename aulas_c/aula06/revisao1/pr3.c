void aumentaOsDiferentes(int* end_var1, int* end_var2) {
    
    if (*end_var1 == *end_var2){
        
        *end_var1 = 0;
        *end_var2 = 0;
        
    } else {
        
        int temp = *end_var1 + *end_var2;
        *end_var1 = temp;
        *end_var2 = temp;
        
    }
    
    
    
}