#include <stdio.h>
int main(){
    double num;
    int age;
    char nama[105];
    for (int i = 1; i <= 2; i++)
    {    
        scanf("%s %lf %d", &nama, &num, &age);
        printf("Name %d: %s\nHeight %d: %.2lf\nAge %d: %d\n", i, nama, i, num, i, age);
    }
    
    return 0;
}