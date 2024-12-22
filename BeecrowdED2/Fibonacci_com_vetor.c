/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Faça um programa que leia um valor e apresente o número de Fibonacci correspondente a este valor lido. 
Lembre que os 2 primeiros elementos da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele. 
Todos os valores de Fibonacci calculados neste problema devem caber em um inteiro de 64 bits sem sinal.

Entrada
A primeira linha da entrada contém um inteiro T, 
indicando o número de casos de teste. Cada caso de teste contém um único inteiro N (0 ≤ N ≤ 60), 
correspondente ao N-esimo termo da série de Fibonacci.

Saída
Para cada caso de teste da entrada, imprima a mensagem "Fib(N) = X", onde X é o N-ésimo termo da série de Fibonacci.

 */


 #include <stdio.h>

// Função para calcular o N-ésimo termo da série de Fibonacci
unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int t; // Número de casos de teste

    // Lê o número de casos de teste
    scanf("%d", &t);

    while (t--) {
        int n;
        // Lê o valor de N para cada caso
        scanf("%d", &n);

        // Calcula e imprime o resultado
        printf("Fib(%d) = %llu\n", n, fibonacci(n));
    }

    return 0;
}
