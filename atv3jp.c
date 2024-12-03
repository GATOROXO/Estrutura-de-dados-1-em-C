/** Objetivo 3 : tabuada (n) de 1 até 10 em C  
 * Nome: João Paulo Alves Campos
 * Data: 03/12/2024
 * Atividade de treinamento
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, i;
    printf("Digite um numero: ");
    scanf("%d", &num);

    for (i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", num, i, num * i);
    }
    system("pause");
    return 0;
}