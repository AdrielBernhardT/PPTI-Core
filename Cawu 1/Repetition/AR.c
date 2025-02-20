#include <stdio.h>
int main(){
    int Tc, kasus;
    scanf("%d %d", &Tc, &kasus);
    for (int i = 0; i < Tc; i++)
    {
        for (int ii = 1; ii <= kasus; ii++)
        {
            for (int iii = 0; iii < kasus; iii++)
            {
                if (iii <= kasus-ii-1)
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }                
            }
            puts("");
        }
    }
    return 0;
}