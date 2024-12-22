#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int linha;
    int coluna;
    int valor;
} Entrada;

int comparar(const void *a, const void *b) {
    Entrada *entrada1 = (Entrada *)a;
    Entrada *entrada2 = (Entrada *)b;

    if (entrada1->linha != entrada2->linha) {
        return entrada1->linha - entrada2->linha;
    }
    return entrada1->coluna - entrada2->coluna;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        if (t > 0) {
            printf("\n");
        }

        int N, L;
        scanf("%d %d", &N, &L);

        Entrada entradas[L];
        int numEntradas = 0;

        for (int i = 0; i < L; i++) {
            int Pk, lk, ck, vk;
            scanf("%d %d %d %d", &Pk, &lk, &ck, &vk);

            int encontrado = 0;
            for (int j = 0; j < numEntradas; j++) {

                if (entradas[j].linha == lk && entradas[j].coluna == ck) {
                    entradas[j].valor += vk;
                    encontrado = 1;
                    break;
                }
            }
            

            if (!encontrado) {
                entradas[numEntradas].linha = lk;
                entradas[numEntradas].coluna = ck;
                entradas[numEntradas].valor = vk;
                numEntradas++;
            }
        }

        qsort(entradas, numEntradas, sizeof(Entrada), comparar);

        for (int i = 0; i < numEntradas; i++) {
            printf("%d %d %d\n", entradas[i].linha, entradas[i].coluna, entradas[i].valor);
        }
    }

    return 0;
}