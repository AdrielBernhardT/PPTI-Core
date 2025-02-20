#include <stdio.h>
#include <string.h>
int main(){
    long long int cases;
    char nama[100000];

    int gap = 'a' - 'A';
    scanf("%lld", &cases); getchar();
    for (int kasus = 1; kasus <= cases; kasus++)
    {
        long long int poin = 0;
        long long int array[100] = {0};
        scanf("%[^\n]", nama); getchar();

        long long int len = strlen(nama);

        for (int i = 0; i < len; i++)
        {
            if (nama[i] >= 'a' && nama[i] <= 'z')
            {
                nama[i] -= gap;
            }
            if (array[nama[i]] == 0 )
            {
                array[nama[i]] = 1;
                poin++;
            }
        }
        if(poin%2 == 1)
        {
            printf("Case #%d: Ewwww\n", kasus);
        }
        else
        {
            printf("Case #%d: Yay\n", kasus);
        }
    }
    return 0;
}