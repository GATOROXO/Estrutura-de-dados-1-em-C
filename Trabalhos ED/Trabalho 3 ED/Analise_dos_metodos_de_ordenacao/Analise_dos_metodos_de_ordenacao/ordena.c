#include "ordena.h"

// Função para carregar dados do arquivo
void carregar_arquivo(tipo_lista *ls, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }
    ls->cont = 0;
    int valor;
    while (fscanf(arquivo, "%d", &valor) != EOF && ls->cont < MAX_TAMANHO) {
        ls->vet_lista[ls->cont++] = valor;
    }
    fclose(arquivo);
    printf("Arquivo %s carregado com %d valores.\n", nome_arquivo, ls->cont);
}

// Função genérica para executar e medir ordenação
void executar_teste(tipo_lista *ls, const char *nome_arquivo, void (*metodo)(tipo_lista *, unsigned long long *, double *), const char *nome_metodo) {
    unsigned long long trocas = 0; // Alterado para unsigned long long
    double tempo;
    clock_t inicio = clock();
    metodo(ls, &trocas, &tempo);
    tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;

    printf("%s | %s | Trocas: %llu | Tempo: %.4f s\n", nome_metodo, nome_arquivo, trocas, tempo);
    FILE *resultado = fopen("resultados.txt", "a");
    fprintf(resultado, "%s,%s,%llu,%.4f\n", nome_metodo, nome_arquivo, trocas, tempo);
    fclose(resultado);
}

// Métodos de ordenação
void bubbleSort(tipo_lista *ls, unsigned long long *trocas, double *tempo) {
    *trocas = 0;
    int aux;
    for (int i = 0; i < ls->cont - 1; i++) {
        for (int j = 0; j < ls->cont - i - 1; j++) {
            if (ls->vet_lista[j] > ls->vet_lista[j + 1]) {
                aux = ls->vet_lista[j];
                ls->vet_lista[j] = ls->vet_lista[j + 1];
                ls->vet_lista[j + 1] = aux;
                (*trocas)++;
            }
        }
    }
}

void insertSort(tipo_lista *ls, unsigned long long *trocas, double *tempo) {
    *trocas = 0;
    int j, aux;
    for (int i = 1; i < ls->cont; i++) {
        aux = ls->vet_lista[i];
        j = i - 1;
        while (j >= 0 && ls->vet_lista[j] > aux) {
            ls->vet_lista[j + 1] = ls->vet_lista[j];
            j--;
            (*trocas)++;
        }
        ls->vet_lista[j + 1] = aux;
    }
}

void shellSort(tipo_lista *ls, unsigned long long *trocas, double *tempo) {
    *trocas = 0;
    int salto = ls->cont / 2, aux;
    while (salto > 0) {
        for (int i = salto; i < ls->cont; i++) {
            aux = ls->vet_lista[i];
            int j = i;
            while (j >= salto && ls->vet_lista[j - salto] > aux) {
                ls->vet_lista[j] = ls->vet_lista[j - salto];
                j -= salto;
                (*trocas)++;
            }
            ls->vet_lista[j] = aux;
        }
        salto /= 2;
    }
}

void mergeSort(tipo_lista *ls, unsigned long long *trocas, double *tempo) {
    *trocas = 0;
    if (ls->cont > 1) {
        quebraMergeSort(ls->vet_lista, ls->cont, trocas);
    }
}

void quebraMergeSort(int *ls, int tamanho, unsigned long long *trocas) {
    if (tamanho <= 1) return;
    int meio = tamanho / 2;
    quebraMergeSort(ls, meio, trocas);
    quebraMergeSort(ls + meio, tamanho - meio, trocas);
    merge(ls, tamanho, trocas);
}

void merge(int ls[], int tamanho, unsigned long long *trocas) {
    int meio = tamanho / 2, i = 0, j = meio, posaux = 0;
    int *lsaux = (int *)malloc(tamanho * sizeof(int));
    while (i < meio && j < tamanho) {
        if (ls[i] <= ls[j]) lsaux[posaux++] = ls[i++];
        else {
            lsaux[posaux++] = ls[j++];
            (*trocas) += meio - i;
        }
    }
    while (i < meio) lsaux[posaux++] = ls[i++];
    while (j < tamanho) lsaux[posaux++] = ls[j++];
    for (i = 0; i < tamanho; i++) ls[i] = lsaux[i];
    free(lsaux);
}

void quickSort(tipo_lista *ls, unsigned long long *trocas, double *tempo) {
    *trocas = 0;
    quickSortAux(ls->vet_lista, 0, ls->cont - 1, trocas);
}

void quickSortAux(int *ls, int inicio, int fim, unsigned long long *trocas) {
    if (inicio < fim) {
        int pivo = ls[fim], i = inicio - 1, aux;
        for (int j = inicio; j < fim; j++) {
            if (ls[j] <= pivo) {
                i++;
                aux = ls[i];
                ls[i] = ls[j];
                ls[j] = aux;
                if (i != j) (*trocas)++;
            }
        }
        aux = ls[i + 1];
        ls[i + 1] = ls[fim];
        ls[fim] = aux;
        if (i + 1 != fim) (*trocas)++;
        int pi = i + 1;
        quickSortAux(ls, inicio, pi - 1, trocas);
        quickSortAux(ls, pi + 1, fim, trocas);
    }
}

int main() {
    tipo_lista lista;
    char nome[20];
    int tamanhos[] = {1000, 10000, 100000};
    void (*metodos[])(tipo_lista *, unsigned long long *, double *) = {insertSort, bubbleSort, shellSort, mergeSort, quickSort};
    const char *nomes_metodos[] = {"Insert Sort", "Bubble Sort", "Shell Sort", "Merge Sort", "Quick Sort"};

    FILE *resultado = fopen("resultados.txt", "w"); // Limpa o arquivo de resultados
    fclose(resultado);

    for (int t = 0; t < 3; t++) {
        for (int i = 1; i <= 5; i++) {
            sprintf(nome, "%d-arq%d.txt", tamanhos[t], i);
            carregar_arquivo(&lista, nome);
            for (int m = 0; m < 5; m++) {
                tipo_lista copia = lista;
                executar_teste(&copia, nome, metodos[m], nomes_metodos[m]);
            }
        }
    }

    return 0;
}