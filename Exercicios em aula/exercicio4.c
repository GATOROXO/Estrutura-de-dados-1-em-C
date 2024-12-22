/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 05/12/2024
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, soma=0;
    printf("Digite o valor a multiplicar : \n");
    scanf("%d", &a);
    printf("Digite o valor a ser multiplicado : \n");
    scanf("%d", &b);
    for (int i = 1; i <= b; i++){
        soma = soma + a;
        printf("%d\n", soma);
    }
    printf("%d * %d = %d\n", a, b, soma);
    system("pause");
    return 0;
}