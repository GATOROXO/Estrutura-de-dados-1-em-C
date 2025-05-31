/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) no qual o 
valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1.
A seguir mostre o valor lido e a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).

Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada tipo necessárias, 
conforme o exemplo fornecido. Não esqueça de imprimir o fim de linha após cada linha, 
caso contrário seu programa apresentará a mensagem: “Presentation Error”.

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int valor,i,notas[7]={100,50,20,10,5,2,1};
    scanf("%d",&valor);
    printf("%d\n",valor);
    for(i=0;i<7;i++){
        printf("%d nota(s) de R$ %d,00\n",valor/notas[i],notas[i]);
        valor=valor%notas[i];
    }
    return 0;
    //achei genial a solução, muito simples e eficiente(nao fiz sozinho)
}
