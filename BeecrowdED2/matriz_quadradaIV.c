#include <stdio.h>

int main() {
    int N;

    while (scanf("%d",&N)!= EOF) {
        int matriz[N][N];
        int i,j;
        for (int linha = 0; linha < N; linha++){
            for(int coluna = 0; coluna < N; coluna++){
                if (linha == N/2 && coluna == N/2) {
                    matriz[linha][coluna] = 4;
                } 
                else if (linha >= N / 3 && coluna >= N / 3 && linha < N - N / 3 && coluna < N - N / 3) {
                    matriz[linha][coluna] = 1;
                }
                else if (linha == coluna){
                    matriz[linha][coluna] = 2;
                }
                else if (linha + coluna +1 == N) {
                    matriz[linha][coluna] = 3;
                } 
                else {
                    matriz[linha][coluna] = 0;
                }
            }
        }
        for (i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", matriz[i][j]);
            }
            printf("\n"); 
        }
        printf("\n"); 
    }

    return 0;
}