#include <stdio.h>

void printTerbilang(int number) {
    switch (number) {
        case 1: printf("satu"); break;
        case 2: printf("dua"); break;
        case 3: printf("tiga"); break;
        case 4: printf("empat"); break;
        case 5: printf("lima"); break;
        case 6: printf("enam"); break;
        case 7: printf("tujuh"); break;
        case 8: printf("delapan"); break;
        case 9: printf("sembilan"); break;
    }
}

void printTerbilangs(int number) {
    switch (number) {
        case 1: printf("se"); break;
        case 2: printf("dua"); break;
        case 3: printf("tiga"); break;
        case 4: printf("empat"); break;
        case 5: printf("lima"); break;
        case 6: printf("enam"); break;
        case 7: printf("tujuh"); break;
        case 8: printf("delapan"); break;
        case 9: printf("sembilan"); break;
    }
}

int main() {
    int number;
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++){
        scanf("%d", &number);

        printf("Case #%0.2d:  ", i+1);
        int ribuan = number / 1000;
        int ratusan = (number % 1000) / 100;
        int puluhan = (number % 100) / 10;
        int satuan = number % 10;

        printTerbilangs(ribuan);
        if (ribuan > 1) printf(" ribu ");
        else if (ribuan == 1) printf("ribu ");

        printTerbilangs(ratusan);
        if (ratusan > 1) printf(" ratus ");
        else if (ratusan == 1) printf("ratus ");

        if (puluhan == 1 && satuan > 0) {
            // Special case for numbers between 11 and 19
            switch (satuan) {
                case 1: printf("sebelas"); break;
                case 2: printf("dua belas"); break;
                case 3: printf("tiga belas"); break;
                case 4: printf("empat belas"); break;
                case 5: printf("lima belas"); break;
                case 6: printf("enam belas"); break;
                case 7: printf("tujuh belas"); break;
                case 8: printf("delapan belas"); break;
                case 9: printf("sembilan belas"); break;
            }
        } else {
            switch (puluhan) {
                case 1: printf("sepuluh"); break;
                case 2: printf("dua puluh"); break;
                case 3: printf("tiga puluh"); break;
                case 4: printf("empat puluh"); break;
                case 5: printf("lima puluh"); break;
                case 6: printf("enam puluh"); break;
                case 7: printf("tujuh puluh"); break;
                case 8: printf("delapan puluh"); break;
                case 9: printf("sembilan puluh"); break;
            }
            if (puluhan > 0 && satuan > 0) printf(" ");
            printTerbilang(satuan);
        }

        printf("\n");
    }
    
    return 0;
}

