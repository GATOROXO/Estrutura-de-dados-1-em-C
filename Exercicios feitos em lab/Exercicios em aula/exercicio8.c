/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 12/12/2024
*/

//fazer o mesmo do exercicio 7 porem solicitando os dados usando laços 
// fazer um sistema de venda contendo 2 tipos astratos de produto 
//que solicite o codigo do produto ao usuario e a quantidade de produtos que ele vai levar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

// define a estrutura produto
 struct est_produto{
    int codigo;
    float custo;
    float venda;
};
typedef struct est_produto tipo_produto;

int main(){
    int i;
    int lucro;
    tipo_produto p[TAM];
    for (i=0; i<TAM; i++){
        printf("Digite o codigo do produto %d: \n", i + 1);
        scanf("%d", &p[i].codigo);
        printf("Digite o custo do produto %d: \n", i + 1);
        scanf("%f", &p[i].custo);
    }
    printf("Digite o lucro: ");
    scanf("%d", &lucro);

    for(i=0; i<TAM; i++){
        p[i].venda = p[i].custo + (p[i].custo*lucro/100);
    }
    for(i=0;i<TAM;i++){
        printf("O produto %d tem o custo de %.2f e o preco de venda de %.2f\n", p[i].codigo, p[i].custo, p[i].venda);
    }
    // venda de 3 produtos
    
    for(i=0;i<TAM;i++){
        int codigoUS;
        int quantidadeUS;
        printf("Digite o codigo do produto que deseja comprar: ");
        scanf("%d", &codigoUS);
        if(codigoUS == p[i].codigo){
            printf("Digite a quantidade de produtos que deseja comprar: ");
            scanf("%d", &quantidadeUS);
            if(quantidadeUS > 0){
                printf("O valor total da compra eh: %.2f\n", p[i].venda*quantidadeUS);
                }
                else{
                printf("quantidade invalida\n");
                }
        else{
            printf("codigo nao encontrado.\n");
        }
    }
    return 0;
}