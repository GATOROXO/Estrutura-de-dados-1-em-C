#include "fila_dinamica.h"

// Função para visualizar todos os elementos da fila
void visualizarFila(Fila* fila) {
    No* atual = fila->frente;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    // Cria uma nova fila
    Fila* fila = criarFila();

    // Adiciona elementos na fila
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    // Visualiza a fila completa
    visualizarFila(fila);

    // Remove e imprime elementos da fila
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));

    // Verifica se a fila está vazia e imprime o resultado
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
    } else {
        printf("A fila não está vazia.\n");
    }

    return 0;
}