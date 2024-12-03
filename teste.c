/** Veriificaçao de numeros pares ou impares
 *  Nome : João Paulo Alves Campos
 *  Data : 03/12/2024
 */

#include <stdio.h>

int main(){
    int usuario;
    printf("Digite um numero: ");
    scanf("%d", &usuario);

    if (usuario% 2 == 0){ 
        printf("O numero %d é par", usuario);

    }
    else {
        printf("O numero %d é impar", usuario);
    }
    return 0;
}   