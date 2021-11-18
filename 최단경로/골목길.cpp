#include<stdio.h>
#include<algorithm>
#include<vector> 
#include<queue>
#define INF 987654321
using namespace std;
int N,M;

vector<pair<int,int>> v[102];
int dist[102];
int parent[102];
vector<int> res;
bool visit[102];

void find(int x){
	if (1 == x){
		return;
	}
	
	res.push_back(x);
	find(parent[x]);
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; i++){
		int from, to, val;
		scanf("%d%d%d",&from,&to,&val);
		v[from].push_back({to,-val});
	}
	
	for (int i = 1; i <= N; i++){
		parent[i] = i;
		dist[i] = INF;
	}
	dist[1] = 0;
	
	queue<int> Q;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			for (int k = 0; k < v[j].size(); k++){
				if (dist[j] != INF && dist[v[j][k].first] > dist[j] + v[j][k].second){
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					parent[v[j][k].first] = j;
					if (i == N){
						Q.push(j);
					}
				}
			}
		}
	}
	bool cycle = false;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		if (visit[cur]){
			continue;
		}
		visit[cur] = true;
		for (int i = 0; i < v[cur].size(); i++){
			if (v[cur][i].first == N){
				cycle = true;
				break;
			}
			if (!visit[v[cur][i].first]){
				Q.push(v[cur][i].first);
			}
		}
		if (cycle){
			break;
		}
	}
	
	if (cycle){
		printf("-1");
	}
	else{
		parent[1] = 1;
		find(N);
		res.push_back(1);
        for (int i = res.size() - 1; i >= 0; i--){
       		printf("%d ",res[i]);
       	}
	}

	
    return 0;
}

