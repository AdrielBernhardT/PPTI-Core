#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
pseudocode:
1. buat array flag dengan size 1000005
2. memset flag dengan 0
3. input testcase
4. loop sebanyak testcase
5. input jumlah angka
6. loop sebanyak jumlah angka
7. input angka
8. jika flag angka = 0 maka flag angka = 1 dan counter++
9. print hasil
10. memset flag dengan 0
*/

int main(){
    int* flag = (int*)malloc(1000005*sizeof(int)); 
    memset(flag,0,sizeof(flag));
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
            if (flag[input] == 0)
            {
                flag[input] = 1;
                counter++;
            }
        }
        printf("Case #%d: %lld\n", i, counter);
        memset(flag,0,1000005);
    }
    free(flag);
    return 0;
}

/*
2 
5 
1 2 3 3 3 
10 
1 2 3 4 5 4 3 2 1 6
*/