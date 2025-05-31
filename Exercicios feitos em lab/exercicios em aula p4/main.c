#include <stdio.h>
// Corrigir o nome do arquivo de cabeçalho incluído
#include "pilha_dinamica.h"

int main() {
    // Cria uma nova pilha
    Pilha* pilha = cria_pilha();

    // Empilha alguns valores
    empilha(pilha, 10);
    empilha(pilha, 20);
    empilha(pilha, 30);

    // Mostra o topo da pilha
    printf("Topo da pilha: %d\n", topo_pilha(pilha));

    // Desempilha e mostra os valores
    printf("Desempilhando: %d\n", desempilha(pilha));
    printf("Desempilhando: %d\n", desempilha(pilha));

    // Verifica se a pilha está vazia
    if (pilha_vazia(pilha)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

    // Destroi a pilha
    destroi_pilha(pilha);

    return 0;
}