#include <stdio.h>
int main(){
    char mapel[15];
    int H1,M1,H2,M2;
    for (int i = 0; i < 5; i++)
    {
        scanf("%s %d:%d-%d:%d", mapel, &H1, &M1, &H2, &M2);
        printf("%s %02d:%02d-%02d:%02d\n", mapel, H1-1, M1, H2-1, M2);
    }
    return 0;
}