/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 09/12/2024

Objetivo1: declare 2 vetores entao some os valores de cada vetor e armazene em um terceiro vetor e imprima o resultado
objetivo2: Descubra o maior e menor valor do vetor resultado
onjetivo3: some os valores do vetor1 do inicio+1 com os valores do vetor2 no final-1
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
// objetivo 1
int main(){
    int vetor1[TAM];
    int vetor2[TAM];
    int vetor_resultado[TAM];
    int i;
    for (i = 0; i < TAM; i++){
        system("cls");
        printf("Digite o valor %d do vetor 1: ", i+1);
        scanf("%d", &vetor1[i]);
        system("cls");
    }
    for (i = 0; i < TAM; i++){
        printf("Digite o valor %d do vetor 2: ", i+1);
        scanf("%d", &vetor2[i]);
        system("cls");

    }
    for (i = 0; i < TAM; i++){
        vetor_resultado[i] = vetor1[i] + vetor2[i];
    }
// objetivo 2
    int menor=vetor_resultado[0];
    int maior=vetor_resultado[0];
    for(i = 1 ; i<TAM; i++){
        if(vetor_resultado[i]< menor){
            menor = vetor_resultado[i];
        }
    }
    for (i = 1; i < TAM; i++){
        if(vetor_resultado[i]> maior){
            maior = vetor_resultado[i];
        }
    }
    // objetivo 3
    int vetor_soma_resultado[TAM];
    int j = TAM -1 ;
    for(i= 0 ; i<TAM; i++){
        vetor_soma_resultado[i] = vetor1[i] + vetor2[j];
        j--;
    }
    
//prints     
    for (i = 0; i < TAM; i++){ 
        printf("O valor %d do vetor resultado eh: %d\n", i, vetor_resultado[i]);
    
    }
    for(i= 0 ; i<TAM; i++){
        printf("O valor da soma vetor %d eh: %d\n", i,vetor_soma_resultado[i]); 
    }
    printf("O maior valor do vetor resultado eh: %d\n", maior);
    printf("O menor valor do vetor resultado eh: %d\n", menor);
    system("pause");
    return 0;
}
