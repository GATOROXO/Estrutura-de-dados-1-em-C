#include <stdio.h>

int main() {
    int N; // Número de medidas
    scanf("%d", &N);

    int velocidades[N];

    // Lendo as medidas de velocidade
    for (int i = 0; i < N; i++) {
        scanf("%d", &velocidades[i]);
    }

    int indiceQueda = 0; // Inicialmente, não há queda

    // Verificando a primeira queda
    for (int i = 1; i < N; i++) {
        if (velocidades[i] < velocidades[i - 1]) {
            indiceQueda = i + 1; // Ajustando para o índice começar em 1
            break;
        }
    }

    // Saída do índice da primeira queda ou 0
    printf("%d\n", indiceQueda);

    return 0;
}
