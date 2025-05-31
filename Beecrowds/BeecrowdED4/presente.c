/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 4

exercicio 1425 do Beecrowd 

Presente?!

Existe um belo riacho em uma bela vila. N Pedras estão alinhadas em linha reta do número 1 até N, 
da margem esquerda à margem direita, como mostrado abaixo.

[Flanco esquerdo] - [Pedra 1] - [Pedra 2] - [Pedra 2] - [Pedra 3] - [Pedra 4] - [Pedra N] - [Flanco Direito]

A distância entre duas Pedras adjacentes é exatamente 1 metro, enquanto a distância entre a
 margem esquerda e a Pedra 1 e a distância entre a Pedra N e a margem direita também são 1 metro.

O sapo Frank está prestes a atravessar o riacho, seu vizinho, o sapo Funny veio a ele e disse:

'Olá Frank, feliz dia das Crianças! Eu tenho um presente para você. Vê? Um pequeno pacote na Pedra 5.'

'Oh, que legal! Obrigado! Eu vou pegar.'

'Espere! Este presente é apenas para sapos inteligentes. Você não pode pegar pulando direto.'

'Oh? Então o que devo fazer?'

'Pular mais vezes. Seu primeiro pulo deve ser da margem esquerda para a Pedra 1, 
então, pule quantas vezes quiser - não importa se for pra frente ou para traz - mas seu pulo i deve cobrir 2 × i - 1
metros. E mais, uma vez que alcance a margem direita ou esquerda, o jogo termina, sem mais pulos!'

'Hummmm, nada fácil... deixa eu pensar!' Respondeu sapo Frank, 'Devo tentar?'

Entrada
A entrada contém mais de 2000 casos de teste. Cada caso de teste contém um única linha. 
Ela contém dois positivos inteiros N(2 ≤ N ≤ 106), e M(1 ≤ M ≤ N), M indica o número da pedra em que o presente está. 
O caso de teste no qual N = 0, M = 0 terminará a entrada e não deve ser contado como caso de teste.

Saída
Para cada cado de teste, imprima uma única linha contendo 'Let me try!'(Me deixe tentar) se for possível 
chegar a Pedra M, caso contrário, imprima um linha contendo 'Don't make fun of me!'(Não ria de mim!).

 */

 #include <stdio.h>
 #include <stdlib.h>
 #define MAX 100000
 
 
int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n > MAX) break; // caso base 2
        if (n == 0 && m == 0) break; // caso base
        if(n>m){

            int *p = (int*)malloc(sizeof(int) * (n+1)); // tamanho do cenario que ira funcionar.
            int flanco_direito = n + 1;
            int sapo;
            int erro;
    
            for (int i = 0; i < n; i++) { // preenche os valores das pedras
                p[i] = i + 1;
                sapo = (p[i]*2);
                
                if(sapo == m){
                    erro =0;
                    break;

                }
                else if(sapo >= flanco_direito){
                    erro =1;
                }
    
            };
            if(erro == 0)printf("Let me try!\n");
            if(erro == 1)printf("Don't make fun of me!\n");
            free(p);
        }
        else{
            printf("Don't make fun of me!\n");
        }
        
    }
    return 0;
}