/** 
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 5


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[60];
    struct Node* next;
} Node;

Node* insertAtEnd(Node* head, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return head;
}

Node* findNode(const char* name, Node* head) {
    Node* node = head;
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void printList(Node* head) {
    Node* node = head;
    while (node != NULL) {
        printf("%s", node->name);
        node = node->next;
        if (node != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char list_L[1000], list_N[1000], friend_S[60];
    Node* head = NULL;
    
    fgets(list_L, sizeof(list_L), stdin);
    list_L[strcspn(list_L, "\n")] = 0;
    
    char* token = strtok(list_L, " ");
    while (token != NULL) {
        head = insertAtEnd(head, token);
        token = strtok(NULL, " ");
    }
    
    fgets(list_N, sizeof(list_N), stdin);
    list_N[strcspn(list_N, "\n")] = 0;
    
    scanf("%s", friend_S);
    
    if (strcmp(friend_S, "nao") == 0) {
        token = strtok(list_N, " ");
        while (token != NULL) {
            head = insertAtEnd(head, token);
            token = strtok(NULL, " ");
        }
    } else {
        Node* prev = NULL;
        Node* current = head;
        while (current != NULL && strcmp(current->name, friend_S) != 0) {
            prev = current;
            current = current->next;
        }
        
        token = strtok(list_N, " ");
        while (token != NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            strcpy(newNode->name, token);
            
            if (prev == NULL) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
            prev = newNode;
            token = strtok(NULL, " ");
        }
    }
    
    printList(head);
    freeList(head);
    
    return 0;
}