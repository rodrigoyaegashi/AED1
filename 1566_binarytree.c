#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int altura;
    int quantidade; 
    struct No *esq;
    struct No *dir;
} No;

No* criar_no(int h) {
    No* novo = (No*)malloc(sizeof(No));
    novo->altura = h;
    novo->quantidade = 1; 
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int h) {
    if (raiz == NULL) {
        return criar_no(h);
    }

    if (h == raiz->altura) {
        raiz->quantidade++; 
    } else if (h < raiz->altura) {
        raiz->esq = inserir(raiz->esq, h);
    } else {
        raiz->dir = inserir(raiz->dir, h);
    }
    
    return raiz;
}

int primeiro;

void em_ordem(No* raiz) {
    if (raiz == NULL) return;

    em_ordem(raiz->esq);

    for (int i = 0; i < raiz->quantidade; i++) {
        if (!primeiro) printf(" ");
        printf("%d", raiz->altura);
        primeiro = 0;
    }

    em_ordem(raiz->dir);
}

void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

int main() {
    int NC; 
    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        int N, h;
        if (scanf("%d", &N) != 1) break;

        No* raiz = NULL;

        for (int i = 0; i < N; i++) {
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        primeiro = 1;
        em_ordem(raiz);
        printf("\n");

        liberar_arvore(raiz);
    }

    return 0;
}
