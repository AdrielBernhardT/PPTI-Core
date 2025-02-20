#include <stdio.h>
int main(){
    char string[50];
    for (int i = 0; i < 5; i++)
    {
        scanf("%[^\n]", string); getchar();
        printf("%10s|%s\n", string, string);
    }

    return 0;
}