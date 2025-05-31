#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

// Definição da estrutura do nó da pilha
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Definição da estrutura da pilha
typedef struct Pilha {
    No* topo;
} Pilha;

// Funções públicas
Pilha* cria_pilha();
void destroi_pilha(Pilha* pilha);
bool pilha_vazia(Pilha* pilha);
void empilha(Pilha* pilha, int valor);
int desempilha(Pilha* pilha);
int topo_pilha(Pilha* pilha);

#endif // PILHA_H