#include <stdio.h>

int main (){
    
    int n;
    scanf ("%d", &n);
    
    int m;
    long long int arr[1005] = {0};
    long long int count[1005] = {0};
    int min = 2000000001;
    
    for (int i = 0 ; i < n; i++){
        scanf ("%d", &m);
        
        for (int j = 0; j < m; j++){
            scanf ("%lld", &arr[j]);
        }
        
        for (int j = 0; j < m-1; j++){
            count[j] = arr[j] - arr[j+1];
            
            if (count[j] < 0){
                count[j] *= -1;
            }

            if (min > count[j]){
                min = count[j];
            }
        }
                
        printf ("Case #%d: %lld\n", i+1, min);
        min = 2000000001;
    }
    return 0;
}
