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

No* empilhar(No *p,int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=p;
        return novo;
    }
    else{
        printf("erro\n");
    }
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;
    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("Pilha vazia\n");
    return remover;
}

void imprimir_pilha(No *p){
    printf("Pilha\n");
    while(p){
       printf("%d\n",p->valor);
       p = p -> proximo;
    }
}

int fatorial(int num){
    No *pilha= NULL;
    No *remover;
    while(num>1){
        pilha = empilhar(pilha,num);
        num--;
    }

    imprimir_pilha(pilha);

    while(pilha){
        remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    return num;
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