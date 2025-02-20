#include <stdio.h>

int main(){
    int tukar, sum, honey, loop, baru;
    scanf ("%d", &loop);
    for (int i=1; i <= loop; i++)
    {
        scanf ("%d %d", &honey, &tukar);
        sum = 0;
        sum += honey;
        while (honey >= tukar)
        {
            baru = 0;
            honey -= tukar;
            honey += 1;
            baru += 1;
            sum += baru;
        }
        printf ("Case #%d: %d\n", i, sum);
    }
    return 0;
}