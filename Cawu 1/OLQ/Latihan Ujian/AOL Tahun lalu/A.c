#include <stdio.h>
#include <string.h>

void reverse(char string[], int len){
    char temp[105];
    for(int i = 0; i < len; i++){
        temp[i]=string[len - i - 1];
    }
    for (int i = 0; i < len; i++)
    {
        string[i] = temp[i];
    }
}

void convert(char string[], int len){
    int gap = 'a' - 'A';
    for (int i = 0; i < len; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += gap;
        }
        else
        {
            string[i] -= gap;
        }
    }
}

int main(){
    char string[105];
    scanf("%[^\n]", string); getchar();
    int len = strlen(string);
    reverse(string, len);
    convert(string, len);
    printf("%s\n", string);
    return 0;
 }