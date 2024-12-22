#include <stdio.h>

int main() {
    char nome[120];
    int n, i;
    int totalsaque = 0, totalbloqueio = 0, totalataque = 0;
    int ss = 0, sb = 0, sa = 0;  
    double saque, bloqueio, ataque;

    scanf("%d", &n);
    
    int tentativas[n][3], acertos[n][3];

    
    for (i = 0; i < n; i++) {
        scanf("%s", nome);  
        scanf("%d %d %d", &tentativas[i][0], &tentativas[i][1], &tentativas[i][2]);
        
      
        scanf("%d %d %d", &acertos[i][0], &acertos[i][1], &acertos[i][2]);

        
        totalsaque += tentativas[i][0];
        totalbloqueio += tentativas[i][1];
        totalataque += tentativas[i][2];

        
        ss += acertos[i][0];
        sb += acertos[i][1];
        sa += acertos[i][2];
    }

    
    if (totalsaque > 0) {
        saque = (ss * 100.0) / totalsaque;
    } else {
        saque = 0.0; 
    }

    if (totalbloqueio > 0) {
        bloqueio = (sb * 100.0) / totalbloqueio;
    } else {
        bloqueio = 0.0; 
    }

    if (totalataque > 0) {
        ataque = (sa * 100.0) / totalataque;
    } else {
        ataque = 0.0; 
            }

    
    printf("Pontos de Saque: %.2lf %%.\n", saque);
    printf("Pontos de Bloqueio: %.2lf %%.\n", bloqueio);
    printf("Pontos de Ataque: %.2lf %%.\n", ataque);

    return 0;
}

