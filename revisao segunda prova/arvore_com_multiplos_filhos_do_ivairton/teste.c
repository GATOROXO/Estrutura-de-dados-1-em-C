#define T 5
#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_no{
    int chave[T];
    void *dado[T];
    int cont;
    struct tipo_no* filhos[T+1];
};

tipo_no* remove_no(tipo_no* no, int chave){
    int i, j , z ,flag =1 , chave_aux;
    tipo_no* no_aux;
    if(no==NULL){return NULL;}
    if(no!=NULL){
        for(i=0;i<no->cont&&chave<no->chave[i];i++);
        if(i<no->cont&&chave== no->chave[i]){
            for(j=0;j<=no->cont&&no->filhos[j]!=NULL;j++){
                flag =0;
                break;
            }
            if(flag&&no->cont==1){
                free(no);
                return NULL;
            }
            else if(flag&&no->cont>1){
                for(j=i+1;i<no->chave[j];j--){
                    no->chave[j-1]=no->chave[j];
                    no->dado[j-1]=no->dado[j];
                }
                no->cont--;
                return no;
                }
                else{
                    if(no->filhos[i]!=NULL){
                        chave_aux=busca_maior(no->filhos[i]);
                        no_aux = busca_no(no->filhos[i], chave_aux);
                        for(j=0;chave_aux!=no_aux->chave[j];j++){
                            no->chave[i]=no_aux->chave[j];
                            no->dado[i]=no_aux->dado[j];
                        }
                        no->filhos[i]=remove_no(no->filhos[i], chave_aux);
                        
                    }
                }
            }
        }

    }
    




int busca_maior(tipo_no*no){
    if(no!=NULL){
        for(int i =0;i<=no->cont;i++){
            if(no->filhos[no->cont]!=NULL){
                return busca_maior(no->filhos[no->cont]);
            }
            else{
                return no->chave[no->cont-1];
            }
        }
    }
    else{return -1;}
}

tipo_no *busca_no(tipo_no* no, int chave){
    if(no==NULL){return NULL;}
    for(int i =0;i<no->cont && chave>no->chave[i];i++){
        if(chave==no->chave[i]){
            return no;
        }
        else{
            return busca_no(no->filhos[i], chave);
        }
    }
}
int busca_menor(tipo_no*no){
    if(no!=NULL){
        for(int i =0;i<=no->cont;i++){
            if(no->filhos[0]!=NULL){
                return busca_maior(no->filhos[0]);
            }
            else{
                return no->chave[0];
            }
        }
    }
    else{return -1;}