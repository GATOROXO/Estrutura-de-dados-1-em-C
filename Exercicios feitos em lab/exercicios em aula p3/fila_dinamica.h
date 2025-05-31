#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da fila
typedef struct No {
    int dado; // Valor armazenado no nó
    struct No* proximo; // Ponteiro para o próximo nó
} No;

// Estrutura da fila
typedef struct Fila {
    No* frente; // Ponteiro para o primeiro nó da fila
    No* tras; // Ponteiro para o último nó da fila
} Fila;

// Protótipos das funções

// Função para criar uma nova fila
Fila* criarfila();

// Função para adicionar um elemento na fila
void enfileirar(Fila* fila, int valor);

// Função para remover um elemento da fila
int desinfileirar(Fila* fila);

// Função para verificar se a fila está vazia
int estaVazia(Fila* fila);

#endif

