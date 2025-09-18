 #include <stdio.h>

unsigned long long fast_pow_2(int expoente){
   unsigned long long _pow = 1 ;
   _pow <<= expoente;
    printf("%lld ", _pow);
    return _pow;
}

// int main(int argc, char const *argv[])
// {
//     fast_pow_2(3);
//     return 0;
// }

