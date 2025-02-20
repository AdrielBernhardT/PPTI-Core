#include <stdio.h>
#include <string.h>

int main(){
    int T, length, num_count, dots;
    char s[105];
    bool isTrue;

    scanf("%d", &T); getchar();
    for(int i = 1; i <= T; i++){
        scanf("%s", s);

        length = strlen(s);
        num_count = dots = 0; isTrue = true;
        for(int j = 0; j < length; j++){
            //printf("%c ", s[j]);
            if(s[j] == '.'){
                //setelah dot ahrus angka, jika bukan angka(dot lagi atau char lain) maka isTRue=false
                if(j+1 < length){
                    if(!(s[j+1] >= '0' && s[j+1] <= '9')) isTrue = false;
                } else {
                    isTrue = false;
                }
                dots++;
            }
        }
        
        printf("Case #%d: ", i);
        if (dots == 5 && isTrue) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
