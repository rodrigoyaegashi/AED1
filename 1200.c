#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char v;
    struct no *esq, *dir;
} No;

No* novo(char v) {
    No *n = malloc(sizeof(No));
    n->v = v;
    n->esq = n->dir = NULL;
    return n;
}

No* insere(No *r, char v) {
    if (r == NULL) return novo(v);
    if (v < r->v) r->esq = insere(r->esq, v);
    else if (v > r->v) r->dir = insere(r->dir, v);
    return r;
}

int busca(No *r, char v) {
    if (r == NULL) return 0;
    if (r->v == v) return 1;
    if (v < r->v) return busca(r->esq, v);
    return busca(r->dir, v);
}

void infixa(No *r, int *f) {
    if (!r) return;
    infixa(r->esq, f);
    if (*f) { printf("%c", r->v); *f = 0; }
    else printf(" %c", r->v);
    infixa(r->dir, f);
}

void prefixa(No *r, int *f) {
    if (!r) return;
    if (*f) { printf("%c", r->v); *f = 0; }
    else printf(" %c", r->v);
    prefixa(r->esq, f);
    prefixa(r->dir, f);
}

void posfixa(No *r, int *f) {
    if (!r) return;
    posfixa(r->esq, f);
    posfixa(r->dir, f);
    if (*f) { printf("%c", r->v); *f = 0; }
    else printf(" %c", r->v);
}

int main() {
    char op[20], c;
    No *raiz = NULL;

    while (scanf("%s", op) != EOF) {

        if (strcmp(op, "I") == 0) {
            scanf(" %c", &c);
            raiz = insere(raiz, c);

        } else if (strcmp(op, "P") == 0) {
            scanf(" %c", &c);
            if (busca(raiz, c)) printf("%c existe\n", c);
            else printf("%c nao existe\n", c);

        } else if (strcmp(op, "INFIXA") == 0) {
            int f = 1;
            infixa(raiz, &f);
            printf("\n");

        } else if (strcmp(op, "PREFIXA") == 0) {
            int f = 1;
            prefixa(raiz, &f);
            printf("\n");

        } else if (strcmp(op, "POSFIXA") == 0) {
            int f = 1;
            posfixa(raiz, &f);
            printf("\n");
        }
    }
    return 0;
}
