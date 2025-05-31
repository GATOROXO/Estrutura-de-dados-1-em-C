#include "lista.h"

// Insertion Sort
void insertionSort(Lista* lista) {
    if (lista->inicio == NULL || lista->inicio->proximo == NULL) return;

    No* ordenada = NULL;
    No* atual = lista->inicio;

    while (atual != NULL) {
        No* proximo = atual->proximo;

        if (ordenada == NULL || ordenada->dado >= atual->dado) {
            atual->proximo = ordenada;
            ordenada = atual;
        } else {
            No* temp = ordenada;
            while (temp->proximo != NULL && temp->proximo->dado < atual->dado) {
                temp = temp->proximo;
            }
            atual->proximo = temp->proximo;
            temp->proximo = atual;
        }

        atual = proximo;
    }

    lista->inicio = ordenada;
}