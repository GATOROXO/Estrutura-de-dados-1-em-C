#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Movie.h"
#include "sort.h"

/** @brief Exibe o menu de opções do programa */
void exibirMenu() {
    printf("\n===== MENU DE ORDENACAO =====\n");
    printf("Escolha o criterio de ordenacao:\n");
    printf("1. Titulo\n2. Ano\n3. Avaliacao\n");
    
    printf("\nEscolha o algoritmo de ordenacao:\n");
    printf("1. Merge Sort\n2. Insertion Sort\n3. Quick Sort\n");
    
    printf("\nEscolha a ordem:\n");
    printf("1. Crescente\n2. Decrescente\n");
    
    printf("\nDigite sua escolha (criterio algoritmo ordem): ");
}

int main() {
    printf("Iniciando o programa...\n");
    MovieList *lista = criarListaFilmes(1000);

    printf("Carregando filmes...\n");
    carregarFilmesDoCSV(lista, "movies.csv", "ratings.csv");
    if (lista->size == 0) {
        printf("Nenhum filme foi carregado. Verifique os arquivos CSV.\n");
        liberarListaFilmes(lista);
        return 1;
    }
    printf("Carregados %d filmes.\n", lista->size);

    int criterio, algoritmo, ordem;
    while (1) {
        exibirMenu();
        printf("Aguardando entrada do usuario...\n");
        if (scanf("%d %d %d", &criterio, &algoritmo, &ordem) != 3) {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }
        
        if (criterio < 1 || criterio > 3 || algoritmo < 1 || algoritmo > 3 || ordem < 1 || ordem > 2) {
            printf("Escolha invalida. Tente novamente.\n");
            continue;
        }

        // Criar cópia da lista para ordenação
        Movie *copiaFilmes = (Movie*)malloc(lista->size * sizeof(Movie));
        if (!copiaFilmes) {
            perror("Falha na alocacao de memoria");
            liberarListaFilmes(lista);
            return 1;
        }
        memcpy(copiaFilmes, lista->movies, lista->size * sizeof(Movie));

        // Converter ordem para o enum SortOrder
        int ordemClassificacao = (ordem == 1) ? ASCENDING : DESCENDING;
        
        // Preparar informações para exibição
        const char *nomeCriterio[] = {"Titulo", "Ano", "Avaliacao"};
        const char *nomeAlgoritmo[] = {"Ordenacao por Merge Sort", "Ordencao por Insertion Sort", "Ordenacao por Quick Sort"};
        const char *nomeOrdem[] = {"crescente", "decrescente"};
        
        printf("\nAplicando %s por %s em ordem %s...\n", 
               nomeAlgoritmo[algoritmo-1], 
               nomeCriterio[criterio-1], 
               nomeOrdem[ordem-1]);

        clock_t inicio = clock();
        if (algoritmo == 1) {
            mergeSort(copiaFilmes, 0, lista->size - 1, criterio - 1, ordemClassificacao);
        }
        else if (algoritmo == 2) {
            insertionSort(copiaFilmes, lista->size, criterio - 1, ordemClassificacao);
        }
        else {
            quickSort(copiaFilmes, 0, lista->size - 1, criterio - 1, ordemClassificacao);
        }
        clock_t fim = clock();

        // Exibe os 10 melhores filmes
        exibirTop10Vetor(copiaFilmes, lista->size);
        printf("Tempo de execucao: %.6f segundos\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);

        free(copiaFilmes);

        printf("\nDeseja continuar? (1 = Sim, 0 = Nao): ");
        int continuar;
        scanf("%d", &continuar);
        if (!continuar) break;
    }

    liberarListaFilmes(lista);
    printf("Programa encerrado.\n");
    return 0;
}
