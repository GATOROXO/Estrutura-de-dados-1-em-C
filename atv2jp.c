/** 
 * Objetivo: pedir tres numeros ao usuario e mostrar o maior deles
 * Nome: João Paulo Alves Campos
 * Data: 03/12/2024
 * Atividade de treinamento
 */

#include <stdio.h>

int main(){
    int a , b ,c ;
    
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    printf("Digite o terceiro valor: ");
    scanf("%d", &c);

    if (a > b && a > c){
        printf("O maior valor eh %d", a);
    }
    if (b > a && b > c){
        printf("O maior valor eh %d", b);
    }
    else {
        printf("O maior valor eh %d", c);
    }
    return 0;
}