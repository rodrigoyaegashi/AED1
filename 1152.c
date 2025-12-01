#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Aresta;

int pai[200000];

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b) {
    pai[find(a)] = find(b);
}

int cmp(const void *a, const void *b) {
    return ((Aresta*)a)->w - ((Aresta*)b)->w;
}

int main() {
    int m, n;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;

        Aresta e[n];
        int total = 0;

        for (int i = 0; i < m; i++) pai[i] = i;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
            total += e[i].w;
        }

        qsort(e, n, sizeof(Aresta), cmp);

        int mst = 0;

        for (int i = 0; i < n; i++) {
            if (find(e[i].u) != find(e[i].v)) {
                join(e[i].u, e[i].v);
                mst += e[i].w;
            }
        }

        printf("%d\n", total - mst);
    }
    return 0;
}
