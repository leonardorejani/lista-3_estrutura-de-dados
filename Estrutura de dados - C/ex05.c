#include <stdio.h>

#define TAM 100

typedef struct {
    int dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, int valor) {
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha *p) {
    return p->dados[(p->topo)--];
}

int topo(Pilha *p) {
    return p->dados[p->topo];
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int main() {
    Pilha p1, p2;
    inicializar(&p1);
    inicializar(&p2);

    push(&p1, 4);
    push(&p1, 1);
    push(&p1, 3);
    push(&p1, 2);

    while (!estaVazia(&p1)) {
        int tmp = pop(&p1);
        while (!estaVazia(&p2) && topo(&p2) > tmp) {
            push(&p1, pop(&p2));
        }
        push(&p2, tmp);
    }

    printf("Pilha ordenada: ");
    while (!estaVazia(&p2)) {
        printf("%d ", pop(&p2));
    }

    return 0;
}
