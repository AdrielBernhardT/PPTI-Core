#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int Tc, n, len;
    scanf("%d", &Tc); getchar();
    for (int cases = 1; cases <= Tc; cases++)
    {

        char *str = (char*)malloc(1005 * sizeof(char));
        char *need_convert = (char*)malloc(105 * sizeof(char));
        char *convert = (char*)malloc(105 * sizeof(char));
        scanf("%[^\n]", str); getchar();
        scanf("%d", &n); getchar();
        for (int x = 0; x < n; x++)
        {
            scanf("%c %c", &need_convert[x], &convert[x]); getchar();
        }
        len = strlen(str);
        for (int x = 0; x < len; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (str[x] == need_convert[y])
                {
                    str[x] = convert[y];
                }
            }
        }
        printf("Case #%d: %s\n", cases, str);
        free(str);
        free(need_convert);
        free(convert);
    }
    return 0;
}