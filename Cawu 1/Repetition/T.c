#include <stdio.h>
int main(){
    int permintaan;
    scanf("%d", &permintaan);
    int waktu[permintaan], terjawab[permintaan], melihat[permintaan];
    int poin = 0;
    for (int i = 0; i < permintaan; i++)
    {
        scanf("%d %d %d", &waktu[i], &terjawab[i], &melihat[i]);
        if (waktu[i]<terjawab[i] && terjawab[i]>melihat[i])
        {
            poin++;
        }
        else
        {
            continue;
        }
    }
    printf("%d\n", poin);
    
    return 0;
}