#ifndef __LISTA_DUPLA_ENC_H__
#define __LISTA_DUPLA_ENC_H__

#include <stdio.h>
#include <stdlib.h>

// Definicao da estrutura
struct est_no_lista {
    int valor; // Armazena apenas um numero inteiro
    struct est_no_lista *prox;
    struct est_no_lista *ant;
};
typedef struct est_no_lista tipo_no_lista;

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

#endif // __LISTA_DUPLA_ENC_H__