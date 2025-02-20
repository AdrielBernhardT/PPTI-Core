#include <stdio.h>

int main(){
    int TC, a,b,c,d,e, poin = 0;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++)
    {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        for (int ii = 1; ii <= a; ii++)
        {
            if (ii%b == 0 && ii%c == 0 && ii%d == 0 && ii%e == 0)
            {
                poin++;
            }
            else if (ii%b == 0)
            {
                poin++;
            }
            else if (ii%c == 0)
            {
                poin++;
            }
            else if (ii%d == 0)
            {
                poin++;
            }
            else if (ii%e == 0)
            {
                poin++;
            }
        }
        printf("Case #%d: %d\n", i, poin);
        poin = 0;
    }
    

    return 0;
}