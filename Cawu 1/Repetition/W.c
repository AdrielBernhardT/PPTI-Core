#include <stdio.h>
int main(){
    long int genap = 0, ganjil = 0 ,bidak, TC, angka;
    scanf("%ld", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%ld", &angka);
        for (int ii = 0; ii < angka; ii++)
        {
            scanf("%ld", &bidak);
            if (bidak%2 == 0)
            {
                genap++;
            }
            else
            {
                ganjil++;
            }
        }
        printf("Odd group : %ld integer(s).\nEven group : %ld integer(s).\n", ganjil, genap);
        genap = 0;
        ganjil = 0; 
        printf("\n");  
    }
    return 0;
}