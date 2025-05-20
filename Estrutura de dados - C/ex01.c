#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct {
    int dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == TAM - 1;
}

void push(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->dados[++(p->topo)] = valor;
    }
}

int pop(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[(p->topo)--];
    }
    return -1; 
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(int);
    Pilha p;
    inicializar(&p);

    for (int i = 0; i < tamanho; i++) {
        push(&p, vetor[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = pop(&p);
    }

    printf("Vetor invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
