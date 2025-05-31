#include "lista_din.h"

// Função para alocar um novo nó
tipo_no_lista *alocaNo(int valor) {
    tipo_no_lista *novoNo = (tipo_no_lista *)malloc(sizeof(tipo_no_lista));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

// Insere um elemento no início da lista
void insereInicioLst(tipo_no_lista **lst, int valor) {
    tipo_no_lista *novoNo = alocaNo(valor);
    novoNo->prox = *lst;
    *lst = novoNo;
}

// Insere um elemento no fim da lista
void insereFimLst(tipo_no_lista **lst, int valor) {
    tipo_no_lista *novoNo = alocaNo(valor);
    if (*lst == NULL) {
        *lst = novoNo;
    } else {
        tipo_no_lista *aux = *lst;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoNo;
    }
}

// Insere um elemento em uma posição específica da lista
void inserePosLst(tipo_no_lista **lst, int valor, int pos) {
    if (pos < 0) {
        printf("Erro: Posição inválida.\n");
        return;
    }
    if (pos == 0) {
        insereInicioLst(lst, valor);
        return;
    }
    tipo_no_lista *novoNo = alocaNo(valor);
    tipo_no_lista *aux = *lst;
    int cont = 0;
    while (aux != NULL && cont < pos - 1) {
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL) {
        printf("Erro: Posição fora dos limites da lista.\n");
        free(novoNo);
        return;
    }
    novoNo->prox = aux->prox;
    aux->prox = novoNo;
}

// Remove o elemento do início da lista
int removeInicioLst(tipo_no_lista **lst) {
    if (*lst == NULL) {
        printf("Erro: Lista vazia.\n");
        return -1;
    }
    tipo_no_lista *aux = *lst;
    int valor = aux->valor;
    *lst = aux->prox;
    free(aux);
    return valor;
}

// Remove o elemento do fim da lista
int removeFimLst(tipo_no_lista **lst) {
    if (*lst == NULL) {
        printf("Erro: Lista vazia.\n");
        return -1;
    }
    tipo_no_lista *aux = *lst;
    tipo_no_lista *anterior = NULL;
    while (aux->prox != NULL) {
        anterior = aux;
        aux = aux->prox;
    }
    int valor = aux->valor;
    if (anterior == NULL) { // A lista só tem um elemento
        *lst = NULL;
    } else {
        anterior->prox = NULL;
    }
    free(aux);
    return valor;
}

// Remove o elemento de uma posição específica da lista
int removePosLst(tipo_no_lista **lst, int pos) {
    if (*lst == NULL || pos < 0) {
        printf("Erro: Posição inválida ou lista vazia.\n");
        return -1;
    }
    if (pos == 0) {
        return removeInicioLst(lst);
    }
    tipo_no_lista *aux = *lst;
    tipo_no_lista *anterior = NULL;
    int cont = 0;
    while (aux != NULL && cont < pos) {
        anterior = aux;
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL) {
        printf("Erro: Posição fora dos limites da lista.\n");
        return -1;
    }
    int valor = aux->valor;
    anterior->prox = aux->prox;
    free(aux);
    return valor;
}

// Remove o primeiro nó que contém um valor específico
int removeValorLst(tipo_no_lista **lst, int valor) {
    if (*lst == NULL) {
        printf("Erro: Lista vazia.\n");
        return -1;
    }
    tipo_no_lista *aux = *lst;
    tipo_no_lista *anterior = NULL;
    while (aux != NULL && aux->valor != valor) {
        anterior = aux;
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Erro: Valor não encontrado na lista.\n");
        return -1;
    }
    if (anterior == NULL) { // O valor está no início da lista
        return removeInicioLst(lst);
    }
    int val = aux->valor;
    anterior->prox = aux->prox;
    free(aux);
    return val;
}

// Busca um nó por posição
tipo_no_lista *buscaPosLst(tipo_no_lista *lst, int pos) {
    if (lst == NULL || pos < 0) {
        printf("Erro: Posição inválida ou lista vazia.\n");
        return NULL;
    }
    tipo_no_lista *aux = lst;
    int cont = 0;
    while (aux != NULL && cont < pos) {
        aux = aux->prox;
        cont++;
    }
    return aux;
}

// Busca um nó pelo valor
tipo_no_lista *buscaValorLst(tipo_no_lista *lst, int valor) {
    tipo_no_lista *aux = lst;
    while (aux != NULL && aux->valor != valor) {
        aux = aux->prox;
    }
    return aux;
}

// Conta o número de nós na lista
int contaNosLst(tipo_no_lista *lst) {
    int cont = 0;
    tipo_no_lista *aux = lst;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

// Imprime os valores da lista
void imprimeLista(tipo_no_lista *lst) {
    tipo_no_lista *aux = lst;
    printf("[ ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("]\n");
}