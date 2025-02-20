#include <stdio.h>
int main(){
    int TC;
    long int heigh, width;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++)
    {
        scanf("%ld %ld", &heigh, &width);
        printf("Case #%d:\n", i);
        for (int ii = 0; ii < heigh; ii++)
        {
            for (int iii = 0; iii < width; iii++)
            {
                if (ii == 0 || iii == 0 || ii == heigh-1 || iii == width-1)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }  
    }
    
    return 0;
}