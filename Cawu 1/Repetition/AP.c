#include <stdio.h>
int main(){
    int TC;
    long long int n, converter;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; i++){
        scanf("%lld %lld", &n, &converter);
        char huruf[n];
        scanf("%s", &huruf);  getchar();
        for (int ii = 0; ii < n; ii++){
            huruf[ii]-='a';
            huruf[ii]+=converter;
            while (huruf[ii]>25){
                huruf[ii]-=26;
            }
            huruf[ii]+='a';
        }
        printf("Case #%d: %s\n", i, huruf);
    }
    return 0;
}

/*
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K); getchar();

        char S[N];
        scanf("%s", S);

        for (int j =0; j < N; j++) {
            S[j] = (S[j] - 'a' + K) % 26 + 'a';
        }

        printf("Case #%d: %s\n", i + 1, S);
    }

    return 0;
}
*/