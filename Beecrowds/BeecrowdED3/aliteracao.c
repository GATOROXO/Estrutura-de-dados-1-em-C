/** 
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 3

exercicio 1263 Beecrowd

Aliteração
Uma aliteração ocorre quando duas ou mais palavras consecutivas de um texto possuem a mesma letra inicial 
(ignorando maiúsculas e minúsculas). Sua tarefa é desenvolver um programa que identifique, a partir de uma sequência de palavras, 
o número de aliterações que essa sequência possui.

Entrada
A entrada contém diversos casos de testes. Cada caso é expresso como um texto em uma única linha, 
contendo de 1 a 100 palavras separadas por um único espaço, cada palavra tendo de 1 a 50 letras 
minúsculas ou maiúsculas ('A'-'Z','a'-'z'). A entrada termina em EOF.

Saída
Para cada caso de teste imprima o número de aliterações existentes no texto informado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[1024]; // Declara um array de caracteres para armazenar a frase
    while (fgets(frase, sizeof(frase), stdin)) { // Recebe a frase do usuário com limite de 1023 caracteres
        int cont = 0, aliteracao = 0; // Inicializa os contadores
        char* p1 = strtok(frase, " \n"); // Divide a frase em tokens usando espaço e nova linha como delimitadores
        char letra = tolower(p1[0]); // Armazena a primeira letra da primeira palavra em minúsculo

        while ((p1 = strtok(NULL, " \n")) != NULL) { // Continua dividindo a frase em tokens
            if (letra == tolower(p1[0])) { // Verifica se a primeira letra da palavra atual é igual à letra armazenada
                cont++; // Incrementa o contador se for igual
            } 
            else {
                if (cont > 0) { // Se o contador for maior que 0, incrementa o número de aliterações
                    aliteracao++;
                }
                cont = 0; // Reseta o contador
                letra = tolower(p1[0]); // Atualiza a letra armazenada para a primeira letra da palavra atual
            }
        }
        if (cont > 0) { // Verifica se há uma aliteração no final da frase
            aliteracao++;
        }
        printf("%d\n", aliteracao); // Imprime o número de aliterações
    }
    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}