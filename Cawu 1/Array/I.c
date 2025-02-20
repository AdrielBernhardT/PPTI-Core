#include <stdio.h>
int main(){
    long int test_case, kotak;
    long long int urutan[100000];
    // input testcase
    scanf("%ld", &test_case);
    for (int i = 0; i < test_case; i++)
    {
        //input kotak
        scanf("%ld",&kotak);
        for (int j = 0; j < kotak; j++)
        {
            // input angka-angka
            scanf("%lld", &urutan[j]);
        }
        printf("Case #%d: ", i+1);
        for (int j = kotak - 1; j >= 0; j--)
        {
            if (j != 0)
            {
                printf("%lld ", urutan[j]);
            }
            else
            {
                printf("%lld\n", urutan[j]);
            }
        }   
    }
    return 0;
}