#include <stdio.h>
#include <string.h>

#define TAM 100

typedef struct {
    char dados[TAM];
    int topo;
} PilhaChar;

void inicializar(PilhaChar *p) {
    p->topo = -1;
}

void push(PilhaChar *p, char c) {
    p->dados[++(p->topo)] = c;
}

char pop(PilhaChar *p) {
    return p->dados[(p->topo)--];
}

int main() {
    char palavra[TAM];
    PilhaChar p;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inicializar(&p);
    int len = strlen(palavra);

    for (int i = 0; i < len; i++) {
        push(&p, palavra[i]);
    }

    int palindromo = 1;
    for (int i = 0; i < len; i++) {
        if (pop(&p) != palavra[i]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        printf("É um palíndromo.\n");
    } else {
        printf("Não é um palíndromo.\n");
    }

    return 0;
}
