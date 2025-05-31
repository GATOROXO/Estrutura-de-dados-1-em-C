#include "fila_dinamica.h"

// Função para criar uma nova fila dinâmica
Fila* criarfila() {
    // Aloca memória para a estrutura da fila
    Fila* fila = (Fila*)malloc(sizeof(fila));
    // Inicializa os ponteiros frente e tras como NULL, indicando que a fila está vazia
    fila->frente = fila->tras = NULL;
    return fila;
}

// Função para adicionar um elemento na fila
void enfileirar(Fila* fila, int valor) {
    // Aloca memória para um novo nó
    No* Novono = (No*)malloc(sizeof(No));
    // Atribui o valor ao novo nó e define o próximo como NULL
    Novono->dado = valor;
    Novono->proximo = NULL;
    // Se a fila estiver vazia, o novo nó será tanto a frente quanto o tras
    if (fila->tras == NULL) {
        fila->frente = fila->tras = Novono;
    } else {
        // Caso contrário, adiciona o novo nó ao final da fila
        fila->tras->proximo = Novono;
        fila->tras = Novono;
    }
}

// Função para remover um elemento da fila
int desinfileirar(Fila* fila) {
    // Armazena o nó da frente temporariamente
    No* temp = fila->frente;
    // Armazena o valor do nó da frente
    int valor = temp->dado;
    // Move o ponteiro frente para o próximo nó
    fila->frente = fila->frente->proximo;
    // Se a fila ficar vazia, ajusta o ponteiro tras para NULL
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    // Libera a memória do nó removido
    free(temp);
    return valor;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila) {
    // Retorna 1 (verdadeiro) se a fila estiver vazia, caso contrário 0 (falso)
    return fila->frente == NULL;
}
