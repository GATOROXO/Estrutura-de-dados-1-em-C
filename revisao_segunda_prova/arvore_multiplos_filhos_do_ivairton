#include "arv_m_filhos.h" // Inclui o cabeçalho que contém a struct tipo_no e protótipos

// Função: aloca_no
// Aloca e inicializa um novo nó da árvore. Define o primeiro valor (chave e dado) e inicializa todos os ponteiros dos filhos com NULL.
tipo_no *aloca_no(int chave, void *dado) {
    tipo_no *no = (tipo_no *)malloc(sizeof(tipo_no)); // Aloca memoria para um tipo_no e converte para tipo_no*
    if (no == NULL) {
        printf("[ERRO] Falha na alocacao do no\n");
        exit(EXIT_FAILURE);
    }
    no->cont = 1;                    // Define que este nó começa com 1 chave armazenada
    no->chaves[0] = chave;           // Atribui a chave recebida na primeira posição
    no->dados[0] = dado;             // Salva o ponteiro genérico, associando-o à chave
    for (int i = 0; i < (T + 1); i++) {
        no->filhos[i] = NULL;        // Inicializa todos os ponteiros dos filhos com NULL
    }
    return no; // Retorna o novo nó alocado
}

// Função: insere_no
// Insere uma nova chave/dado na árvore. Se o nó atual estiver com espaço (menor que T chaves),
// insere em ordem (deslocando para a direita conforme necessário); senão, faz inserção recursiva no filho adequado.
tipo_no *insere_no(tipo_no *arv, int chave, void *dado) {
    int i;
    if (arv == NULL) {
        return aloca_no(chave, dado); // Se a arvore está vazia, cria nó novo
    }
    if (arv->cont < T) {
        i = arv->cont; // i será usado para "deslocar" chaves e dados, abrindo espaço
        // Desloca elementos para manter a ordenação: encontra a posição correta
        while (i > 0 && chave < arv->chaves[i - 1]) {
            arv->chaves[i] = arv->chaves[i - 1];   // Move a chave maior para a direita
            arv->dados[i] = arv->dados[i - 1];     // Move o dado correspondente para a direita
            i--;                                   // Decrementa i para continuar abrindo espaço
        }
        // Insere a nova chave e dado na posição encontrada
        arv->chaves[i] = chave;   // Insere a nova chave na posição correta
        arv->dados[i] = dado;     // Insere o dado correspondente
        arv->cont++;              // Incrementa o contador de chaves
        return arv;               // Retorna a árvore (nó atualizado)
    } else { // Nó cheio: insere recursivamente no filho adequado
        i = 0;
        while (i < arv->cont && chave > arv->chaves[i]) i++;
        arv->filhos[i] = insere_no(arv->filhos[i], chave, dado); // Insere recursivamente no filho certo
        return arv;
    }
}

// Função: imprime_pre_ordem
// Imprime o nó atual (com todas suas chaves e dados usando a função de impressão genérica print_dado)
// e, em seguida, imprime recursivamente todos os filhos (pré-ordem).
void imprime_pre_ordem(tipo_no *no, void (*print_dado)(void *)) {
    if (no != NULL) {
        printf("[ ");                      // Início da impressão do nó atual
        for (int i = 0; i < no->cont; i++) {
            printf("(%d/", no->chaves[i]); // Imprime a chave na posição i
            print_dado(no->dados[i]);      // Chama a função de impressão de dados fornecida
            printf(") ");
        }
        printf("]\n");                    // Fecha a impressão do nó
        for (int i = 0; i <= no->cont; i++) {
            imprime_pre_ordem(no->filhos[i], print_dado); // Chama recursivamente para os filhos
        }
    }
}

// Função: imprime_pos_ordem
// Primeiro imprime recursivamente pelos filhos, depois imprime as chaves e dados do nó atual.
void imprime_pos_ordem(tipo_no *no, void (*print_dado)(void *)) {
    if (no != NULL) {
        for (int i = 0; i <= no->cont; i++) {
            imprime_pos_ordem(no->filhos[i], print_dado); // Primeiro imprime os filhos
        }
        printf("[ ");
        for (int i = 0; i < no->cont; i++) {
            printf("(%d/", no->chaves[i]); // Depois imprime a chave atual
            print_dado(no->dados[i]);      // E o dado correspondente
            printf(") ");
        }
        printf("]\n");
    }
}

// Função: imprime_em_ordem
// Imprime recursivamente o filho à esquerda, depois o dado atual e então o filho à direita para cada posição.
void imprime_em_ordem(tipo_no *no, void (*print_dado)(void *)) {
    if (no != NULL) {
        // Para cada posição i, imprime recursivamente a subárvore esquerda, depois a chave i, depois a subárvore direita
        for (int i = 0; i < no->cont; i++) {
            imprime_em_ordem(no->filhos[i], print_dado);     // Esquerda
            printf("(%d/", no->chaves[i]);                    // Imprime a chave
            print_dado(no->dados[i]);                         // E o dado
            printf(") ");
        }
        imprime_em_ordem(no->filhos[no->cont], print_dado);   // Imprime a subárvore do último filho
    }
}

// Função: busca_dado
// Localiza a posição no vetor de chaves onde a chave deve estar; se encontrada, retorna o dado (void*).
// Senão, chama recursivamente em o filho na posição certa.
void *busca_dado(tipo_no *no, int chave) {
    // Verifica se o nó é nulo; se for, não encontra a chave
    int i;
    if (no == NULL) {
        return NULL; // Se chegou em NULL, significa que não encontrou a chave
    }
    // Loop para avançar enquanto 'chave' for maior que as chaves armazenadas
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++);
    // Se a chave coincide, retorna o dado correspondente
    if (i < no->cont && chave == no->chaves[i]) {
        return no->dados[i]; // Se encontrou a chave, retorna o dado anexo
    } else {
        // Caso contrário, desce recursivamente ao filho i
        return busca_dado(no->filhos[i], chave); // Segue para o filho adequado
    }
}

// Função: busca_no
// Procura e retorna o nó onde a chave está presente; se não localizada, retorna NULL.
tipo_no *busca_no(tipo_no *no, int chave) {
    // Se chegou a um nó nulo, não há nada para buscar
    if (no == NULL) {
        return NULL;
    }
    int i;
    // Avança pelo vetor de chaves do nó enquanto a chave atual for maior que as registradas
    // Isso localiza a posição "i" onde a chave desejada poderia estar ou o filho a seguir
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++);

    // Se a posição i ainda está dentro do número de chaves e encontramos a chave, retornamos este nó
    if (i < no->cont && chave == no->chaves[i]) {
        return no;
    } else {
        // Se não, desce no filho "i" para continuar a busca de forma recursiva
        return busca_no(no->filhos[i], chave);
    }
}

// Função: total_nos
// Conta recursivamente todos os nós da árvore.
int total_nos(tipo_no *no) {
    int i, total = 0;
    if (no != NULL) {
        total++; // Conta o próprio nó
        for (i = 0; i <= no->cont; i++) {
            total += total_nos(no->filhos[i]); // Soma recursivamente a quantidade de nós nos filhos
        }
    }
    return total;
}

// Função: total_folhas
// Conta quantas folhas (nós sem filhos) existem na árvore.
int total_folhas(tipo_no *no) {
    int i, flag = 1, total = 0;
    if (no != NULL) {
        for (i = 0; i <= no->cont; i++) {
            if (no->filhos[i] != NULL) {
                flag = 0; // Se algum filho existir, este nó não é folha
                total += total_folhas(no->filhos[i]); // Soma folhas dos filhos
            }
        }
        return flag ? 1 : total; // Se flag permaneceu 1, significa que é folha
    }
    return 0;
}

// Função: verifica_folha
// Verifica se o nó que contém a chave informada é folha (ou seja, todos os filhos são NULL).
int verifica_folha(tipo_no *no, int chave) {
    int i, flag = 1;
    if (no == NULL) {
        return 0; // Se a árvore acabou, chave não existe
    }
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++);
    if (i < no->cont && chave == no->chaves[i]) {
        for (int j = 0; j <= no->cont; j++) {
            if (no->filhos[j] != NULL) {
                flag = 0;
                break;
            }
        }
        return flag; // Se encontrou a chave, verifica se todos os filhos são NULL
    } else {
        return verifica_folha(no->filhos[i], chave); // Se não encontrou, continue recursão
    }
}

// Função: altura_arvore
// Retorna a altura da árvore (o caminho mais longo da raiz até uma folha)
int altura_arvore(tipo_no *no) {
    int i, altura = 0, h;
    if (no != NULL) {
        for (i = 0; i <= no->cont; i++) {
            h = altura_arvore(no->filhos[i]); // Calcula a altura do filho i
            if (h > altura) {
                altura = h; // Fica com o maior valor de altura
            }
        }
        return altura + 1; // Soma 1 para contar o nível do nó atual
    }
    return -1; // Altura de árvore vazia
}

// Função: imprime_arv_nivel
// Imprime a árvore nível a nível, chamando imprime_nivel para cada nível
void imprime_arv_nivel(tipo_no *no) {
    // Calcula a altura da árvore para saber quantos níveis percorrer
    int h = altura_arvore(no); // Pega a altura da árvore
    for (int i = 0; i < h; i++) {
        // Para cada nível, imprime as chaves encontradas nesse nível
        printf("Nivel %d: ", i);      
        imprime_nivel(no, i);        // Imprime nós que estão nesse nível
        printf("\n");
    }
}

// Função: imprime_nivel
// Imprime os nós que estão exatamente no nível especificado
void imprime_nivel(tipo_no *no, int nivel) {
    if (no != NULL) {
        if (nivel == 0) {
            // Se já estamos no nível buscado, imprime as chaves do nó
            printf("[ ");
            for (int i = 0; i < no->cont; i++) {
                printf("%d ", no->chaves[i]);
            }
            printf("] ");
        } else {
            // Se não estamos no nível ainda, desce um nível nos filhos
            for (int i = 0; i <= no->cont; i++) {
                imprime_nivel(no->filhos[i], nivel - 1);
            }
        }
    }
}

// Função: contabiliza_no_por_nivel
// Conta quantos nós existem em um dado nível da árvore
int contabiliza_no_por_nivel(tipo_no *no, int nivel) {
    int total = 0;
    if (no != NULL) {
        if (nivel == 0) {
            return 1; // Se chegou no nível exato, conta este nó
        } else {
            for (int i = 0; i <= no->cont; i++) {
                total += contabiliza_no_por_nivel(no->filhos[i], nivel - 1); // Soma recursivamente nos filhos, decrementando o nível
            }
        }
    }
    return total;
}

// Função: busca_maior
// Retorna o maior elemento (a maior chave) de um nó, procurando recursivamente o filho mais à direita.
int busca_maior(tipo_no *no) {
    // Se o nó não for nulo, verifica se existe filho na última posição
    if (no != NULL) {
        // Se existir, desce recursivamente para encontrar o maior
        if (no->filhos[no->cont] != NULL) {
            return busca_maior(no->filhos[no->cont]); // Retorna a maior chave descendo sempre para o último filho até não poder mais
        }
        // Se não, a chave final do nó atual é a maior
        return no->chaves[no->cont - 1]; // Se chegou ao final, pega a última chave
    }
    return -1; // Se no é NULL
}

// Função: busca_menor
// Retorna o menor elemento (a menor chave) de um nó, procurando recursivamente o filho mais à esquerda.
int busca_menor(tipo_no *no) {
    // Se o nó não for nulo, verifica se existe filho na posição 0
    if (no != NULL) {
        // Se existir, chama 'busca_maior' no filho 0 (comportamento definido no código original)
        if (no->filhos[0] != NULL) {
            return busca_maior(no->filhos[0]); // Observação: o código usa busca_maior no filho 0
        }
        // Se não, a chave inicial do nó é a menor
        return no->chaves[0];
    }
    return -1; // Se no é NULL
}

// Função: imprime_rota
// Imprime a rota (caminho) do nó raiz até o nó que contém a chave especificada
void imprime_rota(tipo_no *no, int chave) {
    // Percorre o vetor de chaves para localizar ou passar pelo lugar onde a chave deveria estar
    if (no != NULL) {
        int i;
        for (i = 0; i < no->cont && chave > no->chaves[i]; i++); // Localiza posição provável da chave
        // Se encontrou a chave, imprime a rota acumulada
        if (i < no->cont && chave == no->chaves[i]) {
            printf("Rota: ");
            for (int j = 0; j <= i; j++) {
                printf("%d ", no->chaves[j]);
            }
            printf("\n");
        } else {
            // Caso contrário, desce no filho correspondente
            imprime_rota(no->filhos[i], chave); // Desce ao filho para continuar a busca
        }
    }
}

/**
 * Função: remove_no
 * Propósito: Remover uma chave (e seu dado) do nó e ajustar a árvore para manter a ordenação e integridade.
 * O algoritmo verifica se a chave está no nó atual e, se estiver, determina se o nó é folha ou interno.
 * Se for folha, a chave é removida movendo os elementos posteriores para preencher o espaço.
 * Se for interno, busca-se um valor substituto (predecessor ou sucessor) de um filho ou irmão e recorre à remoção nesse ramo.
 */
tipo_no *remove_no(tipo_no *no, int chave) {
    // Declara variáveis para iteração e armazenamento de valores temporários.
    int i, j, z, flag, aux_vl;
    tipo_no *aux_no;  // Será usado para armazenar um nó auxiliar onde a chave substituta é encontrada.

    // Se o nó atual é NULL, não há nada para remover; retorna NULL.
    if (no == NULL) {
        return NULL;
    }

    // Laço para encontrar a posição 'i' onde a chave deve estar.
    // Enquanto 'chave' for maior que no->chaves[i], incrementa i.
    for (i = 0; i < no->cont && chave > no->chaves[i]; i++);

    // Se a chave foi encontrada no nó atual...
    if (i < no->cont && chave == no->chaves[i]) {
        // Verifica se o nó é folha: flag = 1 se todos os filhos são NULL.
        flag = 1;
        for (int j = 0; j <= no->cont; j++) {
            if (no->filhos[j] != NULL) {  // Se algum filho existir, o nó não é folha.
                flag = 0;
            }
        }
        // Caso 1: Nó folha com apenas uma chave.
        if (flag && no->cont == 1) {
            free(no);         // Libera o nó, pois removendo a única chave, o nó fica vazio.
            return NULL;      // Retorna NULL para indicar a remoção deste nó.
        }
        // Caso 2: Nó folha com mais de uma chave.
        else if (flag && no->cont > 1) {
            // Laço para deslocar (mover para a esquerda) chaves e dados posteriores à posição 'i'.
            for (j = i + 1; j < no->cont; j++) {
                no->chaves[j - 1] = no->chaves[j];  // Move cada chave para a posição anterior.
                no->dados[j - 1] = no->dados[j];      // Move o dado associado.
            }
            no->cont--;         // Reduz o contador, pois uma chave foi removida.
            return no;          // Retorna o nó atualizado.
        }
        // Caso 3: Nó interno (não folha).
        else {
            // Se existe um filho à esquerda da posição 'i', usa o predecessor.
            if (no->filhos[i] != NULL) {
                // Busca o maior valor (predecessor) na subárvore do filho esquerdo.
                aux_vl = busca_maior(no->filhos[i]);
                // Encontra o nó que contém esse valor.
                aux_no = busca_no(no->filhos[i], aux_vl);
                // Laço para encontrar a posição exata da chave aux_vl no nó auxiliar.
                for (z = 0; aux_vl != aux_no->chaves[z]; z++);
                // Substitui a chave (e seu dado) na posição 'i' pelo predecessor.
                no->chaves[i] = aux_no->chaves[z];
                no->dados[i] = aux_no->dados[z];
                // Remove recursivamente a chave substituta do filho esquerdo.
                no->filhos[i] = remove_no(no->filhos[i], aux_vl);
            }
            // Se não há filho à esquerda, mas existe à direita, utiliza o sucessor.
            else if (no->filhos[i+1] != NULL) {
                // Busca o menor valor (sucessor) na subárvore do filho direito.
                aux_vl = busca_menor(no->filhos[i+1]);
                // Encontra o nó que contém esse valor.
                aux_no = busca_no(no->filhos[i+1], aux_vl);
                // Laço para encontrar a posição exata da chave aux_vl no nó auxiliar.
                for (z = 0; aux_vl != aux_no->chaves[z]; z++);
                // Substitui a chave e o dado na posição 'i' pelo sucessor.
                no->chaves[i] = aux_no->chaves[z];
                no->dados[i] = aux_no->dados[z];
                // Remove recursivamente a chave substituta do filho direito.
                no->filhos[i+1] = remove_no(no->filhos[i+1], aux_vl);
            }
            // Se a chave removida não tem filhos diretos para substituição, procura em irmãos.
            else {
                // Primeiro, tenta procurar um filho válido à esquerda:
                for (j = i; (j >= 0 && no->filhos[j] == NULL); j--);
                if (j >= 0) {
                    // Encontrou um irmão à esquerda; usa o maior valor deste irmão.
                    aux_vl = busca_maior(no->filhos[j]);
                    // Desloca as chaves e dados para a direita para "abrir espaço" na posição 'i'.
                    for ( ; i > j; i--) {
                        no->chaves[i] = no->chaves[i-1];
                        no->dados[i] = no->dados[i-1];
                    }
                    // Encontra no irmão a chave substituta.
                    aux_no = busca_no(no->filhos[j], aux_vl);
                    for (z = 0; aux_vl != aux_no->chaves[z]; z++);
                    // Coloca a chave e dado substitutos na posição correta.
                    no->chaves[i] = aux_no->chaves[z];
                    no->dados[i] = aux_no->dados[z];
                    // Remove recursivamente o valor substituto do irmão.
                    no->filhos[j] = remove_no(no->filhos[j], aux_vl);
                }
                // Caso contrário, procura um irmão à direita:
                else {
                    for (j = i; (j <= no->cont && no->filhos[j] == NULL); j++);
                    // Obtém o menor valor (sucessor) do irmão à direita.
                    aux_vl = busca_menor(no->filhos[j]);
                    // Desloca as chaves e dados para a esquerda para preencher o buraco.
                    for ( ; i < j; i++) {
                        no->chaves[i] = no->chaves[i+1];
                        no->dados[i] = no->dados[i+1];
                    }
                    // Encontra no irmão a chave substituta.
                    aux_no = busca_no(no->filhos[j], aux_vl);
                    for (z = 0; aux_vl != aux_no->chaves[z]; z++);
                    // Substitui a chave e dado na posição i.
                    no->chaves[i] = aux_no->chaves[z];
                    no->dados[i] = aux_no->dados[z];
                    // Remove recursivamente o valor substituto do irmão.
                    no->filhos[j] = remove_no(no->filhos[j], aux_vl);
                }
            }
        }
    } 
    // Se a chave não foi encontrada no nó atual, desce recursivamente no filho apropriado.
    else {
        no->filhos[i] = remove_no(no->filhos[i], chave);
    }
    // Retorna o nó atualizado após a remoção.
    return no;
}
