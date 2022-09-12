#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int a[], int tam);
void insertion(int a[], int tam);
void merge2(int a[], int c, int f, int b[],int *trocas,int *comps);
//Apenas para testar se o método funcionou para vetores aleatorios que possamos usar
bool organizado(int a[], int n){
    for(int i = 1; i < n ; i++){
        if(a[i - 1] > a[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    int numeroDeVetores;    
    scanf("%d", &numeroDeVetores);

    //indiceInicialDosVetores[1] - indiceInicialDosVetores[0] = tamanho do vetor 0
    //indiceInicialDosVetores[n + 1] - indiceInicialDosVetores[n] = tamanho do vetor n
    int *tamanhoDosVetores = (int*)malloc(sizeof(int)*numeroDeVetores);
    int tamanhoTotal = 0;

    for (int i = 0; i < numeroDeVetores; i++){
        int tamanho;
        scanf("%d", &tamanho);
        tamanhoDosVetores[i] = tamanho;
        tamanhoTotal += tamanho;
    }
    //Todos os vetores são "sub vetores"
    int *vetores = (int*)malloc(sizeof(int)*tamanhoTotal);
    int *vetoresmerge = (int*)malloc(sizeof(int)*tamanhoTotal);
    for(int i = 0; i < tamanhoTotal; i++){
        int x;
        scanf("%d", &x);
        vetores[i] = x;
        vetoresmerge[i]=x;
    }
    
    int ultimoIndiceDosVetores = 0;
    for(int i = 0; i< numeroDeVetores;i++)
    {
        int tamanhoDoVetori = tamanhoDosVetores[i];

        int* vetori = &vetores[ultimoIndiceDosVetores];
        int* vetormerge = &vetoresmerge[ultimoIndiceDosVetores];
        insertion(vetori, tamanhoDoVetori);
        merge(vetormerge, tamanhoDoVetori);
        ultimoIndiceDosVetores += tamanhoDoVetori;
    }    

    free(tamanhoDosVetores);
    free(vetores);
    free(vetoresmerge);
    return 0;
}

void merge2(int a[], int c, int f, int b[],int *trocas,int *comps) {
    if (c >= f) 
        return;   

    int m = (c + f) / 2;

    merge2(a, c, m, b, trocas, comps);
    merge2(a, m + 1, f, b, trocas, comps);

    int i1 = c;
    int i2 = m + 1; 
    int j = 0;

    while (i1 <= m && i2 <= f) {
        *comps=*comps+1;
        if (a[i1] <= a[i2]) {
            *trocas=*trocas+1;
            b[j] = a[i1];
            i1++;
        }
        else {
            *trocas=*trocas+1;          
            b[j] = a[i2];
            i2++;
        }
        j++;
    }

    while (i1 <= m) {
        *trocas=*trocas+1;
        b[j] = a[i1];
        i1++;
        j++;
    }

    while (i2 <= f) {
        *trocas=*trocas+1;
        b[j] = a[i2];
        i2++;
        j++;
    }


    j = 0;
    for(int i = c; i <= f; i++) {
        *trocas=*trocas+1;
        a[i] = b[j];
        j++;
    }

}
void merge(int a[], int tam){
    int trocas=0,comps=0;

    int *b = (int *) malloc (sizeof(int) * tam);

 
    merge2(a, 0, tam-1, b,&trocas,&comps);

    printf("M %d %d %d\n",tam,trocas,comps);

    free(b);

}

void insertion(int a[], int tam){
    int comps = 0;
    int trocas = 0;
    for(int p = 1; p < tam; p++){
        int x = a[p];
        trocas++;
        int i = p-1;
        while(i >= 0 && x < a[i]){
            comps++; //Sempre que esse bloco de código rodar, x < a[i] foi avaliado
            a[i+1] = a[i];
            trocas++;
            i--;
        }
        if(i >= 0){
            comps++; //Existe a chance do while não ter rodado, mas ainda avaliar x < a[i]
            //Isso ocorrerá sempre que sairmos do while sem que tenha ocorrido curto circuito
            //e já que curto circuito ocorre quando i < 0, temos que somar mais um quando
            // i >= 0
        }
        a[i+1] = x;
        trocas++;
    }
    printf ("I %d %d %d\n", tam, trocas, comps);
}