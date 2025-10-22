#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha *p, char c) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha *p) {
    if (p->topo != NULL) {
        No *temp = p->topo;
        p->topo = temp->prox;
        free(temp);
    }
}

int pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

int verificaExpressao(char *exp) {
    Pilha p;
    inicializaPilha(&p);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(&p, '(');
        } else if (exp[i] == ')') {
            if (pilhaVazia(&p)) {

                return 0;
            }
            pop(&p);
        }
    }

    int resultado = pilhaVazia(&p);
    while (!pilhaVazia(&p)) pop(&p);
    return resultado;
}

int main() {
    char expressao[1005];
    while (fgets(expressao, sizeof(expressao), stdin)) {
        expressao[strcspn(expressao, "\n")] = '\0';

        if (verificaExpressao(expressao))
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
