#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    struct No* proximo;
} No;

#define MAXN 10005

No* grafo[MAXN];   
int visitado[MAXN]; 

void adicionar_aresta(int origem, int destino) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->destino = destino;
    novo_no->proximo = grafo[origem]; 
    grafo[origem] = novo_no;       
}

void liberar_grafo(int N) {
    for (int i = 1; i <= N; i++) {
        No* atual = grafo[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        grafo[i] = NULL;
    }
}

int tem_ciclo(int u) {
    visitado[u] = 1; 

    No* aresta = grafo[u];
    while (aresta != NULL) {
        int v = aresta->destino;

        if (visitado[v] == 1) {
            return 1; 
        }
        
        if (visitado[v] == 0) {
            if (tem_ciclo(v)) return 1; 
        }
        
        aresta = aresta->proximo;
    }

    visitado[u] = 2; 
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            grafo[i] = NULL;    
            visitado[i] = 0;    
        }

        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adicionar_aresta(u, v);
        }

        int flag_ciclo = 0;
        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                if (tem_ciclo(i)) {
                    flag_ciclo = 1;
                    break;
                }
            }
        }

        if (flag_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        liberar_grafo(N);
    }

    return 0;
}
