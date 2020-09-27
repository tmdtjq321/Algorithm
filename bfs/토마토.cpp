#include<stdio.h>
#include<queue>
using namespace std;
struct tomato{
	int x,y;
};
int box[1005][1005]; 
int N,M;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
queue<tomato> Q;

bool safe(int x, int y){
  	return x>=0 && y>=0 && x<N && y<M;
}

void print(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%d ",box[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs(){
	while(!Q.empty()){
		tomato cur = Q.front();
		Q.pop();
		print();
		for (int j = 0; j < 4; j++){
			int tx = dx[j] + cur.x;
			int ty = dy[j] + cur.y;
			if (safe(tx,ty) && box[tx][ty] == 0){
				Q.push({tx,ty});
				box[tx][ty] = box[cur.x][cur.y] + 1;
			}
		}
	}
}

int chk(){
	int max = 0;
	for (int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (box[i][j] == 0){
				return -1;
			}
			if (max < box[i][j]){
				max = box[i][j];
			}
		}
	}
	return max - 1;
}

int main(){
	scanf("%d%d",&M,&N);
	int check = 0;	
	for (int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d",&box[i][j]);
			if (box[i][j] == 1) {	// 시작지점  
				Q.push({i,j});
			}
			if (box[i][j] == 0){
				check = 1;
			}
		}
	}	
	if (check == 0){	// 익은 토마토만 있을 경우  
		printf("%d",check);
	}
	else{
		bfs();
		int num = chk();
		printf("%d",num);
	}
	
   	return 0;
}
