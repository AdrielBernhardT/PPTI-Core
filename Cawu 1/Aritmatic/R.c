#include <stdio.h>

int main(){
    long long int A,B,C,D, hasil[5];
    for (int i = 0; i < 3; i++)
    {
        scanf("(%lld+%lld)x(%lld-%lld)", &A, &B, &C, &D); getchar();
        hasil[i] = (A+B)*(C-D);
    }
    for (int i = 0; i < 3; i++)
    {
        if (i!=2)
        {
            printf("%lld ", hasil[i]);
        }
        else
        {
            printf("%lld\n", hasil[i]);
        }
        
    }
    
    return 0;
}