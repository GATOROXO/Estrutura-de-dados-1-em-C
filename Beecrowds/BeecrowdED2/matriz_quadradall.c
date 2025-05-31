/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Escreva um algoritmo que leia um inteiro N (0 ≤ N ≤ 100), correspondente a ordem de uma matriz M de inteiros, 
e construa a matriz de acordo com o exemplo abaixo.

Entrada
A entrada consiste de vários inteiros, um valor por linha, correspondentes as ordens das matrizes a serem construídas. 
O final da entrada é marcado por um valor de ordem igual a zero (0).

Saída
Para cada inteiro da entrada imprima a matriz correspondente, de acordo com o exemplo. 
(os valores das matrizes devem ser formatados em um campo de tamanho 3 justificados à direita e separados por espaço. 
Após o último caractere de cada linha da matriz não deve haver espaços em branco. 
Após a impressão de cada matriz deve ser deixada uma linha em branco.
 */
#include <stdio.h>

int main() {
    int N;

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        int matriz[N][N];
        for (int linha = 0; linha < N; linha++) {
            for (int coluna = 0; coluna < N; coluna++) {
                int result;
                result = (linha - coluna);
                if (result < 0){
                    result = result * (-1);
                    matriz[linha][coluna] = result + 1;
                } else {
                matriz[linha][coluna] = result + 1;
                }
            } 
        }
    for (int i =0;i<N; i++) {
        for (int j =0; j<N; j++) {
            if (j==0) {
                printf("%3d", matriz[i][j]);
            } else {
                printf(" %3d", matriz[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
    return 0;
}