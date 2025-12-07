#include <stdio.h>

int inverter(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

int bfs(int A, int B) {

    int fila[20000];
    int dist[20000] = {0};
    int ini = 0, fim = 0;

    fila[fim++] = A;
    dist[A] = 1;   

    while (ini < fim) {
        int u = fila[ini++];

        if (u == B)
            return dist[u] - 1;   

        int v = u + 1;
        if (v < 20000 && dist[v] == 0) {
            dist[v] = dist[u] + 1;
            fila[fim++] = v;
        }

        v = inverter(u);
        if (v < 20000 && dist[v] == 0) {
            dist[v] = dist[u] + 1;
            fila[fim++] = v;
        }
    }

    return -1; 
}

int main() {
    int T, A, B;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }

    return 0;
}
