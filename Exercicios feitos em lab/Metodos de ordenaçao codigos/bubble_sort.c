#include "lista.h"

// Bubble Sort
void bubbleSort(Lista* lista) {
    if (lista->inicio == NULL || lista->inicio->proximo == NULL) return;

    int trocou;
    No *i, *j;

    do {
        trocou = 0;
        i = lista->inicio;
        while (i->proximo != NULL) {
            j = i->proximo;
            if (i->dado > j->dado) {
                trocaNos(i, j);
                trocou = 1;
            }
            i = i->proximo;
        }
    } while (trocou);
}