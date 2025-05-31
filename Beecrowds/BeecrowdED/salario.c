/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Escreva um programa que leia o número de um funcionário, seu número de horas trabalhadas, o valor que recebe por hora
e calcula o salário desse funcionário. A seguir, mostre o número e o salário do funcionário, com duas casas decimais.

Entrada
O arquivo de entrada contém 2 números inteiros e 1 número com duas casas decimais, 
representando o número, quantidade de horas trabalhadas e o valor que o funcionário recebe por hora trabalhada, 
respectivamente.

Saída
Imprima o número e o salário do funcionário, conforme exemplo fornecido, com um espaço em branco antes 
e depois da igualdade. No caso do salário, também deve haver um espaço em branco após o $

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num_funcionario;
    float num_horas_trabalhadas , num_salario_hora;
    scanf("%d",&num_funcionario);
    scanf("%f",&num_horas_trabalhadas);
    scanf("%f",&num_salario_hora);
    printf("NUMBER = %d\n",num_funcionario);
    printf("SALARY = U$ %.2f\n", num_horas_trabalhadas*num_salario_hora);
    return 0;
}