/**

C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 19/12/2024

// Objetivo 1:
escreva um algoritmo que declare um vetor dinamicamete (usando ponteiro) na sua funçao
principal,lembre-se de perguntar ao usuario quantos valores serão armazenados 
no vetor.
Então, escreva uma funçao que receba este vetor como parametro e que preencha o vetor com valores
informados pelo usuario.
na sequencia escreva uma segunda funçao que faz a copia do vetor inicial e que retorna
esta copia para um segundo vetor criado na funçao principal.
*/



#include <stdio.h>
#include <stdlib.h>

void referencia(int *vetor, int n){
    printf("Preencha o vetor com %d valores:\n ", n);
    for(int i=0;i<n;i++){
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
}
int *copia(int vetor[], int n){
    int*copiar_vetor = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        copiar_vetor[i] = vetor[i]+10;
    }
        return copiar_vetor;
}




int main(){
    int n, i, *copiar_vetor ;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n); //quantidade de memoria que sera alocada
    int* vetor = (int*)malloc(n*sizeof(int)); //alocando memoria e inicializando o vetor
    referencia(vetor, n);
    for(i=0;i<n;i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    copiar_vetor=copia(vetor, n);
    for (i=0; i<n; i++){
        printf("vetor copia[%d] = %d\n", i, copiar_vetor[i]);
    }
    
    return 0;

}
