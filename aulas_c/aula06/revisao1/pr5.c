void divisao(int* end_var1, int* end_var2) {
    
    int resultDiv = *end_var1 / *end_var2;
    int restoDiv = *end_var1 % *end_var2;
    
    *end_var1 = resultDiv;
    *end_var2 = restoDiv;
    
}