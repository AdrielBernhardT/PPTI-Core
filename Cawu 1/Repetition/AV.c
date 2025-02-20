#include <stdio.h>
int main(){
    int angka, poin = 0;
    scanf("%d", &angka);
    for (int i = 0; i <= angka; i++)
    {
        for (int ii = 0; ii <= angka; ii++)
        {
            for (int iii = 0; iii <= angka; iii++)
            {
                if (i+ii+iii == angka){
                    poin++;
                }
            }   
        }
    }
    printf("%d\n", poin);
    return 0;
}