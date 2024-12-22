#include <stdio.h>

int main() {
    int n, i, pico = 0, vale = 0;
    scanf("%d", &n);
    if (n < 2) {
        printf("0\n");
        return 0;
    }
    int paisagem[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &paisagem[i]);
    }

    if (paisagem[1] == paisagem[0]) {
        printf("0\n");
        return 0;
    } else if (paisagem[1] > paisagem[0]) {
        pico = 1;
    } else {
        vale = 1;
    }

    for (i = 2; i < n; i++) {
        if (paisagem[i] == paisagem[i - 1]) {
            printf("0\n");
            return 0;
        } else if (paisagem[i] > paisagem[i - 1]) {
            if (pico == 1) {
                printf("0\n");
                return 0;
            }
            pico = 1;
            vale = 0;
        } else {
            if (vale == 1) {
                printf("0\n");
                return 0;
            }
            vale = 1;
            pico = 0;
        }
    }
    printf("1\n");
    return 0;
}