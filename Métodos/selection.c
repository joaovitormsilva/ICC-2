#include <stdio.h>

int main(){
    int tam;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }

    int menor;
    for(int i=0;i<tam-1;i++){
        menor =i;
        for(int j=i+1;j<tam;j++){
            if(vet[j]<vet[menor]){
                menor=j;
            }
        }
        if(i!=menor){
            vet[i] ^= vet[menor];
            vet[menor] ^= vet[i];
            vet[i] ^= vet[menor];
        }
    }    
    
    for(int i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }


}