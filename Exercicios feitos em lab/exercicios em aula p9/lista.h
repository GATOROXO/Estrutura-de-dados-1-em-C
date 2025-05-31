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

// Protótipos das funções básicas
void iniciaLista(Lista* lista);
No* criaNo(int dado);
void insereFim(Lista* lista, int dado);
void exibeLista(Lista* lista);
int contaNos(Lista* lista);
No* pegaNo(Lista* lista, int indice);
void trocaNos(No* no1, No* no2);
void liberaLista(Lista* lista);

// Protótipos dos algoritmos de ordenação
void bubbleSort(Lista* lista);
void insertionSort(Lista* lista);
void shellSort(Lista* lista);
void mergeSort(Lista* lista);

// Funções auxiliares para Merge Sort
No* divideLista(No* inicio, int tamanho); // Divide a lista em duas metades usando o tamanho
No* merge(No* esquerda, No* direita);     // Junta duas sublistas ordenadas

#endif