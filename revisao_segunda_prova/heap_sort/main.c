#include <stdio.h>
#include <stdlib.h>
#include "Estruturas.h"

int main() {
    ListaEncadeada* lista = criar_lista();

    inserir(lista, 5);
    inserir(lista, 2);
    inserir(lista, 8);
    inserir(lista, 3);
    inserir(lista, 1);
    inserir(lista, 9);
    inserir(lista, 4);

    printf("Lista original: ");
    imprimir_lista(lista);

    heap_sort(lista);

    printf("Lista ordenada: ");
    imprimir_lista(lista);

    liberar_lista(lista);

    return 0;
}
