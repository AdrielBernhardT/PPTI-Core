#include <stdio.h>

int main() {
    int loop1, loop2;
    scanf("%d %d", &loop1, &loop2);
    
    //Bentuk 1
    for (int i = 0 ; i < loop1; i++)
    {
        for (int j = 0; j < loop1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    puts("");

    //Bentuk 2
    for (int i = 1 ; i <= loop1; i++)
    {
        if (i%loop2==0)
        {
            for (int j = 0; j < loop1; j++)
            {
                printf("#");
            }
        } 
        else 
        {
            for (int j = 0; j < loop1; j++)
            {
                printf(".");
            }
        } 
        printf("\n");
    }

    puts("");

    //Bentuk 3
    for (int i = 0 ; i < loop1; i++)
    {
        for (int j = 1; j <= loop1; j++)
        {
            if (j%loop2==0)
            {
                printf("#");
            } else
            {
                printf(".");
            } 
        }
        printf("\n");
    }
    

    return 0;
}