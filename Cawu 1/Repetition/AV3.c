#include <stdio.h>

int capek(int n){
    if (n == 1){
        return 3;
    }
    return capek(n-1)+(n+1);   
}

int main(){
    int angka;
    scanf("%d", &angka);
    printf("%d\n", capek(angka));
    return 0;
}