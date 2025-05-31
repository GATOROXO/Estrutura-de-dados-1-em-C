#include "est_lista_dupla_din.h"

int main(){
    tipo_no_lista *lista = NULL;
    srand(time(NULL));
    clock_t inicio , fim;
    int contador = 0;
    double tempo_de_cpu;
    inicio = clock();
    int media =[10];
    for(int m = 0;m<10;m++){

        for(int i =0; i<3333;i++){
            int aleatorio = rand() %10000;
            insereInicioLst(&lista, aleatorio);
            contador++;
        }
        for(int j = 0; j<3333;j++){
            int aleatorio = rand()%10000;
            insereFimLst(&lista, aleatorio);
            contador++;
        }
    
        for(int k =0; k<3334; k++){
            int aleatorio = rand()%10000;
            inserePosLst(&lista, aleatorio, (rand() % contador+1));
        }
        tempo_de_cpu = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }
    int num_lista = contaNosLst(lista);
    size_t tamanho_no = sizeof(tipo_no_lista);
    int memoria_total = tamanho_no *num_lista;
    fim = clock();
    printf("tempo de cpu usado na estrutura: %f\nestruturas criadas: %d\nMemoria utilizada: %d bytes.\n", tempo_de_cpu, num_lista, memoria_total);
    liberaLista(&lista);
    return 0;

}

