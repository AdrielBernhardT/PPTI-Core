#include <stdio.h>

int main(){
    int tukar, sum, Thai, loop, baru;
    scanf ("%d", &loop);
    for (int i=1; i <= loop; i++)
    {
        scanf ("%d %d", &Thai, &tukar);
        sum = 0;
        sum += Thai;

        while (Thai >= tukar)
        {
            baru = 0;
            Thai -= tukar;
            Thai += 1;
            baru += 1;
            sum += baru;
        }
        printf ("Case #%d: %d\n", i, sum);
    }
    return 0;
}