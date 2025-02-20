#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int jojo, lili, bibi, oranglain;
    int sum = 0;
    scanf("%d %d %d",&jojo, &lili, &bibi);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &oranglain);
        sum += oranglain;
    }
    sum = (sum + jojo + lili + bibi) / (3 + N);
    if(jojo >= sum)
    {
        printf("Jojo lolos\n");
    } 
    else
    {
        printf("Jojo tidak lolos\n");
    }
    if(lili >= sum)
    {
        printf("Lili lolos\n");
    } 
    else
    {
        printf("Lili tidak lolos\n");
    }
    if(bibi >= sum)
    {
        printf("Bibi lolos\n");
    } 
    else
    {
        printf("Bibi tidak lolos\n");
    }
    return 0;
}