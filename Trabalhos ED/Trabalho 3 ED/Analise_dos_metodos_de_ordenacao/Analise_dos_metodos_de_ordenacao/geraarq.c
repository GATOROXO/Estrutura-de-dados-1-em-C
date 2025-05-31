#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para embaralhar um array (Fisher-Yates Shuffle)
void embaralhar(int *vet, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}

// Função para gerar um arquivo com números únicos
void gerar_arquivo(const char *nome, int quantidade, int seed) {
    FILE *arquivo = fopen(nome, "w");
    if (!arquivo) {
        printf("Erro ao criar o arquivo %s\n", nome);
        return;
    }

    int *numeros = (int *)malloc(quantidade * sizeof(int));
    if (!numeros) {
        printf("Erro ao alocar memória para %s\n", nome);
        fclose(arquivo);
        return;
    }

    // Preenche o array com números sequenciais
    for (int i = 0; i < quantidade; i++) {
        numeros[i] = i + 1;
    }

    // Define a semente única e embaralha os números
    srand(seed);
    embaralhar(numeros, quantidade);

    // Escreve os números no arquivo
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d\n", numeros[i]);
    }

    free(numeros);
    fclose(arquivo);
    printf("Arquivo %s gerado com sucesso com %d valores!\n", nome, quantidade);
}

int main() {
    int tamanhos[] = {1000, 10000, 100000};
    char nome_arquivo[20];
    time_t base_seed = time(NULL); // Semente base baseada no tempo atual

    // Gera 5 arquivos para cada tamanho
    for (int t = 0; t < 3; t++) {
        for (int i = 1; i <= 5; i++) {
            sprintf(nome_arquivo, "%d-arq%d.txt", tamanhos[t], i);
            int seed = (int)(base_seed + t * 5 + i); // Semente única
            gerar_arquivo(nome_arquivo, tamanhos[t], seed);
        }
    }

    return 0;
}