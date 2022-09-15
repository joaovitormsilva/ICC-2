void shell(int vetor[], int tam){
    int g=1;
    while(g<tam){
        g = g*2;
    }  
    g=(g/2)-1;

    while(g>1){
        for(int p = g; p < tam; p++){
            int valor = vetor[p];
            int i = p-g;

            while(i >= 0 && valor < vetor[i]){
                vetor[i+g] = vetor[i];
                i--;
            }
            vetor[i+g] = valor;
        }
        g=g/2;
    }
}
