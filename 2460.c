#include <stdio.h>
#include <string.h>

#define MAX_ID 100005
#define MAX_N 50005

int fila_inicial[MAX_N];
int saiu[MAX_ID];

int main() {
    int N, M, id;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila_inicial[i]);
    }

    memset(saiu, 0, sizeof(saiu));

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &id);
        saiu[id] = 1; 
    }

    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        int pessoa = fila_inicial[i];
        
        if (!saiu[pessoa]) {
            if (!primeiro) printf(" "); 
            printf("%d", pessoa);
            primeiro = 0;
        }
    }
    printf("\n");

    return 0;
}
