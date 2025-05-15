#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

Processo* cria_processo(int pid) {
    Processo *p = malloc(sizeof(Processo));
    if (!p) { 
        exit(EXIT_FAILURE);
    }
    p->pid = pid;
    p->tempo_execucao = rand() % 26 + 5;
    p->tempo_restante = p->tempo_execucao;
    p->prox = NULL;
    return p;
}

void insere_fim(Processo **head /*Ponteiro p primeiro nó da lista*/, Processo **tail /*Último nó da lista*/, Processo *p) {
    if (!*head) {
        *head = *tail = p;
        p->prox = p;
    } else {
        p->prox = *head;
        (*tail)->prox = p;
        *tail = p;
    }
}

void remove_processo(Processo **head, Processo **tail, Processo *prev, Processo *cur) {
    if (cur == prev) {

        *head = *tail = NULL;
    } else {
        prev->prox = cur->prox; /*O cur aponta pro processo que recebe a fatia de tempo nessa iteração do laço*/
        if (cur == *head) *head = cur->prox;
        if (cur == *tail) *tail = prev;
    }
    free(cur);
}