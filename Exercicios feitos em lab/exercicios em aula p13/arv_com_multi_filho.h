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

arv_multi* aloca_no(int, char);
arv_multi*insere_inicio(int , char);
#endif