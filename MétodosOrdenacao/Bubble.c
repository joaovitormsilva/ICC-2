#include <stdio.h>

int main(){
    int tam;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }


    int sentinela= tam-1;
    int ultimaTroca;
    while(sentinela){
        ultimaTroca=0;
        for(int j=0;j<sentinela;j++){
            printf("C %d %d\n",j,j+1);
            if(vet[j]>vet[j+1]){
                printf("T %d %d\n",j,j+1);
                vet[j] ^= vet[j+1];
                vet[j+1] ^= vet[j];
                vet[j] ^= vet[j+1];
                ultimaTroca=j;
            }
        } 
            sentinela=ultimaTroca;
    }

    
    for(int i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }


}