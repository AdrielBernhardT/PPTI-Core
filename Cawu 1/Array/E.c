#include <stdio.h>
int main(){
    int kasus;
    int bentuk;
    long long int angka[105][105];

    // input loop awal
    scanf("%d", &kasus); getchar();

    // loop input kasus
    for(int i = 1; i <= kasus; i++){
        scanf("%d", &bentuk); getchar();

        // loop angka input
        for (int j = 1; j <= bentuk; j++)
        {
            for (int k = 1; k <= bentuk; k++)
            {
               scanf("%lld", &angka[j][k]); getchar();
            }
        } 

        int sum[105] = {0};

        // memulai proses penjumlahan matriks
        //loop sum [a][b]
        for (int a = 1; a <= bentuk ; a++)
        {
            for (int b = 1; b <= bentuk; b++)
            {
                sum[a] += angka[b][a];
            }
        }

        // loop print case
        printf("Case #%d: ", i);
        for (int a = 1; a <= bentuk; a++)
        {
            if (a < bentuk)
            {
                printf("%lld ", sum[a]);
            }
            else if (a = bentuk)
            {
                printf("%lld\n", sum[a]);
            }
        }
    }  
    return 0;
}