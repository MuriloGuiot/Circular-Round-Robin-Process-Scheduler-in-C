#define UTILS_H

typedef struct Processo {
    int pid;                
    int tempo_execucao;     
    int tempo_restante;     
    struct Processo *prox;  
} Processo;


Processo* cria_processo(int pid);
void insere_fim(Processo **head, Processo **tail, Processo *p);
void remove_processo(Processo **head, Processo **tail, Processo *prev, Processo *cur);
