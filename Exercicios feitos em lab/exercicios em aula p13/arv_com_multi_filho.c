#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arv_com_multi_filho.h"
/**
 * @brief funçao aloca no para arvore com multiplos filhos
 */
arv_multi* aloca_no(){
    arv_multi* novo_no = (arv_multi*)malloc(sizeof(arv_multi));
    if(novo_no == NULL){
        printf("erro ao alocar memoria");
        return NULL;
    }
    for(int i = 0; i<T;i++){
        novo_no->filhos[i] = NULL;
    }
    novo_no->contador = 0;
    return novo_no;
}

arv_multi**insere_inicio(int chave, char dado){
    arv_multi*novo_no = aloca_no();
    if()
}