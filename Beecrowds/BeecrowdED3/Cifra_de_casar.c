/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 3

Exercico 1253 beecrowd

Júlio César usava um sistema de criptografia, 
agora conhecido como Cifra de César, que trocava cada letra pelo equivalente em duas posições adiante no alfabeto 
(por exemplo, 'A' vira 'C', 'R' vira 'T', etc.). Ao final do alfabeto nós voltamos para o começo, isto é 'Y' vira 'A'. 
Nós podemos, é claro, tentar trocar as letras com quaisquer número de posições.

Entrada
A entrada contém vários casos de teste. A primeira linha de entrada contém um inteiro N que indica a 
quantidade de casos de teste. Cada caso de teste é composto por duas linhas. 
A primeira linha contém uma string com até 50 caracteres maiúsculos ('A'-'Z'), 
que é a sentença após ela ter sido codificada através desta Cifra de César modificada. 
A segunda linha contém um número que varia de 0 a 25 e que representa quantas posições cada letra foi deslocada para a direita.

Saída
Para cada caso de teste de entrada, imprima uma linha de saída com o texto decodificado (transformado novamente para o texto original) 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void descriptografar(char* palavra, int cesar){
    for(int j = 0; j < strlen(palavra);j++){
        palavra[j] = 'A' + (palavra[j] + 'A' - cesar )%26;// operaçao matematica ASCII para manter com deslocamento para a esquerda.
    }
}

//O codigo correto para manter sempre entre letras maiusculas mas fazer a operaçao de deslocamento para a direita é:
//palavra[j] = 'A' + (palavra[j] - 'A' + cesar )%26; // operaçao matematica ASCII para manter sempre entre letras maiusculas com deslocamento para a direita


int main(){
    int n;
    scanf("%d",&n); //pergunta o numero de casos que irei realizar
    getchar(); //limpa buffer
    for(int i=0; i<n;i++){
        char palavra[51]= ""; //cria um vetor de char com 51 posiçoes e inicializa com vazio
        int cesar; //cria uma variavel para guardar o deslocamento
        scanf("%50[ABCDEFGHIJKLMNOPQRSTUVWXYZ]",palavra); //le apenas palavras com no maximo 50 caracteres e sempre maiusculos
        getchar(); //limpa buffer
        scanf("%d",&cesar);
        getchar();
        descriptografar(palavra, cesar);
        printf("%s\n", palavra);
        //system("pause");
        }

return 0;
}
//DEI CONTAAAAAAAAAAAAAAAAAAAAAA CARALHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOUUUUUUUUUUUUUUUUUUUUUUUUUUUUU 4:53 da manha
