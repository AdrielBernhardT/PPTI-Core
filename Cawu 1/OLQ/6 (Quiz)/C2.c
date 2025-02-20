#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    bool* flag = (bool*)malloc(1000005*sizeof(bool)); 
    long long int kasus, counter, input;
    int Tc;
    scanf("%d", &Tc); getchar();
    for (int i = 1; i <= Tc; i++)
    {  
        counter = 0;
        
        scanf("%lld", &kasus); getchar();

        for (int j = 0; j < kasus; j++)
        {
           scanf("%lld", &input); getchar();
           if (!flag[input]) { // ketika flag belum ke isi
               flag[input] = true; // ketika flag isi 1
               counter++;
           }
        }

        for (long long int j = 0; j < 1000005; j++)
        {
            if (flag[j])
            {
                flag[j] = false; // Reset 
            }
        }
        
        printf("Case #%d: %lld\n", i, counter);
    }

    free(flag);

    return 0;
}