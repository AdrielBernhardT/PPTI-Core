#include <stdio.h>

void solve(long long int case_number, long long int N) {
    int turn = 0;  // 0 for Jojo, 1 for Lili
    
    while (N > 1) {
        if (N % 2 == 0) {
            N /= 2;  // If even, halve the number
        } else {
            N = N * 3 + 1;  // If odd, multiply by 3 and add 1
        }
        turn = 1 - turn;  // Alternate between Jojo (0) and Lili (1)
    }
    
    // If it's Jojo's turn and the number is 1, then Jojo lost, so Lili wins.
    if (turn == 0) {
        printf("Case #%d: Lili\n", case_number);
    } else {
        printf("Case #%d: Jojo\n", case_number);
    }
}

int main() {
    long long int T, N;
    
    // Read number of test cases
    scanf("%lld", &T);
    
    for (long long int i = 1; i <= T; i++) {
        // Read each test case
        scanf("%lld", &N);
        // Solve for each test case
        solve(i, N);
    }
    
    return 0;
}
