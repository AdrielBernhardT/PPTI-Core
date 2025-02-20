#include <stdio.h>
int main(){
    int TC, A, B, kasus, high = 0;
    int sum = 0;
    scanf("%d", &TC); getchar();
    for (int i = 1; i <= TC; i++)
    {
        scanf("%d %d", &A, &B); getchar();
        for (int j = 0; j < A; j++)
        {
            scanf("%d", &kasus);
            sum = B/kasus;
            if (sum>high){
                high = sum;
            }
        }
        printf("Case #%d: %d\n", i, high);
        high = 0;
    }
    return 0;
}