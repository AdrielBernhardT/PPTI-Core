#include <stdio.h>
#include <string.h>

int main(){
    long int jumlah_kasus, jumlah_permainan, bibi = 0, lili = 0;
    char hasil[99999];
  
    scanf("%ld", &jumlah_kasus);
    for (int i = 0; i < jumlah_kasus; i++)
    {
        scanf("%d", &jumlah_permainan);
        scanf("%s",hasil); getchar();
        int length = strlen(hasil);
        for (int j = 0; j < length; j++)
        {
             if (hasil[j] == 'L')
            {
                lili++;
            }
            else if (hasil[j] == 'B')
            {
                bibi++;
            }
        }
        if (bibi>lili)
        {
            printf("Bibi\n");
        }
        else if (bibi<lili)
        {
            printf("Lili\n");
        }
        else
        {
            printf("None\n");
        }
        bibi=0;
        lili=0;
    }
   
    return 0;
}