#include <stdio.h>
#include <stdlib.h>

/*
    Função Recursiva do Algoritmo Merge Sort

    Parâmetros:
        - a: vetor a ser ordenado;
        - c: começo do vetor (incluso);
        - f: fim do vetor (incluso);
        - b: vetor extra pré alocado para cópias;
*/
void merge2(int a[], int c, int f, int b[]) {

    // Caso base: 
    if (c >= f) {
        // ou o vetor é de tamanho 0 ou de
        // tamanho 1, ou seja, já está ordenado
        return;   
    }

    // Cálculo da posição central do vetor:
    int m = (c + f) / 2;

    // Chamadas recursivas para as 2 metades:
    merge2(a, c, m, b);
    merge2(a, m + 1, f, b);

    // Inicialização dos apontadores para os vetores 
    // da esquerda e da direita, sabendo que o primeiro vetor
    // vai de c à m e que o segundo vetor de m + 1 à f:
    int i1 = c;
    int i2 = m + 1; 
    int j = 0;

    // Junção ordenada e estável dos 2 vetores:
    while (i1 <= m && i2 <= f) {
        if (a[i1] <= a[i2]) {
            b[j] = a[i1];
            i1++;
        }
        else {
            b[j] = a[i2];
            i2++;
        }
        j++;
    }

    // Junção dos elementos restantes do primeiro
    // vetor (se ele não tiver terminado):
    while (i1 <= m) {
        b[j] = a[i1];
        i1++;
        j++;
    }

    // Junção dos elementos restantes do segundo
    // vetor (se ele não tiver terminado):
    while (i2 <= f) {
        b[j] = a[i2];
        i2++;
        j++;
    }

    // Cópia dos elementos ordenados de b para a:
    j = 0;
    for(int i = c; i <= f; i++) {
        a[i] = b[j];
        j++;
    }
}
 
/*
    Função que ordena um vetor, chamando a função recursiva do Merge Sort

    Parâmetros:
        a: vetor a ser ordenado
        n: número de elementos do vetor
*/
void merge(int a[], int n) {

    // Alocação de memória extra para o vetor auxiliar b:
    int *b = (int *) malloc (sizeof(int) * n);

    // Chamada inical da recursão:
    merge2(a, 0, n-1, b);

    // Liberação de memória extra alocada para b:
    free(b);

}