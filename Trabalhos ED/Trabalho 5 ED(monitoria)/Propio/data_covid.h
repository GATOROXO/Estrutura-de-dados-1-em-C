#ifndef DATA_COVID_H
#define DATA_COVID_H

/**
 * @brief Estrutura para armazenar os dados de COVID-19 de cada país
 */
struct est_data_covid {
    char* pais;
    int casos;
    int mortes;
    int recuperados;
    float mortes_por_100_casos;
    float recuperados_por_100_casos;
    float mortes_por_100_recuperados;
    char* regiao_OMS;
};
typedef struct est_data_covid data;

/**
 * @brief Estrutura de nó para lista encadeada que armazena dados de países
 */
typedef struct lista {
    data info;
    struct lista* prox;
} lista;

/**
 * @brief Estrutura do heap para ordenar os dados
 */
typedef struct heap {
    data* elementos;     // Vetor de elementos do tipo data
    int tamanho;         // Número atual de elementos no heap
    int capacidade;      // Capacidade máxima do heap
    int tipo;            // Tipo de ordenação: 1=casos, 2=mortes, 3=recuperados
} heap;

/**
 * @brief Protótipos das funções para operações com lista encadeada
 */
lista* aloca_no();
lista* carregarcsv(const char* arquivo);
void liberar_lista(lista* l);

/**
 * @brief Protótipos das funções para operações com heap
 */
heap* criar_heap(int capacidade, int tipo);
void destruir_heap(heap* h);
void inserir_heap(heap* h, data elemento);
data extrair_raiz(heap* h);
void heapify(heap* h, int indice);
void construir_heap(heap* h, lista* l);
void exibir_dados(data d, int tipo);

/**
 * @brief Função utilitária para liberar uma estrutura de dados
 */
void liberar_data(data* d);

#endif // DATA_COVID_H