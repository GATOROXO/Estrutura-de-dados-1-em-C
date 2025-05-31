/**
 * Análise de Dados COVID-19 usando Lista Encadeada e Heap
 * Estrutura de Dados I
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <locale.h>
 
 #define MAX_COUNTRY_NAME 100
 #define MAX_LINE_SIZE 1024
 #define MAX_FIELD_SIZE 256
 
 // Estrutura para armazenar os dados de cada país
 typedef struct {
     char country[MAX_COUNTRY_NAME];
     int confirmed;
     int deaths;
     int recovered;
     int active;
     float deaths_per_100_cases;
     float recovered_per_100_cases;
 } CovidData;
 
 // Nó da lista encadeada
 typedef struct Node {
     CovidData data;
     struct Node* next;
 } Node;
 
 // Lista encadeada
 typedef struct {
     Node* head;
     int size;
 } LinkedList;
 
 // Heap Máximo
 typedef struct {
     CovidData* array;
     int size;
     int capacity;
     int keyType; // 1: confirmed, 2: deaths, 3: recovered
 } MaxHeap;
 
 // Funções para manipulação da lista encadeada
 LinkedList* createLinkedList();
 void insertAtEnd(LinkedList* list, CovidData data);
 void destroyLinkedList(LinkedList* list);
 
 // Funções para manipulação do Heap
 MaxHeap* createMaxHeap(int capacity, int keyType);
 void insertIntoHeap(MaxHeap* heap, CovidData data);
 CovidData extractMax(MaxHeap* heap);
 void heapify(MaxHeap* heap, int idx);
 void destroyHeap(MaxHeap* heap);
 
 // Funções para carregar e processar dados
 LinkedList* loadDataFromCSV(const char* filename);
 void processUserRequest(LinkedList* list);
 void displayHeapData(MaxHeap* heap, int count);
 int getKeyValue(CovidData data, int keyType);
 
 // Função principal
 int main() {
     setlocale(LC_ALL, "Portuguese");
     
     // Parte 1: Carregar dados do CSV para uma lista encadeada
     LinkedList* covidDataList = loadDataFromCSV("country_wise_latest.csv");
     
     if (covidDataList == NULL) {
         printf("Erro ao carregar os dados. Verifique se o arquivo existe.\n");
         return 1;
     }
     
     printf("Dados carregados com sucesso! Total de registros: %d\n\n", covidDataList->size);
     
     // Parte 2-5: Menu principal
     int option;
     do {
         printf("\n====== Sistema de Análise de Dados COVID-19 ======\n");
         printf("1. Visualizar informações\n");
         printf("0. Sair\n");
         printf("Escolha uma opção: ");
         scanf("%d", &option);
         
         switch (option) {
             case 1:
                 processUserRequest(covidDataList);
                 break;
             case 0:
                 printf("Saindo do programa...\n");
                 break;
             default:
                 printf("Opção inválida. Tente novamente.\n");
         }
     } while (option != 0);
     
     // Liberar memória
     destroyLinkedList(covidDataList);
     
     return 0;
 }
 
 /* Implementação das funções da lista encadeada */
 
 LinkedList* createLinkedList() {
     LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
     if (list != NULL) {
         list->head = NULL;
         list->size = 0;
     }
     return list;
 }
 
 void insertAtEnd(LinkedList* list, CovidData data) {
     Node* newNode = (Node*)malloc(sizeof(Node));
     if (newNode == NULL) {
         printf("Erro de alocação de memória\n");
         return;
     }
     
     newNode->data = data;
     newNode->next = NULL;
     
     if (list->head == NULL) {
         list->head = newNode;
     } else {
         Node* current = list->head;
         while (current->next != NULL) {
             current = current->next;
         }
         current->next = newNode;
     }
     
     list->size++;
 }
 
 void destroyLinkedList(LinkedList* list) {
     if (list == NULL) return;
     
     Node* current = list->head;
     Node* next;
     
     while (current != NULL) {
         next = current->next;
         free(current);
         current = next;
     }
     
     free(list);
 }
 
 /* Implementação das funções do Heap Máximo */
 
 MaxHeap* createMaxHeap(int capacity, int keyType) {
     MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
     if (heap == NULL) {
         printf("Erro de alocação de memória para o heap\n");
         return NULL;
     }
     
     heap->array = (CovidData*)malloc(capacity * sizeof(CovidData));
     if (heap->array == NULL) {
         printf("Erro de alocação de memória para o array do heap\n");
         free(heap);
         return NULL;
     }
     
     heap->capacity = capacity;
     heap->size = 0;
     heap->keyType = keyType;
     
     return heap;
 }
 
 int getKeyValue(CovidData data, int keyType) {
     switch (keyType) {
         case 1: return data.confirmed;
         case 2: return data.deaths;
         case 3: return data.recovered;
         default: return data.confirmed;
     }
 }
 
 void insertIntoHeap(MaxHeap* heap, CovidData data) {
     if (heap->size == heap->capacity) {
         printf("Heap está cheio\n");
         return;
     }
     
     // Inserir no final
     int i = heap->size;
     heap->array[i] = data;
     heap->size++;
     
     // Fixar a propriedade do heap (sift up)
     while (i > 0) {
         int parent = (i - 1) / 2;
         
         if (getKeyValue(heap->array[i], heap->keyType) <= getKeyValue(heap->array[parent], heap->keyType)) {
             break;
         }
         
         // Trocar com o pai
         CovidData temp = heap->array[i];
         heap->array[i] = heap->array[parent];
         heap->array[parent] = temp;
         
         i = parent;
     }
 }
 
 CovidData extractMax(MaxHeap* heap) {
     if (heap->size <= 0) {
         CovidData empty;
         memset(&empty, 0, sizeof(CovidData));
         strcpy(empty.country, "Vazio");
         return empty;
     }
     
     if (heap->size == 1) {
         heap->size--;
         return heap->array[0];
     }
     
     // Armazenar o valor máximo e removê-lo
     CovidData root = heap->array[0];
     heap->array[0] = heap->array[heap->size - 1];
     heap->size--;
     
     // Restaurar a propriedade do heap
     heapify(heap, 0);
     
     return root;
 }
 
 void heapify(MaxHeap* heap, int idx) {
     int largest = idx;
     int left = 2 * idx + 1;
     int right = 2 * idx + 2;
     
     // Verificar se o filho esquerdo é maior que o nó atual
     if (left < heap->size && getKeyValue(heap->array[left], heap->keyType) > getKeyValue(heap->array[largest], heap->keyType)) {
         largest = left;
     }
     
     // Verificar se o filho direito é maior que o maior até agora
     if (right < heap->size && getKeyValue(heap->array[right], heap->keyType) > getKeyValue(heap->array[largest], heap->keyType)) {
         largest = right;
     }
     
     // Se o maior não é o nó atual, trocar e continuar heapify
     if (largest != idx) {
         CovidData temp = heap->array[idx];
         heap->array[idx] = heap->array[largest];
         heap->array[largest] = temp;
         
         heapify(heap, largest);
     }
 }
 
 void destroyHeap(MaxHeap* heap) {
     if (heap == NULL) return;
     
     free(heap->array);
     free(heap);
 }
 
 /* Implementação das funções para carregar e processar dados */
 
 LinkedList* loadDataFromCSV(const char* filename) {
     FILE* file = fopen(filename, "r");
     if (file == NULL) {
         printf("Não foi possível abrir o arquivo: %s\n", filename);
         return NULL;
     }
     
     LinkedList* list = createLinkedList();
     if (list == NULL) {
         fclose(file);
         return NULL;
     }
     
     char line[MAX_LINE_SIZE];
     
     // Pular a linha de cabeçalho
     fgets(line, MAX_LINE_SIZE, file);
     
     // Ler os dados
     while (fgets(line, MAX_LINE_SIZE, file)) {
         CovidData data;
         char* token;
         int field = 0;
         
         // Remover o caractere de nova linha
         line[strcspn(line, "\n")] = 0;
         
         // Parse da linha CSV
         token = strtok(line, ",");
         while (token != NULL && field < 8) {
             switch (field) {
                 case 0: // Country/Region
                     strncpy(data.country, token, MAX_COUNTRY_NAME - 1);
                     data.country[MAX_COUNTRY_NAME - 1] = '\0';
                     break;
                 case 1: // Confirmed
                     data.confirmed = atoi(token);
                     break;
                 case 2: // Deaths
                     data.deaths = atoi(token);
                     break;
                 case 3: // Recovered
                     data.recovered = atoi(token);
                     break;
                 case 4: // Active
                     data.active = atoi(token);
                     break;
                 case 7: // Deaths / 100 Cases
                     data.deaths_per_100_cases = atof(token);
                     break;
                 case 8: // Recovered / 100 Cases
                     data.recovered_per_100_cases = atof(token);
                     break;
             }
             
             token = strtok(NULL, ",");
             field++;
         }
         
         // Adicionar à lista
         insertAtEnd(list, data);
     }
     
     fclose(file);
     return list;
 }
 
 void processUserRequest(LinkedList* list) {
     int infoType, count;
     
     printf("\n=== Tipos de informação disponíveis ===\n");
     printf("1. Número de casos de COVID-19\n");
     printf("2. Número de mortes por COVID-19\n");
     printf("3. Número de pessoas recuperadas da COVID-19\n");
     printf("Escolha o tipo de informação (1-3): ");
     scanf("%d", &infoType);
     
     if (infoType < 1 || infoType > 3) {
         printf("Opção inválida. Voltando ao menu principal.\n");
         return;
     }
     
     printf("Quantos registros deseja visualizar? ");
     scanf("%d", &count);
     
     if (count <= 0) {
         printf("Número inválido. Voltando ao menu principal.\n");
         return;
     }
     
     // Limitar o número de registros ao tamanho da lista
     if (count > list->size) {
         count = list->size;
         printf("Ajustando para o máximo disponível: %d registros.\n", count);
     }
     
     // Criar um heap máximo
     MaxHeap* heap = createMaxHeap(list->size, infoType);
     if (heap == NULL) {
         printf("Erro ao criar o heap. Voltando ao menu principal.\n");
         return;
     }
     
     // Transferir dados da lista para o heap
     Node* current = list->head;
     while (current != NULL) {
         insertIntoHeap(heap, current->data);
         current = current->next;
     }
     
     // Exibir os registros
     displayHeapData(heap, count);
     
     // Liberar memória do heap
     destroyHeap(heap);
 }
 
 void displayHeapData(MaxHeap* heap, int count) {
     char infoTypeStr[20];
     
     switch (heap->keyType) {
         case 1:
             strcpy(infoTypeStr, "Casos");
             break;
         case 2:
             strcpy(infoTypeStr, "Mortes");
             break;
         case 3:
             strcpy(infoTypeStr, "Recuperados");
             break;
         default:
             strcpy(infoTypeStr, "Desconhecido");
     }
     
     printf("\n=== Top %d Países/Regiões por %s de COVID-19 ===\n", count, infoTypeStr);
     printf("%-25s %-10s %-10s %-12s %-10s %-15s %-15s\n", 
            "País/Região", "Casos", "Mortes", "Recuperados", "Ativos", 
            "Mortes / 100", "Recup. / 100");
     printf("---------------------------------------------------------------------------------\n");
     
     for (int i = 0; i < count && i < heap->size; i++) {
         CovidData data = extractMax(heap);
         
         printf("%-25s %-10d %-10d %-12d %-10d %-15.2f %-15.2f\n",
                data.country, data.confirmed, data.deaths, data.recovered, data.active,
                data.deaths_per_100_cases, data.recovered_per_100_cases);
     }
 }