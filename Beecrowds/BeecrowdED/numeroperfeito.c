/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Na matemática, um número perfeito é um número inteiro para o qual a soma de todos os seus 
divisores positivos próprios (excluindo ele mesmo) é igual ao próprio número. 
Por exemplo o número 6 é perfeito, pois 1+2+3 é igual a 6. 
Sua tarefa é escrever um programa que imprima se um determinado número é perfeito ou não.

Entrada
A entrada contém vários casos de teste. A primeira linha da entrada contém um inteiro N (1 ≤ N ≤ 20), 
indicando o número de casos de teste da entrada. Cada uma das N linhas seguintes contém um valor inteiro X (1 ≤ X ≤ 108),
que pode ser ou não, um número perfeito.

Saída
Para cada caso de teste de entrada, imprima a mensagem “X eh perfeito” ou “X nao eh perfeito”, 
de acordo com a especificação fornecida.

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int c, n;
    scanf("%d", &c);

    for(int j = 1; j <=c; j++){
        scanf("%d", &n);
        int soma = 0;
        for(int i = 1; i<n; i++){
            if(n % i ==0){
                soma += i;
            }
        }

        if(soma == n){
            printf("%d eh perfeito\n", n);
        } else{
            printf("%d nao eh perfeito\n", n);
        }
    }
    return 0;
    }