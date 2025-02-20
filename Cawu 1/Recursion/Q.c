#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Perpindahan x untuk 8 arah gerakan kuda
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2}; // Perpindahan y untuk 8 arah gerakan kuda             

int vis[9][9]; // Memakai ukuran [9][9] karena papan catur hanya dari 1-8
int temp[9][9]; // Memakai ukuran [9][9] karena papan catur hanya dari 1-8
int move = 0;

void reset(int map[9][9]){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            map[i][j] = -1;
        }
    }
}

void printmap(int map[9][9]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
}

bool isInside(int x, int y) { // validasi x,y di dalam papan
    return (0 <= x && x < 8 && 0 <= y && y < 8);
}

void recurtion(int x, int y, int move) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isInside(nx, ny)) {
            temp[ny][nx] = move;
            if (vis[ny][nx] == -1) {
                vis[ny][nx] = temp[ny][nx];
                recurtion(nx, ny, move+1);
            } else { // ketika ada isi maka cari minimum
                if (vis[ny][nx] > temp[ny][nx]) {
                    vis[ny][nx] = temp[ny][nx];
                    recurtion(nx, ny, move+1);
                }
            }
        }
    }
}

int main() {
    int tc, startY, endY, startX, endX;
    char tempStartX, tempEndX;

    scanf("%d", &tc); // Jumlah kasus uji
    for (int kasus = 1; kasus <= tc; kasus++) {
        // Baca posisi kuda hitam dan putih
        scanf(" %c%d %c%d", &tempStartX, &startY, &tempEndX, &endY);

        startX = tempStartX - 'A'; // Konversi huruf ke angka 1-8 untuk start X
        endX = tempEndX - 'A'; // Konversi huruf ke angka 1-8 untuk end X
        startY = 8 - startY; // Konversi start Y ke 0-7
        endY = 8 - endY; // Konversi end Y ke 0-7

        // Inisialisasi array `vis` untuk menandai semua posisi belum dikunjungi
        reset(vis);
        reset(temp);
        move = 0;

        vis[startY][startX] = move; // Set posisi awal
        move++;

        // print vis awal
        // printmap(vis);
        // printf("\n\n");

        // Rekursi untuk mencari jarak terpendek dari Start ke End
        recurtion(startX, startY, move);

        // print vis akhir
        // printmap(vis);
        // printf("\n\n");

        // Output hasil untuk setiap kasus uji
        if (vis[endY][endX] == -1) {
            printf("Case #%d: 0\n", kasus);
        } else {
            printf("Case #%d: %d\n", kasus, vis[endY][endX]);
        }
    }
    return 0;
}
