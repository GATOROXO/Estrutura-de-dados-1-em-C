/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 05/12/2024

 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, media;
    printf("Digite o primeiro valor: ");
    scanf("%f", &a);
    printf("Digite o segundo valor: ");
    scanf("%f", &b);
    printf("Digite o terceiro valor: ");
    scanf("%f", &c);
    media = (a + b + c)/ 3;
    printf("A media dos valores eh: %d\n", media);
    if (media == a || media == b || media == c) {
        printf("A media eh igual a um dos valores\n");
    } else {
        printf("A media nao eh igual a nenhum dos valores\n");
    }
    system("pause");
    return 0;
}