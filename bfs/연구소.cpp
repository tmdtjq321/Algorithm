#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int N,M;
int map[8][8];
int virus[8][8];
int dx[]= {1,-1,0,0}, dy[] = {0,0,1,-1};
int max_num = 0;

struct point{
	int x,y;
};

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void print(int arr[8][8]){
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j  = 0; j < M; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int count(int arr[8][8]){
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0 ; j < M; j++){
			if (arr[i][j] == 0){
				cnt++;
			}
		}
	}
	return cnt;
}

void bfs(){
	queue<point> Q;
	int tmp[8][8];
	int c;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			tmp[i][j] = virus[i][j];
			if (virus[i][j] == 2){
				Q.push({i,j});
			}
		}
	}
	while(!Q.empty()){
		point cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = dx[i] + cur.x;
			int ty = dy[i] + cur.y;
			if (isin(tx,ty) && tmp[tx][ty] == 0){
				Q.push({tx,ty});
				tmp[tx][ty] = 2;
			}
		}
	}
	c = count(tmp);
	if (max_num < c){
		max_num = c;
		print(tmp);
		printf("%d\n",c);
	}
}

void wall(int c){
	if (c == 3){
		bfs();
		return;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (virus[i][j] == 0){
				virus[i][j] = 1;
				wall(c+1);		
				virus[i][j] = 0;
			}
		}
	}
}


int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d",&map[i][j]);	
			virus[i][j] = map[i][j];	
		}
	}
	wall(0);
	
	
   	return 0;
}
