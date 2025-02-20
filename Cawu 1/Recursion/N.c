#include <stdio.h>
#include <stdbool.h>

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Perpindahan x untuk 8 arah gerakan kuda
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2}; // Perpindahan y untuk 8 arah gerakan kuda             

bool vis[9][9][2]; // Memakai ukuran [9][9][2] karena papan catur hanya dari 1-8

bool isInside(int x, int y) {
    return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

void recurtion(int x, int y, int N, int horse) {
    if (N == 0) return;
    for (int i = 0; i < 8; i++) { 
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isInside(nx, ny) && !vis[nx][ny][horse]) {
            vis[nx][ny][horse] = true;
            recurtion(nx, ny, N - 1, horse);
        }
    }
}

int main() {
    int tc, N, startx[2], starty[2];
    char temph, tempp;

    scanf("%d", &tc); // Jumlah kasus uji
    for (int kasus = 1; kasus <= tc; kasus++) {
        scanf("%d", &N); // Batas langkah
        // Baca posisi kuda hitam dan putih
        scanf(" %c%d %c%d", &temph, &starty[1], &tempp, &starty[0]);
        startx[1] = temph - 'A' + 1; // Konversi huruf ke angka 1-8 untuk kuda hitam
        startx[0] = tempp - 'A' + 1; // Konversi huruf ke angka 1-8 untuk kuda putih
        // Inisialisasi array `vis` untuk menandai semua posisi belum dikunjungi
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                vis[i][j][0] = false;
                vis[i][j][1] = false;
            }
        }
        // Rekursi untuk setiap kuda
        for (int horse = 0; horse < 2; horse++) {
            vis[startx[horse]][starty[horse]][horse] = true;
            recurtion(startx[horse], starty[horse], N, horse);
        }
        // Cek apakah ada posisi yang bisa dicapai kedua kuda dalam batas langkah N
        bool canMeet = false;
        for (int i = 1; i <= 8 && !canMeet; i++) {
            for (int j = 1; j <= 8 && !canMeet; j++) {
                if (vis[i][j][0] && vis[i][j][1]) { // Jika posisi yang sama dikunjungi kedua kuda
                    canMeet = true;
                }
            }
        }
        // Output hasil untuk setiap kasus uji
        if (canMeet) {
            printf("Case #%d: YES\n", kasus);
        } else {
            printf("Case #%d: NO\n", kasus);
        }
    }

    return 0;
}
