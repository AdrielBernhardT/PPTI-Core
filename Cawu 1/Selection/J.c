#include <stdio.h>
int main (){
    int a, b, c, ans = -1;
    scanf ("%d %d %d", &a, &b, &c);
    if (c - a == b - c) {
        if ((c - a) >= 0) {
            ans = c - a;
        }
    }
    printf("%d\n", ans);
    return 0;
}