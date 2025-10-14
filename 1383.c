#include <stdio.h>

int main() {
    int n, k, i, j;
    int grid[9][9];
    
    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        int valido = 1;
      
        for (i = 0; i < 9 && valido; i++) {
            int seen[10] = {0};
            for (j = 0; j < 9; j++) {
                int v = grid[i][j];
                if (v < 1 || v > 9 || seen[v]) {
                    valido = 0;
                    break;
                }
                seen[v] = 1;
            }
        }

        for (j = 0; j < 9 && valido; j++) {
            int seen[10] = {0};
            for (i = 0; i < 9; i++) {
                int v = grid[i][j];
                if (v < 1 || v > 9 || seen[v]) {
                    valido = 0;
                    break;
                }
                seen[v] = 1;
            }
        }

        for (int q = 0; q < 9 && valido; q++) {
            int seen[10] = {0};
            int baseR = 3 * (q / 3);
            int baseC = 3 * (q % 3);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    int v = grid[baseR + i][baseC + j];
                    if (v < 1 || v > 9 || seen[v]) {
                        valido = 0;
                        break;
                    }
                    seen[v] = 1;
                }
            }
        }

        printf("Instancia %d\n", k);
        if (valido) printf("SIM\n\n");
        else printf("NAO\n\n");
    }
    return 0;
}
