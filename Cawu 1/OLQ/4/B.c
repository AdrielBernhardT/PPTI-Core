#include <stdio.h>
#include <string.h>

void convert(int *H, char Time[]){
    if((strcmp(Time,"am") == 0) && *H >= 12){
        *H-=12;
    } else if ((strcmp(Time,"pm") == 0) && *H < 12){
        *H+=12;
    }
}

int main(){
    int Tc, H, M;
    char Time[5];
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++){
        scanf("%d:%d %s", &H, &M, Time);
        convert(&H, Time);
        printf("Case #%d: %02d:%02d\n", i,H ,M);
    }
    return 0;
}