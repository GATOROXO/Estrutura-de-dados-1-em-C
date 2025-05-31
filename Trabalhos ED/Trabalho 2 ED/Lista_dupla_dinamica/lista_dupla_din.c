#include "est_lista_dupla_din.h"

tipo_no_lista *alocaNo(int valor) {
    tipo_no_lista* novo_no = (tipo_no_lista*)malloc(sizeof(tipo_no_lista));
    if (novo_no == NULL) {
        printf("[ERRO 1]\n");
        return NULL;
    }
    novo_no->ant = NULL;
    novo_no->prox = NULL;
    novo_no->valor = valor;
    return novo_no;
}

void insereInicioLst(tipo_no_lista** inicio, int valor) {
    tipo_no_lista *novo_no = alocaNo(valor);
    if (novo_no == NULL) return;
    if (*inicio == NULL) {
        *inicio = novo_no;
    } else {
        novo_no->prox = *inicio;
        (*inicio)->ant = novo_no;
        *inicio = novo_no;
    }
}

void insereFimLst(tipo_no_lista** inicio, int valor) {
    tipo_no_lista *novo_no = alocaNo(valor);
    if (novo_no == NULL) return;
    if (*inicio == NULL) {
        *inicio = novo_no;
    } else {
        tipo_no_lista* aux = *inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo_no;
        novo_no->ant = aux;
    }
}

void inserePosLst(tipo_no_lista** inicio, int valor, int pos) {
    if (pos < 0) return;
    tipo_no_lista* novo_no = alocaNo(valor);
    if (novo_no == NULL) return;
    if (*inicio == NULL || pos == 0) {
        insereInicioLst(inicio, valor);
        free(novo_no);
        return;
    }
    tipo_no_lista* aux = *inicio;
    int i = 0;
    while (i < pos - 1 && aux->prox != NULL) {
        aux = aux->prox;
        i++;
    }
    novo_no->prox = aux->prox;
    novo_no->ant = aux;
    if (aux->prox != NULL) {
        aux->prox->ant = novo_no;
    }
    aux->prox = novo_no;
}

int contaNosLst(tipo_no_lista* inicio) {
    int count = 0;
    tipo_no_lista* aux = inicio;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

void liberaLista(tipo_no_lista** inicio) {
    tipo_no_lista* aux;
    while (*inicio != NULL) {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
    }
}