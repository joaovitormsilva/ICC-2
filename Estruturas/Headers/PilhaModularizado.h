#ifndef PILHA_H
#define PILHA_H

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* empilhar(No *pilha, int num);
No* desempilhar(No **pilha);
void imprimir(No *pilha);

#endif