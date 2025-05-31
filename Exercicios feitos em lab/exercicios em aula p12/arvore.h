#ifndef arvore_h
#define arvore_h
struct est_no {
    char letra;
    int chave;
    struct est_no *esq;
    struct est_no *dir;
};
typedef struct est_no tipo_no;

// Prototipacao
tipo_no *aloca_no(char letra, int chave);
void insere_no(tipo_no **no, char letra, int chave);
void imprime_pre_ordem(tipo_no *no);
void imprime_em_ordem(tipo_no *no);
void imprime_pos_ordem(tipo_no *no);
//TODO
int total_nos(tipo_no *no);
int total_folhas(tipo_no *no);
tipo_no *busca_no(tipo_no *no, int chave);
int verifica_folha(tipo_no *no, int chave);
int altura_arvore(tipo_no *no);
void imprime_nivel(tipo_no *no, int nivel, int max_nivel);
int contabiliza_no_nivel(tipo_no *no, int nivel);
void imprime_arv_nivel(tipo_no *no);
void imprime_rota(tipo_no *no, int chave);
tipo_no *remove_no(tipo_no *no, int chave);
tipo_no *encontra_menor(tipo_no* no);
#endif // arvore_h