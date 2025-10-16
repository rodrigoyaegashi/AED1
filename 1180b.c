#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

int main() {
    int N;
    scanf("%d", &N);

    struct No* topo = NULL;

    for (int i = 0; i < N; i++) {
        struct No* novo = (struct No*) malloc(sizeof(struct No));
        scanf("%d", &novo->valor);
        novo->prox = topo; 
        topo = novo;      
    }

    int menor, posicao, i = 0;
    struct No* aux = topo;
    menor = aux->valor;
    posicao = 0;

    while (aux != NULL) {
        if (aux->valor < menor) {
            menor = aux->valor;
            posicao = i;
        }
        aux = aux->prox;
        i++;
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", N - 1 - posicao);

    while (topo != NULL) {
        struct No* temp = topo;
        topo = topo->prox;
        free(temp);
    }

    return 0;
}
