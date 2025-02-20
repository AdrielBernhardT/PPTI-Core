#include <stdio.h>
#include <string.h>

int main(){
    char tod[35];
    scanf("%[^\n]", tod); getchar();
    int len = strlen(tod);
    for (int i = 0; i < len; i++)
    {
        if (tod[i] >= 'a' && tod[i] <= 'z') {
            tod[i]-= 32;
        } else if (tod[i] >= 'A' && tod[i] <= 'Z') {
            tod[i]+= 32;
        }
    }
    printf("%s\n", tod);
    return 0;
}