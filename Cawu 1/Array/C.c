#include<stdio.h>
int main(){
    int jumlah_angka;
    scanf("%d", &jumlah_angka); getchar();

    int angka_angka[jumlah_angka];

    for (int i = 1; i <= jumlah_angka; i++)
    {
        scanf("%d", &angka_angka[i]); getchar();
    }

    int testcase;
    scanf("%d",&testcase); getchar();

    int urutan, ganti;

    for (int i = 1; i <= testcase; i++)
    {
        scanf("%d %d", &urutan, &ganti); getchar();

        angka_angka[urutan] = ganti;

        printf("Case #%d: ", i);
        for (int j = 1; j <= jumlah_angka; j++)
        {
            if (j < jumlah_angka)
            { 
                printf("%d ", angka_angka[j]);
            }
            else
            {
                printf("%d\n", angka_angka[j]);
            }
        }
    }
    return 0;
}


// 7
// 12 3 2 9 6 2 5
// 5
// 1 4
// 3 6
// 3 15
// 7 1
// 1 7