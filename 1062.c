#include <stdio.h>

int pilha[1005];
int topo;

void push(int x) { pilha[++topo] = x; }
void pop() { if(topo > 0) topo--; }
int top() { return pilha[topo]; }

int main() {
    int N;
    
    while (scanf("%d", &N) && N != 0) {
        int target[1005];
        
        while (1) {
            scanf("%d", &target[0]);
            
            if (target[0] == 0) {
                printf("\n"); 
                break;
            }
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &target[i]);
            }

            topo = 0; 
            int vagao_entrada = 1;
            int indice_alvo = 0;
            int possivel = 1;

            while (indice_alvo < N) {
                int necessario = target[indice_alvo];
                if (topo > 0 && top() == necessario) {
                    pop();
                    indice_alvo++;
                } 
                else if (vagao_entrada <= N) {
                    push(vagao_entrada);
                    vagao_entrada++;
                } 
                else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
