/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Batuke é um cachorro com comportamento repetitivo que tem uma rotina particular quando sai para caminhar na sua vizinhança. 
A vizinhança também é de certa forma particular: uma matriz N x N que batuke percorre rotineiramente em espiral.
Batuke inicia percorrendo: 1 célula à direita, uma abaixo, seguida por duas à esquerda, duas acima, então 3 à direita, 3 para baixo, 
então 4, e assim por diante.

Lucas (o dono de Batuke), leva Batuke de carro para a célula inicial e 
o cão sempre segue sua rotina de corrida pelas células de sua vizinhança.

Por exemplo, se a vizinhança tem tamanho N = 4, as células são enumeradas como segue:



e o percurso feito por Batuke, iniciando na célula 1,1 (célula superior esquerda é 0,0) é:

6,7,11,10,9,5,1,2,3,4,8,12,16,15,14,13

Neste caso, a rotina de Batuke o faz caminhar por 16 células no total.

Mas Batuke não compreende nada sobre fronteiras e ele sempre faz sua rotina 
(mesmo se ele tem que caminhar por diversas células a mais), para atravessar todas as células da vizinhança.
Se a célula inicial for 2,2 por exemplo, a travessia em espiral 
(apenas as células da vizinhança são mostradas) é: 11,12,16,15,14,10,6,7,8,13,9,5,1,2,3,4.

Neste caso, Batuke caminha por 24 células no total. 
Lucas sabe que você está estudando Computação e ele pediu a você um programa para resolver este problema: 
dado a vizinhança de N linhas por N colunas e uma célula inicial, você deverá mostrar o percurso em espiral e o 
total células percorridas.

Entrada
A entrada consiste em três números inteiros: N (2 < N ≤ 10 ), F e C. N é o número de linhas na vizinhança 
(células enumeradas em 1..NxN, por linhas, da esquerda para a direita). F e C indica linha e coluna aonde Batuke 
inicia o seu percurso.

Saída
A saída consiste em 2 linhas. A primeira linha contém uma lista contendo as células da vizinhança, 
ordenadas pelo percurso que Batuke e separadas por um espaço em branco.
 A segunda linha mostra o número total de células percorridas por Batuke.
 */

/** 
* Questão 2179 - BATUKE
*/
#include <stdio.h>

//N é o número de linhas na vizinhança
int N;

// F e C indica linha e coluna aonde Batuke inicia o seu percurso.
int F, C;

//Indica o total de casas visitadas por Batuke
int casasVisitadas = 0;

int casasPercorridas = 0;

int passo = 1;

void exibeMatriz()
{
    int i, j, valor;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            valor = (i * N) + (j + 1);
            printf("%3d", valor);
        }
        printf("\n");
    }
}

int main()
{
    //exibeMatriz();
    scanf("%d%d%d",&N, &F, &C);

    //visita casa inicial
    if (C >= 0 && C < N && F >= 0 && F < N)
    {
        printf("%d ", ((F * N) + (C + 1)));
        casasVisitadas++;
    }
    casasPercorridas++;

        while (casasVisitadas < (N * N))
    {
        /**
         * Se passo é impar movimento para DIR > BAIXO
         * Caso Contrário ESQ > CIMA
         */
        int k;
        //caso passo é impar
        if (passo % 2 != 0)
        {

            //mover para direita

            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    C++;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }

            //mover para baixo
            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    F++;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }

            //incrementa o passo
            passo++;
        }
        else
        {
            //mover para esquerda
            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    C--;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }
            //mover para cima
            for (k = 0; k < passo; k++)
            {
                if (casasVisitadas < (N * N))
                {
                    F--;
                    casasPercorridas++;
                    if (C >= 0 && C < N && F >= 0 && F < N)
                    {
                        printf("%d ", ((F * N) + (C + 1)));
                        casasVisitadas++;
                    }
                }
            }
            //incrementa o passo
            passo++;
        }
    }

    printf("\n%d", casasPercorridas);

    return 0;
}