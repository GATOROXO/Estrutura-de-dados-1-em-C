/**
 * @file arv_m_filhos.h
 * @brief Arquivo de cabecalho de arvore com multiplos filhos
 * @author Ivairton
 * @date Abril 2025
 */

#ifndef ARV_M_FILHOS_H
#define ARV_M_FILHOS_H

#include <stdio.h>
#include <stdlib.h>

// Definicao de constante
#define T 3

// Definicao de estrutura
struct est_tipo_no {
    int cont; // numero de chaves
    int chaves[T]; // vetor de chaves
    char dados[T]; // vetor de dados
    struct est_tipo_no *filhos[T+1]; // vetor de filhos
};
typedef struct est_tipo_no tipo_no;

// Prototipo das funcoes
tipo_no *aloca_no(int chave, char dado);
tipo_no *insere_no(tipo_no *arv, int chave, char dado);
void imprime_pre_ordem(tipo_no *no);
void imprime_pos_ordem(tipo_no *no);
void imprime_em_ordem(tipo_no *no);
char busca_dado(tipo_no *no, int chave);
tipo_no *busca_no(tipo_no *no, int chave);
int total_nos(tipo_no *no);
int total_folhas(tipo_no *no);
int verifica_folha(tipo_no *no, int chave);
int altura_arvore(tipo_no *no);
void imprime_arv_nivel(tipo_no *no);
void imprime_nivel(tipo_no *no, int nivel);
int contabiliza_no_por_nivel(tipo_no *no, int nivel);
int busca_maior(tipo_no *no);
int busca_menor(tipo_no *no);
void imprime_rota(tipo_no *no, int chave);

#endif