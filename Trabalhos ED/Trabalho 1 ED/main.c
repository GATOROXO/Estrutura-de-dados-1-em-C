#include "estrutura_trab.h"

int main() {
    pedido *lista = NULL;
    fila_pedido *fila = NULL;
    pilha_pedido *pilha = NULL;
    int cont = 1;

    anota_pedido(&lista, "Joao", "Pizza", cont++);
    
    entra_na_fila(&lista, &fila);
    imprime_lista(lista); 
    sai_da_fila(&lista, &fila);
    imprime_lista(lista); 
    entra_na_pilha(&lista, &pilha);
    imprime_lista(lista); 
    sai_da_pilha(&lista, &pilha);
    imprime_lista(lista);
    libera_lista(&lista);
    anota_pedido(&lista, "Maria", "hamburgue", cont++);
    entra_na_fila(&lista, &fila);
    imprime_lista(lista);


    system("pause");
    return 0;
}