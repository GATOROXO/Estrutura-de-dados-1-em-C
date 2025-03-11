/**
 * UFMT - Ciências da Computação
 * Estrutura de Dados 1
 */

#include <stdio.h>   
#include <stdlib.h> 

int main() {
    int x , y , total;
    printf("Digite o valor de X : \n");
    scanf("%d", &x);
    printf("Digite o valor de Y : \n");
    scanf("%d", &y);
    total = x + y;
    printf("X=%d + Y=%d o toth: %d\n", x , y , total);
    return 0;
} 