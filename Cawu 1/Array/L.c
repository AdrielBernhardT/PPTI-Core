#include <stdio.h>
int main(){
    int Tc, urutan[1005], angka[1005];
    scanf("%d", &Tc);
    for (int i = 0; i < Tc; i++){
        scanf("%d", &urutan[i]);
    }
    for (int i = 0; i < Tc; i++){
        scanf("%d", &angka[urutan[i]]);
    }
    for (int i = 0; i < Tc; i++){
        if (i < Tc-1){
            printf("%d ", angka[i]);
        } else{
            printf("%d\n", angka[i]);
        }
    }
    return 0;
}