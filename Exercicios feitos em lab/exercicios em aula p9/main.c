#include "lista.h"

int main() {
    Lista lista;
    iniciaLista(&lista);

    // Insere alguns valores desordenados
    insereFim(&lista, 4);
    insereFim(&lista, 2);
    insereFim(&lista, 7);
    insereFim(&lista, 1);

    printf("Antes do Merge Sort:\n");
    exibeLista(&lista);

    mergeSort(&lista);

    printf("Depois do Merge Sort:\n");
    exibeLista(&lista);
    liberaLista(&lista);
    system("pause");
    return 0;
}