#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 605

bool barreira_h[MAX][MAX];
bool barreira_v[MAX][MAX];
bool visitado[MAX][MAX];

typedef struct { int r, c; } Ponto;
Ponto fila[MAX * MAX];

int N;
int linhas_grade, cols_grade;

void bfs(int r_ini, int c_ini) {
    int inicio = 0, fim = 0;
    fila[fim++] = (Ponto){r_ini, c_ini};
    visitado[r_ini][c_ini] = true;

    while (inicio < fim) {
        Ponto p = fila[inicio++];
        int r = p.r;
        int c = p.c;

        if (r > 0 && !barreira_h[r-1][c] && !visitado[r-1][c]) {
            visitado[r-1][c] = true;
            fila[fim++] = (Ponto){r-1, c};
        }
        if (r < linhas_grade - 1 && !barreira_h[r][c] && !visitado[r+1][c]) {
            visitado[r+1][c] = true;
            fila[fim++] = (Ponto){r+1, c};
        }
        if (c > 0 && !barreira_v[r][c-1] && !visitado[r][c-1]) {
            visitado[r][c-1] = true;
            fila[fim++] = (Ponto){r, c-1};
        }
        if (c < cols_grade - 1 && !barreira_v[r][c] && !visitado[r][c+1]) {
            visitado[r][c+1] = true;
            fila[fim++] = (Ponto){r, c+1};
        }
    }
}

int main() {
    char buffer[MAX];

    while (scanf("%d", &N) != EOF) {
        linhas_grade = 2 * N;
        cols_grade = 2 * N + 1;
        for (int i = 0; i <= linhas_grade; i++) {
            for (int j = 0; j <= cols_grade; j++) {
                barreira_h[i][j] = false;
                barreira_v[i][j] = false;
                visitado[i][j] = false;
            }
        }

        for (int i = 1; i <= 2 * N - 1; i++) {
            scanf("%s", buffer);
            for (int j = 0; j < N; j++) {
                char tipo = buffer[j];
                int r = i; 
                int c = (i % 2 != 0) ? (2 * (j + 1) - 1) : (2 * (j + 1));
                if (tipo == 'H') {
                    barreira_h[r-1][c-1] = true;
                    barreira_h[r-1][c] = true;
                } else { 
                    barreira_v[r-1][c-1] = true;
                    barreira_v[r][c-1] = true;
                }
            }
        }

        int componentes = 0;
        for (int i = 0; i < linhas_grade; i++) {
            for (int j = 0; j < cols_grade; j++) {
                if (!visitado[i][j]) {
                    componentes++;
                    bfs(i, j);
                }
            }
        }

        printf("%d\n", componentes - 1);
    }
    return 0;
}
