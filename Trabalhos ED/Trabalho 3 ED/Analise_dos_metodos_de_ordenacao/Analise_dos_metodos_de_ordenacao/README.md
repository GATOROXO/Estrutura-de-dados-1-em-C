# Analise_computacional_dos_metodos_de_ordenacao


---

UNIVERSIDADE FEDERAL DE MATO GROSSO  
CAMPUS UNIVERSITÁRIO DO ARAGUAIA  
Instituto de Ciências Exatas e da Terra  

Curso de Bacharelado em Ciência da Computação  

Disciplina: Estrutura de Dados I  
Professor: Dr. Ivairton M. Santos  

### Trabalho  

Considere que todas as implementações deste trabalho devem utilizar lista com alocação estática.  

#### Etapa 1: Geração dos dados de entrada  

Implemente um programa que gere os arquivos de entrada para os métodos de ordenação. Este programa irá receber como parâmetro o número de valores que deverão ser gerados e então sortear números inteiros positivos (números pseudo aleatórios) entre 1 e 999.999. O programa deve garantir que não sejam gerados números repetidos. Então gerar um arquivo de saída, contendo a sequência de valores, cada um em uma linha.  

Deverão ser gerados 5 arquivos (sequência de valores) para cada quantidade de valores. Considere as quantidades de valores: 5 arquivos com 1.000 valores; 5 arquivos com 10.000 valores; e 5 arquivos com 100.000 valores. Portanto, ao todo serão utilizados 15 arquivos.  

Sugestão, nomeie os arquivos com o padrão:  
“1000-arq1.txt”, “1000-arq2.txt”, ..., “100000-arq4.txt”, “100000-arq5.txt”  

Lembre-se, estes arquivos serão usados nos testes da etapa seguinte.  

#### Etapa 2: Execução dos testes  

Deverão ser implementados os métodos de ordenação:  

1) Insert Sort  
2) Bubble Sort  
3) Shell Sort  
4) Merge Sort  
5) Quick Sort  

Cada método de ordenação irá processar cada arquivo de valores, produzidos na Etapa1. Portanto, além de ordenar a lista, o método de ordenação deverá retornar as informações de quantas trocas (de posição) foram executadas pelo método de ordenação e o tempo de execução do algoritmo.  

#### Etapa 3: Análise dos resultados  

Faça o registro dos resultados obtidos (quantidade de troca e tempo gasto) pelos métodos de ordenação, para cada arquivo de entrada, e então monte uma tabela comparativa. Nessa tabela registre cada execução e a média dos resultados. A tabela deve obedecer ao modelo:  

**Método de ordenação: Bubble Sort**  

| Entrada          | Num. Trocas | Tempo (s) |
|-----------------|------------|----------|
| 1000-arq1.txt  | nnn        | sss      |
| 1000-arq2.txt  | nnn        | sss      |
| ...            | ...        | ...      |
| 1000-arq5.txt  | nnn        | sss      |
| **MÉDIA**      | **NNN**    | **SSS**  |

Faça uma tabela para cada método de ordenação.  

Analise os dados obtidos e escreva um relatório com suas observações e análises, avaliando o(s) método(s) com melhor e pior desempenho. Discuta a taxa de comparação e troca em relação ao tamanho da entrada e o porquê de cada método ter apresentado determinado resultado.   

---

## Resumo do Conteúdo

Este trabalho envolve a implementação e análise comparativa de cinco algoritmos de ordenação: Insert Sort, Bubble Sort, Shell Sort, Merge Sort e Quick Sort. O objetivo é avaliar a eficiência de cada método em termos de número de trocas e tempo de execução.

### Estrutura do Trabalho
1. **Geração de Dados de Entrada**: Criar arquivos contendo números aleatórios únicos, com diferentes tamanhos (1.000, 10.000 e 100.000 elementos).
2. **Execução dos Testes**: Implementar cada algoritmo de ordenação e registrar o número de trocas e o tempo de execução.
3. **Análise dos Resultados**: Comparar os métodos por meio de tabelas e elaborar um relatório discutindo os desempenhos observados.

Os resultados devem ser organizados em tabelas e um relatório final deve ser enviado com o código-fonte e a análise completa.

