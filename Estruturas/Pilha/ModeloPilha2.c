#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int dia, mes, ano;
}data;

typedef struct{
    char nome[30];
    data aniversario;
}pessoa;

typedef struct no{
    pessoa p;
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
pessoa ler_pessoa(){
    pessoa p;
    printf("Digite seu nome e sua data de aniversario:\n");
    scanf("%30s %d %d %d",p.nome,&p.aniversario.dia,&p.aniversario.mes,&p.aniversario.ano);
    return p;
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

void imprimir_pessoa(pessoa p){
    printf("%s\n%d/%d/%d\n",p.nome,p.aniversario.dia,p.aniversario.mes,p.aniversario.ano);
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
    int opcao;
    do{
        printf("Digite: 0- sair 1 - empilhar 2 - desempilhar 3 - imprimir\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                empilhar(&p);
                break;
            case 2:
                remover = desempilhar(&p);
                if(remover){
                    printf("Elemento removido com sucesso\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                }
                else{
                    printf("já está vazia\n");
                }
                break;
            case 3:
                imprimir_pilha(&p);
                break;
        }
    }while(opcao != 0);
    return 0;
}