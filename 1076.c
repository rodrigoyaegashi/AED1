#include <stdio.h>
#include <string.h>

int adj[50][50];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        
        int V, A;
        
        scanf("%d", &N);

        scanf("%d %d", &V, &A);

        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int arestas_unicas = 0;
        
        for (int i = 0; i < 50; i++) {
            for (int j = i + 1; j < 50; j++) {
                if (adj[i][j] == 1) {
                    arestas_unicas++;
                }
            }
        }

        printf("%d\n", arestas_unicas * 2);
    }

    return 0;
}
