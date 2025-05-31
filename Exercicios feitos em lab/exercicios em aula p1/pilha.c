/***
 * UFMT - Ciencia da computacao
 * Estrutura de dados 1 - ED1
 * Prof Ivairton
 * João Marcello
 */
#include "pilha.h"

void empilhar_pilha(tipo_pilha *pilha, int valor) {
    if (pilha->contador == TAM) {
        printf("[ERRO] A pilha esta cheia\n");
        return;
    } else {
        pilha->vetor[pilha->contador] = valor;
        pilha->contador++;
        printf("O numero %d foi inserido com sucesso na pilha\n", valor);
    }
}

int desempilhar_pilha(tipo_pilha *pilha) {
    if (pilha->contador == 0) {
        printf("[ERRO] A pilha esta vazia\n");
        return -1; 
    } else {
        int valor = pilha->vetor[pilha->contador - 1];
        pilha->contador--;
        return valor;
    }
}

void imprimir_toda_pilha(tipo_pilha pilha) {
    if (pilha.contador == 0) {
        printf("[ERRO] Nao tem elementos na pilha\n");
        return;
    } else {
        printf("Elementos da pilha: ");
        for (int i = 0; i < pilha.contador; i++) {
            printf(" %d ", pilha.vetor[i]);
        }
        printf("\n");
    }
}