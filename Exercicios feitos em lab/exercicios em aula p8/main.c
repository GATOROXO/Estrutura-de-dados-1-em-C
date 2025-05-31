#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista1, lista2, lista3;
    iniciaLista(&lista1);
    iniciaLista(&lista2);
    iniciaLista(&lista3);

    // Insere valores nas listas
    int valores[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        insereFim(&lista1, valores[i]);
        insereFim(&lista2, valores[i]);
        insereFim(&lista3, valores[i]);
    }

    // Testa Bubble Sort
    printf("Antes (Bubble Sort):\n");
    exibeLista(&lista1);
    bubbleSort(&lista1);
    printf("Depois (Bubble Sort):\n");
    exibeLista(&lista1);

    // Testa Insertion Sort
    printf("\nAntes (Insertion Sort):\n");
    exibeLista(&lista2);
    insertionSort(&lista2);
    printf("Depois (Insertion Sort):\n");
    exibeLista(&lista2);

    // Testa Shell Sort
    printf("\nAntes (Shell Sort):\n");
    exibeLista(&lista3);
    shellSort(&lista3);
    printf("Depois (Shell Sort):\n");
    exibeLista(&lista3);

    // Libera memória
    liberaLista(&lista1);
    liberaLista(&lista2);
    liberaLista(&lista3);

    return 0;
}