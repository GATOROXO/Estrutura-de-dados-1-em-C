#ifndef ORDENA_H
#define ORDENA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TAMANHO 100000 // Tamanho máximo para 100.000 valores

// Definição da estrutura lista
struct est_lista {
    int vet_lista[MAX_TAMANHO];
    int cont;
};
typedef struct est_lista tipo_lista;

// Protótipos das funções
void carregar_arquivo(tipo_lista *ls, const char *nome_arquivo);
void executar_teste(tipo_lista *ls, const char *nome_arquivo, void (*metodo)(tipo_lista *, unsigned long long *, double *), const char *nome_metodo);
void bubbleSort(tipo_lista *ls, unsigned long long *trocas, double *tempo);
void insertSort(tipo_lista *ls, unsigned long long *trocas, double *tempo);
void shellSort(tipo_lista *ls, unsigned long long *trocas, double *tempo);
void mergeSort(tipo_lista *ls, unsigned long long *trocas, double *tempo);
void quebraMergeSort(int *ls, int tamanho, unsigned long long *trocas);
void merge(int ls[], int tamanho, unsigned long long *trocas);
void quickSort(tipo_lista *ls, unsigned long long *trocas, double *tempo);
void quickSortAux(int *ls, int inicio, int fim, unsigned long long *trocas);

#endif