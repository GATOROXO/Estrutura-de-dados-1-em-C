#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Movie.h"
#include "sort.h"

/** @brief Compara dois filmes segundo critério e ordem especificados
 *  @param a Primeiro filme
 *  @param b Segundo filme
 *  @param criterio Critério de comparação
 *  @param ordem Ordem desejada
 *  @return Inteiro indicando ordem relativa (-1, 0, 1)
 */
int compararFilmes(Movie a, Movie b, int criterio, int ordem) {
    int resultado;
    
    if (criterio == 0) { // Título
        // Comparação de título insensível a maiúsculas/minúsculas
        char tituloA[100], tituloB[100];
        strcpy(tituloA, a.title);
        strcpy(tituloB, b.title);

        // Converte para minúsculas para comparação
        for (int i = 0; tituloA[i]; i++) {
            tituloA[i] = tolower(tituloA[i]);
        }
        for (int i = 0; tituloB[i]; i++) {
            tituloB[i] = tolower(tituloB[i]);
        }

        resultado = strcmp(tituloA, tituloB);
    } else if (criterio == 1) { // Ano
        resultado = a.year - b.year;
    } else { // Avaliação
        if (a.avgRating > b.avgRating) resultado = -1;
        else if (a.avgRating < b.avgRating) resultado = 1;
        else resultado = 0;
        
        // Para avaliação, o padrão é decrescente (maiores primeiro)
        // então invertemos lógica do ordem
        if (ordem == ASCENDING) resultado = -resultado;
        return resultado;
    }
    
    // Para título e ano, aplicamos ordem normalmente
    return (ordem == DESCENDING) ? -resultado : resultado;
}

// Função auxiliar do MergeSort para juntar dois subarrays ordenados
void fusao(Movie *arr, int esquerda, int meio, int direita, int criterio, int ordem) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    Movie *L = (Movie*)malloc(n1 * sizeof(Movie));
    Movie *R = (Movie*)malloc(n2 * sizeof(Movie));

    if (!L || !R) {
        perror("Falha na alocacao de memoria durante Merge");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++) L[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (compararFilmes(L[i], R[j], criterio, ordem) <= 0) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Algoritmo de ordenação Merge Sort
void mergeSort(Movie *arr, int esquerda, int direita, int criterio, int ordem) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;  // Cálculo seguro do ponto médio
        mergeSort(arr, esquerda, meio, criterio, ordem);
        mergeSort(arr, meio + 1, direita, criterio, ordem);
        fusao(arr, esquerda, meio, direita, criterio, ordem);
    }
}

// Algoritmo de ordenação Insertion Sort
void insertionSort(Movie *arr, int tamanho, int criterio, int ordem) {
    for (int i = 1; i < tamanho; i++) {
        Movie chave = arr[i];
        int j = i - 1;
        while (j >= 0 && compararFilmes(arr[j], chave, criterio, ordem) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// Função auxiliar do QuickSort para particionar o array
int particionar(Movie *arr, int inicio, int fim, int criterio, int ordem) {
    Movie pivo = arr[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (compararFilmes(arr[j], pivo, criterio, ordem) <= 0) {
            i++;
            Movie temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Movie temp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = temp;
    return i + 1;
}

// Algoritmo de ordenação Quick Sort
void quickSort(Movie *arr, int inicio, int fim, int criterio, int ordem) {
    if (inicio < fim) {
        int pi = particionar(arr, inicio, fim, criterio, ordem);
        quickSort(arr, inicio, pi - 1, criterio, ordem);
        quickSort(arr, pi + 1, fim, criterio, ordem);
    }
}
