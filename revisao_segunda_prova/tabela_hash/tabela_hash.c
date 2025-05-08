#include "tabela_hash.h"

// Inicializa a tabela hash, definindo todos os slots como NULL
void tabela_hash_inicializar(TabelaHash* th) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        th->baldes[i] = NULL; // Inicializa cada slot (balde) com NULL
    }
}

// Cria um novo nó com a chave e o valor fornecidos
NoHash* no_hash_criar(int chave, int valor) {
    NoHash* novo_no = (NoHash*)malloc(sizeof(NoHash)); // Aloca memória para o nó
    novo_no->chave = chave;    // Atribui a chave
    novo_no->valor = valor;    // Atribui o valor
    novo_no->proximo = NULL;   // Inicializa o ponteiro para o próximo nó como NULL
    return novo_no;            // Retorna o novo nó criado
}

// Função hash simples: calcula o índice para a chave
int funcao_hash(int chave) {
    return chave % TAMANHO_TABELA; // Retorna o índice baseado no resto da divisão
}

// Insere um novo par chave-valor na tabela hash
void tabela_hash_inserir(TabelaHash* th, int chave, int valor) {
    int indice = funcao_hash(chave); // Calcula o índice do balde baseado na chave
    if (tabela_hash_buscar(th, chave) == NULL) { // Verifica se a chave já existe
        NoHash* novo_no = no_hash_criar(chave, valor); // Cria um novo nó
        novo_no->proximo = th->baldes[indice]; // Aponta para o nó existente no balde
        th->baldes[indice] = novo_no;  // Atualiza o balde para apontar para o novo nó
    } else {
        printf("Erro: Chave %d já existe!\n", chave); // Exibe erro se a chave já estiver na tabela
    }
}

// Remove um elemento da tabela hash pela chave
int tabela_hash_remover(TabelaHash* th, int chave) {
    int indice = funcao_hash(chave); // Calcula o índice do balde
    NoHash* atual = th->baldes[indice]; // Ponteiro para o nó atual
    NoHash* anterior = NULL;           // Ponteiro para o nó anterior

    // Percorre a lista encadeada no balde correspondente
    while (atual != NULL) {
        if (atual->chave == chave) { // Se a chave for encontrada
            int valor_removido = atual->valor; // Armazena o valor a ser removido

            // Se o nó a ser removido não for o primeiro da lista
            if (anterior == NULL) {
                th->baldes[indice] = atual->proximo; // Atualiza a raiz do balde
            } else {
                anterior->proximo = atual->proximo;  // Desencadeia o nó removido
            }

            free(atual); // Libera a memória do nó removido
            return valor_removido; // Retorna o valor removido
        }
        // Avança para o próximo nó
        anterior = atual;
        atual = atual->proximo;
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Busca um elemento na tabela hash pela chave
NoHash* tabela_hash_buscar(TabelaHash* th, int chave) {
    int indice = funcao_hash(chave); // Calcula o índice do balde
    NoHash* atual = th->baldes[indice]; // Ponteiro para o nó atual

    while (atual) { // Percorre a lista encadeada no balde
        if (atual->chave == chave) { // Se a chave for encontrada
            return atual; // Retorna o nó encontrado
        }
        atual = atual->proximo; // Avança para o próximo nó
    }
    return NULL; // Retorna NULL se a chave não for encontrada
}

// Imprime o conteúdo de toda a tabela hash
void tabela_hash_imprimir(TabelaHash* th) {
    printf("\nTabela Hash:\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) { // Itera sobre todos os slots
        printf("[Posição %2d]: ", i);
        NoHash* atual = th->baldes[i]; // Ponteiro para o nó atual
        while (atual) { // Percorre a lista encadeada
            printf("(%d: %d) → ", atual->chave, atual->valor); // Imprime a chave e o valor
            atual = atual->proximo; // Avança para o próximo nó
        }
        printf("NULL\n"); // Indica o final da lista
    }
}

// Libera toda a memória alocada para a tabela hash
void tabela_hash_destruir(TabelaHash* th) {
    for (int i = 0; i < TAMANHO_TABELA; i++) { // Itera sobre todos os slots
        NoHash* atual = th->baldes[i]; // Ponteiro para o nó atual
        while (atual) { // Percorre a lista encadeada
            NoHash* temp = atual; // Armazena o nó atual
            atual = atual->proximo; // Avança para o próximo nó
            free(temp); // Libera a memória do nó atual
        }
    }
}
