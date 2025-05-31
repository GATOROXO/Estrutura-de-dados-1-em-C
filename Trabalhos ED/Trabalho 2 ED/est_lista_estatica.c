#include "est_lista_estatica.h"

// Inicializa a lista
lista criar_lista() {
    lista l;
    l.contador = 0; // Inicializa o contador
    return l;
}

// Insere no início com deslocamento
void inserir_inicio(lista* l, int valor) {
    if (l->contador >= MAX) { // Verifica se a lista está cheia
        printf("Erro: Lista cheia!\n");
        return;
    }
    // Desloca os elementos para a direita
    for (int i = l->contador; i > 0; i--) {
        l->vet[i] = l->vet[i - 1];
    }
    l->vet[0] = valor; // Insere o novo valor no início
    l->contador++; // Incrementa o contador
}

// Insere no fim
void inserir_fim(lista* l, int valor) {
    if (l->contador >= MAX) { // Verifica se a lista está cheia
        printf("Erro: Lista cheia!\n");
        return;
    }
    l->vet[l->contador] = valor; // Insere o valor no fim
    l->contador++; // Incrementa o contador
}

// Insere em uma posição específica com deslocamento
void inserir_posicao_especifica(lista* l, int valor, int pos) {
    if (l->contador >= MAX) { // Verifica se a lista está cheia
        printf("Erro: Lista cheia!\n");
        return;
    }
    if (pos < 0 || pos > l->contador) { // Verifica se a posição é inválida
        inserir_fim(l, valor); // Insere no fim se posição inválida
        return;
    }
    // Desloca os elementos para a direita
    for (int i = l->contador; i > pos; i--) {
        l->vet[i] = l->vet[i - 1];
    }
    l->vet[pos] = valor; // Insere o valor na posição específica
    l->contador++; // Incrementa o contador
}


// Conta o número de elementos na lista
int contar_elementos(lista* l) {
    return l->contador; // Retorna o contador de elementos
}

// Imprime a lista (para depuração)
void imprime_lista(lista* l) {
    printf("Lista: ");
    for (int i = 0; i < l->contador; i++) {
        printf("%d ", l->vet[i]); // Imprime cada elemento da lista
    }
    printf("\n");
}