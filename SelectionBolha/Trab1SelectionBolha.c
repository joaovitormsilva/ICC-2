#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selecao(int tam, int vet[]){
    int menor,troca=0,aux;
    for(int i=0;i<tam-1;i++){
        menor = i;
        for(int j=i;j<tam;j++){

            if(j!=i)
                printf("C %d %d\n",menor,j);

            if(vet[j]<vet[menor]){
                menor = j;
                troca=1;
            }
        }
            if(troca ==1){
                printf("T %d %d\n", i,menor);
                troca=0;
            }
            aux=vet[menor];
            vet[menor]=vet[i];
            vet[i]=aux;

    }
    
    for(int i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

void bolha(int tam,int vet[]){
    int sentinela= tam-1;
    int chance;
    while(sentinela){
        chance=0;
        for(int j=0;j<sentinela;j++){
            printf("C %d %d\n",j,j+1);
            if(vet[j]>vet[j+1]){
                printf("T %d %d\n",j,j+1);
                vet[j] ^= vet[j+1];
                vet[j+1] ^= vet[j];
                vet[j] ^= vet[j+1];
                chance=j;
            }
        } 
            sentinela=chance;
    }
    for(int i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int main(){
    char tipo[15], s[15]="selecao";
    scanf("%s",tipo);
    fflush(stdin);
    int tam;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }
    if(!strcmp(tipo,s)){
        selecao(tam,vet);
    }
    else{
        bolha(tam,vet);
    }
    return 0;
}