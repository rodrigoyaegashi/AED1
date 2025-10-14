#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        int size = n + 5;
        int *queue = malloc(size * sizeof(int));
        int front = 0, back = 0;
        for (int i = 1; i <= n; ++i) {
            queue[back++] = i;
            if (back == size) back = 0;
        }
        int first_print = 1;
        printf("Discarded cards:");
        while ((front + 1) % size != back) { 
            int discarded = queue[front++];
            if (front == size) front = 0;
            if (first_print) {
                printf(" %d", discarded);
                first_print = 0;
            } else {
                printf(", %d", discarded);
            }
            int move = queue[front++];
            if (front == size) front = 0;
            queue[back++] = move;
            if (back == size) back = 0;
        }
        if (first_print) {
            printf("\n");
        } else {
            printf("\n");
        }
        printf("Remaining card: %d\n", queue[front]);
        free(queue);
    }
    return 0;
}

