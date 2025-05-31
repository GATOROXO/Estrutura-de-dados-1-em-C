#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_covid.h"

#define TAMANHO_LINHA 1024
#define CAPACIDADE_INICIAL 200

/**
 * @brief Função auxiliar para duplicar uma string
 * @param str String a ser duplicada
 * @return Nova string alocada dinamicamente
 */
char* duplicar_string(const char* str) {
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* nova_str = (char*) malloc(len);
    if (nova_str == NULL) {
        printf("Erro ao alocar memoria para string\n");
        exit(1);
    }
    return memcpy(nova_str, str, len);
}

/**
 * @brief Aloca um novo nó para a lista encadeada
 * @return Ponteiro para o novo nó alocado
 */
lista* aloca_no() {
    lista* novo = (lista*) malloc(sizeof(lista));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para no\n");
        exit(1);
    }
    novo->info.pais = NULL;
    novo->info.regiao_OMS = NULL;
    novo->prox = NULL;
    return novo;
}

/**
 * @brief Libera a memória de uma estrutura de dados
 * @param d Ponteiro para a estrutura data a ser liberada
 */
void liberar_data(data* d) {
    if (d->pais) free(d->pais);
    if (d->regiao_OMS) free(d->regiao_OMS);
}

/**
 * @brief Libera toda a lista encadeada
 * @param l Ponteiro para o início da lista
 */
void liberar_lista(lista* l) {
    while (l) {
        lista* temp = l;
        l = l->prox;
        liberar_data(&temp->info);
        free(temp);
    }
}

/**
 * @brief Carrega os dados do arquivo CSV para uma lista encadeada
 * @param csv_file Nome do arquivo CSV a ser carregado
 * @return Ponteiro para o início da lista encadeada com os dados
 */
lista* carregarcsv(const char* csv_file) {
    FILE* arquivocsv = fopen(csv_file, "r");
    if (!arquivocsv) {
        printf("Erro ao abrir arquivo CSV: %s\n", csv_file);
        return NULL;
    }
    printf("Arquivo aberto com sucesso\n");

    char linha[TAMANHO_LINHA];
    lista* cabeca = NULL;
    lista* atual = NULL;
    int contador = 0;

    // Pular o cabeçalho
    if (fgets(linha, sizeof(linha), arquivocsv) == NULL) {
        printf("Erro ao ler cabecalho do arquivo\n");
        fclose(arquivocsv);
        return NULL;
    }

    // Ler os dados linha por linha
    while (fgets(linha, sizeof(linha), arquivocsv)) {
        lista* novo = aloca_no();
        
        // Usar strtok para separar os campos da linha por vírgulas
        char* token;
        char* resto = linha;
        
        // País (primeiro campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.pais = duplicar_string(token);
            resto = NULL; // Para as próximas chamadas de strtok
        }

        // Casos (segundo campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.casos = atoi(token);
        }

        // Mortes (terceiro campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.mortes = atoi(token);
        }

        // Recuperados (quarto campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.recuperados = atoi(token);
        }

        // Pular campos: Active, New cases, New deaths, New recovered
        for (int i = 0; i < 4; i++) {
            token = strtok(resto, ",");
        }

        // Mortes por 100 casos (nono campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.mortes_por_100_casos = atof(token);
        }

        // Recuperados por 100 casos (décimo campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.recuperados_por_100_casos = atof(token);
        }

        // Mortes por 100 recuperados (décimo primeiro campo)
        token = strtok(resto, ",");
        if (token) {
            novo->info.mortes_por_100_recuperados = atof(token);
        }

        // Pular campos: Confirmed last week, 1 week change, 1 week % increase
        for (int i = 0; i < 3; i++) {
            token = strtok(resto, ",");
        }

        // Região OMS (décimo quinto campo)
        token = strtok(resto, ",");
        if (token) {
            // Remover possível \n no final
            size_t len = strlen(token);
            if (len > 0 && token[len-1] == '\n') {
                token[len-1] = '\0';
            }
            novo->info.regiao_OMS = duplicar_string(token);
        }

        // Adicionar à lista encadeada
        if (cabeca == NULL) {
            cabeca = novo;
            atual = novo;
        } else {
            atual->prox = novo;
            atual = novo;
        }
        contador++;
    }

    fclose(arquivocsv);
    printf("Foram lidos %d registros do arquivo.\n", contador);
    return cabeca;
}

/**
 * @brief Cria um novo heap
 * @param capacidade Capacidade inicial do heap
 * @param tipo Tipo de ordenação: 1=casos, 2=mortes, 3=recuperados
 * @return Ponteiro para o heap criado
 */
heap* criar_heap(int capacidade, int tipo) {
    heap* h = (heap*) malloc(sizeof(heap));
    if (!h) {
        printf("Erro ao alocar memoria para heap\n");
        exit(1);
    }
    h->elementos = (data*) malloc(capacidade * sizeof(data));
    if (!h->elementos) {
        printf("Erro ao alocar memoria para elementos do heap\n");
        free(h);
        exit(1);
    }
    h->tamanho = 0;
    h->capacidade = capacidade;
    h->tipo = tipo;
    return h;
}

/**
 * @brief Destrói o heap liberando sua memória
 * @param h Ponteiro para o heap a ser destruído
 */
void destruir_heap(heap* h) {
    if (h) {
        for (int i = 0; i < h->tamanho; i++) {
            liberar_data(&h->elementos[i]);
        }
        free(h->elementos);
        free(h);
    }
}

/**
 * @brief Compara dois elementos com base no tipo do heap
 * @param a Primeiro elemento a ser comparado
 * @param b Segundo elemento a ser comparado
 * @param tipo Tipo de comparação: 1=casos, 2=mortes, 3=recuperados
 * @return -1 se a < b, 0 se a == b, 1 se a > b
 */
int comparar(data a, data b, int tipo) {
    switch(tipo) {
        case 1: // Casos
            return a.casos < b.casos ? -1 : (a.casos > b.casos ? 1 : 0);
        case 2: // Mortes
            return a.mortes < b.mortes ? -1 : (a.mortes > b.mortes ? 1 : 0);
        case 3: // Recuperados
            return a.recuperados < b.recuperados ? -1 : (a.recuperados > b.recuperados ? 1 : 0);
        default:
            return 0;
    }
}

/**
 * @brief Função heapify para manter a propriedade de heap
 * @param h Ponteiro para o heap
 * @param indice Índice a partir do qual fazer o heapify
 */
void heapify(heap* h, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    // Verifica se o filho da esquerda é maior que o nó atual
    if (esquerda < h->tamanho && comparar(h->elementos[esquerda], h->elementos[maior], h->tipo) > 0) {
        maior = esquerda;
    }

    // Verifica se o filho da direita é maior que o maior até agora
    if (direita < h->tamanho && comparar(h->elementos[direita], h->elementos[maior], h->tipo) > 0) {
        maior = direita;
    }

    // Se o maior não for o nó atual, troca e continua o heapify
    if (maior != indice) {
        data temp = h->elementos[indice];
        h->elementos[indice] = h->elementos[maior];
        h->elementos[maior] = temp;
        heapify(h, maior);
    }
}

/**
 * @brief Insere um elemento no heap
 * @param h Ponteiro para o heap
 * @param elemento Elemento a ser inserido
 */
void inserir_heap(heap* h, data elemento) {
    // Verifica se é necessário aumentar a capacidade do heap
    if (h->tamanho >= h->capacidade) {
        h->capacidade *= 2;
        h->elementos = (data*) realloc(h->elementos, h->capacidade * sizeof(data));
        if (!h->elementos) {
            printf("Erro ao realocar memoria para heap\n");
            exit(1);
        }
    }

    // Insere o elemento na última posição
    h->elementos[h->tamanho] = elemento;
    int i = h->tamanho;
    h->tamanho++;

    // Ajusta o heap para cima (up-heapify)
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (comparar(h->elementos[i], h->elementos[pai], h->tipo) > 0) {
            // Troca o elemento com seu pai se for maior
            data temp = h->elementos[i];
            h->elementos[i] = h->elementos[pai];
            h->elementos[pai] = temp;
            i = pai;
        } else {
            break;
        }
    }
}

/**
 * @brief Extrai o elemento raiz (maior) do heap
 * @param h Ponteiro para o heap
 * @return O elemento raiz extraído
 */
data extrair_raiz(heap* h) {
    if (h->tamanho == 0) {
        data vazio = {0};
        return vazio;
    }

    // Guarda a raiz para retornar
    data raiz = h->elementos[0];
    
    // Move o último elemento para a raiz
    h->elementos[0] = h->elementos[h->tamanho - 1];
    h->tamanho--;

    // Restaura a propriedade de heap
    heapify(h, 0);
    return raiz;
}

/**
 * @brief Constrói um heap a partir de uma lista encadeada
 * @param h Ponteiro para o heap a ser construído
 * @param l Ponteiro para a lista encadeada com os dados
 */
void construir_heap(heap* h, lista* l) {
    lista* atual = l;
    while (atual) {
        // Cria uma cópia dos dados para inserir no heap
        data novo = atual->info;
        // Duplica as strings para evitar problemas de memória
        novo.pais = duplicar_string(atual->info.pais);
        novo.regiao_OMS = duplicar_string(atual->info.regiao_OMS);
        inserir_heap(h, novo);
        atual = atual->prox;
    }
}

/**
 * @brief Exibe os dados de um único registro
 * @param d Dados a serem exibidos
 * @param tipo Tipo de dados sendo visualizado
 */
void exibir_dados(data d, int tipo) {
    printf("\nPais/Regiao: %s\n", d.pais);
    
    if (tipo == 1) {
        printf("Casos: %d (Selecionado)\n", d.casos);
    } else {
        printf("Casos: %d\n", d.casos);
    }
    
    if (tipo == 2) {
        printf("Mortes: %d (Selecionado)\n", d.mortes);
    } else {
        printf("Mortes: %d\n", d.mortes);
    }
    
    if (tipo == 3) {
        printf("Recuperados: %d (Selecionado)\n", d.recuperados);
    } else {
        printf("Recuperados: %d\n", d.recuperados);
    }
    
    printf("Mortes por 100 casos: %.2f%%\n", d.mortes_por_100_casos);
    printf("Recuperados por 100 casos: %.2f%%\n", d.recuperados_por_100_casos);
    printf("Regiao OMS: %s\n", d.regiao_OMS);
}