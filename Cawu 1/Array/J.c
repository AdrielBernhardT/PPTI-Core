#include <stdio.h>
#include <string.h>
int main(){
    int test_case;
    char kata[100000];

    scanf("%d", &test_case); getchar();
    
    for (int i = 0; i < test_case; i++)
    {
        scanf("%s", kata); getchar();

        int len = strlen(kata);

        printf("Case %d: ", i+1);

        for (int j = 0; j < len; j++)
        {
            if (j < len-1)
            {
                printf("%d-", kata[j]);
            }
            else
            {
                printf("%d\n", kata[j]);
            } 
        }
    }
    return 0;
}