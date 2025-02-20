#include <stdio.h>

int main() {
    int TC;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++) 
    {
        int N, onCounter = 0, counter = 0;
        scanf("%d", &N);
        long long int temp, A[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%lld", &A[j]);
        }
        for (int j = 0; j < N; j++) 
        {
            for (int k = j + 1; k < N; k++) 
            {
                long long int bitCount = 0;
                temp = A[j] ^ A[k];
                while (temp) 
                {
                    bitCount += temp & 1;
                    temp >>= 1;
                }
                if (bitCount >= 3)
                {
                    onCounter++;
                }
                counter++;
            }
        }
        printf("Case #%d: %d %d\n", i, onCounter, counter - onCounter);
    }

    return 0;
}
