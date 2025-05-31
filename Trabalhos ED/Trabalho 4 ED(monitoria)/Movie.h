#ifndef MOVIE_H
#define MOVIE_H

// Definição da estrutura para representar um filme
typedef struct {
    int movieId;
    char title[100];
    int year;
    char genre[50];
    float avgRating;
} Movie;

// Definição da estrutura para uma lista de filmes
typedef struct {
    Movie *movies;
    int size;
    int capacity;
} MovieList;

// Opcoes de ordenacao
typedef enum {
    ASCENDING = 0,
    DESCENDING = 1
} SortOrder;

/** @brief Cria uma nova lista de filmes com capacidade inicial especificada */
MovieList* criarListaFilmes(int capacidadeInicial);

/** @brief Adiciona um novo filme à lista */
void adicionarFilme(MovieList *lista, Movie filme);

/** @brief Carrega filmes dos arquivos CSV e calcula médias das avaliações */
void carregarFilmesDoCSV(MovieList *lista, const char *arquivoFilmes, const char *arquivoAvaliacoes);

/** @brief Exibe os 10 primeiros filmes da lista */
void exibirTop10(MovieList *lista);

/** @brief Exibe os 10 primeiros filmes de um array */
void exibirTop10Vetor(Movie *filmes, int tamanho);

/** @brief Libera a memória alocada pela lista de filmes */
void liberarListaFilmes(MovieList *lista);

/** @brief Verifica se um filme tem dados válidos para exibição */
int ehFilmeValido(Movie *filme);

#endif