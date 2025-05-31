#include "lista.h"

// Funções básicas (mantidas iguais)
void iniciaLista(Lista* lista) {
    lista->inicio = NULL;
}

No* criaNo(int dado) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = dado;
        novo->proximo = NULL;
    }
    return novo;
}

void insereFim(Lista* lista, int dado) {
    No* novo = criaNo(dado);
    if (novo == NULL) return;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

int contaNos(Lista* lista) {
    int contador = 0;
    No* atual = lista->inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void exibeLista(Lista* lista) {
    No* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberaLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}

// Funções auxiliares para Merge Sort

// Divide a lista em duas metades contando os nós até o meio
No* divideLista(No* inicio, int tamanho) {
    if (inicio == NULL || inicio->proximo == NULL) {
        return inicio;
    }

    int meio = tamanho / 2;
    No* atual = inicio;
    No* anterior = NULL;

    // Percorre até o nó anterior ao meio
    for (int i = 0; i < meio; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Divide a lista cortando o ponteiro no meio
    if (anterior != NULL) {
        anterior->proximo = NULL; // Separa a primeira metade
    }
    return atual; // Retorna o início da segunda metade
}

// Junta duas sublistas ordenadas em uma única lista ordenada
No* merge(No* esquerda, No* direita) {
    No* resultado = NULL;

    // Caso base: se uma das listas estiver vazia
    if (esquerda == NULL) return direita;
    if (direita == NULL) return esquerda;

    // Compara os valores e escolhe o menor para o início
    if (esquerda->dado <= direita->dado) {
        resultado = esquerda;
        resultado->proximo = merge(esquerda->proximo, direita);
    } else {
        resultado = direita;
        resultado->proximo = merge(esquerda, direita->proximo);
    }

    return resultado;
}

// Implementação do Merge Sort para lista encadeada
void mergeSort(Lista* lista) {
    // Caso base: lista vazia ou com 1 elemento
    if (lista->inicio == NULL || lista->inicio->proximo == NULL) {
        return;
    }

    // Calcula o tamanho total da lista
    int tamanho = contaNos(lista);
    if (tamanho <= 1) return;

    // Divide a lista em duas metades
    No* inicio = lista->inicio;
    No* segundaMetade = divideLista(inicio, tamanho);

    // Cria listas temporárias para as duas metades
    Lista esquerdaLista;
    Lista direitaLista;
    iniciaLista(&esquerdaLista);
    iniciaLista(&direitaLista);
    esquerdaLista.inicio = inicio;
    direitaLista.inicio = segundaMetade;

    // Ordena recursivamente cada metade
    mergeSort(&esquerdaLista);
    mergeSort(&direitaLista);

    // Junta as duas metades ordenadas
    lista->inicio = merge(esquerdaLista.inicio, direitaLista.inicio);
}