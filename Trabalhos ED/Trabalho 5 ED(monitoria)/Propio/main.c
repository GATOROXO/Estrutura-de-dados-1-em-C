#include <stdio.h>
#include <stdlib.h>
#include "data_covid.h"
#define CAPACIDADE_INICIAL 200
#define CSV_FILE "country_wise_latest.csv"

int main() {
    // Carregar dados CSV em uma lista encadeada
    lista* dados = carregarcsv(CSV_FILE);
    if (!dados) {
        printf("Falha ao carregar os dados. Encerrando o programa.\n");
        return 1;
    }

    int opcao, quantidade;
    while (1) {
        // Exibir menu
        printf("\n=== Sistema de Analise de Dados COVID-19 ===\n");
        printf("1. Visualizar numero de casos\n");
        printf("2. Visualizar numero de mortes\n");
        printf("3. Visualizar numero de recuperados\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao (1-4): ");
        scanf("%d", &opcao);

        if (opcao == 4) {
            break;
        }

        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }

        // Obter número de registros a serem exibidos
        printf("Quantos registros deseja visualizar? ");
        scanf("%d", &quantidade);
        if (quantidade <= 0) {
            printf("Quantidade invalida! Tente novamente.\n");
            continue;
        }

        // Criar heap
        heap* h = criar_heap(CAPACIDADE_INICIAL, opcao);
        if (!h) {
            printf("Erro ao criar heap.\n");
            liberar_lista(dados);
            return 1;
        }

        // Construir heap a partir da lista encadeada
        construir_heap(h, dados);

        // Exibir os N principais registros
        printf("\n=== Top %d registros ===\n", quantidade);
        for (int i = 0; i < quantidade && h->tamanho > 0; i++) {
            data d = extrair_raiz(h);
            if (d.pais) { // Verificar se os dados são válidos
                printf("\nRegistro %d:", i + 1);
                exibir_dados(d, opcao);
                liberar_data(&d); // Liberar dados extraídos
            }
        }

        // Destruir heap
        destruir_heap(h);
    }

    // Liberar lista encadeada
    liberar_lista(dados);
    printf("Programa encerrado.\n");
    return 0;
}