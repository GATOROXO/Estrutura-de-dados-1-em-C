/**
C.comp
aluno Joao Paulo
Estrutura de dados 1
Exercicios do dia 12/12/2024

elabore um sistema que registre um aluno(nome , RGA, nota 1 ,nota 2 , media final). O
sistema deve representar tambem uma turma de uma disciplina(nome, codigo , até 40 alunos).
faça o cadastro de aluos e de uma turma. registre as notas 1 e 2 dos alunos, entao calcule a
media final. Ao final imprima quantos alunos foram aprovados e quantos foram reprovados.
calcular a media final entre as medias finais dos alunos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 40

enum tipo_situacao {APROVADO, REPROVADO};

struct tipo_aluno{
    char nome[60];
    unsigned int rga;
    float nota1;
    float nota2;
    float media;
    enum tipo_situacao situacao;
};

struct tipo_turma{
    char nome[60];
    unsigned int codigo;
    int ano;
    int qtd_aluno;
};

typedef struct tipo_aluno aluno;
typedef struct tipo_turma turma;

int main(){
    int i;
    struct tipo_aluno aluno[TAM];
    turma turma;
        printf("Digite o nome da turma que deseja cadastrar: ");
        scanf("%s", turma[i].nome);
        printf("Digite o codigo da turma: ");
        scanf("%d", &turma[i].codigo);
        printf("Digite o ano da turma: ");
        scanf("%d", &turma[i].ano);

    for(i=0;i<3;i++){
        printf("Digite o nome do aluno %d :",i+1);
        scanf("%s", aluno[i].nome);
        printf("Digite o RGA do aluno %d :",i+1);
        scanf("%d", &aluno[i].rga);
        printf("Digite a nota 1 do aluno %d :",i+1);
        scanf("%f", &aluno[i].nota1);
        printf("Digite a nota 2 do aluno %d :",i+1);
        scanf("%f", &aluno[i].nota2);
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2)/2;
    }
    for(i=0;i<3;i++){
        if(aluno[i].media >= 6){
            aluno[i].situacao = APROVADO;
        }
        else{
            aluno[i].situacao = REPROVADO;
        }
    }
    
            printf("Lista de aprovados: \n");
    for(i=0;i<3;i++){
        if(aluno[i].situacao == APROVADO){
            printf("\tturma: %s\n", turma.nome);
            printf("\tano: %d\n", turma.ano);
            printf("\taluno: %s\n", aluno[i].nome);
            printf("\tRGA: %d\n", aluno[i].rga);
            printf("\tNota 1: %.2f\n", aluno[i].nota1);
            printf("\tNota 2: %.2f\n", aluno[i].nota2);
            printf("\tMedia: %.2f\n", aluno[i].media);
            //printf("\tMedia: %.2f\n", turma[i].nome, turma[i].ano, aluno[i].nome, aluno[i].rga, aluno[i].nota1, aluno[i].nota2, aluno[i].media);
        }
    }
    printf("Lista de reprovados: \n");
    for(i=0;i<3;i++){
        if(aluno[i].situacao == REPROVADO){
            printf("\tturma: %s\n", turma.nome);
            printf("\tano: %d\n", turma.ano);
            printf("\taluno: %s\n", aluno[i].nome);
            printf("\tRGA: %d\n", aluno[i].rga);
            printf("\tNota 1: %.2f\n", aluno[i].nota1);
            printf("\tNota 2: %.2f\n", aluno[i].nota2);
            printf("\tMedia: %.2f\n", aluno[i].media);
           // printf("\tMedia: %.2f\n", turma[i].nome, turma[i].ano, aluno[i].nome, aluno[i].rga, aluno[i].nota1, aluno[i].nota2, aluno[i].media);
        }
    }
    system("pause");
    return 0;
    }