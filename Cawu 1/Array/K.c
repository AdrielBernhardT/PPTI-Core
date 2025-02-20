#include <stdio.h>
#include <string.h>

int main(){
    int Tc;
    char string[1005], reverse[1005] = {};
    scanf("%d",  &Tc); getchar();
    for (int i = 1; i <= Tc; i++)
    {
        scanf("%[^\n]", &string); getchar();
        int length = strlen(string);
        printf("Case #%d : ", i);
        for (int ii = 0; ii <= length; ii++)
        {
            reverse[ii] = string[length-ii-1];
        }
        printf("%s\n", reverse);
    }
    return 0;
}