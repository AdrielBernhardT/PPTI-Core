#include <stdio.h>
int main(){
    int kasus_uji;
    long int jumlah_hasil_tes;
    long long int hasil_tes[100000], minimum[100000], poin = 0;

    //input kasus
    scanf("%d", &kasus_uji);

    for (int i = 0; i < kasus_uji; i++)
    {
        int poin=0;        
        //input batas angka
        scanf("%ld", &jumlah_hasil_tes);

        // input angka - angka
        for (int j = 0; j < jumlah_hasil_tes; j++)
        {
            scanf("%lld", &hasil_tes[j]);
        }

        //input minimal
        for (int j = 0; j < jumlah_hasil_tes; j++)
        {
            scanf("%lld", &minimum[j]);
        }

        // lolos ga lolos
        for (int j = 0; j < jumlah_hasil_tes; j++)
        {
            if (hasil_tes[j] < minimum[j])
            {
                poin++;
            }
        }

        // output
        printf("Case #%d: %d\n", i+1, poin);
    }

    return 0;
}