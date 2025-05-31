#ifndef __ESTRUTURA_TRAB_H__
#define __ESTRUTURA_TRAB_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct est_pedido {
    int numero;
    char cliente[50];
    char itens[100];
    char status[20];
    struct est_pedido* prox;
};
typedef struct est_pedido pedido;

struct est_fila {
    struct est_pedido *pedido;
    struct est_fila *prox;
};
typedef struct est_fila fila_pedido;

struct est_pilha {
    struct est_pedido *pedido;
    struct est_pilha *prox;
};
typedef struct est_pilha pilha_pedido;

pedido *aloca_pedido(int);
fila_pedido *aloca_fila(pedido*);       
pilha_pedido *aloca_pilha(pedido*);     
pedido *anota_pedido(pedido**, char*, char*, int); 
void entra_na_fila(pedido**, fila_pedido**); 
void sai_da_fila(pedido**, fila_pedido**);   
void entra_na_pilha(pedido**, pilha_pedido**); 
void sai_da_pilha(pedido**, pilha_pedido**); 
void imprime_lista(pedido*); 

#endif // __ESTRUTURA_TRAB_H__