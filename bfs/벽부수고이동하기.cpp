#include<stdio.h>
#include<queue>
using namespace std;

int N,M;
char map[1005][1005];
int visited[2][1005][1005];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int max_num = -1;

// ���� �ϳ��� �μ��� BFS ���� �ٽ� �ʱ�ȭ �Ŀ� ���� ���� ����� Ž�� ������ �ƴ϶�(���� §��) 
// visited[0][x][y]: ���� �μ��� ������ bfs�� Ž���� ��� + visited[1][x][y]: ���� �ν��� �� �� �μ� ����κ��� BFS�� �� ��� 

struct point{
	int x,y,cnt;
};

bool isin(int x, int y){
	return x >= 0 && y >= 0 && x < N && y <M;
}

void print(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			printf("%d ",visited[0][i][j]);
		}
		for (int j = 0; j < M; j++){
			printf("  %d ",visited[1][i][j]);
		}
		printf("\n");
	}
}

void bfs(){
	queue<point> Q;
	Q.push({0,0,0});
	visited[0][0][0] = 1;
	while(!Q.empty()){
		point cur = Q.front();
		printf("%d %d %d\n\n",cur.x,cur.y,cur.cnt); 
		print();
		Q.pop();
		if (cur.x == N-1 && cur.y == M-1){
			max_num = visited[cur.cnt][cur.x][cur.y];
			return;
		}
		
		for (int i = 0; i < 4; i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (isin(tx,ty) && visited[cur.cnt][tx][ty] == 0 && map[tx][ty] == '0'){
				visited[cur.cnt][tx][ty] = visited[cur.cnt][cur.x][cur.y] + 1;
				Q.push({tx,ty,cur.cnt});
			}
			if (isin(tx,ty) && visited[cur.cnt][tx][ty] == 0 && map[tx][ty] == '1' && cur.cnt == 0){
				visited[1][tx][ty] = visited[cur.cnt][cur.x][cur.y] + 1;
				Q.push({tx,ty,1});
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%s",map[i]);
		
	}
	
	bfs();
	printf("%d",max_num);
   	return 0;
}


