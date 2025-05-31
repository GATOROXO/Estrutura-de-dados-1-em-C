
#include "estrutura_trab.h"
fila_pedido * aloca_fila(pedido*no_existente){
    fila_pedido * nova_fila = (fila_pedido*)malloc(sizeof(fila_pedido));
    if(nova_fila == NULL){
        printf("Fila Vazia || Erro de alocacao\n\n");
        return NULL;
    }
    else{
        nova_fila->pedido = no_existente;
        nova_fila->prox = NULL;
        return nova_fila;
    }
}
void entra_na_fila(pedido **lista, fila_pedido **fila) {
    pedido *aux = *lista;
    while (aux != NULL && strcmp(aux->status, "Pendente") != 0) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Nao ha pedidos pendentes para processar na fila\n");
        return;
    }
    fila_pedido *novo = aloca_fila(aux);
    if (novo == NULL) return;
    
    strcpy(aux->status, "Em preparo");
    if (*fila == NULL) { 
        *fila = novo;
    } else { 
        fila_pedido *ultimo = *fila;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novo;
    }
}

void sai_da_fila(pedido **lista, fila_pedido **fila) {
    if (*fila == NULL) {
        printf("Fila vazia, nenhum pedido para preparar\n");
        return;
    }
    fila_pedido *aux = *fila;
    *fila = aux->prox;
    strcpy(aux->pedido->status, "Pronto");
    printf("Pedido %d saiu da fila (status: %s)\n", aux->pedido->numero, aux->pedido->status);
    free(aux);
}