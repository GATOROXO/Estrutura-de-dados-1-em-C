#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>


// Estrutura do nó
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Estrutura da lista
typedef struct Lista {
    No* inicio;
} Lista;

// Protótipos das funções
void iniciaLista(Lista* lista);
No* criaNo(int dado);
void insereFim(Lista* lista, int dado);
void exibeLista(Lista* lista);
int contaNos(Lista* lista);
No* pegaNo(Lista* lista, int indice);
void trocaNos(No* no1, No* no2);
void liberaLista(Lista* lista);

// Protótipos dos algoritmos
void bubbleSort(Lista* lista);
void insertionSort(Lista* lista);
void shellSort(Lista* lista);

#endif