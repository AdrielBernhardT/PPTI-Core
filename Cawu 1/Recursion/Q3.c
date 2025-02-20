#include <stdio.h>

void horse(int map[10][10], int x, int y, int step){
    if(x < 0 || x >= 8 || y < 0 || y >= 8) return;
    if (step >= map[x][y]) return;
    map[x][y] = step;

    horse(map, x + 2, y + 1, step + 1);
    horse(map, x + 2, y - 1, step + 1);
    horse(map, x - 2, y + 1, step + 1);
    horse(map, x - 2, y - 1, step + 1);
    horse(map, x + 1, y + 2, step + 1);
    horse(map, x + 1, y - 2, step + 1);
    horse(map, x - 1, y + 2, step + 1);
    horse(map, x - 1, y - 2, step + 1);
}

void printMap(int map[10][10]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tc;

    scanf("%d", &tc); getchar();
    for (int c = 1; c <= tc; c++){
        char x1, y1, x2, y2;
        int map[10][10] = {[0 ... 9][0 ... 9] = 100};

        scanf("%c%c %c%c", &x1, &y1, &x2, &y2); getchar();
        x1 -= 'A'; y1 -= '1'; x2 -= 'A'; y2 -= '1';
        
        horse(map, x1, y1, 0);
        // printMap(map);
        printf("Case #%d: %d\n", c, map[x2][y2]);
    }
    return 0;
}