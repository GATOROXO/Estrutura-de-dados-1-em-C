/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Escreva um programa que leia um valor inteiro N. Este N é a quantidade de linhas de saída que serão apresentadas na execução do programa.

Entrada
O arquivo de entrada contém um número inteiro positivo N.

 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i ,cont=0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("%d %d %d PUM\n",cont+1, cont+2, cont+3);
        cont += 4;
    }
}