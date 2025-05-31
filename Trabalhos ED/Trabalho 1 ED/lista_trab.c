
#include "estrutura_trab.h"

pedido *aloca_pedido(int cont) {
    pedido *novo_pedido = (pedido*) malloc(sizeof(pedido));
    if (novo_pedido == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    novo_pedido->prox = NULL;
    novo_pedido->numero = cont;
    strcpy(novo_pedido->status, "Pendente"); 
    return novo_pedido;
}

pedido *anota_pedido(pedido **lista, char *nome, char *item, int cont) {
    pedido *novo_no = aloca_pedido(cont);
    if (novo_no == NULL) {
        printf("Erro ao armazenar dados do pedido\n");
        return NULL;
    }
    
    strcpy(novo_no->cliente, nome);
    strcpy(novo_no->itens, item);
    
    novo_no->prox = *lista;
    *lista = novo_no;
    
    printf("\n\nPedido de numero %d\nStatus atual: %s\n", novo_no->numero, novo_no->status);
    return novo_no;
}
void imprime_lista(pedido *lista) {
    pedido *aux = lista;
    while (aux != NULL) {
        printf("Pedido %d | Cliente: %s | Itens: %s | Status: %s\n", 
               aux->numero, aux->cliente, aux->itens, aux->status);
        aux = aux->prox;
    }
}