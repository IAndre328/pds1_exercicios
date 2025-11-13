/* 


TÓPICO : RECURSIVIDADE;


















*/

/*


 long long T(int n){
    if (n == 0) return 1;
    return 3 * T(n - 1);
 }

int main(){

    int n = 0;

    scanf("%d", &n);

    printf("%lld", T(n));

    return 0;
}


*/

int F(int n, int* fibs){

    if(n <= 1) return n;
    if (fibs[n] != 0) return fibs[n];
    return fibs[n] = F(n - 2, fibs) + F(n - 1, fibs);

}

int main(){

    int n = 0;
    int fibs[1000];

    scanf("%d", &n);

    F(n, fibs);

}
