#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct {
    char operacoes[TAM][50];
    int topo;
} PilhaStr;

void inicializar(PilhaStr *p) {
    p->topo = -1;
}

void push(PilhaStr *p, char *op) {
    strcpy(p->operacoes[++(p->topo)], op);
}

char* pop(PilhaStr *p) {
    return p->operacoes[(p->topo)--];
}

int estaVazia(PilhaStr *p) {
    return p->topo == -1;
}

int main() {
    PilhaStr desfazer, refazer;
    inicializar(&desfazer);
    inicializar(&refazer);

    push(&desfazer, "Escreveu 'Olá'");
    push(&desfazer, "Escreveu 'Mundo'");
    push(&desfazer, "Apagou 'Olá'");

    printf("Desfazendo: %s\n", pop(&desfazer));
    push(&refazer, "Apagou 'Olá'");

    printf("Refazendo: %s\n", pop(&refazer));
    push(&desfazer, "Apagou 'Olá'");

    return 0;
}
