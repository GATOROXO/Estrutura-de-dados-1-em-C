/*
Arvore Múltiplos Filhos
*/

#include <stdlib.h>
#include <stdio.h>
#include "arvoreMult.h"

tipo_arvore *alocaNo(int chave, char letra){
    tipo_arvore* novo_no;
    novo_no = (tipo_arvore*) malloc (sizeof(tipo_arvore));
    for (int i = 0; i < TAM + 1; i++){
        novo_no->vetPont[i] = NULL;
    }
    novo_no->vet[0].chave = chave;
    novo_no->vet[0].letra = letra;
    novo_no->contador = 1;
    return novo_no;
}


void insereArvore(tipo_arvore** arvore, int chave, char letra){
    if ((*arvore) == NULL){
        (*arvore) = alocaNo(chave, letra);
        printf("inserido novo\n");
        return;
    } else {
        if ((*arvore)->contador < TAM){
            int posicao = 0;
            while (posicao < (*arvore)->contador && chave > (*arvore)->vet[posicao].chave){
                posicao++;    
            }
            for (int i = (*arvore)->contador; i > posicao; i--){
                (*arvore)->vet[i].chave = (*arvore)->vet[i-1].chave;
                (*arvore)->vet[i].letra = (*arvore)->vet[i-1].letra;
            }
            (*arvore)->vet[posicao].chave = chave;
            (*arvore)->vet[posicao].letra = letra;
            (*arvore)->contador++;
            printf("inserido vetor\n");
            return;
        } else {
            if ((*arvore)->contador == TAM){
                int j = 0;
                while (chave > (*arvore)->vet[j].chave && j < TAM){
                    j++;
                }
                insereArvore(&(*arvore)->vetPont[j], chave, letra);
            }
        }
    }
}

void percursoPreOrdem(tipo_arvore* arvore){
    if (arvore == NULL){
        return;
    } else {
        int i;
        for (i = 0; i < arvore->contador; i++){
            printf("[%d] -> [%c] / ", arvore->vet[i].chave, arvore->vet[i].letra);
        }
        printf("\n");
        int j;
        for (j = 0; j < TAM + 1; j++){
            percursoPreOrdem(arvore->vetPont[j]);
        }
    }
}

void percursoPosOrdem(tipo_arvore* arvore){
    if (arvore == NULL){
        return;
    } else {
        int j;
        for (j = 0; j < TAM + 1; j++){
            percursoPosOrdem(arvore->vetPont[j]);
        }
        int i;
        for (i = 0; i < arvore->contador; i++){
            printf("[%d] -> [%c] / ", arvore->vet[i].chave, arvore->vet[i].letra);
        }
        printf("\n");
    }
}

void percursoEmOrdem(tipo_arvore* arvore){
    if (arvore == NULL){
        return;
    } else {
        int j;
        for (j = 0; j < arvore->contador; j++){
            percursoEmOrdem(arvore->vetPont[j]);
            printf("[%d] -> [%c]", arvore->vet[j].chave, arvore->vet[j].letra);
            printf("\n");
        }
        percursoEmOrdem(arvore->vetPont[arvore->contador]);
    }
}

int contaNos(tipo_arvore* arvore){
    if (arvore == NULL){
        return 0;
    } else {
        int j, quantNos = 1; //conta o no atual
        for (j = 0; j < TAM + 1; j++){
            //chama para os ponteiros do no e soma
            quantNos += contaNos(arvore->vetPont[j]);
        };
        return quantNos;
    }
}

int somaFolhas(tipo_arvore* arvore){
    if (arvore == NULL){
        return 0;
    } else {
        //flag se o no eh folha
        int somaDasFolhas = 0, flag = 1, j;
        for (j = 0; j < TAM + 1; j++){
            if (arvore->vetPont[j] != NULL){
                flag = 0;
                somaDasFolhas += somaFolhas(arvore->vetPont[j]);
            }
        }
        if (flag == 1){
            //Somando uma folha
            return 1;
        } else {
            return somaDasFolhas;
        }
    }
}
 

void verificaFolha(tipo_arvore* arvore, int chave){
    if (arvore == NULL){
        return;
    } else {
        //flag para se a chave foi encontrada
        int i, chaveEncontrada = 0;
        for (i = 0; i < arvore->contador; i++){
            if (chave == arvore->vet[i].chave){
                int flag = 1; // flag para ver se eh folha
                //chave encontrada
                chaveEncontrada = 1;
                for (int j = 0; j < TAM + 1; j++){
                    //confere se ha algum no diferente de nulo
                    if (arvore->vetPont[j] != NULL){
                        flag = 0; //nao eh folha
                        verificaFolha(arvore->vetPont[j], chave);
                    }
                }
                if (flag == 1){
                    printf("eh folha\n");
                } else {
                    printf("nao eh folha\n");
                }
                break;
            } 
        }
        //nao encontrou a chave nesse no
        if (chaveEncontrada == 0){
            for (int i = 0; i < TAM + 1; i++) {
                //chama para os nos filhos
                verificaFolha(arvore->vetPont[i], chave);
            }
        }
    }
}

void buscaDadoChave(tipo_arvore *arvore, int chave){
    if (arvore == NULL){
        printf("noh nao encontrado\n");
        return;
    } else {
        //flag pra no encontrado
        int i, noEncontrado = 0;

        //percorrendo lista
        for (i = 0; i < arvore->contador; i++){
            if (chave == arvore->vet[i].chave){
                //encontrado
                noEncontrado = 1;
                break;
            }
        }
        if (noEncontrado == 1){
            //impressao
            printf("Noh encontrado: [%d], [%c]\n", arvore->vet[i].chave, arvore->vet[i].letra);
            return;
        } else {
            //se o vetor estiver cheio
            if (arvore->contador == TAM){
                int j = 0;
                //encontrando ponteiro correto para chamar recursivamente
                while (chave > arvore->vet[j].chave && j < TAM){
                    j++;
                }
                buscaDadoChave(arvore->vetPont[j], chave);
            } else {
                //se nao estiver cheio e o noh nao foi encontrao eh pq ele nao existe
                printf("noh nao encontrado\n");
                return;
            }
        }
    }
}

void buscaNoChave(tipo_arvore *arvore, int chave){
    if (arvore == NULL){
        printf("noh nao encontrado\n");
        return;
    } else {
        //flag pra no encontrado
        int i, noEncontrado = 0;

        //percorrendo lista
        for (i = 0; i < arvore->contador; i++){
            if (chave == arvore->vet[i].chave){
                //encontrado
                noEncontrado = 1;
                break;
            }
        }
        if (noEncontrado == 1){
            //impressao
            int t;
            printf("Noh encontrado: ");
            for (t = 0; t < arvore->contador; t++){
                printf("[%d], [%c] / ", arvore->vet[t].chave, arvore->vet[t].letra);
            }
            return;
        } else {
            //se o vetor estiver cheio
            if (arvore->contador == TAM){
                int j = 0;
                //encontrando ponteiro correto para chamar recursivamente
                while (chave > arvore->vet[j].chave && j < TAM){
                    j++;
                }
                buscaNoChave(arvore->vetPont[j], chave);
            } else {
            }
        }
    }
}

int alturaArvore(tipo_arvore *arvore){
    if (arvore == NULL){
        return -1;
    } else {
        int alturaMax = -1, alturaFilho, i;

        //percorrendo lista
        for (i = 0; i <= arvore->contador; i++){

            //se houver no sendo apontado
            if (arvore->vetPont[i] != NULL){

                //calcula altura do filho
                alturaFilho = alturaArvore(arvore->vetPont[i]);

                //substituindo caso a altura por esse filho seja maior que a altura max
                if (alturaFilho > alturaMax){
                    alturaMax = alturaFilho;
                }
            }
        }
        //contando o nivel atual
        return alturaMax + 1;
    }
}

void imprimeArvoreNivel(tipo_arvore *arvore, int nivel){
    if (arvore == NULL){
        return;
    }
    //chega ao nivel
    if (nivel == 0){
        for (int i = 0; i < arvore->contador; i++){
            printf("[%d], [%c]\n", arvore->vet[i].chave, arvore->vet[i].letra);
        }
    } else {
        //chama recursivamente
        for (int j = 0; j < TAM + 1; j++){
            imprimeArvoreNivel(arvore->vetPont[j], nivel-1);
        }
    }
}

void imprimeArvorePorNivel(tipo_arvore *arvore){
    //recebendo a quantidade de niveis
    int quantNiveis = alturaArvore(arvore);

    //realizando a impressao de cada nivel
    for (int i = 0; i <= quantNiveis; i++){
        printf("nivel %d:\n", i);
        imprimeArvoreNivel(arvore, i);
    }
    return;
}

int contaNosNivel(tipo_arvore *arvore, int nivel){
    if (arvore == NULL){
        return 0;
    }

    if (nivel == 0){
        return 1; //contabilizando quando chega ao nivel
    } else {
        int quantNos = 0; 
        for (int i = 0; i <= arvore->contador; i++){
            quantNos += contaNosNivel(arvore->vetPont[i], nivel-1);
        }
        //retornando total de nos
        return quantNos;
    }
}

void contabilizaNosPorNivel(tipo_arvore *arvore){
    int quantNiveis = alturaArvore(arvore);

    //contabilizando
    for (int i = 0; i <= quantNiveis; i++){
        printf("nos no nivel %d: ", i);
        int quantNos = contaNosNivel(arvore, i);
        printf("%d\n", quantNos);
    }
    return;
}

void imprimeRotaValor(tipo_arvore *arvore, int chave){
    if (arvore == NULL){
        return;
    } 
     
    int valorEncontrado = 0;
    printf("\n");
    for (int i = 0; i < arvore->contador; i++){
        if (arvore->vet[i].chave == chave){
            valorEncontrado = 1;
        }
        printf("[%d] -> [%c]\n", arvore->vet[i].chave, arvore->vet[i].letra);
    }
    if (valorEncontrado == 1){
        return;
    } else {
        int j = 0;
        while (chave > arvore->vet[j].chave && j < TAM){
            j++;
        }
        imprimeRotaValor(arvore->vetPont[j], chave);
    }
}

dado *buscaMaiorValor(tipo_arvore *arvore) {
    if (arvore == NULL) {
        return NULL;
    }

    //se existir ponteiro pro maior filho
    if (arvore->vetPont[arvore->contador] != NULL) {
        return buscaMaiorValor(arvore->vetPont[arvore->contador]);
    } else {
        //chegou no noh, maior valor é o ultimo da posicao do vetor
        //printf("Maior Valor: [%d] -> [%c]\n", arvore->vet[arvore->contador-1].chave, arvore->vet[arvore->contador-1].letra);
    }
    return &arvore->vet[arvore->contador-1];
}

dado *buscaMenorValor(tipo_arvore *arvore){
    if (arvore == NULL) {
        return NULL;
    }

    //se existir ponteiro pro menor filho
    if (arvore->vetPont[0] != NULL) {
        return buscaMenorValor(arvore->vetPont[0]);
    } else {
        //chegou no noh, menor valor é o primeiro da posicao do vetor
        //printf("Menor Valor: [%d] -> [%c]\n", arvore->vet[0].chave, arvore->vet[0].letra);
    }
    return &arvore->vet[0];
}

dado *removeNo(tipo_arvore** arvore, int chave) {
    if ((*arvore) == NULL) {
        return NULL; // Árvore vazia ou nó não encontrado
    }

    int valorEncontrado = 0;
    int posicao = -1;

    // Verifica se a chave está no vetor do nó atual
    for (int i = 0; i < (*arvore)->contador; i++) {
        if (chave == (*arvore)->vet[i].chave) {
            valorEncontrado = 1;
            posicao = i;
            break;
        }
    }

    if (valorEncontrado == 1) {
        // Caso 1: Nó é folha
        int ehFolha = 1;
        for (int i = 0; i < TAM + 1; i++) {
            if ((*arvore)->vetPont[i] != NULL) {
                ehFolha = 0;
                break;
            }
        }

        if (ehFolha) {
            // Remove a chave do vetor
            for (int i = posicao; i < (*arvore)->contador - 1; i++) {
                (*arvore)->vet[i] = (*arvore)->vet[i + 1];
            }
            (*arvore)->contador--;

            // Desaloca o nó se ele ficar vazio
            if ((*arvore)->contador == 0) {
                free(*arvore);
                *arvore = NULL;
            }
            return NULL;
        }

        // Caso 2: Nó não é folha
        // Substitui a chave pelo maior valor do filho esquerdo ou menor valor do filho direito
        if ((*arvore)->vetPont[posicao] != NULL) {
            dado *maiorNoh = buscaMaiorValor((*arvore)->vetPont[posicao]);
            (*arvore)->vet[posicao] = *maiorNoh;
            removeNo(&(*arvore)->vetPont[posicao], maiorNoh->chave);
        } else if ((*arvore)->vetPont[posicao + 1] != NULL) {
            dado *menorNoh = buscaMenorValor((*arvore)->vetPont[posicao + 1]);
            (*arvore)->vet[posicao] = *menorNoh;
            removeNo(&(*arvore)->vetPont[posicao + 1], menorNoh->chave);
        }
        return NULL;
    }

    // Caso 3: Chave não está no nó atual, busca nos filhos
    int i = 0;
    while (i < (*arvore)->contador && chave > (*arvore)->vet[i].chave) {
        i++;
    }
    removeNo(&(*arvore)->vetPont[i], chave);
    return NULL;
}
