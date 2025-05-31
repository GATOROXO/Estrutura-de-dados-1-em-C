#ifndef __est_lista_estatica_H__
#define __est_lista_estatica_H__
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
void inserir_posicao_especifica(lista* l, int valor, int pos); // Insere em posição específica
int contar_elementos(lista* l);                // Conta elementos na lista
void imprime_lista(lista* l);                  // Imprime a lista 

#endif  //__est_lista_estatica_H__