#include <stdio.h>
#include <stdbool.h>

// Fungsi untuk memeriksa apakah tiga sisi dapat membentuk segitiga
bool canFormTriangle(long long a, long long b, long long c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int tc;
    // Membuka file input
    FILE *fin = fopen("testdata.in", "r");

    // Memeriksa apakah file berhasil dibuka
    if (fin == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Membaca jumlah test case dari file
    fscanf(fin, "%d", &tc);

    // Membuat array untuk menyimpan panjang sisi
    long long panjang[tc];
    for (int i = 0; i < tc; i++) {
        fscanf(fin, "%lld", &panjang[i]);
    }
    
    // Menutup file setelah selesai membaca
    fclose(fin);

    bool found = false;

    // Mencari kombinasi tiga sisi yang dapat membentuk segitiga
    for (int i = 0; i < tc - 2 && !found; i++) {
        for (int j = i + 1; j < tc - 1 && !found; j++) {
            for (int k = j + 1; k < tc && !found; k++) {
                if (canFormTriangle(panjang[i], panjang[j], panjang[k])) {
                    found = true;
                }
            }
        }
    }

    // Menampilkan hasil apakah ada kombinasi yang dapat membentuk segitiga
    if (found) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}