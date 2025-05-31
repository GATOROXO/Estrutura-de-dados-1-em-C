/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 05/12/2024
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a , b;
    printf("Digite o primeiro valor : \n");
    scanf("%d", &a);
    printf("Digite o segundo valor : \n");
    scanf("%d", &b);
    if (a > b){
        while(b<=a){
            printf("%d\n", b);
            b++;
        }
    }
    else if (b > a){
        while(a<=b){
            printf("%d\n", a);
            a++;
        }
    }
    system("pause");
    return 0;
}