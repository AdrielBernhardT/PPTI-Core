#include <stdio.h>
int main(){
    long int TC, a,b,c;
    scanf("%ld", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if (a > b+c)
        {
            printf("Case #%d: no\n", i+1);
        }
        else
        {
            printf("Case #%d: yes\n", i+1);
        }
    }
    return 0;
}