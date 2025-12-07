#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 255
#define INF 100000000 

int grafo[MAX_N][MAX_N];
int dist[MAX_N];
int visitado[MAX_N];

int main() {
    int N, M, C, K;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grafo[i][j] = INF;
            }
            dist[i] = INF;
            visitado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            
            if (p < grafo[u][v]) { 
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        dist[K] = 0;

        for (int i = 0; i < N; i++) {
            int u = -1;
            int min_val = INF;

            for (int j = 0; j < N; j++) {
                if (!visitado[j] && dist[j] < min_val) {
                    min_val = dist[j];
                    u = j;
                }
            }

            if (u == -1) break; 
            visitado[u] = 1;

            for (int v = 0; v < N; v++) {
                if (grafo[u][v] != INF) {
                    
                    if (u < C - 1) {
                        if (v == u + 1) {
                            if (dist[u] + grafo[u][v] < dist[v]) {
                                dist[v] = dist[u] + grafo[u][v];
                            }
                        }
                    } else {
                        if (dist[u] + grafo[u][v] < dist[v]) {
                            dist[v] = dist[u] + grafo[u][v];
                        }
                    }
                }
            }
        }

        printf("%d\n", dist[C-1]);
    }

    return 0;
}
