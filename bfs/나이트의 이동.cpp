#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct point{
	int x,y;
};
int N;
int size;
int board[305][305];
int dx[]={2,2,-2,-2,-1,1,-1,1}, dy[] = {-1,1,-1,1,2,2,-2,-2};
int sx, sy;
int ax, ay;
queue<point> Q;

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < size && y < size;
}
void print(){
	printf("\n");
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}
void flush(){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			board[i][j] = 0;
		}
	}
}

void bfs(){
	while(!Q.empty()){
		point cur = Q.front();
		Q.pop();
		for (int i = 0; i < 8; i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (isin(tx,ty) && board[tx][ty] == 0){
				Q.push({tx,ty});
				board[tx][ty] = board[cur.x][cur.y] + 1;
			}
		}
	}
} 

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d",&size);
		scanf("%d %d",&sx, &sy);
		Q.push({sx,sy});
		scanf("%d %d",&ax, &ay);
		if ((sx == ax) && (sy == ay)){
			printf("0");
			continue;
		}
		bfs();
		print();
		printf("%d",board[ax][ay]);
		flush();
		
	}
	
   	return 0;
}
