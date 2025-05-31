/** 
C.comp
aluno : Joao Paulo
Estrutura de dados 1
Exercicios do BeeCrowd ED 5


*/



#include <stdio.h>
#include <string.h>

int main() {
    int N, D;
    while (scanf("%d %d", &N, &D) == 2 && !(N == 0 && D == 0)) {
        char c[100005], b[100005];
        scanf("%s", c);
        
        int count = 0, size = 0;
        int len = strlen(c);
        
        for (int i = 0; i < len; i++) {
            while (size > 0 && count < D && b[size - 1] < c[i]) {
                count++;
                size--;
            }
            if (size < N - D) {
                b[size++] = c[i];
            }
        }
        b[size] = '\0';
        printf("%s\n", b);
    }
    return 0;
}