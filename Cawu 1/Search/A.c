#include <stdio.h>   // Pustaka I/O standar
#include <string.h>  // Fungsi manipulasi string
#include <stdlib.h>  // Fungsi pustaka standar
#include <stdbool.h> // Tipe dan nilai boolean

// Mendefinisikan struktur untuk menyimpan entri kamus
struct dictionary {
    char singkatan[55];   // Singkatan
    char kepanjangan[55]; // Bentuk lengkap
} DB[105]; // Array dari entri kamus

int main() {
    FILE* database = fopen("testdata.in", "r");

    int n, tc; // Variabel untuk menyimpan jumlah entri kamus dan kasus uji
    char kasus[105]; // Buffer untuk menyimpan setiap kasus uji

    // Membaca jumlah entri kamus
    fscanf(database, "%d\n", &n);
    // Membaca setiap entri kamus dari file
    for (int i = 0; i < n; i++) {
        fscanf(database, "%[^#]#%s\n", DB[i].singkatan, DB[i].kepanjangan);
    }
    // Membaca jumlah kasus uji
    fscanf(database, "%d\n", &tc);
    // Memproses setiap kasus uji
    for (int i = 0; i < tc; i++) {
        fscanf(database, "%[^\n]\n", kasus); // Membaca seluruh baris untuk kasus uji
        char* singkat = strtok(kasus, " "); // Memisahkan baris dengan spasi

        printf("Case #%d:\n", i + 1); // Mencetak nomor kasus
        bool first = true, found = false; // Flag untuk mengatur format output dan hasil pencarian
        while (singkat != NULL) {
            if (!first) {
                printf(" "); // Mencetak tanda hubung antara kata
            }
            first = false; found = false; // Mengatur ulang flag untuk setiap kata

            // Mencari singkatan dalam kamus
            for (int j = 0; j < n; j++) {
                if (strcmp(singkat, DB[j].singkatan) == 0) {
                    printf("%s", DB[j].kepanjangan); // Mencetak bentuk lengkap jika ditemukan
                    found = true;
                    break;
                }
            }
            if (!found) printf("%s", singkat); // Mencetak kata itu sendiri jika tidak ditemukan
            singkat = strtok(NULL, " "); // Pindah ke kata berikutnya
        }
        printf("\n"); // Mengakhiri baris untuk kasus uji saat ini
    }

    fclose(database); // Menutup file
    return 0; // Mengembalikan sukses
}