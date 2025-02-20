#include <stdio.h>
#include <string.h>

int main() {
    // Membuka file testdata.in dalam mode baca
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        // Jika file tidak dapat dibuka, cetak pesan error dan keluar dari program
        printf("Tidak dapat membuka file.\n");
        return 1;
    }

    // Membaca jumlah karakter dari file
    int N;
    fscanf(file, "%d", &N);

    // Membaca string dari file
    char ground[N + 1];
    fscanf(file, "%s", ground);
    fclose(file); // Menutup file setelah selesai membaca

    // Inisialisasi variabel untuk menyimpan panjang maksimum dan panjang saat ini
    int maxLength = 0, currentLength = 0;

    // Loop melalui setiap karakter dalam string
    for (int i = 0; i < N; i++) {
        if (ground[i] == '1') {
            // Jika karakter adalah '1', tambahkan panjang saat ini
            currentLength++;
            if (currentLength > maxLength) {
                // Jika panjang saat ini lebih besar dari panjang maksimum, perbarui panjang maksimum
                maxLength = currentLength;
            }
        } else {
            // Jika karakter bukan '1', reset panjang saat ini
            currentLength = 0;
        }
    }

    // Cetak panjang maksimum
    printf("%d\n", maxLength);
    return 0;
}