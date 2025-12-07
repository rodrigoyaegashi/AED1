#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000005

typedef struct No {
    struct No *filhos[2]; 
    int eh_fim;          
} No;

No* criarNo() {
    No* n = (No*)malloc(sizeof(No));
    n->filhos[0] = NULL;
    n->filhos[1] = NULL;
    n->eh_fim = 0;
    return n;
}

int inserir(No* raiz, char* s) {
    No* atual = raiz;
    int i = 0;
    
    while (s[i] != '\0') {
        int indice;
        if (s[i] == '(') {
            indice = 0;
        } else if (s[i] == ')') {
            indice = 1;
        } else {
            i++; 
            continue;
        }

        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        
        atual = atual->filhos[indice];
        i++;
    }

    if (atual->eh_fim) {
        return 0; 
    } else {
        atual->eh_fim = 1; 
        return 1;
    }
}

char buffer[MAX_SIZE];

int main() {
    No* raiz = criarNo();
    int contagem = 0;
    while (scanf("%s", buffer) != EOF) {
        contagem += inserir(raiz, buffer);
    }

    printf("%d\n", contagem);

    return 0;
}
