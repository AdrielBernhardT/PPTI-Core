#include <stdio.h>

int main (){
    long int test_case, bahan_dibutuhkan;
    long long int barangA[101], barangB[101];
    scanf("%ld", &test_case);
    getchar();
    // getchar();
    // printf("%ld\n", test_case);
    // printf("Hello1\n");

    //input yg ke 2
    for(int i  = 0; i < test_case; i++)
    {
        scanf("%ld", &bahan_dibutuhkan);
        getchar();
        // getchar();
        // printf("%ld\n", bahan_dibutuhkan);
        // printf("Hello2\n");

        //input data barang A
        for (int j = 0; j < bahan_dibutuhkan; j++)
        {
            scanf("%lld", &barangA[j]);
            getchar();
            // getchar();
            // printf("%d\n", barangA[j]);
            // printf("Hello3\n");
        }
        

        //input data barang B
        for (int j = 0; j < bahan_dibutuhkan; j++)
        {
            scanf("%lld", &barangB[j]);
            // getchar();
            // printf("%d\n", barangB[j]);
        } 
            //print Case
        printf("Case #%ld: ", i +1);
            
        //print isi Case
        for (int j = 0; j < bahan_dibutuhkan; j++)
        {
            if (j < bahan_dibutuhkan-1)
            {
                printf("%lld ", barangA[j]-barangB[j]);
            }
            else
            {
                printf("%lld\n", barangA[j]-barangB[j]);
            } 
        }
    }
    return 0;
}