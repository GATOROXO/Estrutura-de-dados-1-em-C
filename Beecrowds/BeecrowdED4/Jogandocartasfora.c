/** 
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 4

exercicio 1110 do Beecrowd 

Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base.  
A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50. 
A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída. 
A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. 
A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, 
cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. 
Nenhuma linha tem espaços extras no início ou no final. Veja exemplo para conferir o formato esperado.
 */


 
#include <stdio.h>
#include <stdlib.h>

// Definindo a constante para o tamanho do vetor
#define MAXIMO 51

struct est_fila {
    int vetor[MAXIMO];
    int contador;
};
typedef struct est_fila tipo_fila;

void inserir_fila(tipo_fila*, int);
int remover_fila(tipo_fila*);

int main() {
    tipo_fila fila;
    fila.contador = 0;
    int N;

    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }

        for (int i = 1; i <= N; i++) {
            inserir_fila(&fila, i);
        }

        printf("Discarded cards: ");
        while (fila.contador > 1) {
            // Descartando a carta do início da fila
            int descartada = remover_fila(&fila);
            printf("%d", descartada);

            // Movendo a próxima carta para o final da fila
            int mover = remover_fila(&fila);
            inserir_fila(&fila, mover);

            // Adicionando a vírgula apenas se houver mais cartas para descartar
            if (fila.contador > 1) {
                printf(", ");
            }
        }

        printf("\nRemaining card: %d\n", remover_fila(&fila));
    }

    return 0;
}

void inserir_fila(tipo_fila* fila, int valor) {
        fila->vetor[fila->contador] = valor;
        fila->contador++;
    }


int remover_fila(tipo_fila* fila) {
        int removido = fila->vetor[0];
        for (int i = 0; i < fila->contador - 1; i++) {
            fila->vetor[i] = fila->vetor[i + 1];
        }
        fila->contador--;
        return removido;
    }