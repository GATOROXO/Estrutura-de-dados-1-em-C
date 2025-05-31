/***
 * UFMT - Ciencia da computacao
 * Estrutura de dados 1 - ED1
 * Prof Ivairton
 * Joao Marcello
 * Aquivo auxiliar
 */
/** __PILHA_H__ */
#ifndef __PILHA_H__
#define __PILHA_H__

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

struct est_pilha {
    int vetor[TAM];
    int contador;
};
typedef struct est_pilha tipo_pilha;

// Prototipacao das funcoes
void empilhar_pilha(tipo_pilha*, int);
int desempilhar_pilha(tipo_pilha*);
void imprimir_toda_pilha(tipo_pilha);
#endif /** __PILHA_H__ */