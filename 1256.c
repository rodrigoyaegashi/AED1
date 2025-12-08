#include <stdio.h>
#include <stdlib.h>

typedef struct NoHash {
    int valor;
    struct NoHash* proximo;
} NoHash;

NoHash* tabela[105];

void inserir_hash(int indice, int valor) {
    NoHash* novo = (NoHash*)malloc(sizeof(NoHash));
    novo->valor = valor;
    novo->proximo = NULL;

    if (tabela[indice] == NULL) {
        tabela[indice] = novo;
    } else {
        NoHash* temp = tabela[indice];
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

void limpar_tabela(int M) {
    for (int i = 0; i < M; i++) {
        NoHash* atual = tabela[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        tabela[i] = NULL;
    }
}

int main() {
    int N; 
    scanf("%d", &N);
    int primeiro_caso = 1;

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        for(int i=0; i<M; i++) tabela[i] = NULL;

        for (int i = 0; i < C; i++) {
            int val;
            scanf("%d", &val);
            int idx = val % M; 
            inserir_hash(idx, val);
        }

        if (!primeiro_caso) printf("\n");
        primeiro_caso = 0;

        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            NoHash* atual = tabela[i];
            while (atual != NULL) {
                printf("%d -> ", atual->valor);
                atual = atual->proximo;
            }
            printf("\\\n");
        }

        limpar_tabela(M);
    }

    return 0;
}
