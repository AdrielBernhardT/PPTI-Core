#include <stdio.h>

int main(){
    int jumlah_case, parameter, garis_finish, sum = 0, langkah = 0;
    // Test Case    
    scanf("%d", &jumlah_case);
    for (int i = 1; i <= jumlah_case; i++)
    {
        // Input Garis Finish
        scanf("%d", &garis_finish);
        // selama belum finish
        for (int j = 1; sum+j <= garis_finish; j++)
        {
            // jumlahin lompatan dia hingga finish
            sum += j;
            // itung berapa kali lompat
            langkah += 1;
        }
        if (sum < garis_finish)
        {
            // ketika jarak lompat dia lebih sedikit dari jarak langkah ke finish
            langkah+=1;
        }
        printf("Case #%d: %d\n", i, langkah); 
        sum = 0;
        langkah = 0;
    }
    return 0;
}