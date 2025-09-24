int codigoDeArea(unsigned int number) {
    return number / 100000000;
}

int parEmImpar(unsigned int number) {
    int mask = 0x0001;
    return number | mask;
}


int par(unsigned int number) {
    int mask = 0x0001;
    return ((number ^ mask) & mask);
}