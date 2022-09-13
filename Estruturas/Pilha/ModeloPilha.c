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

pessoa ler_pessoa(){
    pessoa p;
    printf("Digite seu nome e sua data de aniversario:\n");
    scanf("%30s %d %d %d",p.nome,&p.aniversario.dia,&p.aniversario.mes,&p.aniversario.ano);
    return p;
}
No* empilhar(No *topo){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->p=ler_pessoa();
        novo->proximo=topo;
        return novo;
    }
    else{
        printf("erro\n");
    }
    return NULL;
}
No* desempilhar(No **topo){
    if(topo){
        No *auxiliar = *topo;
        *topo = auxiliar->proximo;
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
void imprimir_pilha(No *topo){
    while(topo){
        printf("%s\n",topo->p.nome);
        printf("%d/%d/%d\n",topo->p.aniversario.dia,topo->p.aniversario.mes,topo->p.aniversario.ano);
        topo = topo->proximo;
    }

}
int main(){
    setlocale(LC_ALL,"Portuguese");
    No *remover;
    No *topo=NULL;
    int opcao;
    do{
        printf("Digite: 0- sair 1 - empilhar 2 - desempilhar 3 - imprimir\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                topo= empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo);
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
                imprimir_pilha(topo);
                break;
        }
    }while(opcao != 0);
    return 0;
}