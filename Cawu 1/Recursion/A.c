#include <stdio.h>

int counter = 0;

int recursion(int n){
    if(n == 0){
        return 1;
    } else if (n == 1){
        return 2; 
    } 
    
    if (n%3==0){
        counter++;
    } 

    if (n%5==0){
        return n * 2;
    } else {
        return recursion(n-1)+n+recursion(n-2)+n-2;
    }
}

int main(){
    int Tc, n, hasil;
    scanf("%d", &Tc);
    for (int i = 1; i <= Tc; i++)
    {
        scanf("%d", &n);
        hasil = recursion(n); 
        printf("Case #%d: %d %d\n", i, hasil, counter);
        counter = 0;
    }
    
}