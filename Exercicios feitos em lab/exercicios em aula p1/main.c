/***
 * UFMT - Ciencia da Computacao
 * Estrutura de dados 1 - ED1
 * Prof Ivairton
 * João Marcello Galdino Pereira
 */
#include <stdio.h>
#include <stdlib.h>


#include "fila.h"
#include "pilha.h"

int main(int argc, char *argv[]) {
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    tipo_fila fila;
    fila.contador = 0;

    tipo_pilha pilha;
    pilha.contador = 0;

    // Abre o arquivo de entrada
    FILE *arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Lê os valores do arquivo e insere na fila
    int valor;
    for (int i = 0; i < MAXIMO; i++) {
        if (fscanf(arquivo_entrada, "%d", &valor) != 1) {
            printf("Erro ao ler o arquivo ou arquivo incompleto.\n");
            fclose(arquivo_entrada);
            return 1;
        }
        inserir_fila(&fila, valor);
    }
    fclose(arquivo_entrada);

    // Imprime a fila (opcional, para depuração)
    printf("Fila lida do arquivo: ");
    imprimir_fila(fila);

    // Remove os elementos da fila e coloca na pilha
    for (int j = 0; j < MAXIMO; j++) {
        valor = remover_fila(&fila);
        empilhar_pilha(&pilha, valor);
    }

    // Abre o arquivo de saída
    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    // Desempilha a pilha e escreve no arquivo de saída
    fprintf(arquivo_saida, "Valores em ordem inversa: [ ");
    for (int k = 0; k < MAXIMO; k++) {
        int valor_reverso = desempilhar_pilha(&pilha);
        fprintf(arquivo_saida, "%d ", valor_reverso);
    }
    fprintf(arquivo_saida, "]\n");

    fclose(arquivo_saida);
    printf("Valores invertidos foram salvos no arquivo 'saida.txt'.\n");

    return 0;
}