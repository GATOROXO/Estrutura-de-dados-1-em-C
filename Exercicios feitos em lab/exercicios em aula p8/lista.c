#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Inicializa a lista
void iniciaLista(Lista* lista) {
    lista->inicio = NULL;
}

// Cria um novo nó
No* criaNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) exit(1);
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

// Insere no final
void insereFim(Lista* lista, int dado) {
    No* novoNo = criaNo(dado);
    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
        return;
    }
    No* temp = lista->inicio;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }
    temp->proximo = novoNo;
}

// Exibe a lista
void exibeLista(Lista* lista) {
    No* temp = lista->inicio;
    if (temp == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

// Conta o número de nós
int contaNos(Lista* lista) {
    int conta = 0;
    No* temp = lista->inicio;
    while (temp != NULL) {
        conta++;
        temp = temp->proximo;
    }
    return conta;
}

// Pega o nó em um índice
No* pegaNo(Lista* lista, int indice) {
    No* temp = lista->inicio;
    for (int i = 0; i < indice && temp != NULL; i++) {
        temp = temp->proximo;
    }
    return temp;
}

// Troca os valores de dois nós
void trocaNos(No* no1, No* no2) {
    int temp = no1->dado;
    no1->dado = no2->dado;
    no2->dado = temp;
}

// Libera a memória da lista
void liberaLista(Lista* lista) {
    No* temp = lista->inicio;
    while (temp != NULL) {
        No* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    lista->inicio = NULL;
}