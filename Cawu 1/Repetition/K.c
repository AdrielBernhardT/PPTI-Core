#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("Case #%d:\n", i);
        for (int j = 0; j < a[i]; j++)
        {
            for (int k = 0; k < a[i]; k++) 
            {
                if (k < a[i] - 1 - j )
                {
                    printf(" ");
                }
                else
                {
                    if ((k+j)%2 == 1)
                    {
                        printf("#");
                    }
                    else
                    {
                        printf("*");
                    }  
                }
            }
            printf("\n");
        }
    }

    return 0;
}
