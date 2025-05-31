/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Faça um programa que leia 5 valores inteiros.
Conte quantos destes valores digitados são pares e mostre esta informação.

Entrada
O arquivo de entrada contém 5 valores inteiros quaisquer.

Saída
Imprima a mensagem conforme o exemplo fornecido, 
indicando a quantidade de valores pares lidos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int par, contador = 0 ,i;
    for(i=0;i<5;i++){
        scanf("%d",&par);
        if(par%2==0){
            contador++;
        }
    }
    printf("%d valores pares\n",contador);
    return 0;
}

