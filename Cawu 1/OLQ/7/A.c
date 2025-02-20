#include <stdio.h>
#define MOD 1000000000

long long int hitungcabang(int n, int m){
    if (m == 1){
        return n;
    }
    long long int normal_branches = (n - 1) * hitungcabang(n - 1, m - 1) % MOD;
    long long int special_branch = m-1;
    return (n + normal_branches + special_branch) % MOD;
}

int main(){
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