/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

onjetivo1 :Leia um caractere maiúsculo, 
que indica uma operação que deve ser realizada e uma matriz M[12][12]. 
Em seguida, calcule e mostre a soma ou a média considerando 
somente aqueles elementos que estão acima da diagonal principal da matriz, 
conforme ilustrado abaixo (área verde).

Entrada
A primeira linha de entrada contem um único caractere Maiúsculo O ('S' ou 'M'), 
indicando a operação (Soma ou Média) que deverá ser realizada com os elementos da matriz. 
Seguem os 144 valores de ponto flutuante que compõem a matriz.

Saída
Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char operacao;
    float matriz[12][12], soma = 0.0, media = 0.0;
    int i, j, cont = 0;
    scanf("%c", &operacao);
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            if(j > i){
                soma += matriz[i][j];
                cont++;
            }
        }
    }
    media = soma / cont;
    if(operacao == 'S'){
        printf("%.1f\n", soma);
    }else if(operacao == 'M'){
        printf("%.1f\n", media);
    }
    return 0;
}

