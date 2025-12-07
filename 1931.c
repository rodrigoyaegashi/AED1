#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CIDADES 10005
#define INFINITO INT_MAX

// Estrutura para representar uma estrada (aresta) na lista de adjacência
typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta* proximo;
} Aresta;

typedef struct {
    int custo;
    int cidade;
    int paridade; 
} Estado;

Aresta* adj[MAX_CIDADES];
int dist[MAX_CIDADES][2]; 

Estado fila_prioridade[MAX_CIDADES * 100]; 
int tamanho_fila = 0;

void adicionar_aresta(int u, int v, int p) {
    Aresta* nova1 = (Aresta*)malloc(sizeof(Aresta));
    nova1->destino = v;
    nova1->peso = p;
    nova1->proximo = adj[u];
    adj[u] = nova1;
    Aresta* nova2 = (Aresta*)malloc(sizeof(Aresta));
    nova2->destino = u;
    nova2->peso = p;
    nova2->proximo = adj[v];
    adj[v] = nova2;
}

void trocar(Estado* a, Estado* b) {
    Estado temp = *a;
    *a = *b;
    *b = temp;
}

void organizar_heap(int idx) {
    int menor = idx;
    int esquerda = 2 * idx + 1;
    int direita = 2 * idx + 2;

    if (esquerda < tamanho_fila && fila_prioridade[esquerda].custo < fila_prioridade[menor].custo)
        menor = esquerda;

    if (direita < tamanho_fila && fila_prioridade[direita].custo < fila_prioridade[menor].custo)
        menor = direita;

    if (menor != idx) {
        trocar(&fila_prioridade[idx], &fila_prioridade[menor]);
        organizar_heap(menor);
    }
}

void inserir_fila(int custo, int cidade, int paridade) {
    int idx = tamanho_fila++;
    fila_prioridade[idx].custo = custo;
    fila_prioridade[idx].cidade = cidade;
    fila_prioridade[idx].paridade = paridade;

    while (idx > 0 && fila_prioridade[(idx - 1) / 2].custo > fila_prioridade[idx].custo) {
        trocar(&fila_prioridade[idx], &fila_prioridade[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

Estado remover_fila() {
    Estado raiz = fila_prioridade[0];
    fila_prioridade[0] = fila_prioridade[--tamanho_fila];
    organizar_heap(0);
    return raiz;
}

int fila_vazia() {
    return tamanho_fila == 0;
}

void dijkstra(int no_inicial, int total_cidades) {
    for (int i = 1; i <= total_cidades; i++) {
        dist[i][0] = INFINITO; 
        dist[i][1] = INFINITO; 
    }

    dist[no_inicial][0] = 0;
    inserir_fila(0, no_inicial, 0);

    while (!fila_vazia()) {
        Estado atual = remover_fila();
        int custo_atual = atual.custo;
        int u = atual.cidade;
        int paridade_atual = atual.paridade;
        
        if (custo_atual > dist[u][paridade_atual]) continue;
        
        Aresta* vizinho = adj[u];
        while (vizinho != NULL) {
            int v = vizinho->destino;
            int peso = vizinho->peso;
            
            int nova_paridade = 1 - paridade_atual; 

            if (dist[u][paridade_atual] + peso < dist[v][nova_paridade]) {
                dist[v][nova_paridade] = dist[u][paridade_atual] + peso;
                inserir_fila(dist[v][nova_paridade], v, nova_paridade);
            }
            vizinho = vizinho->proximo;
        }
    }
}

int main() {
    int C, V;
    
    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (int i = 0; i <= C; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < V; i++) {
        int u, v, custo;
        scanf("%d %d %d", &u, &v, &custo);
        adicionar_aresta(u, v, custo);
    }

    dijkstra(1, C);

    int resultado = dist[C][0];

    if (resultado == INFINITO) {
        printf("-1\n");
    } else {
        printf("%d\n", resultado);
    }

    for (int i = 1; i <= C; i++) {
        Aresta* atual = adj[i];
        while (atual != NULL) {
            Aresta* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    return 0;
}
