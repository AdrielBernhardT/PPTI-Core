#include <stdio.h>

int main(){
    long int jumlah_balon, kekuatan_bibi;
    scanf("%ld %ld", &jumlah_balon, &kekuatan_bibi);
    long int kekuatan_balon[jumlah_balon], sum = 0;
    for (int i = 0; i < jumlah_balon; i++)
    {
        scanf("%ld", &kekuatan_balon[i]);
        if (kekuatan_balon[i] < kekuatan_bibi)
        {
            sum++;
        }
        else if (kekuatan_balon[i] >= kekuatan_bibi)
        {
            continue;
        }
    }
    printf("%ld\n", sum);
    return 0;
}