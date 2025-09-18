#include <stdio.h>
int parOuImpar(unsigned int number){
    unsigned int mask1 = 0x1111;
    unsigned int mask2 = 0x0001;
    unsigned p_ou_i = number ^ mask1;
    p_ou_i = p_ou_i & mask2;
    return p_ou_i;
}

 
/*
int main(int argc, char const *argv[])
{
    printf("%d\n ", parOuImpar(2));
    return 0;
}
*/
