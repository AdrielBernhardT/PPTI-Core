#include <stdio.h>

int main(){
    int loop;
    scanf("%d", &loop);
    int angka[loop];
    int sum = 0;
    for (int i = 0; i < loop; i++)
    {
        scanf("%d", &angka[i]);
        sum += angka[i];
    }
    printf("%d\n", sum);
    return 0;
}