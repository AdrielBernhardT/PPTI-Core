#include <stdio.h>
#include <string.h>

void reverse(char str[1005], int A, int B){
    char temp[1005];
    int len = strlen(str);
    for (int i = 0; i <= len; i++)
    {
        if (i < A || i >= B)
        {
            temp[i] = str[i];
        }
        else
        {
            for (int ii = 0; ii <= B-A; ii++)
            {
                temp[i] = str[B - ii];
                if(ii != B - A){
                    i++;
                }
            } 
        }
    }
    strcpy(str,temp);
}

int  main(){
    int Tc,  jumlahangka, awal, pindah;
    char string[1005], temp;
    scanf("%d", &Tc);
    for(int i = 1; i <= Tc; i++){
        scanf("%d %s", &jumlahangka, string);
        for (int ii = 0; ii < jumlahangka; ii++)
        {
            scanf("%d %d", &awal, &pindah);
            awal -= 1;
            pindah -= 1;
            reverse(string, awal, pindah);
        }
        printf("Case #%d: %s\n", i,string);
    }
    return 0;
}