#include "est_lista_estatica.h"

int main() {
    lista l = criar_lista(); // Cria uma nova lista
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    clock_t inicio, fim; // Variáveis para medir o tempo
    int contador = 0; // Contador de elementos inseridos
    double tempo_de_cpu; // Variável para armazenar o tempo de CPU

    inicio = clock(); // Marca o início da medição do tempo

    // Insere 3333 elementos no início da lista
    for (int i = 0; i < 3333; i++) {
        int aleatorio = rand() % 10000; // Gera um número aleatório
        inserir_inicio(&l, aleatorio); // Insere no início
        contador++;
    }

    // Insere 3333 elementos no fim da lista
    for (int j = 0; j < 3333; j++) {
        int aleatorio = rand() % 10000; // Gera um número aleatório
        inserir_fim(&l, aleatorio); // Insere no fim
        contador++;
    }

    // Insere 3334 elementos em posições aleatórias
    for (int k = 0; k < 3334; k++) {
        int aleatorio = rand() % 10000; // Gera um número aleatório
        int pos = rand() % (contador + 1); // Gera uma posição aleatória
        inserir_posicao_especifica(&l, aleatorio, pos); // Insere na posição específica
    }

    int num_lista = contar_elementos(&l); // Conta o número de elementos na lista
    size_t tamanho_no = sizeof(lista); // Calcula o tamanho da estrutura lista
    size_t memoria_total = tamanho_no; // Calcula a memória total utilizada
    fim = clock(); // Marca o fim da medição do tempo
    tempo_de_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de CPU utilizado

    // Imprime o tempo de CPU, o número de estruturas criadas e a memória utilizada
    printf("Tempo de CPU usado na estrutura: %f\nEstruturas criadas: %d\nMemoria utilizada: %zu bytes\n", tempo_de_cpu, num_lista, memoria_total);
    return 0; 
}