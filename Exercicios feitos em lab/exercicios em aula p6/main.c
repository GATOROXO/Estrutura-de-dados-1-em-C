#include "lista_dupla_enc.h"

int main() {
    tipo_no_lista* lista = NULL;

    // Inserindo elementos na lista
    insereInicioLst(&lista, 10);
    insereFimLst(&lista, 20);
    inserePosLst(&lista, 15, 1);

    // Imprimindo a lista
    imprimeLista(lista);

    // Removendo elementos da lista
    removeInicioLst(&lista);
    removeFimLst(&lista);
    removePosLst(&lista, 0);

    // Imprimindo a lista apos remocoes
    imprimeLista(lista);

    // Buscando e imprimindo o valor
    buscaEImprimeValorLst(lista, 20);

    return 0;
}