#include <stdio.h>
#include <string.h>

char map[105][105];

int pacmon(int startx, int starty, int n, int m) {
    if (startx < 0 || startx >= m || starty < 0 || starty >= n) {
        return 0;
    }
    if (map[starty][startx] == '#') {
        return 0;
    }

    int counter = 0;
    
    if (map[starty][startx] == '*') {
        counter++;
    }
    
    // Tandai posisi yang sudah dikunjungi
    map[starty][startx] = '#';

    // Rekursif untuk empat arah (atas, bawah, kanan, kiri)
    counter += pacmon(startx + 1, starty, n, m);
    counter += pacmon(startx - 1, starty, n, m);
    counter += pacmon(startx, starty + 1, n, m);
    counter += pacmon(startx, starty - 1, n, m);

    return counter;
}

int main() {
    int tc, n, m, startx, starty;
    scanf("%d", &tc);
    for (int c = 1; c <= tc; c++) {
        memset(map, 0, sizeof(map));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }

        // Cari posisi start 'P'
        startx = -1;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (map[y][x] == 'P') {
                    startx = x;
                    starty = y;
                    break;
                }
            }
            if (startx != -1) {
                break;
            }
        }

        int counter = pacmon(startx, starty, n, m);
        printf("Case #%d: %d\n", c, counter);
    }

    return 0;
}
/*
2
5 5
#####
#P..#
###.#
#*.*#
#####
5 5
#####
#P#*#
#####
#*.*#
#####
*/