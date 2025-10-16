#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *vetor = (int*) malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    int menor = vetor[0];
    int posicao = 0;

    for (int i = 1; i < N; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free(vetor);

    return 0;
}
