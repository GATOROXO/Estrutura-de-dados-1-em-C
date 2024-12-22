/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. 
Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, 
caso haja uma divisão por 0 ou raiz de numero negativo.

Entrada
Leia três valores de ponto flutuante (double) A, B e C.

Saída
Se não houver possibilidade de calcular as raízes, apresente a mensagem "Impossivel calcular". 
Caso contrário, imprima o resultado das raízes com 5 dígitos após o ponto,
com uma mensagem correspondente conforme exemplo abaixo. Imprima sempre o final de linha após cada mensagem.

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double A,B,C,delta,r1,r2;
    scanf("%lf %lf %lf", &A, &B, &C);
    delta = (B*B)-4*A*C;
    if(delta<0 || A==0){
        printf("Impossivel calcular\n");
    }
    else{
        r1 = (-B+sqrt(delta))/(2*A);
        r2 = (-B-sqrt(delta))/(2*A);
        
        printf("R1 = %.5f\n",r1);
        printf("R2 = %.5f\n",r2);
    }
    return 0;


}
