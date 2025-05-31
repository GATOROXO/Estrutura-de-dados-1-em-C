#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10000 
// Definição da estrutura da lista estática
typedef struct lista {
    int vet[MAX]; // Array estático para armazenar valores
    int contador; // Número atual de elementos (não inicializado aqui)
} lista;

// Declarações das funções
lista criar_lista();                           // Inicializa a lista
void inserir_inicio(lista* l, int valor);      // Insere no início
void inserir_fim(lista* l, int valor);         // Insere no fim
void remover_inicio(lista* l);                 // Remove do início
void remover_fim(lista* l);                    // Remove do fim
void inserir_especifico(lista* l, int valor);  // Insere no fim (interpretação)
void remover_especifico(lista* l, int valor);  // Remove um valor específico
void inserir_posicao_especifica(lista* l, int valor, int pos); // Insere em posição específica
void remover_posicao_especifica(lista* l, int pos);            // Remove de posição específica
int contar_elementos(lista* l);                // Conta elementos na lista
void imprime_lista(lista* l);                  // Imprime a lista (para depuração)

#endif // LISTA_H