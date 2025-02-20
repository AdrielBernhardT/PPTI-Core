#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct Player untuk menyimpan data pemain
typedef struct {
    int rating;     // Rating pemain
    char name[11];  // Nama pemain (maksimal 10 karakter)
    char label[7];  // Label pemain (maksimal 6 karakter)
    int diff;       // Selisih rating pemain dengan rata-rata rating
} Player;

// Fungsi untuk membandingkan dua pemain berdasarkan rating dan nama
int compare(const void *a, const void *b) {
    Player *playerA = (Player *)a;
    Player *playerB = (Player *)b;
    // Jika rating berbeda, urutkan berdasarkan rating secara menurun
    if (playerA->rating != playerB->rating) {
        return playerB->rating - playerA->rating;
    }
    // Jika rating sama, urutkan berdasarkan nama secara alfabetis
    return strcmp(playerA->name, playerB->name);
}

// Fungsi untuk memberikan label berdasarkan rating pemain
void assignLabel(Player *player) {
    if (player->rating <= 200) {
        strcpy(player->label, "Ascend");
    } else if (player->rating <= 350) {
        strcpy(player->label, "Mortal");
    } else {
        strcpy(player->label, "Radial");
    }
}

int main() {
    int P;
    // Membaca jumlah pemain
    scanf("%d", &P);

    Player players[P]; // Array untuk menyimpan data semua pemain
    int totalRating = 0; // Variabel untuk menyimpan total rating semua pemain

    // Membaca data setiap pemain
    for (int i = 0; i < P; i++) {
        scanf("%d %s", &players[i].rating, players[i].name);
        totalRating += players[i].rating; // Menambahkan rating pemain ke total rating
        assignLabel(&players[i]); // Memberikan label ke pemain berdasarkan rating
    }

    // Menghitung rata-rata rating
    int averageRating = totalRating / P;

    // Menghitung selisih rating setiap pemain dengan rata-rata rating
    for (int i = 0; i < P; i++) {
        players[i].diff = players[i].rating - averageRating;
    }

    // Mengurutkan pemain berdasarkan rating dan nama
    qsort(players, P, sizeof(Player), compare);

    // Mencetak data setiap pemain setelah diurutkan
    for (int i = 0; i < P; i++) {
        printf("%s %d %d %s\n", players[i].label, players[i].rating, players[i].diff, players[i].name);
    }

    return 0;
}