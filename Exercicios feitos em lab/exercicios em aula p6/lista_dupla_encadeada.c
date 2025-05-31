#include "lista_dupla_enc.h"

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

int removeInicioLst(tipo_no_lista** inicio) {
    if (*inicio == NULL) {
        printf("[ERRO] Lista Vazia.\n");
        return -1;
    }
    tipo_no_lista* aux = *inicio;
    int valor = aux->valor;
    *inicio = aux->prox;
    if (*inicio != NULL) {
        (*inicio)->ant = NULL;
    }
    free(aux);
    return valor;
}

int removeFimLst(tipo_no_lista** inicio) {
    if (*inicio == NULL) {
        printf("Lista Vazia!\n");
        return -1;
    }
    tipo_no_lista* aux = *inicio;
    if (aux->prox == NULL) {
        int valor = aux->valor;
        *inicio = NULL;
        free(aux);
        return valor;
    }
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    int valor = aux->valor;
    aux->ant->prox = NULL;
    free(aux);
    return valor;
}

int removePosLst(tipo_no_lista** inicio, int pos) {
    if (*inicio == NULL || pos < 0) {
        printf("Lista vazia ou posicao invalida\n");
        return -1;
    }
    tipo_no_lista* aux = *inicio;
    if (pos == 0) {
        return removeInicioLst(inicio);
    }
    int i = 0;
    while (i < pos && aux != NULL) {
        aux = aux->prox;
        i++;
    }
    if (aux == NULL) {
        printf("Posicao inexistente\n");
        return -1;
    }
    int valor = aux->valor;
    aux->ant->prox = aux->prox;
    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }
    free(aux);
    return valor;
}

int removeValorLst(tipo_no_lista** inicio, int valor) {
    tipo_no_lista* aux = buscaValorLst(*inicio, valor);
    if (aux == NULL) {
        printf("Valor nao encontrado\n");
        return -1;
    }
    if (aux == *inicio) {
        return removeInicioLst(inicio);
    }
    if (aux->prox == NULL) {
        return removeFimLst(inicio);
    }
    int val = aux->valor;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    return val;
}

tipo_no_lista *buscaPosLst(tipo_no_lista* inicio, int pos) {
    if (pos < 0) return NULL;
    tipo_no_lista* aux = inicio;
    int i = 0;
    while (aux != NULL && i < pos) {
        aux = aux->prox;
        i++;
    }
    return aux;
}

tipo_no_lista *buscaValorLst(tipo_no_lista* inicio, int valor) {
    tipo_no_lista* aux = inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
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

void imprimeLista(tipo_no_lista* inicio) {
    tipo_no_lista* aux = inicio;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void buscaEImprimeValorLst(tipo_no_lista* inicio, int valor) {
    tipo_no_lista* no = buscaValorLst(inicio, valor);
    if (no != NULL) {
        printf("Valor encontrado: %d\n", no->valor);
        int pos = 0;
        tipo_no_lista* aux = inicio;
        while (aux != no && aux != NULL) {
            pos++;
            aux = aux->prox;
        }
        if (aux != NULL) {
            printf("Posicao encontrada: %d\n", pos);
        }
    } else {
        printf("Valor nao encontrado\n");
    }
}