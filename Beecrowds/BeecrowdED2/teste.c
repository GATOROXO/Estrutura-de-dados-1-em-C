#include <stdio.h>
#include <stdbool.h>

void batuke_percurso(int N, int F, int C) {
    // Ajustar índices para base zero
    F -= 1;
    C -= 1;

    // Inicializar matriz de visitados e ordem de visita
    bool visitadas[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visitadas[i][j] = false;
        }
    }

    int ordem_visita[N * N];
    int contador = 0;

    // Direções: esquerda, cima, direita, baixo
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};

    // Posição inicial
    int x = F, y = C;
    visitadas[x][y] = true;
    ordem_visita[contador++] = x * N + y + 1;

    int passos = 1;

    // Percorrer espiral
    while (contador < N * N) {
        for (int d = 0; d < 4; d++) { // Iterar pelas direções
            for (int p = 0; p < passos; p++) {
                x += dx[d];
                y += dy[d];
                if (x >= 0 && x < N && y >= 0 && y < N && !visitadas[x][y]) {
                    visitadas[x][y] = true;
                    ordem_visita[contador++] = x * N + y + 1;
                }
            }
            // Aumentar os passos após cada duas direções
            if (d % 2 == 1) {
                passos++;
            }
        }
    }

    // Imprimir os resultados
    for (int i = 0; i < contador; i++) {
        printf("%d ", ordem_visita[i]);
    }
    printf("\n%d\n", contador);
}

int main() {
    int N, F, C;

    // Entrada do usuário
    printf("Digite o tamanho da matriz (N): ");
    scanf("%d", &N);
    printf("Digite a linha inicial (F): ");
    scanf("%d", &F);
    printf("Digite a coluna inicial (C): ");
    scanf("%d", &C);

    if (N < 1) {
        printf("O tamanho da matriz deve ser maior que zero.\n");
        return 1;
    }

    batuke_percurso(N, F, C);

    return 0;
}