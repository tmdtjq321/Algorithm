#include<stdio.h>
#include<queue>
using namespace std;
struct point{
	int x,y;
};
char arr[101][101];
int visit[101][101]; 
int N,M;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int sx = 0;
int sy = 0;
int ax, ay;

bool safe(int x, int y){
  	return x>=0 && y>=0 && x<N && y<M;
}

void bfs(){
	queue<point> Q;
	Q.push({sx,sy});
	while(!Q.empty()){
		point cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = dx[i] + cur.x;
			int ty = dy[i] + cur.y;
			if (safe(tx,ty) && visit[tx][ty] == 1){
				Q.push({tx,ty});
				visit[tx][ty] = visit[cur.x][cur.y] + 1;
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	ax = N-1, ay = M-1;
	for (int i = 0; i < N; i++){
		scanf("%s",arr[i]);
		for(int j = 0; j < M; j++){
			if (arr[i][j] == '0') {
				visit[i][j] = -1;
			}
			else if (arr[i][j] == '1'){
				visit[i][j] = 1;
			}
		}
	}
	bfs();
	printf("%d",visit[ax][ay]);
   	return 0;
}

