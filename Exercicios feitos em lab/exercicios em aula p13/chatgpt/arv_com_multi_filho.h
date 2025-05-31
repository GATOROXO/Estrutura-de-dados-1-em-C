#ifndef arv_com_multi_filho_H
#define arv_com_multi_filho_H
#define T 3
struct arvore_com_multiplos_filhos{
    int chave[T];
    char dado[T];
    struct arvore_com_multiplos_filhos* filhos [T];
    int contador;
};
typedef struct arvore_com_multiplos_filhos arv_multi;

// Funções básicas
arv_multi* aloca_no(int, char);
arv_multi* insere_inicio(arv_multi* raiz, int chave, char dado);

// Funções de percurso
void pre_ordem(arv_multi* raiz);
void em_ordem(arv_multi* raiz);
void pos_ordem(arv_multi* raiz);

// Funções de contagem e análise
int total_nos(arv_multi* raiz);
int total_folhas(arv_multi* raiz);
int eh_folha(arv_multi* raiz);
int altura_arvore(arv_multi* raiz);
void imprime_por_nivel(arv_multi* raiz);
int* nos_por_nivel(arv_multi* raiz, int altura);
void imprime_rota(arv_multi* raiz, int chave);

// Funções de busca
arv_multi* busca_valor(arv_multi* raiz, int chave);
int busca_menor_valor(arv_multi* raiz);
int busca_maior_valor(arv_multi* raiz);

#endif