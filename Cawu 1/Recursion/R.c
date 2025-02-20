#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[105][105];

long long int proses(int startx, int starty, int sizex, int sizey){
    // kalau keluar
    if (startx < 0 || startx >= sizex || starty < 0 || starty >= sizey){
        return 0;
    }
    
    // kalau ketemu tembok
    if (map[starty][startx] == '#'){
        return 0;
    }

    int counter = 0;
    //  kalau ketemu posisi sekarang titik
    if (map[starty][startx] == '.'){
        counter++;
        map[starty][startx] = '#';
    }

    counter+= proses(startx+1,starty,sizex,sizey);
    counter+= proses(startx-1,starty,sizex,sizey);
    counter+= proses(startx,starty+1,sizex,sizey);
    counter+= proses(startx,starty-1,sizex,sizey);
    return counter;
}

int main(){
    long long int tc, counter;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++) {
        memset(map, 0, sizeof(map));
        int sizex, sizey;
        int startx = -1, starty;

        scanf("%d %d", &sizey, &sizex); getchar();

        for (int y = 0; y < sizey; y++) {
            scanf("%s", &map[y]); getchar();
        }

        //  cari start
        for (int y = 0; y < sizey; y++) {
            for (int x = 0; x < sizex; x++) {
                if (map[y][x] == 'S'){
                    startx = x;
                    starty = y;
                    break;
                }
            }
            if (startx != -1) {
                break;
            }
            
        }

        counter = proses(startx,starty,sizex,sizey);
        printf("Case #%d: %lld\n", i, counter);
    }
    
    return 0;
}