#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char c = getchar();
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);
    printf("%c = %d ", c, x + y);

    return 0;
}
