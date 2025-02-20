#include <stdio.h>
int main(){
    int Tc, kasus, duade[505][505], hasil = 0;
    scanf("%d", &Tc);
    for(int i = 1; i <= Tc; i++){
        scanf("%d", &kasus);
        for (int ii = 0; ii < kasus; ii++)
        {
            for (int iii = 0; iii < kasus; iii++)
            {
                scanf("%d", &duade[ii][iii]);
            }
        }
        printf("Case #%d:", i);
        for (int ii = 0; ii < kasus; ii++)
        {
            for (int iii = 0; iii < kasus; iii++)
            {
                hasil += duade[iii][ii];
            }
            printf(" %d", hasil);
            hasil = 0;
        }
        printf("\n");       
    }
    return 0;
}