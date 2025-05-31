#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

// Função para criar uma nova pilha
Pilha* cria_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Erro: Falha ao alocar memória para a pilha.\n");
        exit(1);
    }
    pilha->topo = NULL;
    return pilha;
}

// Função para destruir a pilha e liberar memória
void destroi_pilha(Pilha* pilha) {
    while (!pilha_vazia(pilha)) {
        desempilha(pilha);
    }
    free(pilha);
}

// Função para verificar se a pilha está vazia
bool pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

// Função para empilhar um elemento
void empilha(Pilha* pilha, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha ao alocar memória para o nó.\n");
        exit(1);
    }
    novo_no->dado = valor;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
}

// Função para desempilhar um elemento
int desempilha(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }
    No* no_removido = pilha->topo;
    int valor = no_removido->dado;
    pilha->topo = no_removido->proximo;
    free(no_removido);
    return valor;
}

// Função para obter o elemento do topo da pilha
int topo_pilha(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }
    return pilha->topo->dado;
}