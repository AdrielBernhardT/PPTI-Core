#include <stdio.h>
int main(){
    // input bentuk awal
    int panjang, lebar;
    scanf("%d %d", &panjang, &lebar); getchar();
    
    int angka[105][105];
    int testcase;
    int x, y, ganti;

    //input angka ke
    for (int i = 1; i <= panjang; i++)
    {
        for (int j = 1; j <= lebar; j++)
        {
            scanf("%d", &angka[i][j]); getchar();
        }
    }

    //input testcase
    scanf("%d", &testcase); getchar();

    // input x y dan mau di ganti berapa
    for (int k = 1; k <= testcase; k++)
    {
        scanf("%d %d %d", &x, &y, &ganti); getchar();

        angka[x][y] = ganti;
    }

    //print output
    for (int i = 1; i <= panjang; i++)
    {
        for (int j = 1; j <= lebar; j++)
        {
            if (j == lebar)
            {
                printf("%d", angka[i][j]);
            }
            else
            {
                printf("%d ", angka[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}