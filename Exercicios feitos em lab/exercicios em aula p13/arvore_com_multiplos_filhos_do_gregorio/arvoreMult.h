/*
Árvore Múltiplos Filhos
*/

#ifndef __ARVOREMULT_H__
#define __ARVOREMULT_H__
#define TAM 3

typedef struct tipo_dado{
    int chave;
    char letra;
}dado;

typedef struct tipo_arvore{
    dado vet[TAM];
    struct tipo_arvore *vetPont[TAM + 1];  
    int contador;
}tipo_arvore;

void insereArvore(tipo_arvore**, int, char);
tipo_arvore* alocaNo(int, char); 
void percursoPreOrdem(tipo_arvore*);
void percursoPosOrdem(tipo_arvore*);
void percursoEmOrdem(tipo_arvore*);
int contaNos(tipo_arvore*);
int somaFolhas(tipo_arvore*);
void verificaFolha(tipo_arvore*, int);
void buscaDadoChave(tipo_arvore*, int);
void buscaNoChave(tipo_arvore*, int);
int alturaArvore(tipo_arvore*);
void imprimeArvoreNivel(tipo_arvore*, int);
void imprimeArvorePorNivel(tipo_arvore*);
int contaNosNivel(tipo_arvore*, int);
void contabilizaNosPorNivel(tipo_arvore*);
void imprimeRotaValor(tipo_arvore*, int);
dado* buscaMaiorValor(tipo_arvore*);
dado* buscaMenorValor(tipo_arvore*);
dado* removeNo(tipo_arvore**, int);

#endif