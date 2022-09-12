#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *topo;
    int tam;
}pilha;

void criar_pilha(pilha *p){
    p->topo = NULL;
    p->tam = 0;
}
fatorial(int valor){


    
}
void empilhar(pilha *p){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->p=ler_pessoa();
        novo->proximo=p->topo;
        p->topo = novo;
        p->tam++;
    }
    else{
        printf("erro\n");
    }
}
No* desempilhar(pilha *p){
    if(p->topo){
        No *auxiliar=p->topo;
        p->topo = auxiliar->proximo;
        p->tam--;
        return auxiliar;
    }
    else{
        printf("Pilha vazia\n");
    }
    return NULL;
}

void imprimir_pilha(pilha *p){
    No *aux= p->topo;
    printf("Pilha tam: %d\n",p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    No *remover;
    pilha p;
    criar_pilha(&p);
    int valor;
    printf("Digite um valor:");
    scanf("%d",&valor);
    printf("O fatorial de %d eh: %d\n",valor,fatorial(valor));
    return 0;
}