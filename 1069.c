#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char simb;
    struct No *prox;
} No;

void empilhar(No **topo, char c) {
    No *novo = (No *)malloc(sizeof(No));
    novo->simb = c;
    novo->prox = *topo;
    *topo = novo;
}

int desempilhar(No **topo) {
    if (*topo == NULL)
        return 0; 
    No *temp = *topo;
    *topo = temp->prox;
    free(temp);
    return 1; 
}

void liberarPilha(No **topo) {
    while (*topo != NULL) {
        No *temp = *topo;
        *topo = temp->prox;
        free(temp);
    }
}

int main() {
    int N;
    char linha[1001];
    scanf("%d", &N);
    getchar(); 

    while (N--) {
        fgets(linha, sizeof(linha), stdin);
        No *pilha = NULL;
        int diamantes = 0;

        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == '<') {
                empilhar(&pilha, '<');
            } else if (linha[i] == '>') {
                if (desempilhar(&pilha))
                    diamantes++;
            }
        }

        printf("%d\n", diamantes);
        liberarPilha(&pilha);
    }

    return 0;
}
