#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct ListaEncadeada {
    No* inicio;
    int tamanho;
} ListaEncadeada;

// Protótipos das funções
ListaEncadeada* criar_lista();
void inserir(ListaEncadeada* lista, int valor);
void imprimir_lista(ListaEncadeada* lista);
void heap_sort(ListaEncadeada* lista);
void liberar_lista(ListaEncadeada* lista);

#endif
