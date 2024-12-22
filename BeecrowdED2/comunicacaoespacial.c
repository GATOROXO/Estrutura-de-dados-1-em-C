#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    int matriz[n][3];  
    
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);
    }

    for (i = 0; i < n; i++) {
        double min_dist = -1;  

        for (j = 0; j < n; j++) {
            if (i != j) {  
                double dist = sqrt(pow(matriz[i][0] - matriz[j][0], 2) +
                                   pow(matriz[i][1] - matriz[j][1], 2) +
                                   pow(matriz[i][2] - matriz[j][2], 2));
                
                
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }
        }

       
        if (min_dist <= 20) {
            printf("A\n");  
        } else if (min_dist <= 50) {
            printf("M\n");  
        } else {
            printf("B\n");  
        }
    }

    return 0;
}
