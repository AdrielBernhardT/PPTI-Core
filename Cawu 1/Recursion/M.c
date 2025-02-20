#include <stdio.h>

int result = 0;

int recurtion(int a, int b) {
    if(a != b && (a == 1 || a == 0)) {
        return 0;
    }
    if(a == b) {
        return 1;
    }
    if (a%2 == 0) {
        return recurtion(a/2, b);
    } 
    if (a%2 == 1) {
        return recurtion((a*3)+1, b);
    }
}


int main(){
    int tc, a, b, hasil;
    char result[5][5] = {"NO", "YES"};
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d %d", &a, &b);
        hasil = recurtion(a, b);
        printf("Case #%d: %s\n", t, result[hasil]);
    }
    return 0;
}