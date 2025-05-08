#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"


/**
 * @brief Funçao que aloca no para arvore
 */
tipo_no* aloca_no(char letra, int chave) {
    tipo_no* novo_no = (tipo_no*)malloc(sizeof(tipo_no)); 
    if (novo_no == NULL) { 
        printf("[Erro ao alocar memoria]\n");
        return NULL; 
    }
    novo_no->dir = NULL;
    novo_no->esq = NULL;
    novo_no->chave = chave;
    novo_no->letra = letra;
    return novo_no;
}
/**
 * @brief Funçao que insere no ja ordenado
 */
tipo_no* insere_no(tipo_no*no, char letra, int chave) {
    if (no == NULL) {
        no = aloca_no(letra, chave); 
        return;
    }
    if (chave < no->chave) {
        insere_no(no->esq, letra, chave); // Insere na subárvore esquerda
    } else if (chave > no->chave) {
        insere_no(no->dir, letra, chave); 
    }
   
}
/**
 * @brief Metodo de percurso 1
 */
void imprime_pre_ordem(tipo_no* no) {
    if (no == NULL) {
        return;
    }
    printf("[ %c | %d ] ", no->letra, no->chave);
    imprime_pre_ordem(no->esq);
    imprime_pre_ordem(no->dir);
}
/**
 * @brief Metodo de percurso 2
 */

void imprime_em_ordem(tipo_no* no) {
    if (no == NULL) {
        return;
    }
    imprime_em_ordem(no->esq);
    printf("[ %c | %d ] ", no->letra, no->chave);
    imprime_em_ordem(no->dir);
}
/**
 * @brief Metodo de percurso 3
 */
void imprime_pos_ordem(tipo_no* no) { // Corrigido o nome da função
    if (no == NULL) {
        return;
    }
    imprime_pos_ordem(no->esq);
    imprime_pos_ordem(no->dir);
    printf("[ %c | %d ] ", no->letra, no->chave);
}
/**
 * @brief Funçao que retorna o total de nos na arvore
 */

int total_nos(tipo_no* no) {
    if (no == NULL) {
        return 0;
    }
    return 1 + total_nos(no->esq) + total_nos(no->dir);
}
/**
 * @brief Funçao que verifica quantas folhas ha na arvore
 */
int total_folhas(tipo_no* no) {
    if (no == NULL) {
        return 0;
    }
    if (no->esq == NULL && no->dir == NULL) {
        return 1; // É folha
    }
    return total_folhas(no->esq) + total_folhas(no->dir);
}
/**
 * @brief Funçao que busca um no pela chave(int chave)
 */
tipo_no* busca_no(tipo_no* no, int chave) {
    if (no == NULL) {
        return NULL; // Nó não encontrado
    }
    if (no->chave == chave) {
        return no; // Nó encontrado
    }
    if (chave < no->chave) {
        return busca_no(no->esq, chave); // Busca na subárvore esquerda
    }
    return busca_no(no->dir, chave); // Busca na subárvore direita
}
/**
 * @brief Funçao que verifica se um nó é folha
 */
int verifica_folha(tipo_no *no, int chave) {
    tipo_no *no_encontrado = busca_no(no, chave);
    if (no_encontrado == NULL) {
        return 0; // Nó não encontrado
    }
    return (no_encontrado->esq == NULL && no_encontrado->dir == NULL);  
}
/**
 * @brief Funçao que retorna a altura da arvore 
 */
int altura_arvore(tipo_no * no){
    if (no == NULL){
        return-1;
    }
    int h_esq= altura_arvore(no->esq);
    int h_dir= altura_arvore(no->dir);
    if(h_esq>h_dir){
        return h_esq+1;
    }
    else {
        return h_dir +1;
    };  
};
/**
 * @brief Funçao que imprime os nos do nivel
 */
void imprime_nivel(tipo_no* no, int nivel, int max_nivel) {
    if (no != NULL) { // Verifica se o nó atual não é nulo
        if (nivel == max_nivel) { // Se o nível atual for igual ao nível desejado
            printf("[%d|%c] ", no->chave, no->letra); // Imprime o nó no formato [chave|letra]
        } else { 
            // Caso contrário, chama recursivamente para os filhos esquerdo e direito
            imprime_nivel(no->esq, nivel + 1, max_nivel); // Incrementa o nível ao descer para o filho esquerdo
            imprime_nivel(no->dir, nivel + 1, max_nivel); // Incrementa o nível ao descer para o filho direito
        }
    }
}

/**
 * @brief Funçao que contabiliza o numero de nos em um nivel
 */
int contabiliza_no_nivel(tipo_no * no, int nivel){
    if(no == NULL){
        return 0;
    }
    else if(nivel == 0){
        return 1;
    }
    else{
        return contabiliza_no_nivel(no->esq, nivel -1)+contabiliza_no_nivel(no->dir , nivel -1);
    }
}


/**
 * @brief Funçao que imprime arvore por nivel
 */
void imprime_arv_nivel(tipo_no* no) {
    int h = altura_arvore(no); // Calcula a altura da árvore (nível máximo)
    int nivel = 0; // Inicializa o nível atual como 0 (raiz)
    for (nivel; nivel <= h; nivel++) { // Itera do nível 0 até o nível máximo (altura da árvore)
        printf("nivel: %d ", nivel); // Imprime o número do nível atual
        imprime_nivel(no, 0, nivel); // Chama a função imprime_nivel para imprimir os nós do nível atual
        printf("\n"); // Quebra de linha após imprimir todos os nós do nível atual
    }
}

/**
 * @brief Funçao que mostra a rota até o no(chave) determinado
 */
void imprime_rota(tipo_no*no , int chave){
    if(busca_no(no,chave)== NULL){
        printf("No com chave %d Nao encontrado!\n", chave);
    }
    else{
        printf("[%d|%c] ->", no->chave ,no->letra);
        if(chave< no->chave){
            imprime_rota(no->esq , chave);
        }
        else if(chave>no->chave){
            imprime_rota(no->dir , chave);
        }
        else{
            printf("FIM\n");
        }
    }
}
//remoçao feita no dia 10/04/2025 em conjunto com as outras funçoes 
/**
 * @brief Funçao que busca e remove o no de acordo com a chave
 */
tipo_no *remove_no(tipo_no * no , int chave){
    if(no == NULL){
        return NULL;
    };
    if (chave < no->chave){
        no->esq = remove_no(no->esq , chave);
    }
    else if(chave > no->chave){
        no->dir = remove_no(no->dir, chave);
    }
    else{
        //caso o no for folha 
        if(verifica_folha(no, chave) == 1){
            free(no);
            return NULL;
        }//caso o no possuir apenas um filho
        else if(no->esq == NULL){
            tipo_no * temp = no->dir;
            free(no);
            return temp;
        }
        else if(no->dir == NULL){
            tipo_no*temp = no->esq;
            free(no);
            return temp;
        }
        //caso o no possui 2 filhos
        else{
            tipo_no *temp = encontra_menor(no);
            no->chave = temp->chave;
            no->letra = temp->letra;
            no->dir = remove_no(no->dir , temp->chave);
        }
    }
    return no;
}

tipo_no *encontra_menor(tipo_no * no) {
    tipo_no * atual = no;
    while (atual != NULL && atual->esq != NULL) { // Corrige o loop para parar antes de atual ser NULL
        atual = atual->esq; // Move para o filho esquerdo
    }
    return atual; // Retorna o menor nó encontrado
}
