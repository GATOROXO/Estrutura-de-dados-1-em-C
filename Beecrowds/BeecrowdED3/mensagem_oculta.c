/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 3

Exercicio 1272 Beecrowd 

Textos podem conter mensagens ocultas. Neste problema a mensagem oculta em um texto é composto pelas primeiras letras de cada palavra do texto, na ordem em que aparecem.

É dado um texto composto apenas por letras minúsculas ou espaços. Pode haver mais de um espaço entre as palavras. O texto pode iniciar ou terminar em espaços, ou mesmo conter somente espaços.

Entrada
A entrada contém vários casos de testes. A primeira linha de entrada contém um inteiro N que indica a quantidade de casos de teste que vem a seguir. Cada caso de teste consiste de uma única linha contendo de um a 50 caracteres, formado por letras minúsculas (‘a’-‘z’) ou espaços (‘ ’). Atenção para possíveis espaços no início ou no final do texto!

Nota: No exemplo de entrada os espaços foram substituídos por pequenos pontos (‘·’) para facilitar o entendimento dos exemplos.

Saída
Para cada caso de teste imprima a mensagem oculta no texto de entrada.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[1024];  // Buffer para armazenar a entrada do usuário
    char novaFrase[1024]; // Buffer para armazenar a nova frase
    int numLinhas; // Número de linhas que o usuário vai digitar

    scanf("%d", &numLinhas); // Lê a quantidade de linhas que o usuário planeja digitar
    getchar(); // Limpa o buffer de entrada, capturando o caractere de nova linha após o número

    for (int i = 0; i < numLinhas; i++) {
        fgets(frase, sizeof(frase), stdin); // Lê uma linha do usuário
        int indice = 0; // Índice para construir a nova frase

        char *token = strtok(frase, " .\n"); // Inicia a tokenização com espaço e ponto como delimitadores

        while (token != NULL) {
            novaFrase[indice++] = token[0]; // Adiciona a primeira letra de cada palavra à nova frase
            token = strtok(NULL, " .\n"); // Continua tokenizando
        }
        novaFrase[indice] = '\0'; // Finaliza a nova frase com o caractere nulo

        // Imprime a nova frase formada pelas primeiras letras
        printf("%s\n", novaFrase);
    }

    return 0;
}

//facil de pensar e fazer.
