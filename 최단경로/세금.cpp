 #include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
struct pt{
	int e, w, s;
	pt(){}
	pt(int _e, int _w, int _s){
		e = _e;
		w = _w;
		s = _s;
	}
};

bool operator<(pt a, pt b){
	return (a.w > b.w);
}

int N, M, K, S, D;
vector<pair<int,int>> adj[1002];
int dist[1002][1002];

void dijkstra(){
	for (int i = 0; i < N; i++){
		for (int j = 1; j <= N; j++){
			dist[i][j] = INF;
		}
	}
	dist[0][S] = 0;
	priority_queue<pt> pq;
	pq.push({S,0,0});
	while(!pq.empty()){
		int cur = pq.top().e;
		int val = pq.top().w;
		int link = pq.top().s;
		pq.pop();
		if (dist[link][cur] > val){
			continue;
		}
		for (int i = 0; i < adj[cur].size(); i++){
			int des = adj[cur][i].first;
			int cost = adj[cur][i].second + val;
			if (dist[link+1][des] > cost){
				dist[link+1][des] = cost;
				pq.push({des,cost,link+1});
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	scanf("%d%d",&S,&D);
	for (int i = 0; i < M; i++){
		int from, to, val;
		scanf("%d%d%d",&from,&to,&val);
		adj[from].push_back({to,val});
		adj[to].push_back({from,val});
	}	
	for (int i = 1; i <= N; i++){
		printf("%d: ",i);
		for (int j = 0; j < adj[i].size(); j++){
			printf("(%d %d) ",adj[i][j].first,adj[i][j].second);
		}
		printf("\n");
	}
	dijkstra();
	int res = INF;
	for (int i = 1; i < N; i++){
		if (dist[i][D] < res){
			res = dist[i][D];
		}
	}
	printf("%d\n",res);
	
	for (int i = 0; i < N; i++){
		printf("%d: ",i);
		for (int j = 1; j <= N; j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
		
	for (int i = 0; i < K; i++){
		int tax;
		scanf("%d",&tax);
		int res = INF;
		for (int j = 1; j < N; j++){
			if (dist[j][D] != INF){
				dist[j][D] += tax * j;
				if (res > dist[j][D]){
					res = dist[j][D];
				}
			}
		}
		printf("%d\n",res);
	}
		
	return 0;
}
