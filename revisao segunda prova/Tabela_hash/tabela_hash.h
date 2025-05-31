#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 10  // Define o número de posições na tabela hash

// Estrutura para representar um nó (elemento chave-valor)
typedef struct no_hash {
    int chave;             // Chave para identificar o valor
    int valor;             // Valor associado à chave
    struct no_hash* proximo; // Ponteiro para o próximo nó na lista encadeada
} NoHash;

// Estrutura para representar a tabela hash
typedef struct {
    NoHash* baldes[TAMANHO_TABELA]; // Array de listas encadeadas (baldes)
} TabelaHash;

// Declaração das funções
void tabela_hash_inicializar(TabelaHash* th);        // Inicializa a tabela hash
NoHash* no_hash_criar(int chave, int valor);         // Cria um novo nó
int funcao_hash(int chave);                          // Função hash para calcular índice
void tabela_hash_inserir(TabelaHash* th, int chave, int valor);  // Insere um novo par chave-valor
int tabela_hash_remover(TabelaHash* th, int chave);  // Remove um elemento pela chave
NoHash* tabela_hash_buscar(TabelaHash* th, int chave);  // Busca um elemento pela chave
void tabela_hash_imprimir(TabelaHash* th);           // Imprime o conteúdo da tabela
void tabela_hash_destruir(TabelaHash* th);           // Libera a memória alocada

#endif
