unsigned long long fatorial(int n){
    unsigned long long total = 1;
    for (int i = n; i >= 2; i--){
        total *= i;
    }
    return total;
}