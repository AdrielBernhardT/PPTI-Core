#include <stdio.h>
int main(){
    int Tc, angka;
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        scanf("%d", &angka);
        printf("Case #%d: ", i);
        for (int x = 0; x < angka; x++){
            printf("%c", 97+x);
        }
        puts("");
    }
    return 0;
}