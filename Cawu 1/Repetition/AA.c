#include <stdio.h>

int main(){
    int TC, angka;
    long int sum = 0;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%d", &angka);
        sum += angka;
        if (sum == 9)
        {
            sum = 21;
        }
        else if (sum == 33)
        {
            sum = 42;
        }
        else if (sum == 53)
        {
            sum = 37;
        }
        else if (sum == 76)
        {
            sum = 92;
        }
        else if (sum == 80)
        {
            sum = 59;
        }
        else if (sum == 97)
        {
            sum = 88;
        }
    }
    printf("%ld\n", sum);
    return 0;
}