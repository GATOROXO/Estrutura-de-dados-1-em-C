/*
    Programa: Gerenciamento de Veículos

    Descrição:
    - Este programa permite cadastrar informações de veículos, exibir os dados cadastrados e aplicar 
    descontos no preço de um veículo específico.
    
    Funcionalidades:
    1. Cadastrar um número definido de veículos (modelo, ano de fabricação e preço).
    2. Exibir os dados de todos os veículos cadastrados.
    3. Aplicar um desconto percentual no preço de um veículo selecionado pelo usuário.

    Estrutura Principal:
    - Struct: `Veiculo` (contém modelo, ano e preço).
    - Funções:
      a) `preencherVeiculos`: Preenche um vetor de veículos.
      b) `exibirVeiculos`: Exibe os dados dos veículos.
      c) `aplicarDesconto`: Aplica um desconto ao preço de um veículo específico.

    Exemplo de uso:
    - Entrada:
      Número de veículos, dados de cada veículo, índice para desconto e percentual.
    - Saída:
      Veículos antes e depois da aplicação do desconto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Cadastrar_Veiculo{
    char nome[50];
    int ano;
    float preco;
    
};
void preencher_dados(struct Cadastrar_Veiculo *V, int n){
    for(int i=0;i<n;i++){
    printf("Digite o nome do modelo do Veiculo:\n");
    while(getchar() != '\n');
    fgets(V[i].nome, 50, stdin);
    printf("Digite o Ano do Veiculo:\n");
    scanf("%d", &V[i].ano);
    printf("Digite o preco do Veiculo: RS \n");
    scanf("%f",&V[i].preco);
    }
}
void exibir_dados(struct Cadastrar_Veiculo *V, int n){
    for (int i=0 ; i < n; i++){
        printf("modelo = %s", V[i].nome);
        printf("Ano = %d \n",V[i].ano);
        printf("preco = %.2f \n\n",V[i].preco);
    }
}

int main(){
    int n;
    struct Cadastrar_Veiculo V;
    printf("Quantos Veiculos voce deseja cadastrar(Apenas numeros)?:\n");
    scanf("%d",&n);

    int* vetor = (int*)malloc(sizeof(int)*n);

    printf("\nCadastrar Veiculos:\n");
    preencher_dados(vetor, n);
    printf("\nExibir veiculos cadastrados:\n");
    exibir_dados(vetor, n);

    free(vetor);
    return 0;
};

