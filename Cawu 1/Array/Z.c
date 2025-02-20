#include<stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);    
    getchar();
    
    int left, right;
    
    char str[10005];
    
    int sum;
    int flag, flag2, flag3;

    int count;
    
    int m, t;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &m, &t); getchar();
        scanf("%s", &str); getchar();
        left = -1;
        right = -1;
        sum = 0;
        count = 0;
        
        printf("Case #%d: ", i+1);
        for(int j = 0; j < m; j++){
            if(str[j] == '1'){
                sum++;
            }
        }
        
        for(int j = 0; j < m; j++){
            if(left == -1){
                if(str[j] == '1'){
                    left = j + 1;
                }
            }
        }
        for(int j = m - 1; j > m-t-1; j--){
            if(right == -1){
                if(str[j] == '1'){
                    right = j + 1;
                }
            }
        }
        
        if(m <= t){
            printf("Alive\n");
        } else if(sum == 1){
            printf("Dead\n");
        } else if(left <= t && right > m - t){
            printf("Alive\n");
        } else{
            printf("Dead\n");
        }
        
    }
    
    return 0;
}

/*
5
9 3
001011010
10 4
0000100100
10 4
0001001000
10 4
0001010000
10 4
0001001000
*/