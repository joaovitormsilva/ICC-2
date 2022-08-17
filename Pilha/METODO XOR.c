#include <stdio.h>

int main(){
    int x[]={0,1,9,2,3,4,5,6,7};
    int aux=0;
    for(int i=0;i<=9;i++){
        aux ^= i;
        printf("%d ",aux);
    } 
    printf("\n");
    for(int i=0;i<9;i++){
        aux ^= x[i];
        printf("%d ",aux);
    }
    printf("\n");
    printf("aux:%d\n",aux);
    for(int i=0;i<9;i++){
        printf("%d\n",x[i]);
    }

    int num=2;
    printf("%d",num>>1);
}
