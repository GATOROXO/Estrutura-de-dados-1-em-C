#ifndef __LISTA_DIN_H__
#define __LISTA_DIN_H__

// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura
struct est_no_lista {
    int valor; // Armazena apenas um número inteiro
    struct est_no_lista *prox;
};
typedef struct est_no_lista tipo_no_lista;

// Declaração das funções
tipo_no_lista *alocaNo(int);
void insereInicioLst(tipo_no_lista**, int);
void insereFimLst(tipo_no_lista**, int);
void inserePosLst(tipo_no_lista**, int, int);
int removeInicioLst(tipo_no_lista**);
int removeFimLst(tipo_no_lista**);
int removePosLst(tipo_no_lista**, int);
int removeValorLst(tipo_no_lista**, int);
tipo_no_lista *buscaPosLst(tipo_no_lista*, int);
tipo_no_lista *buscaValorLst(tipo_no_lista*, int);
int contaNosLst(tipo_no_lista*);
void imprimeLista(tipo_no_lista*);

#endif // __LISTA_DIN_H__