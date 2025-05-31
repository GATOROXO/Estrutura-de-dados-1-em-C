/**
 * Defina estrutura da fila 
 * inmpletar inserçao e remoção
 * implementar impressão
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int main(){
    int contador = 0;
    int vetor[10];
    while(1){
        printf("Digite o valor da posiçao %d da fila:", contador+1);
        scanf("%d",&vetor[contador]);
        contador++;
        printf("\n agora digite o que deseja fazer:[1 para inserir]/[2 para remover]/[3 para imprimir]");
        int opcao;
        if(opcao==1){
            if(contador>10){return "erro";}
            else{
                printf("\nInsira dados da posiçao %d da fila: \n", contador+1);
                scanf("%d",&vetor[contador]);
            }
        }
        else if(opcao==2){
            int remover;
            int i= 0;
            printf("\nDigite qual posiçao das %d posiçoes restantes voce deseja remover\n",contador+1);
            scanf("%d",remover);
            for(i;i<contador;i++);
                if(i==remover){
                    vetor[i]--;
                    contador--;
                }
                else continue;
        }
        else if(opcao==3){;
            printf("\n Impressao da Fila:\n");
        for(int i=0;i<contador;i++){
            printf("%d posiçao = %d",contador +1,vetor[i]);
            }
            }
        else if(opcao ==0) {
            break;
        }
        else return"erro";

    }

    system("pause");
    return 0;
}