#include <stdio.h>

int minMoves; 

void horse(int x, int y, int m, int n, int moves){
	if(moves>minMoves) return; 
	if(x<0 || x>7 || y<0 || y>7) return; 
	if(x==m && y==n){
		if(moves<minMoves) minMoves=moves; 
		return; 
	}
	horse(x+2, y+1, m, n, moves+1); 
	horse(x+2, y-1, m, n, moves+1); 
	horse(x+1, y+2, m, n, moves+1); 
	horse(x+1, y-2, m, n, moves+1); 
	horse(x-2, y+1, m, n, moves+1); 
	horse(x-2, y-1, m, n, moves+1); 
	horse(x-1, y+2, m, n, moves+1); 
	horse(x-1, y-2, m, n, moves+1); 
}

int main(){
	int n; 
	scanf("%d", &n); getchar(); 
	for(int i=0; i<n; i++){
		minMoves=8; 
		char a[3], b[3]; 
		scanf("%s %s", &a, &b); getchar(); 
		int x=a[0]-'A'; 
		int y=a[1]-'1'; 
		int m=b[0]-'A'; 
		int n=b[1]-'1'; 
		horse(x, y, m, n, 0); 
		printf("Case #%d: %d\n", i+1, minMoves); 
	}
	return 0; 
}