/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 05/12/2024
 */


#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, Div_inteira, Div_resto;
    printf("Digite um numero inteiro : ");
    scanf("%d", &num);

    Div_inteira = num /3;
    Div_resto = num % 3;

    printf("A divisao inteira eh : %d\n", Div_inteira);
    if (Div_resto != 0){
        printf("O resto da divisao eh : %d\n", Div_resto);
    }
}