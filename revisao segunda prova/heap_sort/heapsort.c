#include <stdio.h>
#include <stdlib.h>
#include "Estruturas.h"

// Função auxiliar para trocar dois nós
void trocar(No* a, No* b) {
    int temp = a->dado;
    a->dado = b->dado;
    b->dado = temp;
}

// Função para "heapificar" uma subárvore enraizada em 'i'
void heapify(No* arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda]->dado > arr[maior]->dado)
        maior = esquerda;

    if (direita < n && arr[direita]->dado > arr[maior]->dado)
        maior = direita;

    if (maior != i) {
        trocar(arr[i], arr[maior]);
        heapify(arr, n, maior);
    }
}

// Função principal do Heap Sort
void heap_sort(ListaEncadeada* lista) {
    if (lista == NULL || lista->tamanho <= 1) {
        return; // Nada a ordenar se a lista for vazia ou tiver apenas um elemento
    }

    // 1. Converter a lista encadeada em um array de ponteiros para nós
    No** arr = (No**)malloc(lista->tamanho * sizeof(No*));
    if (arr == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para o array.\n");
        exit(EXIT_FAILURE);
    }
    No* atual = lista->inicio;
    int i = 0;
    while (atual != NULL) {
        arr[i] = atual;
        atual = atual->proximo;
        i++;
    }

    // 2. Construir o heap máximo
    for (i = lista->tamanho / 2 - 1; i >= 0; i--) {
        heapify(arr, lista->tamanho, i);
    }

    // 3. Extrair elementos um por um do heap
    for (i = lista->tamanho - 1; i > 0; i--) {
        trocar(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    // 4. Atualizar os dados da lista encadeada com os valores ordenados
    atual = lista->inicio;
    for (i = 0; i < lista->tamanho; i++) {
        atual->dado = arr[i]->dado;
        atual = atual->proximo;
    }

    free(arr);
}
