#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 2005

char grafo[MAXN][MAXN];
char transposto[MAXN][MAXN];
bool visitado[MAXN];
int N, M;

void dfs(char g[MAXN][MAXN], int u) {
    visitado[u] = true;
    for (int v = 1; v <= N; v++) {
        if (g[u][v] && !visitado[v]) {
            dfs(g, v);
        }
    }
}

int main() {
    while (scanf("%d %d", &N, &M) && (N != 0 || M != 0)) {
        
        memset(grafo, 0, sizeof(grafo));
        memset(transposto, 0, sizeof(transposto));

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            grafo[u][v] = 1;
            transposto[v][u] = 1;

            if (p == 2) {
                grafo[v][u] = 1;
                transposto[u][v] = 1;
            }
        }

        memset(visitado, 0, sizeof(visitado)); 
        dfs(grafo, 1); 

        int conexo = 1;
        for (int i = 1; i <= N; i++) {
            if (!visitado[i]) {
                conexo = 0;
                break;
            }
        }

        if (!conexo) {
            printf("0\n");
        } else {

            memset(visitado, 0, sizeof(visitado)); 
            dfs(transposto, 1); 

            for (int i = 1; i <= N; i++) {
                if (!visitado[i]) {
                    conexo = 0;
                    break;
                }
            }
            
            printf("%d\n", conexo);
        }
    }

    return 0;
}
