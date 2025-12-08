#include <stdio.h>
#include <string.h>

#define MAX 1005

int pilha[MAX], topo;
int fila[MAX], ini_f, fim_f;
int pq[MAX], tam_pq; 

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        topo = 0;
        ini_f = 0; fim_f = 0;
        tam_pq = 0;

        int is_stack = 1, is_queue = 1, is_pq = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                if (is_stack) pilha[topo++] = x;
                if (is_queue) fila[fim_f++] = x;
                if (is_pq) pq[tam_pq++] = x;
            } else {

                if (is_stack) {
                    if (topo == 0 || pilha[--topo] != x) is_stack = 0;
                }

                if (is_queue) {
                    if (ini_f == fim_f || fila[ini_f++] != x) is_queue = 0;
                }

                if (is_pq) {
                    if (tam_pq == 0) {
                        is_pq = 0;
                    } else {
                        int max_idx = -1;
                        int max_val = -1;
                        for (int j = 0; j < tam_pq; j++) {
                            if (pq[j] > max_val) {
                                max_val = pq[j];
                                max_idx = j;
                            }
                        }
                        
                        if (max_val != x) {
                            is_pq = 0;
                        } else {
                            pq[max_idx] = pq[--tam_pq];
                        }
                    }
                }
            }
        }

        int total = is_stack + is_queue + is_pq;

        if (total == 0) printf("impossible\n");
        else if (total > 1) printf("not sure\n");
        else if (is_stack) printf("stack\n");
        else if (is_queue) printf("queue\n");
        else if (is_pq) printf("priority queue\n");
    }

    return 0;
}
