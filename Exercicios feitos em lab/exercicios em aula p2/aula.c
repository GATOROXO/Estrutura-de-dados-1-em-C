#include "lista.h"

// Inicializa a lista
lista criar_lista() {
    lista l;
    l.contador = 0; // Inicializa o contador
    return l;
}

// Insere no início com deslocamento
void inserir_inicio(lista* l, int valor) {
    if (l->contador >= MAX) {
        printf("Erro: Lista cheia!\n");
        return;
    }
    for (int i = l->contador; i > 0; i--) {
        l->vet[i] = l->vet[i - 1];
    }
    l->vet[0] = valor;
    l->contador++;
}

// Insere no fim
void inserir_fim(lista* l, int valor) {
    if (l->contador >= MAX) {
        printf("Erro: Lista cheia!\n");
        return;
    }
    l->vet[l->contador] = valor;
    l->contador++;
}

// Remove do início com deslocamento
void remover_inicio(lista* l) {
    if (l->contador == 0) {
        printf("Erro: Lista vazia!\n");
        return;
    }
    for (int i = 0; i < l->contador - 1; i++) {
        l->vet[i] = l->vet[i + 1];
    }
    l->contador--;
}

// Remove do fim
void remover_fim(lista* l) {
    if (l->contador == 0) {
        printf("Erro: Lista vazia!\n");
        return;
    }
    l->contador--;
}

// Insere no fim (interpretação para "inserir_especifico")
void inserir_especifico(lista* l, int valor) {
    inserir_fim(l, valor); // Assume que "especifico" significa fim, já que não há posição
}

// Remove um valor específico (primeira ocorrência)
void remover_especifico(lista* l, int valor) {
    if (l->contador == 0) {
        printf("Erro: Lista vazia!\n");
        return;
    }
    for (int i = 0; i < l->contador; i++) {
        if (l->vet[i] == valor) {
            for (int j = i; j < l->contador - 1; j++) {
                l->vet[j] = l->vet[j + 1];
            }
            l->contador--;
            return;
        }
    }
    printf("Valor %d nao encontrado!\n", valor);
}

// Insere em uma posição específica com deslocamento
void inserir_posicao_especifica(lista* l, int valor, int pos) {
    if (l->contador >= MAX) {
        printf("Erro: Lista cheia!\n");
        return;
    }
    if (pos < 0 || pos > l->contador) {
        inserir_fim(l, valor); // Insere no fim se posição inválida
        return;
    }
    for (int i = l->contador; i > pos; i--) {
        l->vet[i] = l->vet[i - 1];
    }
    l->vet[pos] = valor;
    l->contador++;
}


void remover_posicao_especifica(lista* l, int pos) {
    if (l->contador == 0) {
        printf("Erro: Lista vazia!\n");
        return;
    }
    if (pos < 0 || pos >= l->contador) {
        printf("Erro: Posicao invalida!\n");
        return;
    }
    for (int i = pos; i < l->contador - 1; i++) {
        l->vet[i] = l->vet[i + 1];
    }
    l->contador--;
}


int contar_elementos(lista* l) {
    return l->contador;
}


void imprime_lista(lista* l) {
    printf("Lista: ");
    for (int i = 0; i < l->contador; i++) {
        printf("%d ", l->vet[i]);
    }
    printf("\n");
}