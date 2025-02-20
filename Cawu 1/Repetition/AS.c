#include <stdio.h>
int main(){
    int Tc, tot, poin;
    char kunci[105], jawaban[105];
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++){
        scanf("%d", &tot);
        scanf("%s", kunci); getchar();
        scanf("%s", jawaban); getchar();
        poin = 0;
        for (int ii = 0; ii < tot; ii++){
            if (kunci[ii] == jawaban[ii]){
                poin++;
            }
        }
        printf("Case #%d: %d\n", i, (poin*100/tot));
    }
    
    return 0;
}