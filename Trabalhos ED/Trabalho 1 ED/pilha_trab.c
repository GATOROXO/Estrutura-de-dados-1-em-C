#include "estrutura_trab.h"


pilha_pedido *aloca_pilha(pedido*lista){
    pilha_pedido * nova_pilha = (pilha_pedido*)malloc(sizeof(pilha_pedido));
    if(nova_pilha==NULL){
        printf("Erro ao alocar memoria para a pilha!\n");
        return NULL;
    }
        nova_pilha->prox = NULL;
        nova_pilha->pedido = lista;
        return nova_pilha;
}

void entra_na_pilha(pedido **lista, pilha_pedido **pilha) {
    if (*lista == NULL) {
        printf("Nenhum pedido para adicionar na pilha\n");
        return;
    }

    pedido *aux = *lista;
    while (aux != NULL && strcmp(aux->status, "Pronto") != 0) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Nenhum pedido pronto para adicionar  pilha\n");
        return;
    }

    pilha_pedido *novo = aloca_pilha(aux);
    if (novo == NULL) return;

    novo->prox = *pilha; 
    *pilha = novo;

    printf("Pedido %d adicionado a pilha (status: %s)\n", aux->numero, aux->status);
}
void sai_da_pilha(pedido **lista, pilha_pedido **pilha) {
    if (*pilha == NULL) {
        printf("Nao ha pedidos prontos para entregar\n");
        return;
    }
    pilha_pedido *aux = *pilha;
    *pilha = aux->prox;
    strcpy(aux->pedido->status, "Entregue");
    printf("Pedido %d entregue (status: %s)\n", aux->pedido->numero, aux->pedido->status);
    free(aux);
}

void libera_lista(pedido **lista) {
    pedido *aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = aux->prox;
        free(aux);
    }
}