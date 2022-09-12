#include <stdio.h>
#include <stdlib.h>

void heapfy(int a[],int raiz,int ult);

int main(){
    int tam,raiz,ult;
    scanf("%d",&tam);
    int vet[tam];
    for(int i=0;i<tam;i++)
        scanf("%d",&vet[i]);
    
    heapfy(vet,raiz,ult);


    return 0;
}

void heapfy(int a[],int raiz, int ult){
    int pai = raiz;
    while(pai<=ult){
        int filho=2*pai+1;
        if(filho<=ult){
            if(filho+1<=ult){
                if(a[filho+1]>a[filho]){
                    filho++;
                }
            }
            if(a[filho]>a[pai]){
                a[pai] ^= a[filho];
                a[filho] ^= a[pai];
                a[pai] ^= a[filho];
            }
            else{
                break;
            }
        }
            pai=filho;
    }

}