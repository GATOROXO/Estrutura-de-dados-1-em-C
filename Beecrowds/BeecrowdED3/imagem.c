/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 3

Exercicio 1516 do beecrowd

Rafael encontrou um novo hobbie: fazer desenhos usando caracteres do teclado. 
Por mais simples ou limitada que essa nova forma de arte possa parecer, basta criatividade 
para se fazer os mais diferentes tipos de desenhos.

Após fazer alguns desenhos, Rafael imaginou como seriam se eles fossem redimensionados, 
porém ter que refazer todo o desenho pareceu meio cansativo. Para isso, Rafael pediu sua ajuda.

Em um redimensionamento, uma imagem com N linhas e M colunas passa a ter A linhas e B colunas, e,
dado que as novas dimensões da imagem redimensionada é maior do que as dimensões da imagem original,
alguns caracteres terão que se repetir.

Digamos que A seja 3 vezes maior que N. Nesse caso, cada linha terá que 
se repetir 3 vezes, para que a imagem seja redimensionada de forma correta.

Dado um desenho feito por Rafael, imprima como seria se o desenho fosse 
redimensionado para uma determinada nova dimensão.

Entrada
Haverá diversos casos de teste. Cada caso de teste inicia com 
dois inteiros N e M (1 ≤ N, M ≤ 50), representando, respectivamente, 
a altura e a largura do desenho de Rafael.

A seguir haverá N linhas, contendo M caracteres cada, representando o desenho feito por Rafael. 
Após, haverá dois inteiros A e B (N < A ≤ 100, M < B ≤ 100, A é múltiplo de N, e B é multiplo de M), 
representando, respectivamente, a nova altura e largura que Rafael deseja que seu desenho tenha.

O último caso de teste é indicado quando N = M = 0, o qual não deverá ser processado.

Saída
Para cada caso de teste, imprima A linhas, contendo B caracteres cada, 
representando o desenho de Rafael redimensionado.

Após cada caso de teste, imprima uma linha em branco.
 */

#include <stdio.h>

int main() {
    int n, m, a, b;

    while (1) { // Laço infinito até encontrar n = 0 e m = 0
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        char desenho[n][m];

        // Lê o desenho original
        for (int i = 0; i < n; i++) {
            scanf("%s", desenho[i]);
        }

        // Lê as dimensões da nova matriz
        scanf("%d %d", &a, &b);

        // Calcula os fatores de expansão
        int fator_linha = a / n;
        int fator_coluna = b / m;

        // Imprime a matriz redimensionada
        for (int i = 0; i < n; i++) { // Para cada linha original
            for (int fl = 0; fl < fator_linha; fl++) { // Repete a linha
                for (int j = 0; j < m; j++) { // Para cada coluna da linha original
                    for (int fc = 0; fc < fator_coluna; fc++) { // Repete o caractere
                        printf("%c", desenho[i][j]);
                    }
                }
                printf("\n");
            }
        }

        // Imprime uma linha em branco entre os casos de teste
        printf("\n");
    }

    return 0;
}
