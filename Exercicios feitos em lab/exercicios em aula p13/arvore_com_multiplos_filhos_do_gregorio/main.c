/*
Árvore Múltiplos filhos
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvoreMult.h"


int main(){
    //inicializando arvore
    tipo_arvore *arvore = NULL;

    //preenchendo arvore
    insereArvore(&arvore, 20, 'a');
    insereArvore(&arvore, 30, 'c');
    insereArvore(&arvore, 50, 'g');
    insereArvore(&arvore, 15, 'f');
    insereArvore(&arvore, 5, 's');
    insereArvore(&arvore, 8, 'b');
    insereArvore(&arvore, 43, 'q');
    insereArvore(&arvore, 40, 'm');
    insereArvore(&arvore, 31, 'l');
    insereArvore(&arvore, 9, 'p');
    insereArvore(&arvore, 70, 'j');
    insereArvore(&arvore, 52, 'z');
    insereArvore(&arvore, 75, 'y');
    insereArvore(&arvore, 80, 'w');
    insereArvore(&arvore, 79, 'x');
    insereArvore(&arvore, 89, 'l');
    insereArvore(&arvore, 100, 'h');
    insereArvore(&arvore, 77, 'k');
    
    // percursos
    printf("Pre Ordem\n");
    percursoPreOrdem(arvore);
    printf("Pos Ordem\n");
    percursoPosOrdem(arvore);
    printf("Em Ordem\n");
    percursoEmOrdem(arvore);

    //conta nos
    int quantNos = contaNos(arvore);
    printf("\nQuantidade de Nos da arvore: %d\n", quantNos);
    
    //conta folhas
    int quantFolhas = somaFolhas(arvore);
    printf("\nQuantidade de Nos folha da arvore: %d\n", quantFolhas);

    //verifica folha
    verificaFolha(arvore, 9);

    //Busca dado chave
    buscaDadoChave(arvore, 40);
    printf("\n"); 

    //Busca No chave
    buscaNoChave(arvore, 100);
    printf("\n");

    //altura da arvore
    int altura = alturaArvore(arvore);
    printf("altura da arvore: %d\n", altura);
    printf("\n");

    //imprime nivel
    imprimeArvoreNivel(arvore, 1);

    //imprimindo por nivel
    printf("\n");
    imprimeArvorePorNivel(arvore);

    //Conta Nos Nivel
    printf("\n");
    int NosNivel = contaNosNivel(arvore, 1);
    printf("Quanidade de nos no nivel: %d\n", NosNivel);

    //Contabiliza Nos por Nivel
    printf("\n");
    contabilizaNosPorNivel(arvore);

    //imprimindo rota ate valor
    printf("\n");
    printf("Rota ate o valor:\n");
    imprimeRotaValor(arvore, 8); 

    //busca maior
    buscaMaiorValor(arvore);

    //busca menor
    buscaMenorValor(arvore);

    //remove noh
    printf("removendo noh\n");
    removeNo(&arvore, 100);

    //printando arvore
    percursoPreOrdem(arvore);
    return 0; 
}