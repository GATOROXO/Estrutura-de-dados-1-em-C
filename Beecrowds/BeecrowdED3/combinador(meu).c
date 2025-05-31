/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 3

exercicio 1238 Beecrowd

Implemente um programa denominado combinador, 
que recebe duas strings e deve combiná-las, alternando as letras de cada string, 
começando com a primeira letra da primeira string, seguido pela primeira letra da segunda string, 
em seguida pela segunda letra da primeira string, e assim sucessivamente. As letras restantes da cadeia mais 
longa devem ser adicionadas ao fim da string resultante e retornada.

Entrada
A entrada contém vários casos de teste. A primeira linha contém um 
inteiro N que indica a quantidade de casos de teste que vem a seguir. Cada caso de teste é composto por 
uma linha que contém duas cadeias de caracteres, cada cadeia de caracteres contém entre 1 e 50 caracteres inclusive.

Saída
Combine as duas cadeias de caracteres da entrada como mostrado no exemplo abaixo e exiba a cadeia resultante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char frase[101]; // Declara um array de caracteres para armazenar a frase de entrada
    char palavras[2][50]; // Declara uma matriz de caracteres para armazenar até duas palavras, cada uma com no máximo 50 caracteres
    int i = 0; // Inicializa um contador para rastrear o número de palavras extraídas

    // Lê uma linha de entrada do usuário e armazena na variável 'frase'
    fgets(frase, sizeof(frase), stdin);

    // Usa strtok para dividir a frase em palavras, separadas por espaços
    char* token = strtok(frase, " ");
    while(token != NULL && i < 2) { // Continua enquanto houver tokens e o contador for menor que 2
        strcpy(palavras[i], token); // Copia o token atual para a matriz 'palavras'
        i++; // Incrementa o contador
        token = strtok(NULL, " "); // Obtém o próximo token
    }

    char palavra_nova[100]= "";
    for(int k = 0; k < strlen(palavras[0]) || k < strlen(palavras[1]); k++) {
        if (k < strlen(palavras[0])) {
            strncat(palavra_nova, &palavras[0][k], 1); // Adiciona o caractere da primeira palavra
        }
        if (k < strlen(palavras[1])) {
            strncat(palavra_nova, &palavras[1][k], 1); // Adiciona o caractere da segunda palavra
        }
            
    };
        printf("%s",palavra_nova);

    // Itera sobre as palavras extraídas e imprime cada uma
    //for(int j = 0; j < i; j++) {
    //    printf("palavra Numero %d: %s \n", j + 1, palavras[j]);
    //}
    //system("pause");
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso


}
