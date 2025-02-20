#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Fungsi untuk menghitung jumlah sel kosong dalam satu baris
int countEmptyCells(char *line) {
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        // Jika karakter adalah ';' dan diikuti oleh kondisi tertentu, tambahkan count
        if (line[i] == ';' && (i == 0 || line[i-1] == ';')) {
            count++;
        }
    }
    return count;
}

int main() {
    // Membuka file untuk dibaca
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        perror("Unable to open file"); // Menampilkan pesan error jika file tidak bisa dibuka
        return 1;
    }

    char line[105];
    long long possibilities = 1;
    int emptyCells;

    // Membaca file baris demi baris
    while (fgets(line, sizeof(line), file)) {
        // line[strcspn(line, "\n")] = '\0'; // Menghapus karakter newline
        emptyCells = countEmptyCells(line); // Menghitung sel kosong


        // Menghitung kemungkinan dengan formula yang diberikan
        for (int i = 0; i < emptyCells; i++) {
            possibilities *= 101;
            possibilities %= MOD;
        }
        
        // printf("%d\n", emptyCells); // Menampilkan hasil
    }

    fclose(file); // Menutup file
    printf("%lld\n", possibilities); // Menampilkan hasil
}