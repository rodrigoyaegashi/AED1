#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* novoNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    }
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz == NULL) return;
    printf(" %d", raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void inOrdem(No* raiz) {
    if (raiz == NULL) return;
    inOrdem(raiz->esq);
    printf(" %d", raiz->valor);
    inOrdem(raiz->dir);
}

void posOrdem(No* raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf(" %d", raiz->valor);
}

void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, valor, caso = 1;
    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);
        No* raiz = NULL;

        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso++);
        printf("Pre.:");
        preOrdem(raiz);
        printf("\nIn..:");
        inOrdem(raiz);
        printf("\nPost:");
        posOrdem(raiz);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
