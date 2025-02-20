#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int a = 0, b = 1, next;

    printf("%d", a); 

    if (n > 1) {
        printf(" %d", b); 
    }

    for (i = 2; i < n; i++) { 
        next = a + b;         
        if (i % 3 == 0) {  
            printf(" 10"); 
            next = 10;
        } else {
            printf(" %d", next);  
        }
        a = b;                
        b = next;  
    }
    printf("\n");
    return 0;
}