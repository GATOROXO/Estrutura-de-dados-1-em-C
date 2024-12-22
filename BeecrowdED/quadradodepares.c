/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Leia um valor inteiro N. Apresente o quadrado de cada um dos valores pares, de 1 até N, inclusive N, se for o caso.

Entrada
A entrada contém um valor inteiro N (5 < N < 2000).

Saída
Imprima o quadrado de cada um dos valores pares, de 1 até N, conforme o exemplo abaixo.

Tome cuidado! Algumas linguagens tem por padrão apresentarem como saída 1e+006 ao invés de 1000000 
o que ocasionará resposta errada. Neste caso, 
configure a precisão adequadamente para que isso não ocorra.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int i,num, result;
    scanf("%d",&num);

    if(num%2==0){
    for(i=2;i<=num;i+=2){
        result= pow(i,2);
        printf("%d^2 = %d\n",i,result);
        }
    }
    else if(num%2!=0){
        for(i=2;i<num;i+=2){
            result= pow(i,2);
            printf("%d^2 = %d\n",i,result);
        }
    }
    return 0;
}

