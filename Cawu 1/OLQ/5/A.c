#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
        {
            printf("*");
        }
        puts("");
    }
    
    return 0;
}