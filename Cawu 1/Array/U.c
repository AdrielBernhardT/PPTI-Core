#include <stdio.h>
#include <stdlib.h>

int main(){
    int Tc, cases, B, L;
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        int* angka = (int*)malloc(1005*sizeof(int));
        scanf("%d", &cases);
        for (int ii = 0; ii < cases; ii++)
        {
            scanf("%d", &angka[ii]);
        }
        scanf("%d %d", &B, &L);
        printf("Case #%d : ", i);
        if (angka[B-1] > angka[L-1]){
            printf("Bibi\n");
        } else if (angka[L-1] > angka[B-1]){
            printf("Lili\n");
        } else {
            printf("Draw\n");
        }
    }
    return 0;
}