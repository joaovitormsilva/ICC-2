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
    printf("\n");
    int nume[]={1,1,2,3,2};
    int auxi;
    for(int i=0;i<4;i++){
        nume[i]^=nume[i+1];
        nume[i+1]^=nume[i];
        nume[i]^=nume[i+1];
        printf("i %d i+1 %d\n",nume[i],nume[i+1]);
    }
    printf("Nume eh\n");
    for(int i=0;i<5;i++){
        printf("%d ",nume[i]);
    }
    printf("\n");
}
