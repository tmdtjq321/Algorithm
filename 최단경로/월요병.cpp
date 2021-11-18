#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<limits>
using namespace std;
typedef long long ll;
const long long MAX = std::numeric_limits<long long>::max();
struct pt{
	int ex, ey;
	ll w;
	pt(){}
	pt(int _ex, int _ey, ll _w){
		ex = _ex;
		ey = _ey;
		w = _w; 
	}
};

bool operator<(pt a, pt b){
	return (a.w > b.w);
}

int N, M;
ll dist[302][302];
ll board[302][302];
int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1};

bool isin(int x, int y){
	return (x >= 0 && y >= 0 && x < N && y < M);
}

void dijkstra(priority_queue<pt> & pq){
	while(!pq.empty()){
		int nx = pq.top().ex;
		int ny = pq.top().ey;
		ll val = pq.top().w;
		pq.pop();
		if (dist[nx][ny] < val){
			continue;
		}
		for (int i = 0; i < 8; i++){
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (isin(tx,ty) && board[tx][ty] != -1){
				int cost = board[tx][ty] + val;
				if (dist[tx][ty] > cost){
					dist[tx][ty] = cost;
					pq.push({tx,ty,cost});
				}
			}
			
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%lld",&board[i][j]);
			if (board[i][j] == -2){
				board[i][j] = 0;
			}
		}
	}
	ll res1 = MAX;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			dist[i][j] = MAX;
		}
	}
	priority_queue<pt> pq1;	
	for (int i = 0; i < N; i++){	// 가장 오른쪽 줄 
		if (board[i][M-1] != -1){
			dist[i][M-1] = board[i][M-1];
			pq1.push({i,M-1,dist[i][M-1]});
		}
	}
	dijkstra(pq1);	
	for (int i = 0; i < N; i++){
		if (res1 > dist[i][0]){
			res1 = dist[i][0];
		}
	}
	for (int i = 0; i < M; i++){
		if (res1 > dist[N-1][i]){
			res1 = dist[N-1][i];
		}
	}
	
	ll res2 = MAX;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			dist[i][j] = MAX;
		}
	}
	priority_queue<pt> pq2;
	for (int i = 0; i < M; i++){	// 가장 윗줄 
		if (board[0][i] != -1){
			dist[0][i] = board[0][i];
			pq2.push({0,i,dist[0][i]});
		}
	}
	dijkstra(pq2);
	for (int i = 0; i < N; i++){
		if (res2 > dist[i][0]){
			res2 = dist[i][0];
		}
	}
	for (int i = 0; i < M; i++){
		if (res2 > dist[N-1][i]){
			res2 = dist[N-1][i];
		}
	}
	ll ans;
	if (res1 > res2){
		ans = res2;
	}
	else{
		ans = res1;
	}
	if (ans == MAX){
		printf("-1");
	}
	else{
		printf("%lld",ans);
	}
		
	return 0;
}
