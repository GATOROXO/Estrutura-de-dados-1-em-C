/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Escreva um programa para ler as coordenadas (X,Y) de uma quantidade indeterminada de pontos no sistema cartesiano. 
Para cada ponto escrever o quadrante a que ele pertence. 
O algoritmo será encerrado quando pelo menos uma de duas coordenadas for NULA (nesta situação sem escrever mensagem alguma).

Entrada
A entrada contém vários casos de teste. Cada caso de teste contém 2 valores inteiros.

Saída
Para cada caso de teste mostre em qual quadrante do sistema cartesiano se encontra a coordenada lida, conforme o exemplo.


 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y;
    while(1){
        scanf("%d %d", &x, &y);
        if(x == 0 || y == 0){
            break;
        }
        if(x > 0 && y > 0){
            printf("primeiro\n");
        }
        else if(x < 0 && y > 0){
            printf("segundo\n");
        }
        else if(x < 0 && y < 0){
            printf("terceiro\n");
        }
        else if(x > 0 && y < 0){
            printf("quarto\n");
        }
    }

}


