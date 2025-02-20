#include <stdio.h>
int main(){
    int Tc, kasus, parameter = 0;
    char string[105], temp[105];
    scanf("%d", &Tc); getchar();
    for (int i = 1; i <= Tc; i++){
        scanf("%d", &kasus); getchar();
        scanf("%[^\n]", &string); getchar();
        for (int ii = 0; ii < kasus; ii++){
            if (string[ii] >= 'a' && string[ii] <= 'z'){
                temp[parameter] = string[ii];
                parameter++;
            }
        }
        temp[parameter] = 0;
        printf("Case #%d: %s\n", i, temp);
        parameter = 0;
    }
    return 0;
}