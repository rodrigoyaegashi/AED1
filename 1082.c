#include <stdio.h>
#include <string.h>

#define MAX 26

int visitado[MAX];
int adj[MAX][MAX];
int grau[MAX];

char fila[MAX];
int ini, fim;

void bfs(int inicio, char componente[], int *tamComp) {
    ini = fim = 0;

    fila[fim++] = inicio;
    visitado[inicio] = 1;

    while (ini < fim) {
        int u = fila[ini++];

        componente[(*tamComp)++] = 'a' + u;

        for (int i = 0; i < grau[u]; i++) {
            int v = adj[u][i];
            if (!visitado[v]) {
                visitado[v] = 1;
                fila[fim++] = v;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caso = 1; caso <= T; caso++) {

        int V, E;
        scanf("%d %d", &V, &E);

        memset(visitado, 0, sizeof(visitado));
        memset(grau, 0, sizeof(grau));

        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);

            int u = a - 'a';
            int v = b - 'a';

            adj[u][grau[u]++] = v;
            adj[v][grau[v]++] = u;
        }

        printf("Case #%d:\n", caso);

        int componentes = 0;

        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                char comp[30];
                int tam = 0;

                bfs(i, comp, &tam);

                for (int x = 0; x < tam; x++) {
                    for (int y = x + 1; y < tam; y++) {
                        if (comp[y] < comp[x]) {
                            char tmp = comp[x];
                            comp[x] = comp[y];
                            comp[y] = tmp;
                        }
                    }
                }

                for (int x = 0; x < tam; x++) {
                    printf("%c,", comp[x]);
                }
                printf("\n");

                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}
