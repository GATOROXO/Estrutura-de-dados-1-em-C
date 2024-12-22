/**
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd

Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo.
 A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
unsigned int hi,mi,hf,mf;
int Htotal,Mtotal;

scanf("%d %d %d %d",&hi,&mi,&hf,&mf);
if(hi>23 || hf>23 || mi>59 || mf>59){
    return 0;
}
Htotal=hf-hi;
Mtotal=mf-mi;

if(hi==hf && mi==mf){
    Htotal=24;
    Mtotal=0;
}
if(Mtotal < 0){
    Mtotal+=60;
    Htotal-=1;
}
if(Htotal<0){
    Htotal+=24;
}

printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",Htotal,Mtotal);
return 0;
}


