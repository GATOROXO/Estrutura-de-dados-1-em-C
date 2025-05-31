#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array usando o último elemento como pivô
int particionar(int array[], int inicio, int fim) {
    int pivo = array[fim];    // Escolhe o último elemento como pivô
    int i = (inicio - 1);     // Índice do menor elemento

    for (int j = inicio; j < fim; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (array[j] <= pivo) {
            i++;              // Incrementa o índice do menor elemento
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[fim]); // Coloca o pivô na posição correta
    return (i + 1);                   // Retorna a posição do pivô
}

// Função principal do Quick Sort
void quickSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice de partição
        int pi = particionar(array, inicio, fim);

        // Ordena os elementos antes e depois da partição
        quickSort(array, inicio, pi - 1);
        quickSort(array, pi + 1, fim);
    }
}

// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função principal para teste
int main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    imprimirArray(array, tamanho);

    quickSort(array, 0, tamanho - 1);

    printf("Array ordenado: ");
    imprimirArray(array, tamanho);

    return 0;
}