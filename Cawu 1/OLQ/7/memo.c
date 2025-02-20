#include <stdio.h>
#define MOD 1000000000

long long int memo[101][101];

long long int hitungcabang(int n, int m){
    if (m == 1){
        return n;
    }
    if (memo[n][m] != -1) {
        return memo[n][m];
    }
    long long int normal_branches = (n - 1) * hitungcabang(n - 1, m - 1) % MOD;
    long long int special_branch = m-1;
    memo[n][m] = (n + normal_branches + special_branch) % MOD;
    return memo[n][m];
}

void initialize_memo() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            memo[i][j] = -1;
        }
    }
}

int main(){
    initialize_memo();
    int tc;
    long long hasil;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        int N, M;
        scanf("%d %d", &M, &N);
        hasil = hitungcabang(N, M);
        printf("Case #%d: %lld\n", t, hasil);
    }
    return 0;
}