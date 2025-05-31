#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Movie.h"

/** @brief Verifica se um filme tem todos os dados necessários
 *  @param filme Filme a ser verificado
 *  @return Verdadeiro se o filme tem todos os dados necessários
 */
int ehFilmeValido(Movie *filme) {
    // Filme deve ter título, ano válido e gênero
    return filme->title[0] != '\0' && 
           filme->year >= 1900 && filme->year <= 2030 &&
           filme->genre[0] != '\0';
}

/** @brief Cria uma nova lista de filmes com alocação dinâmica
 *  @param capacidadeInicial Capacidade inicial do array
 *  @return Lista inicializada ou NULL em caso de erro
 */
MovieList* criarListaFilmes(int capacidadeInicial) {
    MovieList *lista = (MovieList*)malloc(sizeof(MovieList));
    if (!lista) {
        perror("Falha na alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    lista->movies = (Movie*)malloc(capacidadeInicial * sizeof(Movie));
    if (!lista->movies) {
        perror("Falha na alocacao de memoria");
        free(lista);
        exit(EXIT_FAILURE);
    }
    lista->size = 0;
    lista->capacity = capacidadeInicial;
    return lista;
}

// Adiciona um filme à lista, expandindo sua capacidade se necessário
void adicionarFilme(MovieList *lista, Movie filme) {
    // Verifica se o filme tem dados válidos antes de adicionar
    if (!ehFilmeValido(&filme)) {
        return; // Descarta filmes inválidos
    }
    
    if (lista->size >= lista->capacity) {
        lista->capacity *= 2;
        Movie *temp = (Movie*)realloc(lista->movies, lista->capacity * sizeof(Movie));
        if (!temp) {
            perror("Falha na realocacao de memoria");
            exit(EXIT_FAILURE);
        }
        lista->movies = temp;
    }
    lista->movies[lista->size++] = filme;
}

/** @brief Sanitiza uma string, substituindo caracteres não-ASCII por caracteres legíveis 
 *  @param str String a ser sanitizada
 */
void sanitizarString(char* str) {
    if (!str) return;
    
    unsigned char* p = (unsigned char*)str;
    while (*p) {
        // Se for um caractere não imprimível ou fora do intervalo ASCII padrão
        if (*p > 127 || *p < 32) {
            *p = ' '; // Substitui por espaço
        }
        p++;
    }
    
    // Remove espaços múltiplos
    char* src = str;
    char* dst = str;
    char prev = ' ';
    
    while (*src) {
        if (*src != ' ' || prev != ' ') {
            *dst++ = *src;
        }
        prev = *src++;
    }
    *dst = '\0';
    
    // Remove espaços no início e fim
    int len = strlen(str);
    while (len > 0 && str[len-1] == ' ') {
        str[--len] = '\0';
    }
    if (str[0] == ' ') {
        memmove(str, str + 1, strlen(str + 1) + 1);
    }
}

// Função auxiliar para analisar uma linha do arquivo CSV de filmes
int analisarLinhaFilme(const char* linha, Movie* filme) {
    char buffer[1024];
    int pos = 0;

    // Analisa o ID do filme
    if (sscanf(linha, "%d,%n", &filme->movieId, &pos) != 1) {
        return 0;
    }

    // Avança além do movieId
    const char* p = linha + pos;

    // Verifica se o título está entre aspas
    if (*p == '"') {
        p++; // Pula a aspa de abertura
        int i = 0;
        while (*p && *p != '"' && i < sizeof(filme->title) - 1) {
            filme->title[i++] = *p++;
        }
        filme->title[i] = '\0';
        sanitizarString(filme->title); // Sanitiza o título

        if (*p == '"') p++; // Pula a aspa de fechamento
        if (*p == ',') p++; // Pula a vírgula
    } else {
        // Título não está entre aspas
        int i = 0;
        while (*p && *p != ',' && i < sizeof(filme->title) - 1) {
            filme->title[i++] = *p++;
        }
        filme->title[i] = '\0';
        sanitizarString(filme->title); // Sanitiza o título
        
        if (*p == ',') p++; // Pula a vírgula
    }

    // Extração melhorada do ano do título
    filme->year = 0; // Valor padrão
    char* inicioAno = strrchr(filme->title, '(');
    if (inicioAno && inicioAno > filme->title) {
        int ano;
        if (sscanf(inicioAno, "(%d)", &ano) == 1) {
            // Aceita apenas valores de ano razoáveis
            if (ano >= 1900 && ano <= 2030) {
                filme->year = ano;
                *inicioAno = '\0'; // Remove o ano do título

                // Remove espaços no final
                int len = strlen(filme->title);
                while (len > 0 && (filme->title[len-1] == ' ' || filme->title[len-1] == '\t')) {
                    filme->title[--len] = '\0';
                }
            }
        }
    }

    // Copia os gêneros
    strncpy(filme->genre, p, sizeof(filme->genre) - 1);
    filme->genre[sizeof(filme->genre) - 1] = '\0';
    sanitizarString(filme->genre); // Sanitiza o gênero

    return 1;
}

// Carrega filmes dos arquivos CSV e calcula médias das avaliações
void carregarFilmesDoCSV(MovieList *lista, const char *arquivoFilmes, const char *arquivoAvaliacoes) {
    FILE *arquivoFilmesFp = fopen(arquivoFilmes, "r");
    FILE *arquivoAvaliacoesFp = fopen(arquivoAvaliacoes, "r");
    if (!arquivoFilmesFp || !arquivoAvaliacoesFp) {
        printf("Erro ao abrir os arquivos CSV.\n");
        if (arquivoFilmesFp) fclose(arquivoFilmesFp);
        if (arquivoAvaliacoesFp) fclose(arquivoAvaliacoesFp);
        return;
    }

    printf("Lendo arquivos CSV...\n");

    // Arrays temporários para calcular médias
    int maxFilmeId = 500000; // Capacidade máxima para cobrir todos os IDs
    float *somaAvaliacoes = (float*)calloc(maxFilmeId, sizeof(float));
    int *contagemAvaliacoes = (int*)calloc(maxFilmeId, sizeof(int));

    if (!somaAvaliacoes || !contagemAvaliacoes) {
        printf("Erro ao alocar memoria para avaliacoes.\n");
        fclose(arquivoFilmesFp);
        fclose(arquivoAvaliacoesFp);
        if (somaAvaliacoes) free(somaAvaliacoes);
        if (contagemAvaliacoes) free(contagemAvaliacoes);
        return;
    }

    // Ler ratings.csv e calcular soma e contagem
    char linha[4096]; // Para lidar com linhas longas
    fgets(linha, sizeof(linha), arquivoAvaliacoesFp); // Pula cabeçalho

    int avaliacoesProcessadas = 0;
    printf("Processando avaliacoes... ");
    fflush(stdout);
    
    while (fgets(linha, sizeof(linha), arquivoAvaliacoesFp)) {
        int usuarioId, filmeId;
        float avaliacao;
        // Pula a coluna de timestamp
        if (sscanf(linha, "%d,%d,%f,%*d", &usuarioId, &filmeId, &avaliacao) < 3) {
            continue;
        }
        if (filmeId >= 0 && filmeId < maxFilmeId) {
            somaAvaliacoes[filmeId] += avaliacao;
            contagemAvaliacoes[filmeId]++;
            avaliacoesProcessadas++;

            // Atualiza a linha de status (sobrescrevendo a atual)
            if (avaliacoesProcessadas % 10000 == 0) {
                printf("\rProcessando avaliacoes... %d", avaliacoesProcessadas);
                fflush(stdout);
            }
        }
    }
    printf("\rTotal de avaliacoes processadas: %d\n", avaliacoesProcessadas);

    // Ler movies.csv e criar lista
    fgets(linha, sizeof(linha), arquivoFilmesFp); // Pula cabeçalho

    int filmesProcessados = 0;
    int filmesValidos = 0;
    printf("Processando filmes... ");
    fflush(stdout);
    
    while (fgets(linha, sizeof(linha), arquivoFilmesFp)) {
        Movie filme;

        if (analisarLinhaFilme(linha, &filme)) {
            // Calcular média
            if (filme.movieId >= 0 && filme.movieId < maxFilmeId && contagemAvaliacoes[filme.movieId] > 0) {
                filme.avgRating = somaAvaliacoes[filme.movieId] / contagemAvaliacoes[filme.movieId];
            } else {
                filme.avgRating = 0.0;
            }

            // Adicionar filme (a função adicionarFilme já verifica validade)
            adicionarFilme(lista, filme);
            if (ehFilmeValido(&filme)) filmesValidos++;
            filmesProcessados++;

            // Atualiza a linha de status (sobrescrevendo a atual)
            if (filmesProcessados % 100 == 0) {
                printf("\rProcessando filmes... %d", filmesProcessados);
                fflush(stdout);
            }
        }
    }

    printf("\rTotal de filmes processados: %d (Validos: %d)\n", filmesProcessados, filmesValidos);
    printf("Filmes carregados com sucesso.\n");

    fclose(arquivoFilmesFp);
    fclose(arquivoAvaliacoesFp);
    free(somaAvaliacoes);
    free(contagemAvaliacoes);
}

// Exibe os 10 primeiros filmes da lista
void exibirTop10(MovieList *lista) {
    printf("\n===== TOP 10 FILMES =====\n");
    printf("%-4s | %-40s | %-6s | %-8s | %-30s\n",
           "Pos", "Titulo", "Ano", "Nota", "Genero");
    printf("-------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 10 && i < lista->size; i++) {
        printf("%-4d | %-40.40s | %-6d | %-8.2f | %-30.30s\n",
               i+1,
               lista->movies[i].title,
               lista->movies[i].year,
               lista->movies[i].avgRating,
               lista->movies[i].genre);
    }
    printf("-------------------------------------------------------------------------------------\n");
}

// Exibe os 10 primeiros filmes de um array
void exibirTop10Vetor(Movie *filmes, int tamanho) {
    printf("\n===== TOP 10 FILMES =====\n");
    printf("%-4s | %-40s | %-6s | %-8s | %-30s\n",
           "Pos", "Titulo", "Ano", "Nota", "Genero");
    printf("-------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 10 && i < tamanho; i++) {
        printf("%-4d | %-40.40s | %-6d | %-8.2f | %-30.30s\n",
               i+1,
               filmes[i].title,
               filmes[i].year,
               filmes[i].avgRating,
               filmes[i].genre);
    }
    printf("-------------------------------------------------------------------------------------\n");
}

// Libera a memória alocada pela lista de filmes
void liberarListaFilmes(MovieList *lista) {
    free(lista->movies);
    free(lista);
}
