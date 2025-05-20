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

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int main() {
    Pilha original, auxiliar;
    inicializar(&original);
    inicializar(&auxiliar);

    for (int i = 1; i <= 10; i++) {
        push(&original, i);
    }

    while (!estaVazia(&original)) {
        int val = pop(&original);
        if (val % 2 != 0) {
            push(&auxiliar, val);
        }
    }

    while (!estaVazia(&auxiliar)) {
        push(&original, pop(&auxiliar));
    }

    printf("Pilha sem pares: ");
    while (!estaVazia(&original)) {
        printf("%d ", pop(&original));
    }

    return 0;
}
