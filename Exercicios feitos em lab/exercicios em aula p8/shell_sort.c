#include "lista.h"

// Shell Sort
void shellSort(Lista* lista) {
    int n = contaNos(lista);
    if (n <= 1) return;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            No* atual = pegaNo(lista, i);
            if (atual == NULL) continue;

            int temp = atual->dado;
            int j = i;

            while (j >= gap) {
                No* anterior = pegaNo(lista, j - gap);
                if (anterior == NULL) break;

                if (anterior->dado <= temp) break;

                No* atualJ = pegaNo(lista, j);
                atualJ->dado = anterior->dado;
                j -= gap;
            }

            No* atualJ = pegaNo(lista, j);
            if (atualJ != NULL) atualJ->dado = temp;
        }
    }
}