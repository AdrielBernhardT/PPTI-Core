#include <stdio.h>
int main(){
    long int TC, a,b;
    scanf("%ld", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%ld %ld", &a, &b);
        if (a >= b)
        {
            printf("Case #%d: Go-Jo\n", i+1);
        }
        else
        {
            printf("Case #%d: Bi-Pay\n", i+1);
        }
    }
    return 0;
}