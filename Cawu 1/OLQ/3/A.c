#include <stdio.h>
int main(){
    int Tc, A, B;
    scanf("%d", &Tc);
    for (int i = 0; i < Tc; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", (A/B)<<B);
    }
    

    return 0;
}