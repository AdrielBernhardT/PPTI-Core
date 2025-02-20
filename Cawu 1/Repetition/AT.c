#include<stdio.h>
int main(){
    int Tc, N, parameter = 1;
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        scanf("%d", &N);
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N-x-1; y++)
            {
                printf(" ");
            }
            for (int y = 0; y < parameter; y++)
            {
                printf("*");
            }
            parameter+=2;
            printf("\n");
        }
        parameter=1;
    }
    return 0;
}