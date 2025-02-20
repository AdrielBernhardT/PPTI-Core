#include <stdio.h>
int main(){ 
    char nama[105];
    scanf("%[^\n]", &nama);
    printf("Halo %s\n", nama);
    return 0;
}