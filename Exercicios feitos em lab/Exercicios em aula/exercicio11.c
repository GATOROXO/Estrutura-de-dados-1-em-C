/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 16/12/2024

objetivo 1:

 */

#include <stdio.h>
#include <stdlib.h>

//prototipaçao de funçoes
int soma(int , int); //parametro por copia
int multiplica(int*, int*); //parametro por referencia

int main(){
    int x , y, resultado;
    printf("Digite o valor de x: \n");
    scanf("%d", &x);
    printf("Digite o valor de y: \n");
    scanf("%d", &y);    
    resultado = soma(x, y);
    printf("A soma de %d + %d = %d\n",resultado);
    resultado = multiplica(&x, &y);
    printf("A multiplicacao de %d * %d = %d\n",resultado);

}
int soma(int a, int b){
    return a + b;
}
int multiplica(int *a, int *b){
    return *a * *b;
}

