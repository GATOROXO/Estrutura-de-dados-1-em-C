#include "lista_din.h"

int main() {
    tipo_no_lista *lista = NULL;

    // Inserindo elementos
    insereInicioLst(&lista, 10);
    insereInicioLst(&lista, 20);
    insereFimLst(&lista, 30);
    inserePosLst(&lista, 40, 2);

    printf("Lista após inserções:\n");
    imprimeLista(lista);

    // Contando nós
    printf("Número de nós na lista: %d\n", contaNosLst(lista));

    // Buscando elementos
    tipo_no_lista *no = buscaValorLst(lista, 30);
    if (no != NULL) {
        printf("Elemento encontrado: %d\n", no->valor);
    }

    // Removendo elementos
    printf("Removendo o primeiro elemento: %d\n", removeInicioLst(&lista));
    printf("Removendo o último elemento: %d\n", removeFimLst(&lista));
    printf("Removendo o elemento na posição 1: %d\n", removePosLst(&lista, 1));

    printf("Lista após remoções:\n");
    imprimeLista(lista);

    return 0;
}