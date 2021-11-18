#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1LL << 60
using namespace std;
typedef long long ll;
int S, N, M, E;
struct pt{
	ll e, w;
};

vector<pt> v[105];
ll dist[105];
ll cash[105];
queue<int> Q;
bool visit[105];

int main(){
	scanf("%d%d%d%d",&N,&S,&E,&M);
	for (int i = 0; i < N; i++){
		dist[i] = INF;
	}
	dist[S] = 0;
	
	for (int i = 0; i < M; i++){
		int from, to, weight;
		scanf("%d%d%d",&from,&to,&weight);
		v[from].push_back((pt){to,weight});
	}
	
	for (int i = 0; i < N; i++){
		scanf("%d",&cash[i]);	
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < v[i].size(); j++){
			v[i][j].w = v[i][j].w - cash[v[i][j].e];
		}
	}
	
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < v[i].size(); j++){
				ll cur = v[i][j].e;
				ll cost = v[i][j].w + dist[i];
				if (dist[i] != INF && dist[cur] > cost){
					if (k == N-1){
						Q.push(i);
					} 
					dist[cur] = cost;
				}
			}
		}
	}
	bool chk = false;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		if (visit[now]){
			continue;
		}
		visit[now] = true;
		for (int i = 0; i < v[now].size(); i++){
			if (v[now][i].e == E){
				chk = true;
				break;
			}
			if (!visit[v[now][i].e]){
				Q.push(v[now][i].e);
			}
		}
		if (chk){
			break;
		}
		
	}
	
	if (dist[E] == INF){
		printf("gg\n");
	}
	else if(chk){
		printf("Gee\n");
	}
	else{
		dist[E] -= cash[S];
		printf("%d\n",-dist[E]);
	}
	
	return 0;
}
