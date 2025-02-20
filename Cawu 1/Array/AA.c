#include <stdio.h>

int main(){
    int N, count = 0;
    scanf("%d", &N);
    long long rooms[N];
    for(int i = 0; i < N; i++){
        scanf("%lld", &rooms[i]);
    }
    for(int j = 0; j < N; j++){
       for(int k = j+1; k<N; k++){
           if(rooms[j] == rooms[k]){
               count++; break;
           }
       }
    }
    printf("%d\n", N-count);
    return 0;
}