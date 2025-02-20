#include <stdio.h>

int main() {
    int loop1;
    scanf("%d", &loop1);
for (int i = 0 ; i < loop1; i++)
    {
        for (int j = 0; j < loop1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
