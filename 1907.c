#include <stdio.h>

#define MAX 1024

char imagem[MAX][MAX];
int visitado[MAX][MAX];
int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int filaX[MAX * MAX];
int filaY[MAX * MAX];

void bfs(int x, int y) {
    int ini = 0, fim = 0;

    filaX[fim] = x;
    filaY[fim] = y;
    fim++;

    visitado[x][y] = 1;

    while (ini < fim) {
        int cx = filaX[ini];
        int cy = filaY[ini];
        ini++;

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (!visitado[nx][ny] && imagem[nx][ny] == '.') {
                visitado[nx][ny] = 1;
                filaX[fim] = nx;
                filaY[fim] = ny;
                fim++;
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", imagem[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visitado[i][j] && imagem[i][j] == '.') {
                bfs(i, j);
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
