#include <stdio.h>

char map[100][100];

void floodfill(long long Ai[100][100], int x, int y, int sizex, int sizey, int angka){
    if (x < 0 || x >= sizex || y >= sizey || y < 0 || Ai[y][x]>angka){
        return;
    }
    if (Ai[y][x+1] <= Ai[y][x]){
        map[y][x+1] = 'W'; 
        floodfill(Ai, x+1, y, sizex, sizey, Ai[y][x+1]);        //perbarui angka 
    }
    if (Ai[y][x-1] <= Ai[y][x]){
        map[y][x-1] = 'W';
        floodfill(Ai, x-1, y, sizex, sizey, Ai[y][x-1]);        //rekursi aman dlm if 
    }
    if (Ai[y+1][x] <= Ai[y][x]){
        map[y+1][x] = 'W';
        floodfill(Ai, x, y+1, sizex, sizey, Ai[y+1][x]);
    }
    if (Ai[y-1][x] <= Ai[y][x]){
        map[y-1][x] = 'W'; 
        floodfill(Ai, x, y-1, sizex, sizey, Ai[y-1][x]);
    }
}

int main(){
    int sizex, sizey, x, y;
    long long Ai[100][100];

    scanf("%d %d", &sizex, &sizey);

    for (int i = 0; i < sizey; i++){
        for (int j = 0; j < sizex; j++){
            scanf("%lld", &Ai[i][j]);   
        }
    }

    for(int i=0; i<sizey; i++){
        for(int j=0; j<sizex; j++){
            printf("%lld ", Ai[i][j]); 
        }
        printf("\n"); 
    }
    
    scanf("%d %d", &x, &y);
    
    for (int i = 0; i < sizey; i++){
        for (int j = 0; j < sizex; j++){
            map[i][j] = '.'; 
        }
        map[i][sizex]=0; 
    } 

    int angka=Ai[y][x]; 

    map[y][x]='W'; 

    floodfill(Ai, x, y, sizex, sizey, angka);

    for (int i = 0; i < sizey; i++)
    {
        printf("%s\n", map[i]);
    } 

    return 0;
}