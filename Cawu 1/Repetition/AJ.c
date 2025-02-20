#include <stdio.h>
int main(){
    int TC, angka, sum = 0;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%d", &angka);
        sum+=angka;
    }
    printf("%d\n", sum);
    return 0;
}