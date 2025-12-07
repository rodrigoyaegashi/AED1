#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int NC, N;
    int count[231]; 
    int altura;

    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        if (scanf("%d", &N) != 1) break;

        memset(count, 0, sizeof(count));

        for (int i = 0; i < N; i++) {
            scanf("%d", &altura);
            count[altura]++;
        }

        int primeiro = 1; 
        for (int h = 20; h <= 230; h++) {
            while (count[h] > 0) {
                if (!primeiro) {
                    printf(" ");
                }
                printf("%d", h);
                primeiro = 0;
                count[h]--;
            }
        }
        printf("\n");
    }

    return 0;
}
