#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

struct pt{
	int ex, ey, w, n;
	pt(){}
	pt(int _ex, int _ey, int _w){
		ex = _ex;
		ey = _ey;
		w = _w;
	}
};

bool operator<(pt a, pt b){
	return (a.w > b.w);
}

vector<pt> v[5002];
int N, M, T, cnt;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
char input[52];
int board[52][52];
int dist[52][52];

bool isin(int x, int y){
	return (x >= 0 && y >= 0 && x < N && y < M);
}

void dijkstra(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			dist[i][j] = INF;
		}
	}
	dist[0][0] = 0;
	priority_queue<pt> pq;
	pq.push({0,0,0});
	while(!pq.empty()){
		int nx = pq.top().ex;
		int ny = pq.top().ey;
		int val = pq.top().w;
		pq.pop();
		printf("%d %d %d\n",nx,ny,val);
		for (int i = 0; i < 4; i++){
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (isin(tx,ty)){
				int cost = val + dist[nx][ny];
				if (dist[tx][ty] > cost){
					dist[tx][ty] = cost;
					if (board[tx][ty] == 1){
						pq.push({tx,ty,1});
					}
					else{
						pq.push({tx,ty,0});
					}
					
				}
			}
		}
	}
	
	
}

int main(){
	scanf("%d%d",&M, &N);
	for (int i = 0; i < N; i++){
		scanf("%s",input);
		for (int j = 0; j < M; j++){
			board[i][j] = input[j] - '0';
		}
	}
	dijkstra();
	printf("\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
//	printf("%d\n",res);
	
	return 0;
}
