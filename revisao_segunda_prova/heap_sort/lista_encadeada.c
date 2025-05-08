#include <stdio.h>
#include <stdlib.h>
#include "Estruturas.h"

ListaEncadeada* criar_lista() {
    ListaEncadeada* lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    if (lista == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserir(ListaEncadeada* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void imprimir_lista(ListaEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberar_lista(ListaEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}
