/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 05/12/2024
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    char a, b , c , d, maior, menor ;
    printf("Digite uma letra : \n");
    scanf(" %c", &a);
    printf("Digite a segunda letra : \n");
    scanf(" %c", &b);
    printf("Digite a terceira letra : \n");
    scanf(" %c", &c);
    printf("Digite a quarta letra : \n");
    scanf(" %c", &d);
        if (a > b && a > c && a > d){
            maior = a;
        }
        else if (b > a && b > c && b > d){
            maior = b;
        }
        else if (c > a && c > b && c > d){
            maior = c;
        }
        else if (d > a && d > b && d > c){
            menor = d;
    }
         if (a < b && a < c && a < d){
            menor = a;
        }
        else if (b < a && b < c && b < d){
            menor = b;
        }
        else if (c < a && c < b && c < d){
            menor = c;
        }
        else if (d < a && d < b && d < c){
            menor = d;
    }
    printf("A maior letra digitada foi : %c\n ", maior );
    printf("A menor letra digitada foi : %c\n ", menor);
    system("pause");
    return 0;
}