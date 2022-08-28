#include <stdio.h>
#include <stdlib.h>

void selecao(int tam, int vet[tam]){
    int aux;
    printf("chegou");
    for(int i=0;i<tam;i++){
        for(int j=i;j<tam;j++){
            if(vet[j]<vet[i]){
                printf("C %d %d\n",i,j);
                aux=vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
                printf("T %d %d\n", i,j);
            }
        }
    }
}
int main(){
    char tipo[15], s[15]="selecao";
    gets(tipo);
    fflush(stdin);
    int tam;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }
    if(tipo == s){
        printf("chamou\n");
        selecao(tam,vet);
    }
    else{
        //bolha(vet,tam);
    }
    return 0;
}