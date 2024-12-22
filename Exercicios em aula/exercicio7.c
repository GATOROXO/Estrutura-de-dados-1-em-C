/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 12/12/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define a estrutura produto
struct est_produto{
    int codigo;
    float custo;
    float venda;
};
typedef struct est_produto tipo_produto;

int main(){
    tipo_produto p1, p2;
    int lucro;
    //le o produto 1
    printf("Digite o codigo do produto 1: ");
    scanf("%d", &p1.codigo);
    printf("Digite o custo do produto 1: ");
    scanf("%f", &p1.custo);

    //le o produto 2
    printf("Digite o codigo do produto 2: ");
    scanf("%d", &p2.codigo);
    printf("Digite o custo do produto 2: ");
    scanf("%f", &p2.custo);


    //le o lucro

    printf("Digite o lucro: ");
    scanf("%d", &lucro);

    // calcula o preco de venda
    p1.venda = p1.custo + (p1.custo*lucro/100);
    p2.venda = p2.custo + (p2.custo*lucro/100);

    // imprime o resultado
    printf("O produto %d tem o custo de %.2f e o preco de venda de %.2f\n", p1.codigo, p1.custo, p1.venda);
    printf("O produto %d tem o custo de %.2f e o preco de venda de %.2f\n", p2.codigo, p2.custo, p2.venda);



}