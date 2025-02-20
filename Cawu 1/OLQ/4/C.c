#include <stdio.h>
int main(){
    long long int Tc, area, players, P[100005], counter = 0;
    scanf("%lld", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        scanf("%lld %lld", &area, &players);
        int array[area+1];
        // Reset area 0
        for (int ii = 0; ii <= area; ii++)
        {
            array[ii] = 0;
        }

        // Masukin player
        for (int ii = 0; ii < players; ii++)
        {
            scanf("%lld", &P[ii]);
        }

        // urutan player
        for (int ii = 0; ii < players; ii++)
        {
            if (array[P[ii]] == 0)
            {
                array[P[ii]] = 1;
            }
            else
            {
                counter++;
            }
        }
        printf("Case #%d: %lld\n", i, counter);
        counter = 0;
    }
    return 0;
}