#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int preco;
} Aresta;

int pai[70];

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->preco - ((Aresta*)b)->preco;
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
    int R, C;
    
    if (scanf("%d %d", &R, &C) != 2) return 0;

    Aresta arestas[205]; 

    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].preco);
    }

    qsort(arestas, C, sizeof(Aresta), comparar);

    for (int i = 1; i <= R; i++) {
        pai[i] = i;
    }

    int custo_total = 0;
    int cabos_usados = 0;

    for (int i = 0; i < C; i++) {
        if (find(arestas[i].u) != find(arestas[i].v)) {
            uniao(arestas[i].u, arestas[i].v);
            custo_total += arestas[i].preco;
            cabos_usados++;
            
            if (cabos_usados == R - 1) break; 
        }
    }

    printf("%d\n", custo_total);

    return 0;
}
