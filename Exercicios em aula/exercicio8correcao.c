/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 12/12/2024


1ºfazer o mesmo do exercicio 7 porem solicitando os dados usando laços 
2ºfazer um sistema de venda contendo 2 tipos astratos de produto 
que solicite o codigo do produto ao usuario e a quantidade de produtos que ele vai levar
*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUTOS 3
#define NUM_ITENS_VENDA 2

// Definição de tipos abstratos de dados
struct Produto {
    int codigo;
    float precoCusto;
    float precoVenda;
};
typedef struct Produto Produto;

struct Venda {
    Produto itens[NUM_ITENS_VENDA];
    int quantidades[NUM_ITENS_VENDA];
    float subTotais[NUM_ITENS_VENDA];
    float valorTotal;
};
typedef struct Venda Venda;

int main() {
    Produto catalogo[NUM_PRODUTOS];
    int i, j, codigoProduto, percentualLucro;

    // Leitura dos dados dos produtos
    for (i = 0; i < NUM_PRODUTOS; i++) {
        printf("Informe o codigo do produto %d: ", i + 1);
        scanf("%d", &catalogo[i].codigo);
        printf("Informe o preco de custo: ");
        scanf("%f", &catalogo[i].precoCusto);
    }

    // Leitura do percentual de lucro
    printf("Informe o percentual de lucro: ");
    scanf("%d", &percentualLucro);

    // Calcula o preço de venda de cada produto
    for (i = 0; i < NUM_PRODUTOS; i++) {
        catalogo[i].precoVenda = catalogo[i].precoCusto + (catalogo[i].precoCusto * (float)percentualLucro / 100);
    }

    // Exibição dos dados dos produtos
    for (i = 0; i < NUM_PRODUTOS; i++) {
        printf("Produto %d:\n\tCodigo: %d\n\tPreco de custo: %.2f\n\tPreco de venda: %.2f\n", 
                i + 1, 
                catalogo[i].codigo,
                catalogo[i].precoCusto,
                catalogo[i].precoVenda);
    }

    // Simulação de venda de produtos
    Venda registroVenda;
    printf("\nInforme os produtos comprados:\n");
    for (i = 0; i < NUM_ITENS_VENDA; i++) {
        printf("Informe o codigo do produto %d: ", i + 1);
        scanf("%d", &codigoProduto);
        printf("\tInforme a quantidade: ");
        scanf("%d", &registroVenda.quantidades[i]);

        // Busca pelo produto no catálogo
        for (j = 0; j < NUM_PRODUTOS; j++) {
            if (catalogo[j].codigo == codigoProduto) {
                registroVenda.itens[i] = catalogo[j];
            }
        }

        // Calcula o subtotal
        registroVenda.subTotais[i] = registroVenda.itens[i].precoVenda * registroVenda.quantidades[i];
    }

    // Calcula o valor total da venda
    registroVenda.valorTotal = 0;
    for (i = 0; i < NUM_ITENS_VENDA; i++) {
        registroVenda.valorTotal += registroVenda.subTotais[i];
    }

    // Exibição dos dados da venda
    printf("\nRESUMO DA VENDA\n");
    for (i = 0; i < NUM_ITENS_VENDA; i++) {
        printf("Item %d - Codigo %d - Quantidade %d - Subtotal R$ %.2f\n",
                i + 1,
                registroVenda.itens[i].codigo,
                registroVenda.quantidades[i],
                registroVenda.subTotais[i]);
    }
    printf("TOTAL = R$ %.2f\n", registroVenda.valorTotal);

    return 0;
}
