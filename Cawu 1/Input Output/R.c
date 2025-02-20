#include <stdio.h>
int main(){
    int num;
    char nama[105], id[105], class[15];    
    scanf("%s %[^\n] %s %d", &id, &nama, &class, &num);
    printf("Id    : %s\nName  : %s\nClass : %s\nNum   : %d\n", id, nama, class, num);
    return 0;
}