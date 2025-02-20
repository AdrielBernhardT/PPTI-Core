#include <stdio.h>
#include <string.h>

int main(){
    char string[1005];
    char temp[50];
    int counter = 0;
    char alien[5] = "szs ";
    for (int i = 0; i < 2; i++)
    {
        scanf("%[^\n]", string);
        getchar();
        int len = strlen(string);
        counter = 0;
        for (int j = 0; j <= len; j++)
        {
            if (string[j]!=' ')
            {
                temp[counter]=string[j];
                counter++;
            }
            else
            {
                for (int k = 0; k < 4; k++)
                {
                    temp[counter]=alien[k];
                    counter++;
                }
            }
            
        }
        printf("%sszs\n", temp);
    }
    return 0;
}