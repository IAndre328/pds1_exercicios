#include <stdio.h>

void main() {
    float a = 3.14159, b = 2.71828;

    // seu codigo vai aqui
    float temp = a;
    a = b;
    b = temp;
    // nao modificar as outras linhas de codigo

    printf("\nPi = %f", b);
    printf("\nEuler = %f", a);
}