#include <stdio.h>

int main(){
    int awal, loop;
    scanf("%d %d", &awal, &loop);
    for (int i = awal; i < awal + loop + 1; i++)
    {
        printf("%d\n",i);
    }
    return 0;
}