#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int map[105][105];
int island[105][105];
int visit[105][105];
int tmp[105][105];
int N;
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int min_num = 10005;


struct point{
	int x,y;
};

bool isin(int x, int y){
	return x >=0 && y >=0 && x < N && y < N;
}

void flush(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (visit[i][j] == 0){
				island[i][j] = 0;
			}
		}
	}
}

void print(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%3d ",island[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%3d ",visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs_bri(int x, int y, int num){ // num = visit[x][y]
	queue<point> Q;
	Q.push({x,y});
	while(!Q.empty()){
		point cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (isin(tx,ty) && island[tx][ty] == 0){
				island[tx][ty] = island[cur.x][cur.y] + 1;
				Q.push({tx,ty});
			}
			if (isin(tx,ty) && visit[tx][ty] != num && visit[tx][ty] != 0){
				if (min_num > island[cur.x][cur.y] - num){
					min_num = island[cur.x][cur.y] - num;
				}
//				printf("end : %d %d %d\n",cur.x,cur.y, island[cur.x][cur.y] - num);
				return; 				
			}
		}
	}
}
 
void bfs(int x, int y, int c){
	queue<point> Q;
	Q.push({x,y});
	while(!Q.empty()){
		point cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (isin(tx,ty) && map[tx][ty] == 1){
				map[tx][ty] = c;
				visit[tx][ty] = c;
				Q.push({tx,ty});
			}
			if (isin(tx,ty) && map[tx][ty] == 0){
				map[cur.x][cur.y] = -1;
				
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	int c = 1;
				
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] == 1){
				c++;
				map[i][j] = c;
				visit[i][j] = c;
				bfs(i,j,c);
			}
		}
	}	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			island[i][j] = map[i][j];
		}
	}
//	printf("%d\n",c-1); // ¼¶ÀÇ °³¼ö 
//	print();
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (island[i][j] == -1){
				int count = visit[i][j];
				island[i][j] = count;
//				printf("start: %d %d\n",i,j);
				bfs_bri(i,j,count);
//				print();
				flush();
			}
		}
	}
	printf("%d",min_num);
	
   	return 0;
}


