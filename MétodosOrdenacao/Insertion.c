#include <stdio.h>
#include <stdlib.h>

void insertion(int vetor[], int tam){
    for(int p = 1; p < tam; p++){
        int valor = vetor[p];
        int i = p-1;

        while(i >= 0 && valor < vetor[i]){
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = valor;
    }
}