/***
 * UFMT - Ciência da Computação
 * ED - 1 Prof. Ivairton
 * João Marcello 
 * Tarefa
    *Defina a estrutura da fila
    *Implemente inserção
    *Implemente remoção
*/
#include "fila.h"
void inserir_fila(tipo_fila *fila, int valor) {
    if (fila->contador == MAXIMO){
        printf("[ERRO] A fila está vazia!");
        return;
    } else {
        fila->vetor[fila->contador] = valor;
        fila->contador++;
        printf("Numero %d foi inserido com sucesso\n", valor);
    }
}
void imprimir_fila(tipo_fila fila){
    if (fila.contador == 0) {
        printf("[ERRO] nao tem elementos na fila");
        return;
    } else {
        printf(" Elementos da fila: ");
        for (int i = 0; i < fila.contador ; i++) {
            printf(" %d ", fila.vetor[i]);
        }
        printf("\n");
    }
}
int remover_fila(tipo_fila *fila) {
    if (fila->contador == 0) {
        printf("[ERRO] a fila esta vazia");
        return -1;
    } 
    else {
    int removido = fila->vetor[0];
    for ( int i = 0 ; i < fila->contador -1; i++){
        fila->vetor[i] = fila->vetor[i+1];

        }
    fila->contador--;
    return removido;
    }
}