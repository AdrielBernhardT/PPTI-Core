#include <stdio.h>

int rekursi(long long int N){
    if (N==1){
        return 1;
    }
    
    if(N%2==1){
        return rekursi(N-1)+rekursi(N+1);
    }
    else if(N%2==0){
        return rekursi(N/2);
    }
}

int main(){
    int Tc, hasil;
    long long N;
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++){
        scanf("%lld", &N);
        hasil = rekursi(N);
        printf("Case #%d: %d\n", i, hasil);
    }
    return 0;
}