#include <stdio.h>
int main(){
    long long int Tc, banyak, angka[500000], max = -50000000, temp = 0, hasil = 0;
    scanf("%lld", &Tc);
    for (int i = 1; i <= Tc; i++){
        scanf("%lld", &banyak);
        for (int ii = 0; ii < banyak; ii++){
            scanf("%lld", &angka[ii]);
            if (angka[ii] >= max){
                max = angka[ii];
                temp = ii;
            }
        }
        angka[temp] = -5000000;
        hasil += max;
        max = -50000000;
        for (int ii = 0; ii < banyak; ii++){
            if (angka[ii] >= max){
                max = angka[ii];
            }
        }
        hasil += max;
        printf("Case #%d: %lld\n", i, hasil);
        max = -50000000;
        hasil = 0;
    }
    return 0;
}

