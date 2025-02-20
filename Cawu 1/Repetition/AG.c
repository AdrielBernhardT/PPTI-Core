#include <stdio.h>
int main(){
    long int TC, N, p;
    scanf("%ld", &TC);
    for (int i = 1; i <= TC; i++)
    {
        scanf("%ld", &N);
        p = 1;
        printf("Case %d:", i);
        for (int ii = 0; ii < N; ii++)
        {
            p+=ii;
            printf(" %ld", p);
        }
        puts("");
    }
    return 0;
}