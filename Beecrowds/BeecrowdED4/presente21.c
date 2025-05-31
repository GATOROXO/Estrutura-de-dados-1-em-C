#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Função: canReach
 * ----------------
 * Simula os pulos do sapo utilizando uma abordagem de busca em largura (BFS).
 *
 * Parâmetros:
 *   N - número de pedras (garantidamente positivo; se n for negativo, usamos abs(n))
 *   M - número da pedra onde está o presente
 *
 * Retorna:
 *   1 se o sapo consegue alcançar a pedra M,
 *   0 caso contrário.
 */
int canReach(int N, int M) {
    int capacity = 1024;
    int size = 0;
    int *curr = malloc(capacity * sizeof(int));
    if (!curr) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }
    
    /* O primeiro pulo é forçado: o sapo sempre começa na Pedra 1. */
    curr[0] = 1;
    size = 1;
    
    if (M == 1) {
        free(curr);
        return 1;
    }
    
    int jump = 2;  // a partir do segundo pulo
    while (size > 0) {
        int d = 2 * jump - 1;  // distância do pulo atual
        int nextCapacity = 1024;
        int nextSize = 0;
        int *next = malloc(nextCapacity * sizeof(int));
        if (!next) {
            perror("Erro na alocação de memória");
            exit(EXIT_FAILURE);
        }
        /* Vetor para marcar posições já atingidas neste nível (índices de 1 até N). */
        char *used = calloc(N + 1, sizeof(char));
        if (!used) {
            perror("Erro na alocação de memória");
            exit(EXIT_FAILURE);
        }
        
        for (int i = 0; i < size; i++) {
            int pos = curr[i];
            
            /* Tenta pular para a direita: nova posição = pos + d */
            int pos1 = pos + d;
            if (pos1 >= 1 && pos1 <= N && used[pos1] == 0) {
                used[pos1] = 1;
                if (nextSize >= nextCapacity) {
                    nextCapacity *= 2;
                    next = realloc(next, nextCapacity * sizeof(int));
                    if (!next) {
                        perror("Erro na realocação de memória");
                        exit(EXIT_FAILURE);
                    }
                }
                next[nextSize++] = pos1;
                if (pos1 == M) {
                    free(used);
                    free(curr);
                    free(next);
                    return 1;
                }
            }
            
            /* Tenta pular para a esquerda: nova posição = pos - d */
            int pos2 = pos - d;
            if (pos2 >= 1 && pos2 <= N && used[pos2] == 0) {
                used[pos2] = 1;
                if (nextSize >= nextCapacity) {
                    nextCapacity *= 2;
                    next = realloc(next, nextCapacity * sizeof(int));
                    if (!next) {
                        perror("Erro na realocação de memória");
                        exit(EXIT_FAILURE);
                    }
                }
                next[nextSize++] = pos2;
                if (pos2 == M) {
                    free(used);
                    free(curr);
                    free(next);
                    return 1;
                }
            }
        }
        
        free(used);
        free(curr);
        if (nextSize == 0) {
            free(next);
            return 0;
        }
        
        curr = next;
        size = nextSize;
        jump++;
    }
    
    free(curr);
    return 0;
}

int main(void) {
    int n, m;
    
    while (scanf("%d %d", &n, &m) == 2) {
        /* Caso de parada: quando n e m forem ambos 0 */
        if (n == 0 && m == 0)
            break;
        /* Se n for negativo, usamos o valor absoluto */
        if (n < 0)
            n = abs(n);
        
        if (canReach(n, m))
            printf("Let me try!\n");
        else
            printf("Don't make fun of me!\n");
    }
    
    return 0;
}
