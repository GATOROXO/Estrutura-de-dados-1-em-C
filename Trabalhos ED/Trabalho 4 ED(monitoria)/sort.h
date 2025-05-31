#ifndef SORT_H
#define SORT_H
#include "movie.h"

/** @brief Ordena filmes usando algoritmo Merge Sort
 *  @param arr Array de filmes
 *  @param esquerda Índice inicial
 *  @param direita Índice final
 *  @param criterio Critério de ordenação (0=título, 1=ano, 2=avaliação)
 *  @param ordem Ordem de classificação (ASCENDING/DESCENDING)
 */
void mergeSort(Movie *arr, int esquerda, int direita, int criterio, int ordem);

/** @brief Ordena filmes usando algoritmo Insertion Sort
 *  @param arr Array de filmes
 *  @param tamanho Tamanho do array
 *  @param criterio Critério de ordenação
 *  @param ordem Ordem de classificação
 */
void insertionSort(Movie *arr, int tamanho, int criterio, int ordem);

/** @brief Ordena filmes usando algoritmo Quick Sort
 *  @param arr Array de filmes
 *  @param inicio Índice inicial
 *  @param fim Índice final
 *  @param criterio Critério de ordenação
 *  @param ordem Ordem de classificação
 */
void quickSort(Movie *arr, int inicio, int fim, int criterio, int ordem);

#endif