#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int Tc, len;
    char dictionary[105] = {'A', 'A', 'A', 'A', 'E', 'E', 'E', 'E', 'I', 'I', 'I', 'I', 'I', 'I', 'O', 'O', 'O', 'O', 'O', 'O', 'U', 'U', 'U', 'U', 'U', 'U'};
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        char *str = (char*)malloc(1005*sizeof(char));
        int *angka = (int*)malloc(1005*sizeof(int));
        scanf("%s", str); getchar();
        len = strlen(str);
        for (int j = 0; j < len; j++)
        {
            // simpan angka
            if (str[j] >= 'U'){
                angka[j] = str[j] - 'U';
            } else if (str[j] >= 'O'){
                angka[j] = str[j] - 'O';
            } else if (str[j] >= 'I'){
                angka[j] = str[j] - 'I';
            } else if (str[j] >= 'E'){
                angka[j] = str[j] - 'E';
            } else {
                angka[j] = str[j] - 'A';
            }
            // convert
            str[j] = dictionary[str[j] - 'A']; 
        }
        printf("Case #%d:\n%s\n", i, str);
        for (int j = 0; j < len; j++)
        {
            printf("%d", angka[j]);
        }
        free(angka);
        free(str);
        puts("");
    }
    return 0;
}