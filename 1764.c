#include <stdlib.h>

typedef struct {
    int u, v; 
    int w;  
} Aresta;

int pai[40005];

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->w - ((Aresta*)b)->w;
}

int find(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = find(pai[i]);
}

void uniao(int i, int j) {
    int raiz_i = find(i);
    int raiz_j = find(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
    }
}

int main() {
    int M, N;

    while (scanf("%d %d", &M, &N) && (M != 0 || N != 0)) {
        Aresta arestas[50005];

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }

        qsort(arestas, N, sizeof(Aresta), comparar);

        for (int i = 0; i < M; i++) {
            pai[i] = i;
        }

        int custo_total = 0;

        for (int i = 0; i < N; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            int w = arestas[i].w;

            if (find(u) != find(v)) {
                uniao(u, v);
                custo_total += w;
            }
        }

        printf("%d\n", custo_total);
    }

    return 0;
}
