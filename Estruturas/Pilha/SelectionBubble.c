#include <stdio.h>

int main(){
    char tipo[10];
    gets(tipo);
    fflush(stdin);

    int tamanho;
    scanf("%d",&tamanho);

    int vetor[tamanho];
    for(int i=0;i<tamanho;i++){
        scanf("%d",&vetor[i]);
    }

    if(tipo == 'selecao'){
            printf("selecao");
    }



    return 0;
}