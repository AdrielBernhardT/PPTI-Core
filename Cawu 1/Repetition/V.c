#include <stdio.h>

void bentuk(int angka){
    for (int ii = 0; ii < angka; ii++)
    {
        for (int iii = 0; iii < angka; iii++)
        {
            if (ii == iii || ii == 0 || iii == 0 || ii == angka-1 || iii == angka-1 || iii == angka-ii-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    int TC;
    int angka;
    scanf("%d", &TC); 
    for (int i = 1; i <= TC; i++)
    {
        scanf("%d", &angka);
        bentuk(angka);
        printf("\n");
    }
    return 0;
}