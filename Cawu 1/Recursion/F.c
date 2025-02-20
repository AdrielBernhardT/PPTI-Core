#include <stdio.h>
#include <string.h>

int main(){
    int tc, len;
    char str[1005], reversed[1005];

    scanf("%d", &tc); getchar();

    for (int i = 1; i <= tc; i++)
    {
        scanf("%[^\n]", str); getchar();

        len = strlen(str);

        for (int ii = 0; ii < len; ii++)
        {
            reversed[ii] = str[len-ii-1];   
        }
        reversed[len] = '\0';
        printf("Case #%d: %s\n", i, reversed);
        memset(str, 0, sizeof(str));
        memset(reversed, 0, sizeof(reversed));
    }
    return 0;
}