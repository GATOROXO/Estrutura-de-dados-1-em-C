/***
 * UFMT - Ciencia da computacao
 * Estrutura de dados 1 - ED1
 * Prof Ivairton
 * João Marcello 
 * Arquivo auxiliar
 */

/** FILA.H */
#ifndef __FILA_H__
#define __FILA_H__

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
// Constante
#define MAXIMO 10

//Criando a fila
struct estilo_fila {
    int vetor[MAXIMO];
    int contador;
};
typedef struct estilo_fila tipo_fila;

//Prototipar as funcoes
void inserir_fila(tipo_fila*, int);
int remover_fila(tipo_fila*);
void imprimir_fila(tipo_fila);

#endif //__FILA_H__