#include <stdio.h>
#include <string.h>

int main() {
    int n; // Número de casos de teste
    scanf("%d", &n); // Lê o número de casos
    getchar(); // Consome o '\n' deixado pelo scanf

    for (int t = 0; t < n; t++) {
        char palavras[2][51]; // Cada palavra pode ter no máximo 50 caracteres
        char palavra_nova[102] = ""; // String resultante, máximo 100 caracteres + '\0'

        // Lê as duas palavras separadas por espaço
        scanf("%s %s", palavras[0], palavras[1]);

        // Combina os caracteres alternadamente
        int len1 = strlen(palavras[0]);
        int len2 = strlen(palavras[1]);
        int max_len = len1 > len2 ? len1 : len2;

        for (int i = 0; i < max_len; i++) {
            if (i < len1) {
                strncat(palavra_nova, &palavras[0][i], 1); // Adiciona caractere da primeira palavra
            }
            if (i < len2) {
                strncat(palavra_nova, &palavras[1][i], 1); // Adiciona caractere da segunda palavra
            }
        }

        // Exibe a palavra combinada
        printf("%s\n", palavra_nova);
    }

    return 0;
}
