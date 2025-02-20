#include <stdio.h>
int main(){
    char nama[105], NIS[10];
    int umur;

    scanf("%[^\n] %s %d", nama, NIS, &umur);
    printf("Name: %s\nNIS: %s\nAge: %d\n", nama, NIS, umur);
    return 0;
}