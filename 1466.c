#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criarNo(int v) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->esq = novo->dir = NULL;
    return novo;
}
No* inserir(No* raiz, int v) {
    if (raiz == NULL) return criarNo(v);
    
    if (v < raiz->valor)
        raiz->esq = inserir(raiz->esq, v);
    else if (v > raiz->valor)
        raiz->dir = inserir(raiz->dir, v);
        
    return raiz;
}
void bfs(No* raiz) {
    if (raiz == NULL) return;
    No* fila[1000];
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;
    
    int primeiro = 1;

    while (inicio < fim) {
        No* atual = fila[inicio++]; 
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
    printf("\n");
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, valor;
    
    scanf("%d", &C);

    for (int i = 1; i <= C; i++) {
        scanf("%d", &N);
        No* raiz = NULL;

        for (int j = 0; j < N; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        bfs(raiz);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
