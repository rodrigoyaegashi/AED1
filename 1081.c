#include <stdio.h>
#include <string.h>

int V, E;
int adj[25][25];   
int visitado[25];  

void dfs(int u, int depth) {
    visitado[u] = 1; 

    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1) { 
            
            for (int k = 0; k < depth; k++) printf("  ");

            if (!visitado[v]) {
                printf("%d-%d pathR(G,%d)\n", u, v, v);
                dfs(v, depth + 1);
            } else {
                printf("%d-%d\n", u, v);
            }
        }
    }
}

int main() {
    int N, caso = 1;
    scanf("%d", &N); 

    while (N--) {
        scanf("%d %d", &V, &E);

        memset(adj, 0, sizeof(adj));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
        }

        printf("Caso %d:\n", caso++);

        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                int tem_saida = 0;
                for(int j = 0; j < V; j++) {
                    if(adj[i][j]) {
                        tem_saida = 1;
                        break;
                    }
                }

                if (tem_saida) {
                    dfs(i, 1); 
                    printf("\n"); 
                }
                
                visitado[i] = 1; 
            }
        }
    }

    return 0;
}
