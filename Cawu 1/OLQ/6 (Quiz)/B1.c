#include <stdio.h>

int main(){
    int samples;
    int minganjil = 999999;
    int sum = 0;
    int number[10000];
    scanf("%d", &samples);
    for (int i = 0; i < samples; i++){
        scanf("%d", &number[i]);
        if (number[i]%2 != 0){
            if (number[i] < minganjil){
                minganjil = number[i];
            }
        }
        sum = sum + number[i];
    }
    if (sum % 2 != 0){
        sum = sum - minganjil;
    }
    printf("%d", sum);
    return 0;
}