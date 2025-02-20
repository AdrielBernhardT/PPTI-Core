#include <stdio.h>
#include <string.h>

int main(){
    int tc, len, flag = 0;
    char str[1005];

    scanf("%d", &tc); getchar();

    for (int i = 1; i <= tc; i++)
    {
        scanf("%[^\n]", str); getchar();
        len = strlen(str);
        for (int ii = 0; ii < len; ii++)
        {
            if (str[ii] != str[len-ii-1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("Case #%d: yes\n", i);
        }
        else
        {
            printf("Case #%d: no\n", i);
        }
        flag = 0;
    }
    

    return 0;
}