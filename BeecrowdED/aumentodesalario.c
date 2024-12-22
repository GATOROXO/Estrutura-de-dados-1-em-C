/**

C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Leia o salário do funcionário e calcule e mostre o novo salário, 
bem como o valor de reajuste ganho e o índice reajustado, em percentual.

Entrada
A entrada contém apenas um valor de ponto flutuante, com duas casas decimais.

Saída
Imprima 3 linhas na saída: o novo salário, o valor ganho de reajuste
(ambos devem ser apresentados com 2 casas decimais) e o percentual de reajuste ganho.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float reajuste, salario;
    scanf("%f", &salario);
    if(salario <= 400.00){
        reajuste = salario * 0.15;
        salario = salario + reajuste;
}
    else if(salario <= 800.00){
        reajuste = salario * 0.12;
        salario = salario + reajuste;
}
    else if(salario <= 1200.00){
        reajuste = salario * 0.10;
        salario = salario + reajuste;
}
    else if(salario <= 2000.00){
        reajuste = salario * 0.07;
        salario = salario + reajuste;
}
    else{
        reajuste = salario * 0.04;
        salario = salario + reajuste;
}
    printf("Novo salario: %.2f\n", salario);
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: %.0f %%\n", (reajuste / (salario - reajuste)) * 100);
    return 0;
}


