#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arv_com_multi_filho.h"

/**
 * @brief Função aloca nó para árvore com múltiplos filhos
 */
arv_multi* aloca_no(int chave, char dado){
    arv_multi* novo_no = (arv_multi*)malloc(sizeof(arv_multi));
    if(novo_no == NULL){
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    novo_no->contador = 1;
    novo_no->chave[0] = chave;
    novo_no->dado[0] = dado;
    for(int i = 0; i < T; i++){
        novo_no->filhos[i] = NULL;
    }
    return novo_no;
}

/**
 * @brief Função que insere um valor na árvore
 */
arv_multi* insere_inicio(arv_multi* raiz, int chave, char dado){
    if(raiz == NULL){
        return aloca_no(chave, dado);
    }
    
    if(raiz->contador < T){
        int i = raiz->contador;
        while(i > 0 && chave < raiz->chave[i-1]){
            raiz->chave[i] = raiz->chave[i-1];
            raiz->dado[i] = raiz->dado[i-1];
            i--;
        }
        raiz->chave[i] = chave;
        raiz->dado[i] = dado;
        raiz->contador++;
        return raiz;
    }
    else{
        int i = 0;
        while(i < raiz->contador && chave > raiz->chave[i]){
            i++;
        }
        raiz->filhos[i] = insere_inicio(raiz->filhos[i], chave, dado);
        return raiz;
    }
}

/**
 * @brief Função para percurso em pré-ordem
 */
void pre_ordem(arv_multi* raiz){
    if(raiz == NULL) return;
    
    // Imprime as chaves do nó atual
    for(int i = 0; i < raiz->contador; i++){
        printf("%d:%c ", raiz->chave[i], raiz->dado[i]);
    }
    
    // Visita os filhos
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            pre_ordem(raiz->filhos[i]);
        }
    }
}

/**
 * @brief Função para percurso em-ordem
 */
void em_ordem(arv_multi* raiz){
    if(raiz == NULL) return;
    
    for(int i = 0; i < raiz->contador; i++){
        // Visita filho da esquerda
        if(i == 0 && raiz->filhos[0] != NULL){
            em_ordem(raiz->filhos[0]);
        }
        
        // Processa o nó atual
        printf("%d:%c ", raiz->chave[i], raiz->dado[i]);
        
        // Visita filho da direita
        if(i+1 < T && raiz->filhos[i+1] != NULL){
            em_ordem(raiz->filhos[i+1]);
        }
    }
}

/**
 * @brief Função para percurso em pós-ordem
 */
void pos_ordem(arv_multi* raiz){
    if(raiz == NULL) return;
    
    // Visita todos os filhos primeiro
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            pos_ordem(raiz->filhos[i]);
        }
    }
    
    // Processa o nó atual
    for(int i = 0; i < raiz->contador; i++){
        printf("%d:%c ", raiz->chave[i], raiz->dado[i]);
    }
}

/**
 * @brief Função que conta o total de nós na árvore
 */
int total_nos(arv_multi* raiz){
    if(raiz == NULL) return 0;
    
    int total = 1; // Conta o nó atual
    
    // Soma os nós dos filhos
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            total += total_nos(raiz->filhos[i]);
        }
    }
    
    return total;
}

/**
 * @brief Função que verifica se um nó é folha
 */
int eh_folha(arv_multi* raiz){
    if(raiz == NULL) return 0;
    
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            return 0; // Se tem pelo menos um filho, não é folha
        }
    }
    
    return 1; // Se não tem filhos, é folha
}

/**
 * @brief Função que conta o total de folhas na árvore
 */
int total_folhas(arv_multi* raiz){
    if(raiz == NULL) return 0;
    
    if(eh_folha(raiz)){
        return 1;
    }
    
    int total = 0;
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            total += total_folhas(raiz->filhos[i]);
        }
    }
    
    return total;
}

/**
 * @brief Função que calcula a altura da árvore
 */
int altura_arvore(arv_multi* raiz){
    if(raiz == NULL) return 0;
    
    int maior_altura = 0;
    
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            int altura_filho = altura_arvore(raiz->filhos[i]);
            if(altura_filho > maior_altura){
                maior_altura = altura_filho;
            }
        }
    }
    
    return maior_altura + 1; // Altura do nó atual + maior altura dos filhos
}

/**
 * @brief Função auxiliar para imprimir nós em um nível específico
 */
void imprime_nivel(arv_multi* raiz, int nivel){
    if(raiz == NULL) return;
    
    if(nivel == 1){
        // Imprime nós do nível atual
        for(int i = 0; i < raiz->contador; i++){
            printf("%d:%c ", raiz->chave[i], raiz->dado[i]);
        }
    }
    else if(nivel > 1){
        // Desce para os filhos
        for(int i = 0; i < T; i++){
            if(raiz->filhos[i] != NULL){
                imprime_nivel(raiz->filhos[i], nivel - 1);
            }
        }
    }
}

/**
 * @brief Função que imprime a árvore por níveis
 */
void imprime_por_nivel(arv_multi* raiz){
    int h = altura_arvore(raiz);
    
    for(int i = 1; i <= h; i++){
        printf("Nível %d: ", i);
        imprime_nivel(raiz, i);
        printf("\n");
    }
}

/**
 * @brief Função auxiliar para contar nós em um nível específico
 */
int conta_nos_nivel(arv_multi* raiz, int nivel){
    if(raiz == NULL) return 0;
    
    if(nivel == 1){
        return 1; // Conta o nó atual
    }
    
    int total = 0;
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            total += conta_nos_nivel(raiz->filhos[i], nivel - 1);
        }
    }
    
    return total;
}

/**
 * @brief Função que conta o número de nós por nível
 */
int* nos_por_nivel(arv_multi* raiz, int altura){
    if(raiz == NULL) return NULL;
    
    int* contador = (int*)calloc(altura, sizeof(int));
    if(contador == NULL){
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    
    for(int i = 1; i <= altura; i++){
        contador[i-1] = conta_nos_nivel(raiz, i);
    }
    
    return contador;
}

/**
 * @brief Função que busca um valor na árvore
 */
arv_multi* busca_valor(arv_multi* raiz, int chave){
    if(raiz == NULL) return NULL;
    
    // Verifica se a chave está no nó atual
    for(int i = 0; i < raiz->contador; i++){
        if(raiz->chave[i] == chave){
            return raiz;
        }
    }
    
    // Busca nos filhos
    for(int i = 0; i < raiz->contador; i++){
        if(i < raiz->contador-1 && chave > raiz->chave[i] && chave < raiz->chave[i+1]){
            return busca_valor(raiz->filhos[i+1], chave);
        }
    }
    
    if(chave < raiz->chave[0]){
        return busca_valor(raiz->filhos[0], chave);
    }
    
    return busca_valor(raiz->filhos[raiz->contador-1], chave);
}

/**
 * @brief Função auxiliar para imprimir caminho até o valor
 */
bool encontra_caminho(arv_multi* raiz, int chave, int caminho[], int indice){
    if(raiz == NULL) return false;
    
    // Verifica se a chave está no nó atual
    for(int i = 0; i < raiz->contador; i++){
        if(raiz->chave[i] == chave){
            caminho[indice] = raiz->chave[i];
            return true;
        }
    }
    
    // Busca nos filhos
    for(int i = 0; i < T; i++){
        if(raiz->filhos[i] != NULL){
            caminho[indice] = raiz->chave[0]; // Registra a passagem pelo nó atual
            if(encontra_caminho(raiz->filhos[i], chave, caminho, indice + 1)){
                return true;
            }
        }
    }
    
    return false;
}

/**
 * @brief Função que imprime a rota até um valor
 */
void imprime_rota(arv_multi* raiz, int chave){
    int altura = altura_arvore(raiz);
    int* caminho = (int*)malloc(altura * sizeof(int));
    
    if(caminho == NULL){
        printf("Erro ao alocar memória\n");
        return;
    }
    
    if(encontra_caminho(raiz, chave, caminho, 0)){
        printf("Caminho até %d: ", chave);
        for(int i = 0; i < altura && caminho[i] != 0; i++){
            printf("%d -> ", caminho[i]);
        }
        printf("%d\n", chave);
    }
    else{
        printf("Valor %d não encontrado na árvore\n", chave);
    }
    
    free(caminho);
}

/**
 * @brief Função que busca o menor valor na árvore
 */
int busca_menor_valor(arv_multi* raiz){
    if(raiz == NULL){
        printf("Árvore vazia\n");
        return -1;
    }
    
    while(raiz->filhos[0] != NULL){
        raiz = raiz->filhos[0];
    }
    
    return raiz->chave[0];
}

/**
 * @brief Função que busca o maior valor na árvore
 */
int busca_maior_valor(arv_multi* raiz){
    if(raiz == NULL){
        printf("Árvore vazia\n");
        return -1;
    }
    
    // Vai para o nó mais à direita
    while(raiz->filhos[raiz->contador-1] != NULL){
        raiz = raiz->filhos[raiz->contador-1];
    }
    
    return raiz->chave[raiz->contador-1];
}

/**
 * @brief Função auxiliar para encontrar o índice de uma chave em um nó
 */
int encontra_indice(arv_multi* no, int chave) {
    for(int i = 0; i < no->contador; i++) {
        if(no->chave[i] == chave) {
            return i;
        }
    }
    return -1; // Não encontrado
}

/**
 * @brief Função auxiliar para remover uma chave de um nó folha
 */
void remove_de_folha(arv_multi* no, int indice) {
    // Move todos os elementos à direita do índice uma posição para a esquerda
    for(int i = indice; i < no->contador - 1; i++) {
        no->chave[i] = no->chave[i + 1];
        no->dado[i] = no->dado[i + 1];
    }
    no->contador--;
}

/**
 * @brief Função auxiliar para encontrar o sucessor de uma chave
 */
void encontra_sucessor(arv_multi* no, int indice, arv_multi** sucessor, int* sucess_indice) {
    // Vai para o filho à direita da chave
    arv_multi* atual = no->filhos[indice + 1];
    
    // Continua descendo para o filho mais à esquerda
    while(atual->filhos[0] != NULL) {
        atual = atual->filhos[0];
    }
    
    *sucessor = atual;
    *sucess_indice = 0; // Menor chave do nó
}

/**
 * @brief Função auxiliar para encontrar o predecessor de uma chave
 */
void encontra_predecessor(arv_multi* no, int indice, arv_multi** predecessor, int* pred_indice) {
    // Vai para o filho à esquerda da chave
    arv_multi* atual = no->filhos[indice];
    
    // Continua descendo para o filho mais à direita
    while(atual->filhos[atual->contador] != NULL) {
        atual = atual->filhos[atual->contador];
    }
    
    *predecessor = atual;
    *pred_indice = atual->contador - 1; // Maior chave do nó
}

/**
 * @brief Função para remover uma chave da árvore
 */
arv_multi* remove_chave(arv_multi* raiz, int chave) {
    // Caso base: árvore vazia
    if(raiz == NULL) {
        printf("Árvore vazia, nada a remover.\n");
        return NULL;
    }
    
    // Busca pela chave no nó atual
    int indice = encontra_indice(raiz, chave);
    
    // Se a chave foi encontrada no nó atual
    if(indice != -1) {
        // Caso 1: Nó é uma folha
        if(eh_folha(raiz)) {
            remove_de_folha(raiz, indice);
            
            // Se após remoção o nó ficou vazio, libera memória
            if(raiz->contador == 0) {
                free(raiz);
                return NULL;
            }
        }
        // Caso 2: Nó não é folha
        else {
            arv_multi* sucessor;
            int sucess_indice;
            
            // Encontra o sucessor (menor valor na subárvore direita)
            encontra_sucessor(raiz, indice, &sucessor, &sucess_indice);
            
            // Substitui chave e dado pela do sucessor
            raiz->chave[indice] = sucessor->chave[sucess_indice];
            raiz->dado[indice] = sucessor->dado[sucess_indice];
            
            // Agora remove o sucessor (que é garantido ser uma folha ou ter estrutura mais simples)
            raiz->filhos[indice + 1] = remove_chave(raiz->filhos[indice + 1], sucessor->chave[sucess_indice]);
        }
    }
    // Se a chave não foi encontrada no nó atual, determina em qual filho buscar
    else {
        // Encontra o filho adequado para busca
        int i = 0;
        while(i < raiz->contador && chave > raiz->chave[i]) {
            i++;
        }
        
        // Verifica se o filho existe
        if(raiz->filhos[i] == NULL) {
            printf("Chave %d não encontrada na árvore.\n", chave);
            return raiz;
        }
        
        // Chama recursivamente para o filho adequado
        raiz->filhos[i] = remove_chave(raiz->filhos[i], chave);
    }
    
    return raiz;
}

/**
 * @brief Função principal para remoção - interface pública
 */
arv_multi* remove_valor(arv_multi* raiz, int chave) {
    if(raiz == NULL) {
        printf("Árvore vazia.\n");
        return NULL;
    }
    
    raiz = remove_chave(raiz, chave);
    printf("Valor %d removido da árvore.\n", chave);
    return raiz;
}