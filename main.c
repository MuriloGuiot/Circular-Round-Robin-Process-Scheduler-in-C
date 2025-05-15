#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "utils.h"


int main(void) {
    srand(time(NULL));
    Processo *head = NULL, *tail = NULL;
    const int N = 20;

    for (int i = 1; i <= N; i++) {
        Processo *p = cria_processo(i);
        insere_fim(&head, &tail, p);
    }

    int tempo_total = 0;
    Processo *cur = head, *prev = tail;

    while (head) {
        int fatia = rand() % 5 + 1;
        printf("Tempo total: %3d | PID=%2d | Fatia=%d", tempo_total, cur->pid, fatia);

        cur->tempo_restante -= fatia;
        if (cur->tempo_restante > 0) {
            printf(" | Restante=%2d\n", cur->tempo_restante);
        } else {
            printf(" | Restante= 0 -> concluído!\n");
            Processo *to_remove = cur;
            cur = cur->prox;
            remove_processo(&head, &tail, prev, to_remove);
            if (!head) break;
            continue;
        }

        sleep(fatia);         
        tempo_total += fatia;
        prev = cur;           
        cur  = cur->prox;
    }

    printf("\n==> Todos os processos concluídos em %d unidades de tempo.\n", tempo_total);
    return 0;
}
