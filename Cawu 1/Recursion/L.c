#include <stdio.h>

int jojonanci(int N, int X, int Y) {
    if (N == 0)
        return X;

    if (N == 1)
        return Y;

    int A0 = X;
    int A1 = Y;
    int An;
    
    for (int i = 2; i <= N; i++) {
        An = A1 - A0;  
        A0 = A1;       
        A1 = An;
    }
    
    return An;
}

int main() {
    int T;  // Number of test cases
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N, X, Y;
        scanf("%d %d %d", &N, &X, &Y);
        
        // Find the Nth Jojonanci number
        int result = jojonanci(N, X, Y);
        
        // Print the result in the required format
        printf("Case #%d: %d\n", t, result);
    }
    
    return 0;
}
