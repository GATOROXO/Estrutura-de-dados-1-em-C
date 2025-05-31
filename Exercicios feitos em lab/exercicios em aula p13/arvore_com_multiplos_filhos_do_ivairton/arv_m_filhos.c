// Implementacao do cabecalho ARV_M_FILHOS.H
#include "arv_m_filhos.h"

/**
 * @brief Funcao que aloca um no
 * 
 * @return tipo_no* Ponteiro para o no alocado
 */
tipo_no *aloca_no(int chave, char dado) {
    int i;
    tipo_no *no;
    no = (tipo_no *)malloc(sizeof(tipo_no));
    if (no == NULL) {
        printf("[ERRO] Falha na alocacao do no\n");
        exit(EXIT_FAILURE);
    }
    no->cont = 1;
    no->chaves[0] = chave;
    no->dados[0] = dado;

    for (int i = 0; i < (T+1); i++) {
        no->filhos[i] = NULL;
    }
    return no;
}

/**
 * @brief Funcao que insere um novo dado na arvore
 * @return tipo_no* Ponteiro para o no alocado
 */
tipo_no *insere_no(tipo_no *arv, int chave, char dado) {
    int i, j;
    tipo_no *no, *aux;

    // Verifica se o ponteiro de referencia da arvore estah vazio - aloca novo noh
    if (arv == NULL) {
        return aloca_no(chave, dado);
    }
    // Verifica se o noh atual tem espaco para inserir a nova chave/dado
    if (arv->cont < T) {
        i = arv->cont;
        // Encontra a posicao correta para inserir a nova chave
        // e desloca os elementos para a direita
        while (chave < arv->chaves[i - 1] && i > 0) {
            arv->chaves[i] = arv->chaves[i - 1];
            arv->dados[i] = arv->dados[i - 1];
            i--;
        }
        // Insere a nova chave e dado na posicao correta
        arv->chaves[i] = chave;
        arv->dados[i] = dado;
        arv->cont++;
        return arv;
    } else { // Se o noh estah cheio, identifica o filho a fazer chamada recursiva
        i = 0;
        while (chave > arv->chaves[i] && i < arv->cont)  i++;
        arv->filhos[i] = insere_no(arv->filhos[i], chave, dado);    
        return arv;
    }
}

/** 
 * @brief Funcao que imprime a arvore em pre ordem
 */
void imprime_pre_ordem(tipo_no *no) {
    int i;
    if (no != NULL) {
        printf("[ ");
        for (i = 0; i < no->cont; i++) {
            printf("(%d/%c) ", no->chaves[i], no->dados[i]);
        }
        printf("]\n");
        for (i = 0; i <= no->cont; i++) {
            imprime_pre_ordem(no->filhos[i]);
        }
    }
}

/**
 * @brief Funcao que imprime a arvore em pos ordem
 */
void imprime_pos_ordem(tipo_no *no) {
    int i;
    if (no != NULL) {
        for (i = 0; i <= no->cont; i++) {
            imprime_pos_ordem(no->filhos[i]);
        }
        printf("[ ");
        for (i = 0; i < no->cont; i++) {
            printf("%d ", no->chaves[i]);
        }
        printf("]\n");
    }
}

/**
 * @brief Funcao que imprime a arvore em ordem
 */
void imprime_em_ordem(tipo_no *no) {
    int i;
    if (no != NULL) {
        for (i = 0; i < no->cont; i++) {
            imprime_em_ordem(no->filhos[i]);
            printf("%d ", no->chaves[i]);
        }
        imprime_em_ordem(no->filhos[i]);
    }
}

/**
 * @brief Funcao que busca um dado na arvore, a partir da sua chave
 */
char busca_dado(tipo_no *no, int chave) {
    int i;
    if (no == NULL) { // Se a chave nao existe, retorna caractere nulo/fim de cadeia
        return '\0';
    }
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++); // posiciona i ao longo dos dados do no
    if (i < no->cont && chave == no->chaves[i]) { // verifica se chave foi encontrada
        return no->dados[i]; // Retorna o dado correspondente a chave
    } else {
        return busca_dado(no->filhos[i], chave); // Chamada recursiva para o filho correspondente
    }
}

/**
 * @brief Funcao que busca um noh na arvore, a partir da sua chave (retorna todo o noh)
 */
tipo_no *busca_no(tipo_no *no, int chave) {
    int i;
    if (no == NULL) { // Se a chave nao existe, retorna NULL
        return NULL;
    }
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++); // posiciona i ao longo dos dados do no
    if (i < no->cont && chave == no->chaves[i]) { // verifica se chave foi encontrada
        return no; // Retorna o no
    } else {
        return busca_no(no->filhos[i], chave); // Chamada recursiva para o filho correspondente
    }
}

/** 
 * @brief Funcao que contabiliza o total de nohs da arvore
 * @return int Total de nos
 */
int total_nos(tipo_no *no) {
    int i, total = 0;
    if (no != NULL) {
        total++;
        for (i = 0; i <= no->cont; i++) {
            total += total_nos(no->filhos[i]);
        }
    }
    return total;
}

/**
 * @brief Funcao que contabiliza o total de folhas da arvore
 * @return int Total de folhas
 */
int total_folhas(tipo_no *no) {
    int i, flag, total;
    flag = 1;
    total = 0;
    if (no != NULL) {
        for (i = 0; i <= no->cont; i++) {
            if (no->filhos[i] != NULL) {
                flag = 0;
                total += total_folhas(no->filhos[i]);
            }
        }
        if (flag) // Se o no eh folha
            return 1;
        else
            return total;
    }
    return 0; // poderia ser 'total'
}

/**
 * @brief Funcao que verifica se um noh eh folha
 */
int verifica_folha(tipo_no *no, int chave) {
    int i, flag;
    if (no == NULL) { // Se a chave nao existe, retorna 0
        return 0;
    }
    flag = 1;
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++); // posiciona i ao longo dos dados do no
    if (i < no->cont && chave == no->chaves[i]) { // verifica se chave foi encontrada
        //verifica se folha
        for (int i = 0; i <= no->cont; i++) {
            if (no->filhos[i] != NULL) {
                flag = 0;
                break;
            }
        }
        if (flag) // Se o no eh folha
            return 1;
        else 
            return 0;
    } else {
        return verifica_folha(no->filhos[i], chave); // Chamada recursiva para o filho correspondente
    }
}

/** 
 * @brief Funcao que contabiliza a altura da arvore
 */
int altura_arvore(tipo_no *no) {
    int i, altura = 0, h;
    if (no != NULL) {
        for (i = 0; i <= no->cont; i++) {
            h = altura_arvore(no->filhos[i]);
            if (h > altura)
                altura = h;
        }
        return altura + 1;
    }
    return -1;
}

/** 
 * @brief Funcao que imprime a arvore por nivel
 */
void imprime_arv_nivel(tipo_no *no) {
    int h;
    h = altura_arvore(no);
    for (int i = 0; i < h; i++) {
        printf("Nivel %d: ", i);
        imprime_nivel(no, i);
        printf("\n");
    }
}

/**
 * @brief Funcao que imprime os nos de um nivel
 */
void imprime_nivel(tipo_no *no, int nivel) {
    int i;
    if (no != NULL) {
        if (nivel == 0) {
            printf("[ ");
            for (i = 0; i < no->cont; i++) {
                printf("%d ", no->chaves[i]);
            }
            printf("]\n");
        } else {
            for (i = 0; i <= no->cont; i++) {
                imprime_nivel(no->filhos[i], nivel - 1);
            }
        }
    }
}

/**
 * @brief Funcao que contabiliza o total de nos por nivel
 */
int contabiliza_no_por_nivel(tipo_no *no, int nivel) {
    int i, total = 0;
    if (no != NULL) {
        if (nivel == 0) {
            return 1;
        } else {
            for (i = 0; i <= no->cont; i++) {
                total += contabiliza_no_por_nivel(no->filhos[i], nivel - 1);
            }
        }
    }
    return total;
}

/** 
 * @brief Funcao que busca o maior elemento da arvore
 */
int busca_maior(tipo_no *no) {
    int i;
    if (no != NULL) {
        if (no->filhos[no->cont] != NULL)
            return busca_maior(no->filhos[no->cont]);
            
        return no->chaves[no->cont - 1];
    }
    return -1;
}

/**
 * @brief Funcao que busca o menor elemento da arvore
 */
int busca_menor(tipo_no *no) {
    int i;
    if (no != NULL) {
        if (no->filhos[0] != NULL)
            return busca_maior(no->filhos[0]);
            
        return no->chaves[0];
    }
    return -1;
}

/**
 * @brief Funcao que imprime a rota de um noh
 */
void imprime_rota(tipo_no *no, int chave) {
    int i;
    if (no != NULL) {
        for (i = 0; i < no->cont && chave > no->chaves[i]; i++); // posiciona i ao longo dos dados do no
        if (i < no->cont && chave == no->chaves[i]) { // verifica se chave foi encontrada
            printf("Rota: ");
            for (int j = 0; j <= i; j++) {
                printf("%d ", no->chaves[j]);
            }
            printf("\n");
        } else {
            imprime_rota(no->filhos[i], chave); // Chamada recursiva para o filho correspondente
        }
    }
}

/** 
 * @brief Funcao que remove um noh da arvore 
 * @param no Ponteiro para o noh
 * @param chave Chave do noh a ser removido
 * @return tipo_no* Ponteiro para o noh removido
 */
tipo_no *remove_no(tipo_no *no, int chave) {
    int i, j, z, flag, aux_vl;
    tipo_no *aux_no;
    if (no == NULL) { // Se a chave nao existe, retorna NULL
        return NULL;
    }
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++); // posiciona i ao longo dos dados do no
    if (i < no->cont && chave == no->chaves[i]) { // verifica se chave foi encontrada
        //verifica se noh eh folha
        flag = 1;
        for (int j = 0; j <= no->cont; j++) {
            if (no->filhos[j] != NULL) {
               flag = 0;
            }
        }
        if (flag && no->cont == 1) { // Se o noh eh folha e tem 1 valor
            free(no);
            return NULL;
        } else if (flag && no->cont > 1) { // Se o noh eh folha e tem mais de 1 valor
            // remove ordenado
            for (j = i + 1; j < no->cont; j++) {
                no->chaves[j - 1] = no->chaves[j];
                no->dados[j - 1] = no->dados[j];
            }
            no->cont--;
            return no;
        } else { //se NAO eh folha
            //Verifica se a chave tem filho(s)
            if (no->filhos[i] != NULL) { //Verifica se tem fiho esquerdo
                aux_vl = busca_maior(no->filhos[i]);
                aux_no = busca_no(no->filhos[i], aux_vl);
                for (z=0; aux_vl != aux_no->chaves[z]; z++);
                no->chaves[i] = aux_no->chaves[z];
                no->dados[i] = aux_no->dados[z];
                no->filhos[i] = remove_no(no->filhos[i], aux_vl);
            } else if (no->filhos[i+1] != NULL) { //Verifica se tem filho direito
                aux_vl = busca_menor(no->filhos[i+1]);
                aux_no = busca_no(no->filhos[i+1], aux_vl);
                for (z=0; aux_vl != aux_no->chaves[z]; z++);
                no->chaves[i] = aux_no->chaves[z];
                no->dados[i] = aux_no->dados[z];
                no->filhos[i+1] = remove_no(no->filhos[i+1], aux_vl);
            } else { //Caso a chave NAO tenha filhos
                //Verifica se ha filhos aa esquerda
                for (j = i; ((j >= 0) && (no->filhos[j] == NULL)); j--);
                if ( j >= 0) { //Verifica se achou na ESQ
                    aux_vl = busca_maior(no->filhos[j]);
                    //desloca valores para direita
                    for ( ; i > j; i--) {
                        no->chaves[i] = no->chaves[i-1];
                        no->dados[i] = no->dados[i-1];
                    }
                    aux_no = busca_no(no->filhos[j], aux_vl);
                    for (z=0; aux_vl != aux_no->chaves[z]; z++);
                    no->chaves[i] = aux_no->chaves[z];
                    no->dados[i] = aux_no->dados[z];
                    no->filhos[j] = remove_no(no->filhos[j], aux_vl);
                } else { //Entao busca na DIR
                    for (j = i; ((j <= no->cont) && (no->filhos[j] == NULL)); j++);
                    aux_vl = busca_menor(no->filhos[j]);
                    for ( ; i < j; i++) {
                        no->chaves[i] = no->chaves[i+1];
                        no->dados[i] = no->dados[i+1];
                    }
                    aux_no = busca_no(no->filhos[j], aux_vl);
                    for (z=0; aux_vl != aux_no->chaves[z]; z++);
                    no->chaves[i] = aux_no->chaves[z];
                    no->dados[i] = aux_no->dados[z];
                    no->filhos[j] = remove_no(no->filhos[j], aux_vl);
                }
            }
        }
    } else {
        no->filhos[i] = remove_no(no->filhos[i], chave); // Chamada recursiva para o filho correspondente
    }
    return no;
}