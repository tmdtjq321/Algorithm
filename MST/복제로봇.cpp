#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
struct edge{
	int f,t,w;
};

bool operator<(edge a, edge b){
	return (a.w > b.w);
} 

int N,M,x,y,res;
bool hard = false;
int par[2502];
int dist[52][52];
char input[52][52];
bool visit[52][52];
vector<pair<int,int>> v;
int dx[] = {1,-1,0,0}, dy[]={0,0,1,-1};
priority_queue<edge> pq;
queue<pair<int,int>> Q;

int find(int x){
	if (par[x] == x){
		return x;
	}
	
	return par[x] = find(par[x]);
}

void bfs(int x, int y){
	memset(dist,0,sizeof(dist));
	memset(visit,false,sizeof(visit));
	Q.push({x,y});
	visit[x][y] = true;
	while(!Q.empty()){
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++){
			int tx = dx[i] + cx;
			int ty = dy[i] + cy;
			if (input[tx][ty] != '1' && !visit[tx][ty]){
				int to = tx*N + ty;
				visit[tx][ty] = true;
				dist[tx][ty] = dist[cx][cy] + 1;
				Q.push({tx,ty});
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++){
		scanf("%s",input[i]);
		for (int j = 0; j < N; j++){
			if (input[i][j] != '1'){
				par[i*N + j] = i*N + j;
			}
			if (input[i][j] == 'S' || input[i][j] == 'K'){
				v.push_back({i,j});
			}
		}
	}
	for (int i = 0; i < v.size(); i++){
		bfs(v[i].first,v[i].second);
		for (int j = i + 1; j < v.size(); j++){
			if (!dist[v[j].first][v[j].second]){
				hard = true;
				break;
			}
			pq.push({(v[i].first*N+v[i].second),(v[j].first*N+v[j].second),dist[v[j].first][v[j].second]});
		}
	}
	
	while(!pq.empty()){
		int from = find(pq.top().f);
		int to = find(pq.top().t);
		int cost = pq.top().w;
		pq.pop();
		if (from == to){continue;}
		par[from] = to;
		res += cost;
	}
	if (hard){
		printf("-1");
	}
	else{
		printf("%d",res);
	}
	
	return 0;
}
